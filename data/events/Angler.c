-------- EventFlow: Angler --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Angler
entrypoint: None()
actions: ['SetActorSwitch', 'PlayTailorOtherChannelEx', 'PlayAnimation', 'BossItemDrop', 'ModelVisibility', 'StopTailorOtherChannel', 'PlayAreaOriginCameraAnimation']
queries: ['CheckSawTheFirstEvent', 'CheckKindBoss']
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'SetGravityEnable', 'ClearPowerUp', 'MoveToCompassPoint', 'SetDisablePowerUpEffect', 'SetEquipmentVisibility']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'PlayBGM', 'StopAllBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayInAnim', 'PlayOutAnim']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['PreloadTimeline', 'InvokeTimeline']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['ChangeEnvironmentNonWait']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['WaitZeldaScroll']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void AnglerStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch Angler.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Environment.ChangeEnvironmentNonWait({'name': 'Angler', 'duration': 1.5})

        fork {
            Audio.StopAllBGM({'duration': 1.0})
        } {
            Link.MoveToCompassPoint({'distance': 3.0, 'direction': 4, 'speed': 2, 'timeOut': 7.0})
        }


        fork {
            Hud.PlayOutAnim()
        } {
            Link.SetGravityEnable({'enable': False})
        }


        fork {
            Link.AimActor({'duration': 0.800000011920929, 'actor': ActorIdentifier(name="Angler"), 'withoutTurn': False, 'boneName': ''})
        } {
            FlowControl.PreloadTimeline({'filename': 'Angler'})
        }

        FlowControl.InvokeTimeline({'filename': 'Angler', 'rate': 1.0})
        Angler.SetActorSwitch({'switchIndex': 1, 'value': True})

        fork {
            Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
        } {
            Hud.PlayInAnim()
        } {
            Environment.ChangeEnvironmentNonWait({'name': 'Lv04Side3', 'duration': 0.5})
        }

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call AnglerSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void AnglerEnd() {
    Link.ClearPowerUp()
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})
    Hud.PlayOutAnim()
    Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS', 'duration': 0.0})

    fork {
        Angler.PlayAnimation({'name': 'dead_st', 'blendTime': 0.10000000149011612})
        Angler.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 1.0})
        Angler.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'index': 0, 'time': 4.0, 'restart': False})
        Angler.StopTailorOtherChannel({'index': 0, 'channel': 'Light'})
        Angler.ModelVisibility({'visible': False, 'modelIndex': 0})
    }

    Timer.Wait({'time': 1.0})
    switch Angler.CheckKindBoss() {
      case 0:
        Audio.PlayBGM({'label': 'BGM_FANFARE_BOSS_HEART_GET', 'volume': 1.0})
        Timer.Wait({'time': 3.0})
        Angler.BossItemDrop()
        Timer.Wait({'time': 1.5})
        Hud.PlayInAnim()
        GameControl.RequestAutoSave()
      case 1:
        Audio.PlayBGM({'label': 'BGM_PANEL_RESULT', 'volume': 1.0})

        call PanelAdventure.PanelClear()

      case 2:
        Timer.Wait({'time': 1.0})
        Audio.PlayZoneBGM({'stopbgm': True})
        Hud.PlayInAnim()
        GameControl.RequestAutoSave()
    }
}

void AnglerSkip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Link.MoveToCompassPoint({'distance': 3.0, 'direction': 4, 'speed': 2, 'timeOut': 7.0})
    Link.SetGravityEnable({'enable': False})
    Link.AimActor({'duration': 0.4000000059604645, 'actor': ActorIdentifier(name="Angler"), 'withoutTurn': False, 'boneName': ''})

    fork {
        Angler.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Angler.PlayAreaOriginCameraAnimation({'name': 'demo_pop2', 'lookAtDistanceCtrl': True, 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    } {
        Timer.Wait({'time': 1.2000000476837158})
    }

    Camera.WaitZeldaScroll()
    Hud.PlayInAnim()
    Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
}
