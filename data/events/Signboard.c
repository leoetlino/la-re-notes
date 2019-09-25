-------- EventFlow: Signboard --------

Actor: FieldTipMaze[Tip]
entrypoint: None()
actions: ['LookAtInfomation', 'PlayOneshotSE']
queries: []
params: None

Actor: Signboard
entrypoint: None()
actions: ['Examine', 'GenericExamineSequence', 'ExamineRapidFlow', 'ExamineFishing', 'ExamineKeep']
queries: ['CheckRapidFlowRecord', 'CheckHaveFished']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

void examine_Weathercock() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBWeathercock'})
}

void examine_Shell() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBShellMansion'})
}

void examine_Yarna() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBYarnaDesert'})
}

void examine_Toronbo() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBToronboShores'})
}

void examine_Forest() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBForest'})
}

void examine_EastMabe() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBEastMabe'})
}

void examine_Tamaranch() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBMountTamaranch'})
}

void examine_ExitMabe() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBExitMabe'})
}

void examine_RightHouse() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBWestGoponga'})
}

void examine_ForestCaution() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBForestCaution'})
}

void examine_Telephone() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBTelephoneBox'})
}

void examine_Goponga() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBGoponga'})
}

void examine_MazeSouth() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !EventFlags.CheckFlag({'symbol': 'MamuMazeClear'}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeSouth'})
    } else
    if !Inventory.HasItem({'itemType': 55, 'count': 1}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeClear'})
    } else {
        Signboard.Examine({'message': 'Place:SBMamuByebye'})
    }
}

void examine_MazeNorth() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !EventFlags.CheckFlag({'symbol': 'MamuMazeClear'}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeNorth'})
    } else
    if !Inventory.HasItem({'itemType': 55, 'count': 1}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeClear'})
    } else {
        Signboard.Examine({'message': 'Place:SBMamuByebye'})
    }
}

void examine_MazeEast() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !EventFlags.CheckFlag({'symbol': 'MamuMazeClear'}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeEast'})
    } else
    if !Inventory.HasItem({'itemType': 55, 'count': 1}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeClear'})
    } else {
        Signboard.Examine({'message': 'Place:SBMamuByebye'})
    }
}

void examine_MazeWest() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !EventFlags.CheckFlag({'symbol': 'MamuMazeClear'}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeWest'})
    } else
    if !Inventory.HasItem({'itemType': 55, 'count': 1}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeClear'})
    } else {
        Signboard.Examine({'message': 'Place:SBMamuByebye'})
    }
}

void examine_MazeReset() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !EventFlags.CheckFlag({'symbol': 'MamuMazeClear'}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeReset'})
    } else
    if !Inventory.HasItem({'itemType': 55, 'count': 1}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeClear'})
    } else {
        Signboard.Examine({'message': 'Place:SBMamuByebye'})
    }
}

void examine_MazeClear() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !EventFlags.CheckFlag({'symbol': 'MamuMazeClear'}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeClear'})
        FieldTipMaze[Tip].LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        Timer.Wait({'time': 1.0})

        fork {
            FieldTipMaze[Tip].PlayOneshotSE({'label': 'SE_MAP_KANBAN_CLEAR', 'volume': 1.0, 'pitch': 1.0})
        } {
            EventFlags.SetFlag({'value': True, 'symbol': 'MamuMazeClear'})
        }

        Timer.Wait({'time': 2.5999999046325684})
        Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
        GameControl.RequestAutoSave()
    } else
    if !Inventory.HasItem({'itemType': 55, 'count': 1}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeClear'})
    } else {
        Signboard.Examine({'message': 'Place:SBMamuByebye'})
    }
}

void examine_MamuByebye() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBMamuByebye'})
}

void examine_ManbosPond() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBManbosPond'})
}

void examine_MarthasBay() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBMarthasBay'})
}

void examine_AnimalVillage() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBAnimalVillage'})
}

void examine_Cemetery() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBCemetery'})
}

void examine_TalTalHeights() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBTalTalHeights'})
}

void examine_MoblinsCave() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBMoblinsCave'})
}

void examine_RichardHouse() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBRichardHouse'})
}

void examine_KanaletCount10() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBKanaletCount10'})
}

void examine_KanaletCount5() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBKanaletCount5'})
}

void examine_KanaletMove50() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBKanaletMove50'})
}

void examine_FishPond() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBFishPond'})
}

void examine_MazeReverse() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBMamuMazeReverse'})
}

void examine_TalTalDayo() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBTalTal'})
}

void examine_FishingTime() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !Signboard.CheckHaveFished() {
        Dialog.Show({'message': 'SubEvent:NoMemory'})
    } else {
        Signboard.ExamineFishing({'message': 'SubEvent:SBFishingTime'})
    }
}

void examine_RaftShop() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.ExamineKeep({'message': 'Place:SBRaftShop'})
    if !Signboard.CheckRapidFlowRecord() {
        Dialog.Show({'message': 'SubEvent:NoMemory'})
    } else {
        Signboard.ExamineRapidFlow({'message': 'SubEvent:SBReftShopTime'})
    }
}

void dexamine_Mebe() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBDanpeiMebe'})
}

void dexamine_Ukuku() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBDanpeiUkuku'})
}

void dexamine_Tarutaru() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Signboard.Examine({'message': 'Place:SBDanpeiTalTal'})
}

void examine_MazeFirst() {
    Signboard.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !EventFlags.CheckFlag({'symbol': 'MamuMazeClear'}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeSouthStart'})
    } else
    if !Inventory.HasItem({'itemType': 55, 'count': 1}) {
        Signboard.Examine({'message': 'Place:SBMamuMazeClear'})
    } else {
        Signboard.Examine({'message': 'Place:SBMamuByebye'})
    }
}
