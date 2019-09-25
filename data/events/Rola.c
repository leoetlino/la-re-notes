-------- EventFlow: Rola --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Rola
entrypoint: None()
actions: ['PlayAnimation', 'LookAtGimmick', 'PlayTailorOtherChannelEx', 'BossRoomDoorOpen', 'ModelVisibility', 'BossRoomDoorClose', 'BossItemDrop']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'PlayBGM', 'StopAllBGM', 'PlayZoneBGM']
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

void RolaStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

    fork {
        Rola.BossRoomDoorClose()
    } {
        Rola.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    Link.AimActor({'actor': ActorIdentifier(name="Rola"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

    fork {
        Timer.Wait({'time': 1.2000000476837158})
    } {
        Rola.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
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

void RolaEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    }


    fork {
        Rola.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Rola.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    } {
        Rola.PlayAnimation({'name': 'dead_st', 'blendTime': 0.10000000149011612})
        Rola.PlayAnimation({'name': 'dead', 'blendTime': 0.0})
    }

    Rola.ModelVisibility({'modelIndex': 0, 'visible': False})
    Rola.ModelVisibility({'modelIndex': 1, 'visible': False})
    Rola.BossItemDrop()
    Timer.Wait({'time': 2.0})

    fork {
        Rola.BossRoomDoorOpen()
    } {
        Timer.Wait({'time': 1.0})
    }


    fork {
        Hud.PlayInAnim()
    } {
        Audio.PlayZoneBGM({'stopbgm': True})
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
}
