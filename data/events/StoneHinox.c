-------- EventFlow: StoneHinox --------

Actor: StoneHinox
entrypoint: None()
actions: ['PlayTailorOtherChannelEx', 'PlayAnimation', 'ModelVisibility', 'BossRoomDoorOpen', 'LookAtGimmick', 'BossRoomDoorClose', 'SetActorSwitch', 'BossItemDrop']
queries: ['CheckSawTheFirstEvent']
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

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

void StoneHinoxStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch StoneHinox.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:

        fork {
            Hud.PlayOutAnim()
        } {
            Audio.StopAllBGM({'duration': 1.0})
        }

        Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

        fork {
            StoneHinox.BossRoomDoorClose()
        } {
            StoneHinox.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.AimActor({'actor': ActorIdentifier(name="StoneHinox"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

        fork {
            Timer.Wait({'time': 1.2000000476837158})
        } {
            StoneHinox.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }

        Dialog.Show({'message': 'SubEvent:BattleStoneHinox'})
        StoneHinox.SetActorSwitch({'switchIndex': 1, 'value': True})

        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call StoneHinoxSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void StoneHinoxSkip() {

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

    fork {
        StoneHinox.BossRoomDoorClose()
    } {
        StoneHinox.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    Link.AimActor({'actor': ActorIdentifier(name="StoneHinox"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

    fork {
        Timer.Wait({'time': 1.2000000476837158})
    } {
        StoneHinox.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.699999988079071})
    }

    Camera.WaitZeldaScroll()
    Hud.PlayInAnim()
    Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
}

void StoneHinoxEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    }

    StoneHinox.PlayAnimation({'name': 'dead_st', 'blendTime': 0.10000000149011612})

    fork {
        StoneHinox.PlayAnimation({'name': 'dead_lp', 'blendTime': 0.10000000149011612})
    } {
        StoneHinox.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    } {
        StoneHinox.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    StoneHinox.ModelVisibility({'modelIndex': 0, 'visible': False})
    StoneHinox.BossItemDrop()
    Timer.Wait({'time': 1.5})

    fork {
        StoneHinox.BossRoomDoorOpen()
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
