-------- EventFlow: Walrus --------

Actor: Marin[companion]
entrypoint: None()
actions: ['Talk', 'PlayAnimationEx', 'MoveToCompassPoint', 'Destroy', 'MoveToTargetLinkedPoint', 'AimActor', 'ResetAim', 'AimPlayer', 'PlayAnimation', 'SetFacialExpression', 'PlayTailorOtherChannelEx', 'StopTailorOtherChannel', 'SetTailorProperty']
queries: []
params: None

Actor: Rabbit[RabbitE]
entrypoint: None()
actions: ['Activate', 'Destroy', 'PlayAnimation', 'MoveToTargetActor', 'AimCompassPoint']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['LookAt2ActorsCenterAsTalker']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Walrus
entrypoint: None()
actions: ['PlayAnimation', 'Talk', 'SetModelVisibility', 'Destroy', 'SetFacialExpression', 'GenericTalkSequence', 'LookAtCharacter', 'ThrowShell', 'PlayTailorOtherChannelNoWait', 'AimCompassPoint', 'WarpToActor']
queries: ['CheckPlayerDirection']
params: None

Actor: Link
entrypoint: None()
actions: ['ResetAim', 'MoveToTargetLinkedPoint', 'AimActor', 'LeaveCompanion', 'SetEquipmentVisibility', 'SetFacialExpression', 'AimActorLinkedPoint', 'PlayAnimation', 'SetDisablePowerUpEffect', 'LookAtCharacter', 'GenericItemGetSequence']
queries: ['WithMarin']
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopBGM', 'PlayOneshotSystemSE', 'StopAllBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddSecretShell']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void windfish_repop() {

    fork {
        Link.SetEquipmentVisibility({'flipper': False, 'visibility': False, 'ocarina': False})
    } {
        Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
    }

    Camera.LookAt2ActorsCenterAsTalker({'weight1': 0.10000000149011612, 'weight2': 1.399999976158142, 'actor1': ActorIdentifier(name="Link"), 'actor2': ActorIdentifier(name="Walrus"), 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    if !Walrus.CheckPlayerDirection() {
        Event78:

        fork {
            Timer.Wait({'time': 0.6000000238418579})
            Link.AimActor({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': 'root', 'actor': ActorIdentifier(name="Walrus")})
        } {
            Walrus.PlayAnimation({'name': 'up', 'blendTime': 0.10000000149011612})

            fork {
                Walrus.PlayAnimation({'name': 'dance_swim', 'blendTime': 0.0})
            } {
                Walrus.Talk({'message': 'Scenario:Lv4WalrusWithMarin'})
            } {
                Audio.PlayOneshotSystemSE({'label': 'SE_ENV_WALRUS_WAVE', 'volume': 1.0, 'pitch': 1.0})
            }

        }

        if !EventFlags.CheckFlag({'symbol': 'WalrusShell'}) {

            fork {
                Walrus.PlayTailorOtherChannelNoWait({'channel': 'Give_Shell', 'restart': False, 'index': 0})
            } {
                Walrus.PlayAnimation({'name': 'down', 'blendTime': 0.20000000298023224})
                Walrus.SetModelVisibility({'visible': False})
            } {
                Timer.Wait({'time': 2.049999952316284})
                Walrus.ThrowShell({'startOffsetY': -2.0, 'endOffsetY': 1.5, 'endOffsetX': 0.0, 'endOffsetZ': 0.0, 'startOffsetX': 0.0, 'startOffsetZ': 2.5})
            } {
                Timer.Wait({'time': 0.8999999761581421})
                Link.AimActor({'duration': 0.4000000059604645, 'withoutTurn': False, 'actor': ActorIdentifier(name="Walrus"), 'boneName': 'n_hara'})
            }

            Walrus.Destroy()
            Inventory.AddSecretShell({'index': 39})
            Link.GenericItemGetSequence({'itemType': 23, 'messageEntry': 'Seashell', 'keepCarry': False})
            EventFlags.SetFlag({'symbol': 'WalrusShell', 'value': True})
            Link.SetEquipmentVisibility({'ocarina': False, 'flipper': False, 'visibility': True})
        } else {

            fork {
                Walrus.PlayAnimation({'name': 'down', 'blendTime': 0.20000000298023224})
                Walrus.Destroy()
            } {
                Timer.Wait({'time': 0.8999999761581421})
                Link.AimActor({'duration': 0.4000000059604645, 'withoutTurn': False, 'actor': ActorIdentifier(name="Walrus"), 'boneName': 'n_hara'})
            }

            Link.SetEquipmentVisibility({'ocarina': False, 'flipper': False, 'visibility': True})
        }
    } else {
        Walrus.WarpToActor({'actor': ActorIdentifier(name="Walrus"), 'distance': 1.5, 'offsetY': 0.0})
        Walrus.AimCompassPoint({'direction': 1, 'duration': 0.0, 'withoutTurn': False})
        goto Event78
    }
}

void talk() {
    if !Link.WithMarin() {

        fork {
            Walrus.GenericTalkSequence({'aimToPlayer': False, 'selfTalkAnim': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Walrus.Talk({'message': 'Scenario:Lv4WalrusNoMarin'})
        }

        EventFlags.SetFlag({'symbol': 'WalrusTalked', 'value': True})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {
        Walrus.GenericTalkSequence({'aimToPlayer': False, 'selfTalkAnim': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        Marin[companion].Talk({'message': 'Scenario:Lv4QuestWalrus'})
        if !Dialog.GetLastResult() {
            Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
            Walrus.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
            Link.LeaveCompanion()
            Audio.StopAllBGM({'duration': 1.0})

            fork {
                Link.MoveToTargetLinkedPoint({'index': 2, 'speed': 0, 'actor': ActorIdentifier(name="Walrus"), 'timeOut': 7.0})
                Link.AimActor({'actor': ActorIdentifier(name="Marin", sub_name="companion"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            } {
                Marin[companion].ResetAim()
                Marin[companion].MoveToTargetLinkedPoint({'index': 1, 'speed': 0, 'actor': ActorIdentifier(name="Walrus"), 'timeOut': 7.0})
                Marin[companion].AimActor({'actor': ActorIdentifier(name="Walrus"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            }

            Marin[companion].SetFacialExpression({'expression': 'song'})

            fork {

                fork {

                    fork {
                        Timer.Wait({'time': 2.0})
                        Timer.Wait({'time': 1.7000000476837158})
                        Walrus.SetFacialExpression({'expression': 'normal'})
                        Walrus.PlayAnimation({'name': 'wake', 'blendTime': 0.10000000149011612})

                        fork {
                            Walrus.PlayAnimation({'name': 'dance', 'blendTime': 0.10000000149011612})
                        } {
                            Timer.Wait({'time': 6.300000190734863})
                        }

                    } {
                        Timer.Wait({'time': 1.0})
                        Link.AimActor({'actor': ActorIdentifier(name="Walrus"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                    }

                    Timer.Wait({'time': 1.600000023841858})

                    fork {
                        Walrus.PlayAnimation({'name': 'dive', 'blendTime': 0.15000000596046448})
                    } {
                        Timer.Wait({'time': 2.5})

                        fork {
                            Link.AimActorLinkedPoint({'pointIndex': 3, 'withoutTurn': True, 'duration': 0.20000000298023224, 'actor': ActorIdentifier(name="Walrus")})
                            Link.AimActorLinkedPoint({'pointIndex': 3, 'actor': ActorIdentifier(name="Walrus"), 'duration': 0.4000000059604645, 'withoutTurn': False})
                        } {
                            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                        } {
                            Link.SetFacialExpression({'expression': 'vacant'})
                        }

                    }

                    Audio.PlayOneshotSystemSE({'label': 'SE_ENV_WALRUS_SPLASH', 'volume': 1.0, 'pitch': 1.0})
                } {
                    Audio.PlayBGM({'label': 'BGM_MARINE_SING_WALRUS', 'volume': 1.0})
                }

            } {
                Marin[companion].SetTailorProperty({'propertyIndex': 0, 'value': 'Event', 'index': 0})
                Marin[companion].PlayAnimation({'name': 'sing_st', 'blendTime': 0.0})

                fork {
                    Marin[companion].PlayAnimationEx({'name': 'sing_lp', 'blendTime': 0.0, 'time': 15.699999809265137})

                    fork {
                        Marin[companion].SetFacialExpression({'expression': 'smile'})
                    } {
                        Marin[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                    }

                } {
                    Marin[companion].PlayTailorOtherChannelEx({'channel': 'sing_lp_Walrus', 'time': 15.699999809265137, 'restart': False, 'index': 0})
                    Marin[companion].StopTailorOtherChannel({'channel': 'sing_lp_Walrus', 'index': 0})
                    Marin[companion].SetTailorProperty({'propertyIndex': 0, 'value': 'Normal', 'index': 0})
                }

            }

            Audio.StopBGM({'duration': 1.0, 'label': 'BGM_MARINE_SING_WALRUS'})
            Timer.Wait({'time': 2.0})
            Walrus.Destroy()
            Link.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
            Timer.Wait({'time': 0.5})
            Audio.PlayZoneBGM({'stopbgm': True})

            fork {
                Link.AimActor({'duration': 1.0, 'actor': ActorIdentifier(name="Marin", sub_name="companion"), 'withoutTurn': False, 'boneName': ''})
            } {
                Link.SetFacialExpression({'expression': 'normal'})
            } {
                Marin[companion].AimActor({'actor': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            }

            Marin[companion].Talk({'message': 'Scenario:Lv4YesQuestWalrus'})
            Rabbit[RabbitE].Activate()

            fork {
                Timer.Wait({'time': 1.0})

                fork {
                    Link.AimActor({'actor': ActorIdentifier(name="Rabbit", sub_name="RabbitE"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                } {
                    Marin[companion].AimActor({'actor': ActorIdentifier(name="Rabbit", sub_name="RabbitE"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                } {
                    Marin[companion].SetFacialExpression({'expression': 'surprise'})
                } {
                    Link.SetFacialExpression({'expression': 'normal'})
                }

            } {
                Rabbit[RabbitE].MoveToTargetActor({'distance': 2.0, 'speed': 0, 'actor': ActorIdentifier(name="Rabbit", sub_name="RabbitE"), 'timeOut': 7.0})
                Rabbit[RabbitE].PlayAnimation({'name': 'jumping', 'blendTime': 0.10000000149011612})
            }

            Marin[companion].SetFacialExpression({'expression': 'smile'})
            Marin[companion].Talk({'message': 'Scenario:Lv4ClearQuestWalrus1'})

            fork {
                Marin[companion].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            } {
                Link.AimActor({'actor': ActorIdentifier(name="Marin", sub_name="companion"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            }

            Marin[companion].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
            Marin[companion].Talk({'message': 'Scenario:Lv4ClearQuestWalrus2'})
            Marin[companion].SetFacialExpression({'expression': 'normal'})
            Marin[companion].ResetAim()

            fork {
                Rabbit[RabbitE].AimCompassPoint({'direction': 3, 'duration': 0.4000000059604645, 'withoutTurn': False})
                Rabbit[RabbitE].PlayAnimation({'name': 'walk_jumping', 'blendTime': 0.10000000149011612})
                Timer.Wait({'time': 1.5})
                Rabbit[RabbitE].Destroy()
            } {
                Marin[companion].MoveToCompassPoint({'speed': 0, 'direction': 3, 'distance': 7.0, 'timeOut': 7.0})
                Link.ResetAim()
                Marin[companion].Destroy()
            }

            EventFlags.SetFlag({'value': True, 'symbol': 'WalrusAwaked'})
            Audio.StopBGM({'label': 'BGM_MARINE_SING', 'duration': 0.5})
            Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
            GameControl.RequestAutoSave()
        } else {
            Marin[companion].Talk({'message': 'Scenario:Lv4NoQuestWalrus'})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    }
}
