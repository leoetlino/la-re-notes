-------- EventFlow: Mamu --------

Actor: ChorusFrog[Left]
entrypoint: None()
actions: ['Activate', 'PlayAnimation', 'PlayTailorOtherChannelEx', 'StopTailorOtherChannel']
queries: []
params: None

Actor: ChorusFrog[Right]
entrypoint: None()
actions: ['Activate', 'PlayAnimation', 'PlayTailorOtherChannelEx', 'StopTailorOtherChannel']
queries: []
params: None

Actor: Mamu
entrypoint: None()
actions: ['Talk', 'SetFacialExpression', 'PlayAnimation', 'PlayTailorOtherChannelEx', 'GenericTalkSequence', 'StopTailorOtherChannel']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequence', 'SetEquipmentVisibility', 'AimActor', 'PlayAnimation', 'AddRupee', 'SetDisablePowerUpEffect', 'MoveToTargetLinkedPoint']
queries: ['CheckRupee']
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: ['HasItem']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['ShowRupee', 'PlayOutAnim', 'PlayInAnim']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['InvokeStreamSyncTimeline', 'PreloadTimeline']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['ChangeEnvironmentNonWait', 'StashSaveIntensity', 'StashPopIntensity']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 55, 'count': 1}) {
        if !Inventory.HasItem({'itemType': 17, 'count': 1}) {

            fork {
                Mamu.SetFacialExpression({'expression': 'excitenormal'})
            } {
                Mamu.GenericTalkSequence({'cameraLookAt': False, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Mamu.Talk({'message': 'Scenario:NoneOcarinaMamu'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            Mamu.SetFacialExpression({'expression': 'normal'})
        } else {
            Hud.ShowRupee({'visible': True})

            fork {
                Mamu.SetFacialExpression({'expression': 'excitenormal'})
            } {
                Mamu.PlayAnimation({'name': 'talk', 'blendTime': 0.30000001192092896})
            } {
                Mamu.Talk({'message': 'Scenario:QuestMamuSong'})
            } {
                Mamu.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': False, 'aimFromPlayer': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            if !Dialog.GetLastResult() {
                if !Link.CheckRupee({'amount': 300}) {
                    Mamu.SetFacialExpression({'expression': 'excitenormal'})
                    Mamu.PlayAnimation({'name': 'useless', 'blendTime': 0.10000000149011612})

                    fork {
                        Mamu.Talk({'message': 'Scenario:NoMoneyMamuSong'})
                    } {
                        Mamu.PlayAnimation({'name': 'wait', 'blendTime': 0.0})
                    }

                    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                    Mamu.SetFacialExpression({'expression': 'normal'})
                } else {
                    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
                    Link.AddRupee({'amount': -300})
                    Mamu.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})

                    fork {
                        ChorusFrog[Left].Activate()
                    } {
                        ChorusFrog[Right].Activate()
                    }

                    Hud.PlayOutAnim()
                    Timer.Wait({'time': 0.5})
                    FlowControl.PreloadTimeline({'filename': 'Mamu'})
                    Fade.StartPreset({'preset': 9})

                    fork {
                        Audio.StopAllBGM({'duration': 1.0})
                    } {
                        Environment.ChangeEnvironmentNonWait({'duration': 0.10000000149011612, 'name': 'MamuCaveDark'})
                        Environment.StashSaveIntensity({'duration': 0.0, 'attenuation': 0.20000000298023224})
                    } {
                        Timer.Wait({'time': 1.0})
                    } {
                        Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Mamu"), 'timeOut': 7.0})
                    } {
                        Link.AimActor({'actor': ActorIdentifier(name="Mamu"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                    }

                    Mamu.SetFacialExpression({'expression': 'excitenormal'})
                    Mamu.PlayAnimation({'name': 'cool_pose', 'blendTime': 0.0})

                    fork {
                        Fade.StartPreset({'preset': 4})
                    } {
                        Mamu.PlayTailorOtherChannelEx({'channel': 'light_mamu', 'time': 0.0, 'restart': False, 'index': 0})
                    }

                    Timer.Wait({'time': 1.5})

                    fork {
                        ChorusFrog[Left].PlayTailorOtherChannelEx({'channel': 'light_L', 'time': 0.0, 'restart': False, 'index': 0})
                    } {
                        Timer.Wait({'time': 1.0})
                    }


                    fork {
                        ChorusFrog[Right].PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'light_R', 'restart': False, 'index': 0})
                    } {
                        Timer.Wait({'time': 1.5})
                    }

                    Mamu.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                    FlowControl.InvokeStreamSyncTimeline({'filename': 'Mamu', 'label': 'BGM_OCARINA_SOUL_OF_FROG', 'volume': 1.0})
                    Mamu.PlayAnimation({'name': 'cool_pose', 'blendTime': 0.0})
                    Mamu.Talk({'message': 'Scenario:YesMamuSong'})

                    fork {
                        ChorusFrog[Left].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                    } {
                        ChorusFrog[Right].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                    } {
                        Mamu.PlayAnimation({'blendTime': 0.30000001192092896, 'name': 'wait'})
                    }


                    fork {
                        Mamu.StopTailorOtherChannel({'channel': 'light_mamu', 'index': 0})
                    } {
                        ChorusFrog[Left].StopTailorOtherChannel({'channel': 'light_L', 'index': 0})
                    } {
                        ChorusFrog[Right].StopTailorOtherChannel({'channel': 'light_R', 'index': 0})
                    }

                    Environment.StashPopIntensity({'duration': 0.5})
                    Timer.Wait({'time': 0.5})
                    Environment.ChangeEnvironmentNonWait({'name': 'MamuCave', 'duration': 1.0})
                    Link.GenericItemGetSequence({'itemType': 55, 'keepCarry': False, 'messageEntry': ''})
                    Inventory.AddItem({'itemType': 55, 'count': 1, 'autoEquip': False})

                    fork {
                        Link.AimActor({'actor': ActorIdentifier(name="Mamu"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                    } {
                        Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
                    } {
                        Camera.Reset({'chaseRatio': 0.10000000149011612})
                    }


                    fork {
                        Mamu.SetFacialExpression({'expression': 'normal'})
                    } {
                        Mamu.Talk({'message': 'Npc:MamuGetSong'})
                    } {
                        Audio.PlayZoneBGM({'stopbgm': True})
                    } {
                        Mamu.PlayAnimation({'name': 'talk', 'blendTime': 0.30000001192092896})
                    }

                    Hud.PlayInAnim()
                    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
                }
            } else {
                Mamu.SetFacialExpression({'expression': 'excitenormal'})
                Mamu.PlayAnimation({'name': 'useless', 'blendTime': 0.10000000149011612})

                fork {
                    Mamu.Talk({'message': 'Scenario:NoMamuSong'})
                } {
                    Mamu.PlayAnimation({'name': 'wait', 'blendTime': 0.0})
                }

                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                Mamu.SetFacialExpression({'expression': 'normal'})
            }
        }
    } else {

        fork {
            Mamu.SetFacialExpression({'expression': 'excitenormal'})
        } {
            Mamu.PlayAnimation({'name': 'talk', 'blendTime': 0.30000001192092896})
        } {
            Mamu.Talk({'message': 'Npc:MamuGetSong'})
        } {
            Mamu.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': False, 'aimFromPlayer': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Mamu.SetFacialExpression({'expression': 'normal'})
    }
}
