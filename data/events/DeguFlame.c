-------- EventFlow: DeguFlame --------

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: DeguFlame
entrypoint: None()
actions: ['SetActorSwitch', 'BossRoomDoorClose', 'LookAtGimmick', 'PlayTailorOtherChannelEx', 'BossRoomDoorOpen', 'ModelVisibility', 'BossItemDrop', 'PlayAnimationEx', 'Deactivate', 'Activate', 'PlayAnimation']
queries: ['CheckSawTheFirstEvent', 'CheckSkipEndEvent', 'CheckKindBoss']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'PlayBGM', 'StopBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'ClearPowerUp', 'SetDisablePowerUpEffect', 'MoveZoneEnterDirection']
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

void DeguFlameStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch DeguFlame.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Audio.StopAllBGM({'duration': 1.0})
        Hud.PlayOutAnim()
        Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

        fork {
            DeguFlame.BossRoomDoorClose()
        } {
            Link.AimActor({'duration': 0.800000011920929, 'actor': ActorIdentifier(name="DeguFlame"), 'withoutTurn': False, 'boneName': ''})
        } {
            FlowControl.PreloadTimeline({'filename': 'DeguFlame'})
        }

        Dialog.Show({'message': 'Scenario:Lv8BossHotHead'})
        FlowControl.InvokeTimeline({'filename': 'DeguFlame', 'rate': 1.0})
        DeguFlame.SetActorSwitch({'switchIndex': 1, 'value': True})
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call DeguFlameSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void DeguFlameEnd() {
    Link.ClearPowerUp()
    Hud.PlayOutAnim()
    switch DeguFlame.CheckKindBoss() {
      case 0:

        fork {
            DeguFlame.PlayAnimation({'blendTime': 0.0, 'name': 'dead_talk_st'})
            DeguFlame.PlayAnimation({'name': 'dead_talk_03', 'blendTime': 0.10000000149011612})
        } {
            Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS', 'duration': 0.5})
            Audio.PlayBGM({'label': 'BGM_DEFEAT_LOOP', 'volume': 1.0})
        } {
            DeguFlame.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        if !DeguFlame.CheckSkipEndEvent() {
            Dialog.Show({'message': 'Scenario:Lv8BossClear'})
        }
        DeguFlame.PlayAnimationEx({'name': 'dead_lp_03', 'time': 0.10000000149011612, 'blendTime': 0.10000000149011612})
        DeguFlame.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
        DeguFlame.ModelVisibility({'modelIndex': 0, 'visible': False})
        Audio.StopBGM({'label': 'BGM_DEFEAT_LOOP', 'duration': 0.5})
        Timer.Wait({'time': 1.0})
        Event51:
        switch DeguFlame.CheckKindBoss() {
          case 0:
            Audio.PlayBGM({'label': 'BGM_FANFARE_BOSS_HEART_GET', 'volume': 1.0})
            Timer.Wait({'time': 3.0})
            DeguFlame.BossItemDrop()
            Timer.Wait({'time': 1.5})
            DeguFlame.BossRoomDoorOpen()
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
          case 1:
            Audio.PlayBGM({'label': 'BGM_PANEL_RESULT', 'volume': 1.0})

            call PanelAdventure.PanelClear()

          case 2:
            Timer.Wait({'time': 1.0})
            DeguFlame.BossRoomDoorOpen()
            Audio.PlayZoneBGM({'stopbgm': True})
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
        }
      case [1, 2]:

        fork {
            DeguFlame.PlayAnimation({'blendTime': 0.0, 'name': 'dead_talk_st'})
            DeguFlame.PlayAnimation({'name': 'dead_talk_03', 'blendTime': 0.10000000149011612})
        } {
            Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS', 'duration': 0.5})
        } {
            DeguFlame.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        DeguFlame.PlayAnimationEx({'name': 'dead_lp_03', 'time': 0.10000000149011612, 'blendTime': 0.10000000149011612})
        DeguFlame.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
        DeguFlame.ModelVisibility({'modelIndex': 0, 'visible': False})
        Timer.Wait({'time': 1.0})
        goto Event51
    }
}

void DeguFlameSkip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

    fork {
        DeguFlame.BossRoomDoorClose()
    } {
        DeguFlame.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }


    fork {
        Link.AimActor({'actor': ActorIdentifier(name="DeguFlame"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        DeguFlame.Deactivate()
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

    fork {
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
    } {
        DeguFlame.Activate()
    }

}
