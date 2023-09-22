#include "global.h"
#include "rng.h"
#include "bmunit.h"
#include "bmbattle.h"

#include "common-chax.h"
#include "skill-system.h"
#include "efx-skill.h"
#include "battle-system.h"
#include "strmag.h"
#include "debuff.h"
#include "combat-art.h"
#include "constants/skills.h"

STATIC_DECLAR bool CheckSkillHpDrain(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    if (CheckBattleSkillActivte(attacker, defender, SID_Aether, GetUnitSkill(GetUnit(attacker->unit.index))))
    {
        RegisterActorEfxSkill(GetBattleHitRound(gBattleHitIterator), SID_Aether);
        return true;
    }
    return false;
}

int CalcBattleRealDamage(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    struct Unit * unit = GetUnit(attacker->unit.index);
    int damage = 0;

    if (SkillTester(unit, SID_RuinedBlade))
        damage += 5;

    if (SkillTester(unit, SID_RuinedBladePlus))
        damage += 5;

    if (SkillTester(unit, SID_LunaAttack))
        damage += defender->battleDefense / 4;

    return damage;
}

/* LynJump */
void BattleGenerateHitAttributes(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    int attack, defense;

    struct Unit * unit = GetUnit(attacker->unit.index);

    if (!BattleRoll2RN(gBattleStats.hitRate, TRUE))
    {
        gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_MISS;
        return;
    }

    /* Register combat-art hitted */
    if (attacker == &gBattleActor)
        RegisterCombatArtHitted();

    attack = gBattleStats.attack;
    defense = gBattleStats.defense;

    if (CheckBattleSkillActivte(attacker, defender, SID_Flare, GetUnitSkill(GetUnit(attacker->unit.index))))
    {
        RegisterActorEfxSkill(GetBattleHitRound(gBattleHitIterator), SID_Flare);
        defense = defense / 2;
    }

    if (IsMagicAttack(attacker))
    {
        if (CheckBattleSkillActivte(attacker, defender, SID_Corona, GetUnitSkill(GetUnit(attacker->unit.index))))
        {
            RegisterActorEfxSkill(GetBattleHitRound(gBattleHitIterator), SID_Corona);
            defense = 0;
        }
    }
    else
    {
        if (CheckBattleSkillActivte(attacker, defender, SID_Luna, GetUnitSkill(GetUnit(attacker->unit.index))))
        {
            RegisterActorEfxSkill(GetBattleHitRound(gBattleHitIterator), SID_Luna);
            defense = 0;
        }
    }

    gBattleStats.damage = attack - defense;

    if (SkillTester(unit, SID_FlashingBladePlus))
        gBattleStats.damage += 3;

    if (BattleRoll1RN(gBattleStats.critRate, FALSE) == TRUE && !SkillTester(&defender->unit, SID_Foresight))
    {
        if (BattleRoll1RN(gBattleStats.silencerRate, FALSE))
        {
            /* Silencer */
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_SILENCER;
            gBattleStats.damage = BATTLE_MAX_DAMAGE;
        }
        else
        {
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_CRIT;

            /* InfinityEdge */
            if (SkillTester(unit, SID_InfinityEdge))
                gBattleStats.damage = gBattleStats.damage * 3;
            else
                gBattleStats.damage = gBattleStats.damage * 2;
        }
    }

    /* SID_Astra may half the damage */
    if (attacker == &gBattleActor)
        if (SkillTester(unit, SID_Astra) && gBattleActorGlobalFlag.skill_activated_astra)
            gBattleStats.damage = gBattleStats.damage / 2;

    /* Minus zero */
    if (gBattleStats.damage < 0)
        gBattleStats.damage = 0;

    /* Real damage */
    gBattleStats.damage += CalcBattleRealDamage(attacker, defender);

    if (gBattleStats.damage > 0)
    {
        struct Unit * _tmpunit = GetUnit(defender->unit.index);
        if (IsMagicAttack(attacker))
        {
            if (CheckBattleSkillActivte(defender, attacker, SID_Aegis, GetUnitSkill(_tmpunit)))
            {
                RegisterTargetEfxSkill(GetBattleHitRound(gBattleHitIterator), SID_Aegis);
                gBattleStats.damage = 0;
            }
        }
        else
        {
            if (CheckBattleSkillActivte(defender, attacker, SID_Pavise, GetUnitSkill(_tmpunit)))
            {
                RegisterTargetEfxSkill(GetBattleHitRound(gBattleHitIterator), SID_Pavise);
                gBattleStats.damage = 0;
            }
        }
    }

    /* Post calc */
    if (gBattleStats.damage > BATTLE_MAX_DAMAGE)
        gBattleStats.damage = BATTLE_MAX_DAMAGE;

    BattleCheckPetrify(attacker, defender);

    if (gBattleStats.damage != 0)
        attacker->nonZeroDamage = TRUE;
}

