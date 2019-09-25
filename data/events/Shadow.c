-------- EventFlow: Shadow --------

Actor: Lv9Stair[Stairs]
entrypoint: None()
actions: ['PlayMaterialAnimation', 'Activate']
queries: []
params: None

Actor: ShadowDethI
entrypoint: None()
actions: ['PlayAnimation', 'LookAtGimmick', 'SetActorSwitch']
queries: ['CheckSkipEndEvent']
params: None

Actor: FlowControl
entrypoint: None()
actions: ['PreloadTimeline', 'InvokeTimeline']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: ShadowZol
entrypoint: None()
actions: ['SetActorSwitch', 'ModelVisibility']
queries: ['CheckSawTheFirstEvent']
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'PlayAnimation', 'SetDisablePowerUpEffect', 'ClearPowerUp', 'Activate', 'MoveToTargetActor', 'AimCompassPoint', 'SetCharaCollisionEnabled']
queries: ['IsInRect']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'PlayBGM', 'PlayOneshotSystemSE', 'StopBGM']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['ShowKeep', 'Show']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayInAnim', 'PlayOutAnim', 'SetOpenMenuEnable']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['ChangeEnvironmentNonWait', 'ChangeEnvironment']
queries: []
params: None

void ShadowEnd() {
    Link.ClearPowerUp()

    fork {
        ShadowDethI.PlayAnimation({'blendTime': 0.0, 'name': 'talk_st'})
        ShadowDethI.PlayAnimation({'name': 'talk', 'blendTime': 0.0})
    } {
        Hud.PlayOutAnim()
    } {
        FlowControl.PreloadTimeline({'filename': 'ShadowDead'})
    } {
        ShadowDethI.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Audio.StopAllBGM({'duration': 0.800000011920929})
    }

    if !ShadowDethI.CheckSkipEndEvent() {
        Dialog.ShowKeep({'message': 'Scenario:LastBossClear1'})
        Dialog.ShowKeep({'message': 'Scenario:LastBossClear2'})
        Dialog.Show({'message': 'Scenario:LastBossClear3'})
        Audio.StopAllBGM({'duration': 1.0})

        fork {
            FlowControl.InvokeTimeline({'filename': 'ShadowDead', 'rate': 1.0})
        } {
            Timer.Wait({'time': 4.900000095367432})
            Audio.PlayBGM({'label': 'BGM_LASTBOSS_WIN', 'volume': 1.0})
        }

        Timer.Wait({'time': 4.0})
        Environment.ChangeEnvironment({'name': 'Lv09Base', 'duration': 1.0})
        ShadowDethI.SetActorSwitch({'value': True, 'switchIndex': 0})
        EventFlags.SetFlag({'value': True, 'symbol': 'WarpProhibition'})
        Hud.PlayInAnim()
        Link.SetCharaCollisionEnabled({'enabled': False})

        fork {
            Lv9Stair[Stairs].Activate()

            fork {
                Lv9Stair[Stairs].PlayMaterialAnimation({'name': 'Lv09Stair_on'})
            } {
                Audio.PlayOneshotSystemSE({'label': 'SE_MAP_LAST_STAIRS', 'volume': 1.0, 'pitch': 1.0})
            }

        } {
            if Link.IsInRect({'minZ': 0.0, 'minX': 80.9000015258789, 'maxX': 84.0999984741211, 'maxZ': 5.5}) {
                Timer.Wait({'time': 0.20000000298023224})

                fork {
                    Link.SetCharaCollisionEnabled({'enabled': False})
                } {
                    Link.MoveToTargetActor({'speed': 1, 'distance': 1.0, 'actor': ActorIdentifier(name="Lv9Stair", sub_name="Stairs"), 'timeOut': 7.0})
                }

                Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
            }
        }

        Link.SetCharaCollisionEnabled({'enabled': True})
        Hud.SetOpenMenuEnable({'enable': False})
        Fade.StartPreset({'preset': 10})
    } else {
        Audio.StopAllBGM({'duration': 1.0})
        FlowControl.InvokeTimeline({'filename': 'ShadowDead', 'rate': 1.0})
        Timer.Wait({'time': 2.0})
        Hud.PlayInAnim()
    }
}

void ShadowStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    switch ShadowZol.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        if !EventFlags.CheckFlag({'symbol': 'ShadowBattle'}) {
            Event17:
            Audio.StopAllBGM({'duration': 1.0})
            Hud.PlayOutAnim()

            fork {
                Link.AimActor({'duration': 0.800000011920929, 'actor': ActorIdentifier(name="ShadowZol"), 'withoutTurn': False, 'boneName': ''})
            } {
                FlowControl.PreloadTimeline({'filename': 'Shadow'})
            }

            Audio.PlayBGM({'label': 'BGM_LASTBOSS_DEMO_TEXT', 'volume': 1.0})
            Dialog.ShowKeep({'message': 'Scenario:LastBossShadow1'})
            Dialog.ShowKeep({'message': 'Scenario:LastBossShadow2'})
            Dialog.ShowKeep({'message': 'Scenario:LastBossShadow3'})
            Dialog.ShowKeep({'message': 'Scenario:LastBossShadow4'})
            Dialog.Show({'message': 'Scenario:LastBossShadow5'})
            ShadowZol.ModelVisibility({'modelIndex': 0, 'visible': True})
            Audio.StopBGM({'label': 'BGM_LASTBOSS_DEMO_TEXT', 'duration': 1.0})
            Environment.ChangeEnvironmentNonWait({'duration': 1.0, 'name': 'Lv09Base3'})
            FlowControl.InvokeTimeline({'filename': 'Shadow', 'rate': 1.0})
            Link.Activate()
            EventFlags.SetFlag({'value': True, 'symbol': 'ShadowBattle'})
            ShadowZol.SetActorSwitch({'switchIndex': 1, 'value': True})

            fork {
                Hud.PlayInAnim()
            } {
                Audio.PlayBGM({'label': 'BGM_LASTBOSS_BATTLE', 'volume': 1.0})
            }

            Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
        } else {
            Event36:

            call ShadowSkip()

            Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
        }
      case [1, 3]:
        goto Event36
      case 2:
        goto Event17
    }
}

void ShadowSkip() {
    Audio.StopAllBGM({'duration': 1.0})
    Hud.PlayOutAnim()

    fork {
        Link.AimActor({'duration': 0.800000011920929, 'actor': ActorIdentifier(name="ShadowZol"), 'withoutTurn': False, 'boneName': ''})
    } {
        FlowControl.PreloadTimeline({'filename': 'Shadow'})
    }

    ShadowZol.ModelVisibility({'modelIndex': 0, 'visible': True})
    Environment.ChangeEnvironmentNonWait({'duration': 1.0, 'name': 'Lv09Base3'})
    FlowControl.InvokeTimeline({'filename': 'Shadow', 'rate': 1.0})
    Link.Activate()

    fork {
        Hud.PlayInAnim()
    } {
        Audio.PlayBGM({'label': 'BGM_LASTBOSS_BATTLE', 'volume': 1.0})
    }

}
