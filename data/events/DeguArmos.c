-------- EventFlow: DeguArmos --------

Actor: DeguArmos
entrypoint: None()
actions: ['LookAtGimmick', 'PlayAnimationEx', 'PlayTailorOtherChannelEx', 'BossRoomDoorOpen', 'ModelVisibility', 'PlayAnimation', 'BossItemDrop', 'BossRoomDoorClose', 'SetActorSwitch']
queries: ['CheckActorSwitch']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'StopAllBGM', 'PlayBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveZoneEnterDirection', 'AimActor', 'SetDisablePowerUpEffect']
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

Actor: Camera
entrypoint: None()
actions: ['WaitZeldaScroll', 'Reset']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void DeguArmosStart() {
    if !DeguArmos.CheckActorSwitch({'switchIndex': 0}) {
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': True})

        fork {
            Audio.StopAllBGM({'duration': 1.0})
        } {
            Hud.PlayOutAnim()
        }

        Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

        fork {
            DeguArmos.BossRoomDoorClose()
        } {
            DeguArmos.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.AimActor({'duration': 0.4000000059604645, 'actor': ActorIdentifier(name="DeguArmos"), 'withoutTurn': False, 'boneName': ''})
        DeguArmos.PlayAnimation({'name': 'start_00', 'blendTime': 0.10000000149011612})

        fork {
            Timer.Wait({'time': 0.5})
        } {
            DeguArmos.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
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
}

void DeguArmosEnd() {
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': True})

    fork {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    } {
        Hud.PlayOutAnim()
    }


    fork {
        DeguArmos.PlayAnimationEx({'name': 'dead', 'time': 4.0, 'blendTime': 0.10000000149011612})
    } {
        DeguArmos.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    } {
        DeguArmos.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    DeguArmos.ModelVisibility({'modelIndex': 0, 'visible': False})
    DeguArmos.BossItemDrop()
    Timer.Wait({'time': 1.5})

    fork {
        DeguArmos.BossRoomDoorOpen()
    } {
        Timer.Wait({'time': 1.0})
    }

    Audio.PlayZoneBGM({'stopbgm': True})
    Hud.PlayInAnim()
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    DeguArmos.SetActorSwitch({'switchIndex': 0, 'value': True})
    GameControl.RequestAutoSave()
}
