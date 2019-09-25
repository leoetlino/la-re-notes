-------- EventFlow: MatFace --------

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: MatFace
entrypoint: None()
actions: ['LookAtGimmick', 'PlayTailorOtherChannelEx', 'BossRoomDoorOpen', 'PlayAnimation', 'BossItemDrop', 'SetActorSwitch', 'BossRoomDoorClose', 'ModelVisibility']
queries: ['CheckSkipEndEvent', 'CheckSawTheFirstEvent', 'CheckKindBoss']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'StopBGM', 'PlayBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'SetDisablePowerUpEffect', 'ClearPowerUp', 'MoveZoneEnterDirection']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['PreloadTimeline', 'InvokeTimeline']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayInAnim', 'PlayOutAnim']
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

void MatFaceStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch MatFace.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Audio.StopAllBGM({'duration': 1.0})

        fork {
            Hud.PlayOutAnim()
        } {
            Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})
        }


        fork {
            MatFace.BossRoomDoorClose()
        } {
            Link.AimActor({'duration': 0.800000011920929, 'actor': ActorIdentifier(name="MatFace"), 'withoutTurn': False, 'boneName': ''})
        } {
            FlowControl.PreloadTimeline({'filename': 'MatFace'})
        }

        FlowControl.InvokeTimeline({'filename': 'MatFace', 'rate': 1.0})
        MatFace.SetActorSwitch({'switchIndex': 1, 'value': True})
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call MatFaceSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void MatFaceEnd() {
    Link.ClearPowerUp()

    fork {
        MatFace.PlayAnimation({'name': 'weak_wait', 'blendTime': 0.10000000149011612})
    } {
        Hud.PlayOutAnim()
    }

    Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS', 'duration': 0.5})
    MatFace.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    if !MatFace.CheckSkipEndEvent() {
        Audio.PlayBGM({'label': 'BGM_DEFEAT_LOOP', 'volume': 1.0})
        Dialog.Show({'message': 'Scenario:Lv6BossClear'})
        Event43:

        fork {
            MatFace.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
        } {
            MatFace.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
            MatFace.ModelVisibility({'visible': False, 'modelIndex': 0})
        }

        Audio.StopBGM({'label': 'BGM_DEFEAT_LOOP', 'duration': 0.5})
        Timer.Wait({'time': 1.0})
        switch MatFace.CheckKindBoss() {
          case 0:
            Audio.PlayBGM({'label': 'BGM_FANFARE_BOSS_HEART_GET', 'volume': 1.0})
            Timer.Wait({'time': 3.0})
            MatFace.BossItemDrop()
            Timer.Wait({'time': 1.5})
            MatFace.BossRoomDoorOpen()
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
          case 1:
            Audio.PlayBGM({'label': 'BGM_PANEL_RESULT', 'volume': 1.0})

            call PanelAdventure.PanelClear()

          case 2:
            Timer.Wait({'time': 1.0})
            MatFace.BossRoomDoorOpen()
            Audio.PlayZoneBGM({'stopbgm': True})
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
        }
    } else {
        goto Event43
    }
}

void MatFaceSkip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

    fork {
        MatFace.BossRoomDoorClose()
    } {
        MatFace.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }


    fork {
        Link.AimActor({'actor': ActorIdentifier(name="MatFace"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        MatFace.PlayAnimation({'name': 'pop_st', 'blendTime': 0.10000000149011612})
        MatFace.PlayAnimation({'name': 'pop_lp', 'blendTime': 0.0})
        Timer.Wait({'time': 0.5})
        MatFace.PlayAnimation({'name': 'pop_ed', 'blendTime': 0.0})
        MatFace.PlayAnimation({'blendTime': 0.0, 'name': 'wait'})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.699999988079071})
    }

    Camera.WaitZeldaScroll()
    Hud.PlayInAnim()
    Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
}
