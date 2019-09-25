-------- EventFlow: Hooker --------

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

Actor: Hooker
entrypoint: None()
actions: ['LookAtGimmick', 'BossRoomDoorOpen', 'BossItemDrop', 'ModelVisibility', 'BossRoomDoorClose', 'SetActorSwitch', 'PlayAnimation']
queries: ['CheckSkipEndEvent', 'CheckSawTheFirstEvent', 'CheckKindBoss']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'StopBGM', 'PlayBGM', 'PlayZoneBGM', 'PlayOneshotSystemSE']
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

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect', 'ClearPowerUp', 'MoveZoneEnterDirection']
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

void HookerEnd() {
    Audio.PlayOneshotSystemSE({'label': 'SE_ENE_ALL_BOSS_DAMAGE', 'volume': 1.0, 'pitch': 1.0})
    Link.ClearPowerUp()
    Hud.PlayOutAnim()
    Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS', 'duration': 0.5})
    Hooker.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    if !Hooker.CheckSkipEndEvent() {
        Audio.PlayBGM({'label': 'BGM_DEFEAT_LOOP', 'volume': 1.0})
        Dialog.Show({'message': 'Scenario:Lv5BossClear'})
        FlowControl.InvokeTimeline({'filename': 'HookerDead', 'rate': 1.0})
        Audio.StopBGM({'duration': 1.0, 'label': 'BGM_DEFEAT_LOOP'})
        Event38:
        Hooker.ModelVisibility({'modelIndex': 0, 'visible': False})
        Timer.Wait({'time': 1.0})
        switch Hooker.CheckKindBoss() {
          case 0:
            Audio.PlayBGM({'label': 'BGM_FANFARE_BOSS_HEART_GET', 'volume': 1.0})
            Timer.Wait({'time': 3.0})
            Hooker.BossItemDrop()
            Timer.Wait({'time': 1.5})
            Hooker.BossRoomDoorOpen()
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
          case 1:
            Audio.PlayBGM({'label': 'BGM_PANEL_RESULT', 'volume': 1.0})

            call PanelAdventure.PanelClear()

          case 2:
            Timer.Wait({'time': 1.0})
            Hooker.BossRoomDoorOpen()
            Audio.PlayZoneBGM({'stopbgm': True})
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
        }
    } else {
        Audio.StopAllBGM({'duration': 1.0})
        FlowControl.InvokeTimeline({'filename': 'HookerDead', 'rate': 1.0})
        goto Event38
    }
}

void HookerStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch Hooker.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Audio.StopAllBGM({'duration': 1.0})
        Hud.PlayOutAnim()
        Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

        fork {
            Hooker.BossRoomDoorClose()
        } {
            Timer.Wait({'time': 0.800000011920929})
        } {
            FlowControl.PreloadTimeline({'filename': 'Hooker'})
        }

        FlowControl.InvokeTimeline({'filename': 'Hooker', 'rate': 1.0})
        Hooker.SetActorSwitch({'switchIndex': 1, 'value': True})
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case 1:
        Event46:

        call HookerSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case 2:
        Hooker.SetActorSwitch({'switchIndex': 1, 'value': False})
        goto Event46
      case 3:
        Hooker.SetActorSwitch({'switchIndex': 1, 'value': False})
        goto Event46
    }
}

void HookerSkip() {

    fork {
        Hooker.ModelVisibility({'visible': True, 'modelIndex': 6})
    } {
        Hooker.ModelVisibility({'visible': True, 'modelIndex': 7})
    } {
        Hooker.ModelVisibility({'visible': True, 'modelIndex': 8})
    } {
        Hooker.ModelVisibility({'visible': True, 'modelIndex': 9})
    } {
        Hooker.ModelVisibility({'visible': True, 'modelIndex': 10})
    } {
        Hooker.ModelVisibility({'visible': True, 'modelIndex': 11})
    } {
        Hooker.ModelVisibility({'visible': True, 'modelIndex': 12})
    } {
        Hooker.ModelVisibility({'visible': True, 'modelIndex': 13})
    }


    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

    fork {
        Hooker.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Hooker.BossRoomDoorClose()
    }


    fork {
        Hooker.PlayAnimation({'name': 'tail_wait', 'blendTime': 0.10000000149011612})
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
    Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
}
