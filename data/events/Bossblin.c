-------- EventFlow: Bossblin --------

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopBGM', 'PlayZoneBGM', 'StopAllBGM']
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

Actor: Link
entrypoint: None()
actions: ['MoveZoneEnterDirection', 'AimActor', 'SetDisablePowerUpEffect']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'WaitZeldaScroll']
queries: []
params: None

Actor: Bossblin
entrypoint: None()
actions: ['PlayAnimation', 'PlayTailorOtherChannelEx', 'ModelVisibility', 'BossRoomDoorClose', 'LookAtGimmick', 'SetActorSwitch', 'BossRoomDoorOpen', 'BossItemDrop']
queries: ['CheckSawTheFirstEvent', 'CheckKindBoss']
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

void Bossblin() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch Bossblin.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Hud.PlayOutAnim()
        Bossblin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

        fork {
            Link.AimActor({'actor': ActorIdentifier(name="Bossblin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Bossblin.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            Bossblin.BossRoomDoorClose()
        }

        Dialog.Show({'message': 'Scenario:Lv2MiniBossKingMoblin'})
        Bossblin.SetActorSwitch({'switchIndex': 1, 'value': True})
        Camera.Reset({'chaseRatio': 0.10000000149011612})
        Hud.PlayInAnim()
        Camera.WaitZeldaScroll()
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case 1:
        Hud.PlayOutAnim()
        Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})
        Bossblin.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        Link.AimActor({'actor': ActorIdentifier(name="Bossblin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

        fork {
            Bossblin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Bossblin.BossRoomDoorClose()
        } {
            Timer.Wait({'time': 1.2000000476837158})
        }


        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [2, 3]:

        call BossblinSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void BossblinEnd() {
    switch Bossblin.CheckKindBoss() {
      case 0:
        Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
        Hud.PlayOutAnim()

        fork {
            Bossblin.PlayAnimation({'name': 'dead_st', 'blendTime': 0.10000000149011612})
            Bossblin.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
        } {
            Bossblin.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
        } {
            Bossblin.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Bossblin.ModelVisibility({'modelIndex': 0, 'visible': False})
        Bossblin.BossItemDrop()
        Timer.Wait({'time': 1.5})

        fork {
            Bossblin.BossRoomDoorOpen()
        } {
            Timer.Wait({'time': 1.0})
        }

        Hud.PlayInAnim()
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
        GameControl.RequestAutoSave()
      case [1, 2]:
        Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

        fork {
            Hud.PlayOutAnim()
        } {
            Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
        }


        fork {
            Bossblin.PlayAnimation({'name': 'dead_st', 'blendTime': 0.10000000149011612})
            Bossblin.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
        } {
            Bossblin.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
        } {
            Bossblin.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Bossblin.ModelVisibility({'modelIndex': 0, 'visible': False})
        Bossblin.BossItemDrop()
        Timer.Wait({'time': 1.5})

        fork {
            Bossblin.BossRoomDoorOpen()
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
}

void BossblinSkip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Hud.PlayOutAnim()
    Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})
    Bossblin.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    Link.AimActor({'actor': ActorIdentifier(name="Bossblin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

    fork {
        Bossblin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Bossblin.BossRoomDoorClose()
    } {
        Timer.Wait({'time': 1.2000000476837158})
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
