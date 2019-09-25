-------- EventFlow: Gohma --------

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'PlayBGM', 'StopAllBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Gohma
entrypoint: None()
actions: ['PlayAnimation', 'PlayTailorOtherChannelEx', 'ModelVisibility', 'BossRoomDoorOpen', 'LookAtGimmick', 'BossItemDrop', 'BossRoomDoorClose']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect', 'MoveZoneEnterDirection', 'AimActor']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['WaitZeldaScroll', 'Reset']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void GohmaStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

    fork {
        Gohma.BossRoomDoorClose()
    } {
        Gohma.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    Link.AimActor({'actor': ActorIdentifier(name="Gohma"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

    fork {
        Timer.Wait({'time': 1.2000000476837158})
    } {
        Gohma.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.699999988079071})
    }

    Camera.WaitZeldaScroll()
    Hud.PlayInAnim()
    Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void GohmaEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    }


    fork {
        Gohma.PlayAnimation({'name': 'dead02_st', 'blendTime': 0.10000000149011612})
        Gohma.PlayAnimation({'name': 'dead02', 'blendTime': 0.10000000149011612})
    } {
        Gohma.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    } {
        Gohma.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    Gohma.ModelVisibility({'modelIndex': 0, 'visible': False})
    Gohma.BossItemDrop()
    Timer.Wait({'time': 1.5})

    fork {
        Gohma.BossRoomDoorOpen()
    } {
        Timer.Wait({'time': 1.0})
    }

    Hud.PlayInAnim()
    Audio.PlayZoneBGM({'stopbgm': True})
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
}