/* LynJump */
void BattleGenerateHitEffects(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    int debuff;

    attacker->wexpMultiplier++;

    if (!(gBattleHitIterator->attributes & BATTLE_HIT_ATTR_MISS))
    {
        switch (GetItemWeaponEffect(attacker->weapon)) {
        case WPN_EFFECT_POISON:
            // Poison defender
            defender->statusOut = UNIT_STATUS_POISON;
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_POISON;

            // "Ungray" defender if it was petrified (as it won't be anymore)
            debuff = GetUnitStatusIndex(&defender->unit);
            if (debuff == UNIT_STATUS_PETRIFY || debuff == UNIT_STATUS_13)
                defender->unit.state = defender->unit.state &~ US_UNSELECTABLE;

            break;

        case WPN_EFFECT_HPHALVE:
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_HPHALVE;
            break;

        }

        if ((GetItemWeaponEffect(attacker->weapon) == WPN_EFFECT_DEVIL) && (BattleRoll1RN(31 - attacker->unit.lck, FALSE)))
        {
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_DEVIL;

            attacker->unit.curHP -= gBattleStats.damage;

            if (attacker->unit.curHP < 0)
                attacker->unit.curHP = 0;
        }
        else
        {
            if (gBattleStats.damage > defender->unit.curHP)
                gBattleStats.damage = defender->unit.curHP;

            defender->unit.curHP -= gBattleStats.damage;

            if (defender->unit.curHP < 0)
                defender->unit.curHP = 0;
        }

#ifdef CHAX_IDENTIFIER
        if (GetItemWeaponEffect(attacker->weapon) == WPN_EFFECT_HPDRAIN || CheckSkillHpDrain(attacker, defender))
#else
        if (GetItemWeaponEffect(attacker->weapon) == WPN_EFFECT_HPDRAIN)
#endif
        {
            if (attacker->unit.maxHP < (attacker->unit.curHP + gBattleStats.damage))
                attacker->unit.curHP = attacker->unit.maxHP;
            else
                attacker->unit.curHP += gBattleStats.damage;

            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_HPSTEAL;
        }

        if (GetItemWeaponEffect(attacker->weapon) == WPN_EFFECT_PETRIFY)
        {
            switch (gPlaySt.faction) {
            case FACTION_BLUE:
                if (UNIT_FACTION(&defender->unit) == FACTION_BLUE)
                    defender->statusOut = UNIT_STATUS_13;
                else
                    defender->statusOut = UNIT_STATUS_PETRIFY;
                break;

            case FACTION_RED:
                if (UNIT_FACTION(&defender->unit) == FACTION_RED)
                    defender->statusOut = UNIT_STATUS_13;
                else
                    defender->statusOut = UNIT_STATUS_PETRIFY;
                break;

            case FACTION_GREEN:
                if (UNIT_FACTION(&defender->unit) == FACTION_GREEN)
                    defender->statusOut = UNIT_STATUS_13;
                else
                    defender->statusOut = UNIT_STATUS_PETRIFY;
                break;
            }
            gBattleHitIterator->attributes |= BATTLE_HIT_ATTR_PETRIFY;
        }
    }

    gBattleHitIterator->hpChange = gBattleStats.damage;

    if (!(gBattleHitIterator->attributes & BATTLE_HIT_ATTR_MISS) || attacker->weaponAttributes & (IA_UNCOUNTERABLE | IA_MAGIC))
    {
#ifdef CHAX_IDENTIFIER
        /* Check on combat-art */
        int cost = 1;
        if (attacker == &gBattleActor)
        {
            int cid = GetCombatArtInForce(&attacker->unit);
            if (COMBART_VALID(cid) && gCombatArtInfos[cid].cost > 0)
                cost = gCombatArtInfos[cid].cost;
        }

        while (cost-- > 0)
        {
            u16 weapon = GetItemAfterUse(attacker->weapon);
            attacker->weapon = weapon;

            if (!weapon)
                break;
        }
#else
        attacker->weapon = GetItemAfterUse(attacker->weapon);
#endif
        if (!attacker->weapon)
            attacker->weaponBroke = TRUE;
    }
}

/* LynJump */
bool BattleGenerateHit(struct BattleUnit * attacker, struct BattleUnit * defender)
{
    if (attacker == &gBattleTarget)
        gBattleHitIterator->info |= BATTLE_HIT_INFO_RETALIATION;

    BattleUpdateBattleStats(attacker, defender);

    BattleGenerateHitTriangleAttack(attacker, defender);
    BattleGenerateHitAttributes(attacker, defender);
    BattleGenerateHitEffects(attacker, defender);

    if (attacker->unit.curHP == 0 || defender->unit.curHP == 0)
    {
        attacker->wexpMultiplier++;

        gBattleHitIterator->info |= BATTLE_HIT_INFO_FINISHES;

#if CHAX_IDENTIFIER
        if (defender->unit.curHP == 0)
        {
            if (CheckBattleSkillActivte(defender, attacker, SID_Bane, GetUnitLuck(GetUnit(defender->unit.index))))
            {
                RegisterTargetEfxSkill(GetBattleHitRound(gBattleHitIterator), SID_Bane);

                gBattleStats.damage = gBattleStats.damage - 1;
                gBattleHitIterator->hpChange = gBattleStats.damage;
                defender->unit.curHP = 1;

                gBattleHitIterator->info |= BATTLE_HIT_INFO_FINISHES;
                gBattleHitIterator++;
                return true;
            }
        }
#endif

        if (gBattleTarget.unit.curHP == 0)
            gBattleHitIterator->info |= BATTLE_HIT_INFO_KILLS_TARGET;

        gBattleHitIterator++;
        return true;
    }
    else if (defender->statusOut == UNIT_STATUS_PETRIFY || defender->statusOut == UNIT_STATUS_13)
    {
        gBattleHitIterator->info |= BATTLE_HIT_INFO_FINISHES;
        gBattleHitIterator++;
        return true;
    }

    gBattleHitIterator++;
    return false;
}
