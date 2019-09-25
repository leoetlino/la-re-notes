-------- EventFlow: MightPunch --------

Actor: MightPunch
entrypoint: None()
actions: ['PlayTailorOtherChannelEx', 'PlayAnimation', 'ModelVisibility', 'BossRoomDoorOpen', 'BossRoomDoorClose', 'LookAtGimmick', 'BossItemDrop']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'PlayZoneBGM', 'StopAllBGM', 'PlayBGM']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestRestartWarp', 'RequestAutoSave']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect', 'MoveZoneEnterDirection', 'AimActor']
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

void MightPunchEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    }


    fork {
        MightPunch.PlayAnimation({'name': 'dead_st', 'blendTime': 0.10000000149011612})
        MightPunch.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    } {
        MightPunch.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    } {
        MightPunch.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    MightPunch.ModelVisibility({'modelIndex': 0, 'visible': False})
    MightPunch.BossItemDrop()
    Timer.Wait({'time': 1.5})

    fork {
        MightPunch.BossRoomDoorOpen()
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

void MightPunchCrashOut() {

    fork {
        Fade.StartPreset({'preset': 5})
        GameControl.RequestRestartWarp({'locator': 'MigthPunchRestart', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.PlayZoneBGM({'stopbgm': True})
    }

}

void MightPunchStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})
    MightPunch.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})

    fork {
        MightPunch.BossRoomDoorClose()
    } {
        MightPunch.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    Link.AimActor({'actor': ActorIdentifier(name="MightPunch"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

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
