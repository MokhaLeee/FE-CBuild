#include "global.h"
#include "chapterdata.h"

const struct ROMChapterData PrologueData = {
    .internalName = NULL,
    .map = {
        .obj1Id = 1,
        .obj2Id = 0,
        .paletteId = 2,
        .tileConfigId = 3,
        .mainLayerId = 4,
        .objAnimId = 5,
        .paletteAnimId = 0,
        .changeLayerId = 9,
    },
    .initialFogLevel = 0,
    .hasPrepScreen = FALSE,
    .chapTitleId = 0,
    .chapTitleIdInHectorStory = 0,
    .initialPosX = 1,
    .initialPosY = 0,
    .initialWeather = WEATHER_FINE,
    .battleTileSet = 0,
    .easyModeLevelMalus = 0,
    .difficultModeLevelBonus = 1,
    .normalModeLevelMalus = 0,
    .mapBgmIds = {
        [MAP_BGM_BLUE] = 9,
        [MAP_BGM_RED] = 19,
        [MAP_BGM_GREEN] = 19,
        [MAP_BGM_BLUE_HECTOR] = 9,
        [MAP_BGM_RED_HECTOR] = 19,
        [MAP_BGM_GREEN_HECTOR] = 19,
        [MAP_BGM_BLUE_GREEN_ALT] = 9,
        [MAP_BGM_RED_ALT] = 65535,
        [MAP_BGM_PROLOGUE_LYN] = 11,
        [MAP_BGM_PROLOGUE] = 65535,
        [MAP_BGM_PROLOGUE_HECTOR] = 65535,
    },
    .mapCrackedWallHeath = 50,
    .turnsForTacticsRankAInEliwoodStory = {
        [0] = 5,
        [1] = 5,
    },
    .turnsForTacticsRankAInHectorStory = {
        [0] = 5,
        [1] = 5,
    },
    .turnsForTacticsRankBInEliwoodStory = {
        [0] = 6,
        [1] = 6,
    },
    .turnsForTacticsRankBInHectorStory = {
        [0] = 6,
        [1] = 6,
    },
    .turnsForTacticsRankCInEliwoodStory = {
        [0] = 7,
        [1] = 7,
    },
    .turnsForTacticsRankCInHectorStory = {
        [0] = 7,
        [1] = 7,
    },
    .turnsForTacticsRankDInEliwoodStory = {
        [0] = 8,
        [1] = 8,
    },
    .turnsForTacticsRankDInHectorStory = {
        [0] = 8,
        [1] = 8,
    },
    .unk3D = 0,
    .gainedExpForExpRankAInEliwoodStory = {
        [0] = 100,
        [1] = 100,
    },
    .gainedExpForExpRankAInHectorStory = {
        [0] = 100,
        [1] = 100,
    },
    .gainedExpForExpRankBInEliwoodStory = {
        [0] = 80,
        [1] = 80,
    },
    .gainedExpForExpRankBInHectorStory = {
        [0] = 80,
        [1] = 80,
    },
    .gainedExpForExpRankCInEliwoodStory = {
        [0] = 60,
        [1] = 60,
    },
    .gainedExpForExpRankCInHectorStory = {
        [0] = 60,
        [1] = 60,
    },
    .gainedExpForExpRankDInEliwoodStory = {
        [0] = 40,
        [1] = 40,
    },
    .gainedExpForExpRankDInHectorStory = {
        [0] = 40,
        [1] = 40,
    },
    .unk5E = 0,
    .goldForFundsRankInEliwoodStory = {
        [0] = 1060,
        [1] = 1060,
    },
    .goldForFundsRankInHectorStory = {
        [0] = 1060,
        [1] = 1060,
    },
    .chapTitleTextId = 352,
    .chapTitleTextIdInHectorStory = 352,
    .mapEventDataId = 7,
    .gmapEventId = 1,
    .divinationTextIdBeginning = 0,
    .divinationTextIdInEliwoodStory = 0,
    .divinationTextIdInHectorStory = 0,
    .divinationTextIdEnding = 0,
    .divinationPortrait = 0,
    .divinationFee = 0,
    .prepScreenNumber = 0,
    .prepScreenNumberInHectorStory = 0,
    .merchantPosX = 255,
    .merchantPosXInHectorStory = 255,
    .merchantPosY = 0,
    .merchantPosYInHectorStory = 0,
    .victorySongEnemyThreshold = 1,
    .fadeToBlack = TRUE,
    .statusObjectiveTextId = 418,
    .goalWindowTextId = 413,
    .goalWindowDataType = GOAL_TYPE_DEFEAT_BOSS,
    .goalWindowEndTurnNumber = 0,
    .protectCharacterIndex = 0,
    .destPosX = 255,
    .destPosY = 0,
    .unk91 = 29,
    .unk92 = 0,
    .unk93 = 0,
};
