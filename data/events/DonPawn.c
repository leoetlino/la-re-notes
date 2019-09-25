-------- EventFlow: DonPawn --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: DonPawn
entrypoint: None()
actions: ['LookAtGimmick', 'PlayTailorOtherChannelEx', 'PlayAnimation', 'BossRoomDoorOpen', 'BossRoomDoorClose', 'SetActorSwitch', 'ModelVisibility', 'BossItemDrop']
queries: ['CheckSawTheFirstEvent', 'CheckKindBoss']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'StopAllBGM', 'PlayBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveZoneEnterDirection', 'SetDisablePowerUpEffect', 'ClearPowerUp']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['PreloadTimeline', 'InvokeTimeline']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
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

void DonPawnEnd() {
    Link.ClearPowerUp()
    Hud.PlayOutAnim()
    Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS', 'duration': 0.5})
    DonPawn.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    DonPawn.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    DonPawn.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    DonPawn.ModelVisibility({'modelIndex': 0, 'visible': False})
    switch DonPawn.CheckKindBoss() {
      case [0, 2]:
        DonPawn.BossItemDrop()
        Event5:
        Timer.Wait({'time': 2.0})
        switch DonPawn.CheckKindBoss() {
          case 0:
            Audio.PlayBGM({'label': 'BGM_FANFARE_BOSS_HEART_GET', 'volume': 1.0})
            Timer.Wait({'time': 3.0})
            DonPawn.BossRoomDoorOpen()
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
          case 1:
            Audio.PlayBGM({'label': 'BGM_PANEL_RESULT', 'volume': 1.0})

            call PanelAdventure.PanelClear()

          case 2:
            DonPawn.BossRoomDoorOpen()
            Audio.PlayZoneBGM({'stopbgm': True})
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
        }
      case 1:
        goto Event5
    }
}

void DonPawnStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch DonPawn.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Hud.PlayOutAnim()
        Audio.StopAllBGM({'duration': 1.0})
        Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

        fork {
            DonPawn.BossRoomDoorClose()
        } {
            Timer.Wait({'time': 0.800000011920929})
        } {
            FlowControl.PreloadTimeline({'filename': 'DonPawn'})
        }

        FlowControl.InvokeTimeline({'filename': 'DonPawn', 'rate': 1.0})
        DonPawn.SetActorSwitch({'switchIndex': 1, 'value': True})
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call DonPawnSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void DonPawnSkip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

    fork {
        DonPawn.BossRoomDoorClose()
    } {
        DonPawn.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    DonPawn.PlayAnimation({'name': 'demo_pop_short', 'blendTime': 0.10000000149011612})

    fork {
        Timer.Wait({'time': 0.5})
    } {
        DonPawn.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
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

void DonPawnBattle1() {

    fork {
        DonPawn.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Dialog.Show({'message': 'SubEvent:RevivalEvilOrb'})
    }

    DonPawn.PlayAnimation({'name': 'move', 'blendTime': 0.10000000149011612})
}

void DonPawnBattle2() {

    fork {
        DonPawn.PlayAnimation({'name': 'move', 'blendTime': 0.10000000149011612})
    } {
        Dialog.Show({'message': 'SubEvent:PinchEvilOrb'})
    }

}
