-------- EventFlow: DeguZol --------

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

Actor: DeguZol
entrypoint: None()
actions: ['LookAtGimmick', 'PlayTailorOtherChannelEx', 'PlayAnimation', 'BossRoomDoorOpen', 'BossRoomDoorClose', 'ModelVisibility', 'BossItemDrop', 'SetActorSwitch', 'PlayPhase0ShadowAnim']
queries: ['CheckSawTheFirstEvent', 'CheckKindBoss']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'StopAllBGM', 'PlayBGM', 'PlayZoneBGM', 'PlayOneshotSystemSE']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'SetDisablePowerUpEffect', 'ClearPowerUp', 'MoveZoneEnterDirection']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['PreloadTimeline', 'InvokeTimeline']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: []
queries: ['CheckFlag']
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

void DeguZolStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch DeguZol.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Audio.StopAllBGM({'duration': 1.0})
        Hud.PlayOutAnim()
        Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

        fork {
            Link.AimActor({'duration': 0.800000011920929, 'actor': ActorIdentifier(name="DeguZol"), 'withoutTurn': False, 'boneName': ''})
        } {
            DeguZol.BossRoomDoorClose()
        } {
            FlowControl.PreloadTimeline({'filename': 'DeguZol'})
        }

        DeguZol.PlayPhase0ShadowAnim()
        Timer.Wait({'time': 0.5})
        Dialog.Show({'message': 'Scenario:Lv3BossSlimeEye'})
        Hud.PlayInAnim()
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call DeguZolSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void DeguZolEnd() {
    Audio.PlayOneshotSystemSE({'label': 'SE_ENE_ALL_BOSS_DAMAGE', 'volume': 1.0, 'pitch': 1.0})
    Link.ClearPowerUp()
    Hud.PlayOutAnim()
    Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS', 'duration': 0.5})
    DeguZol.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})

    fork {
        DeguZol.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    } {
        DeguZol.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
        DeguZol.ModelVisibility({'visible': False, 'modelIndex': 0})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_ENE_DEGUZOL_DEAD', 'volume': 1.0, 'pitch': 1.0})
    }

    Timer.Wait({'time': 1.0})
    switch DeguZol.CheckKindBoss() {
      case 0:
        Audio.PlayBGM({'label': 'BGM_FANFARE_BOSS_HEART_GET', 'volume': 1.0})
        Timer.Wait({'time': 3.0})
        DeguZol.BossItemDrop()
        Timer.Wait({'time': 1.5})
        DeguZol.BossRoomDoorOpen()
        Hud.PlayInAnim()
        GameControl.RequestAutoSave()
      case 1:
        Audio.PlayBGM({'label': 'BGM_PANEL_RESULT', 'volume': 1.0})

        call PanelAdventure.PanelClear()

      case 2:
        Timer.Wait({'time': 1.0})
        DeguZol.BossRoomDoorOpen()
        Audio.PlayZoneBGM({'stopbgm': True})
        Hud.PlayInAnim()
        GameControl.RequestAutoSave()
    }
}

void DeguZolSkip() {
    Audio.StopAllBGM({'duration': 1.0})
    Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})
    DeguZol.BossRoomDoorClose()
}

void DeguZolPop() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    switch DeguZol.CheckKindBoss() {
      case 0:
        if !EventFlags.CheckFlag({'symbol': 'Lv3BossDemoClear'}) {

            fork {
                FlowControl.InvokeTimeline({'filename': 'DeguZol', 'rate': 1.0})
            } {
                Timer.Wait({'time': 0.10000000149011612})
                DeguZol.ModelVisibility({'modelIndex': 0, 'visible': True})
            }

            DeguZol.SetActorSwitch({'switchIndex': 1, 'value': True})
            Hud.PlayInAnim()
            Event17:
            Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
            Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
        } else {
            Event63:
            DeguZol.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
            Link.AimActor({'duration': 0.4000000059604645, 'actor': ActorIdentifier(name="DeguZol"), 'withoutTurn': False, 'boneName': ''})

            fork {
                DeguZol.PlayAnimation({'name': 'demo_pop_short', 'blendTime': 0.10000000149011612})

                fork {
                    Timer.Wait({'time': 0.5})
                } {
                    DeguZol.PlayAnimation({'name': 'd1_wait', 'blendTime': 0.30000001192092896})
                }

            } {
                Timer.Wait({'time': 0.10000000149011612})
                DeguZol.ModelVisibility({'modelIndex': 0, 'visible': True})
            }


            fork {
                Camera.Reset({'chaseRatio': 0.10000000149011612})
            } {
                Timer.Wait({'time': 0.699999988079071})
            }

            Camera.WaitZeldaScroll()
            Hud.PlayInAnim()
            goto Event17
        }
      case [1, 2]:
        goto Event63
    }
}
