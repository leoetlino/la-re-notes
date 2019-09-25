-------- EventFlow: Jacky --------

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'StopAllBGM', 'PlayBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Jacky
entrypoint: None()
actions: ['PlayAnimation', 'PlayTailorOtherChannelEx', 'ModelVisibility', 'BossRoomDoorOpen', 'BossRoomDoorClose', 'LookAtGimmick', 'BossItemDrop']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect', 'AimActor', 'MoveZoneEnterDirection']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'WaitZeldaScroll']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayInAnim', 'PlayOutAnim']
queries: []
params: None

void JackyEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    }


    fork {
        Jacky.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    } {
        Jacky.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    } {
        Jacky.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    Jacky.ModelVisibility({'modelIndex': 0, 'visible': False})
    Jacky.BossItemDrop()
    Timer.Wait({'time': 1.5})

    fork {
        Jacky.BossRoomDoorOpen()
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

void JackyStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

    fork {
        Jacky.BossRoomDoorClose()
    } {
        Jacky.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Jacky"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    Timer.Wait({'time': 1.2000000476837158})

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
