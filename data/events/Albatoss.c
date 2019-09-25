-------- EventFlow: Albatoss --------

Actor: AlbatossPiccolo[Left]
entrypoint: None()
actions: ['Destroy']
queries: []
params: None

Actor: AlbatossPiccolo[Right]
entrypoint: None()
actions: ['Destroy']
queries: []
params: None

Actor: Albatoss
entrypoint: None()
actions: ['PlayTailorOtherChannelEx', 'BossItemDrop', 'PlayAnimationEx', 'ModelVisibility', 'BossRoomDoorOpen', 'BossRoomDoorClose', 'SetActorSwitch', 'StopTailorOtherChannel', 'PlayAnimation', 'PlayAreaOriginCameraAnimation']
queries: ['CheckSawTheFirstEvent', 'CheckSkipEndEvent', 'CheckKindBoss']
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

Actor: EventFlags
entrypoint: None()
actions: ['SetLevelFlag']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayOneshotSystemSE', 'PlayBGM', 'StopAllBGM', 'PlayBaseAmbienceSe']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['InvokeTimeline', 'PreloadTimeline']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['PlayAnimation', 'ClearPowerUp', 'SetDisablePowerUpEffect', 'AimActorLinkedPoint', 'ResetAim']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayInAnim', 'PlayOutAnim']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void AlbatossStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch Albatoss.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Hud.PlayOutAnim()

        fork {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActorLinkedPoint({'withoutTurn': True, 'pointIndex': 1, 'actor': ActorIdentifier(name="Albatoss"), 'duration': 0.4000000059604645})
        }


        fork {
            FlowControl.PreloadTimeline({'filename': 'Albatoss'})
        } {
            Audio.StopAllBGM({'duration': 1.0})
        } {
            EventFlags.SetLevelFlag({'value': True, 'index': 11})
        }


        fork {
            FlowControl.InvokeTimeline({'filename': 'Albatoss', 'rate': 1.0})
        } {
            Audio.PlayBGM({'label': 'BGM_DUNGEON_LV7_BOSS', 'volume': 1.0})
        } {
            Albatoss.BossRoomDoorClose()
        } {
            Albatoss.ModelVisibility({'modelIndex': 1, 'visible': True})
        } {
            Audio.PlayOneshotSystemSE({'label': 'SE_MAP_LV7_BOSS_DOOR_CLOSE', 'volume': 1.0, 'pitch': 1.0})
        }


        fork {
            AlbatossPiccolo[Right].Destroy()
        } {
            AlbatossPiccolo[Left].Destroy()
        }

        Hud.PlayInAnim()
        EventFlags.SetLevelFlag({'index': 61, 'value': False})
        Albatoss.SetActorSwitch({'switchIndex': 1, 'value': True})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call AlbatossSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void AlbatossEnd() {
    Link.ClearPowerUp()
    switch Albatoss.CheckKindBoss() {
      case 0:

        fork {
            Albatoss.PlayAnimation({'name': 'weak_hovering_st', 'blendTime': 0.0})
            Albatoss.PlayAnimation({'name': 'weak_hovering', 'blendTime': 0.0})
        } {
            Hud.PlayOutAnim()
        } {
            Audio.StopAllBGM({'duration': 0.5})
        }

        Timer.Wait({'time': 0.30000001192092896})
        EventFlags.SetLevelFlag({'index': 61, 'value': True})
        if !Albatoss.CheckSkipEndEvent() {
            Dialog.Show({'message': 'Scenario:Lv7BossClear'})
        }
        Albatoss.PlayAnimationEx({'name': 'dead', 'time': 0.10000000149011612, 'blendTime': 0.10000000149011612})
        Albatoss.StopTailorOtherChannel({'channel': 'Low_health', 'index': 0})
        Albatoss.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
        Albatoss.ModelVisibility({'modelIndex': 0, 'visible': False})
        Timer.Wait({'time': 1.0})
        Event44:
        switch Albatoss.CheckKindBoss() {
          case 0:
            Audio.PlayBGM({'label': 'BGM_FANFARE_BOSS_HEART_GET', 'volume': 1.0})
            Timer.Wait({'time': 3.0})
            Albatoss.BossItemDrop()
            Timer.Wait({'time': 1.5})

            fork {
                Albatoss.BossRoomDoorOpen()
            } {
                Audio.PlayOneshotSystemSE({'label': 'SE_MAP_LV7_BOSS_DOOR_OPEN', 'volume': 1.0, 'pitch': 1.0})
            }

            EventFlags.SetLevelFlag({'index': 11, 'value': False})
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
          case 1:
            Audio.PlayBGM({'label': 'BGM_PANEL_RESULT', 'volume': 1.0})

            call PanelAdventure.PanelClear()

          case 2:
            Timer.Wait({'time': 1.0})

            fork {
                Albatoss.BossRoomDoorOpen()
            } {
                Audio.PlayOneshotSystemSE({'label': 'SE_MAP_LV7_BOSS_DOOR_OPEN', 'volume': 1.0, 'pitch': 1.0})
            }

            Audio.PlayBaseAmbienceSe({'label': 'SE_AMB_LV7_BOSS_BG', 'groupLabel': 'GROUP_AMB_LV7BOSS'})
            Hud.PlayInAnim()
            GameControl.RequestAutoSave()
        }
      case [1, 2]:

        fork {
            Albatoss.PlayAnimationEx({'name': 'weak_hovering_st', 'blendTime': 0.0, 'time': 0.25})
            Albatoss.PlayAnimationEx({'name': 'dead', 'blendTime': 0.20000000298023224, 'time': 0.44999998807907104})
        } {
            Hud.PlayOutAnim()
            EventFlags.SetLevelFlag({'index': 61, 'value': True})
        } {
            Audio.StopAllBGM({'duration': 0.5})
        }

        Albatoss.StopTailorOtherChannel({'channel': 'Low_health', 'index': 0})
        Albatoss.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
        Albatoss.ModelVisibility({'modelIndex': 0, 'visible': False})
        Timer.Wait({'time': 1.0})
        goto Event44
    }
}

void AlbatossSkip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    EventFlags.SetLevelFlag({'value': True, 'index': 11})

    fork {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Link.AimActorLinkedPoint({'withoutTurn': True, 'pointIndex': 1, 'duration': 0.20000000298023224, 'actor': ActorIdentifier(name="Albatoss")})
    }


    fork {
        EventFlags.SetLevelFlag({'index': 61, 'value': False})
    } {
        Albatoss.PlayAreaOriginCameraAnimation({'name': 'demo_pop_short', 'offsetX': 2.0, 'offsetY': 10.0, 'lookAtDistanceCtrl': True, 'nearClipDistanceCtrl': True, 'farClipDistanceCtrl': True, 'chaseRatio': 0.699999988079071, 'offsetZ': 0.0, 'aspectRatioCtrl': False})
    } {
        Timer.Wait({'time': 2.0})

        fork {
            Albatoss.PlayAnimation({'name': 'demo_pop_short', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActorLinkedPoint({'withoutTurn': True, 'duration': 0.4000000059604645, 'pointIndex': 3, 'actor': ActorIdentifier(name="Albatoss")})
        }

    } {
        Timer.Wait({'time': 1.899999976158142})
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
    } {
        Albatoss.BossRoomDoorClose()
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_MAP_LV7_BOSS_DOOR_CLOSE', 'volume': 1.0, 'pitch': 1.0})
    }


    fork {
        Hud.PlayInAnim()
    } {
        Link.ResetAim()
    }

}
