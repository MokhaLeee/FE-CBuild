.section .rodata

	.global gEventLoCmdTableRe
gEventLoCmdTableRe:
    .4byte Event00_NULL, Event01_End, Event02_EvBitAndIdMod, Event03_CheckEvBitOrId
    .4byte Event04_CheckRandom, Event05_SetSlot, Event06_SlotOperation, Event07_SlotQueueOperations
    .4byte Event08_Label, Event09_Goto, Event0A_Call, Event0B_EnqueueCall
    .4byte Event0C_Branch, Event0D_AsmCall, Event0E_STAL, Event0F_
    .4byte Event10_ModifyEvBit, Event11_SetIgnoredKeys, Event12_StartBGM, Event12_BgmFadeIn
    .4byte Event14_, Event15_BgmVolume, Event16_, Event17_Fade
    .4byte Event18_, Event19_Checks, Event1A_TEXTSTART, Event1B_TEXTSHOW
    .4byte Event1C_TEXTCONT, Event1D_TEXTEND, Event1E_, Event1F_
    .4byte Event20_, Event21_, Event22_ClearScreen, Event23_DisaleMapDisp
    .4byte Event24_EnableMapDisp, Event25_ChangeMap, Event26_CameraControl, Event27_MapChange
    .4byte Event28_ChangeWeather, Event29_SetFogVision, Event2A_MoveToChapter, Event2B_
    .4byte Event2C_LoadUnits, Event2D_GetPid, Event2E_CheckAt, Event2F_MoveUnit
    .4byte Event30_ENUN, Event31_DisplayEffectRange, Event32_SpawnSingleUnit, Event33_CheckUnitVarious
    .4byte Event34_MessWithUnitState, Event35_UnitClassChanging, Event36_CheckInArea, Event37_GiveItem
    .4byte Event38_ChangeActiveUnit, Event39_ChangeAiScript, Event3A_DisplayPopup, Event3B_DisplayCursor
    .4byte Event3C_, Event3D_MenuOverride, Event3E_PrepScreenCall, Event3F_ScriptBattle
    .4byte Event40_, Event41_, Event42_, Event43_
    .4byte Event44_BreakingSacredStone, Event45_
