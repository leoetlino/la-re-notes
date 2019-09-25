-------- EventFlow: Marin --------

Actor: Marin
entrypoint: None()
actions: ['Talk', 'PlayAnimationEx', 'TalkKeep', 'AimActor', 'MoveToLinkedPoint', 'PlayAnimation', 'LookAtCharacter', 'AimPlayer', 'Sing', 'SetFacialExpression', 'GenericTalkSequence', 'LookAtTalker', 'SetTailorProperty', 'ResetAim', 'Destroy', 'AimDegreeAngle', 'TrailTargetActorRail', 'EndPlayCraneGameEvent', 'PressCraneRightButton', 'PressCraneLeftButton', 'PressCraneBothButtons', 'SetGravityEnable']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: ['HasItem']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: ['GetLastResult']
params: None

Actor: Tarin[EventTarin]
entrypoint: None()
actions: ['Activate', 'Talk', 'TrailTargetActorRail', 'MoveToTargetActor', 'PlayAnimationEx', 'PlayAnimation', 'Destroy', 'LookAtCharacter']
queries: []
params: None

Actor: Marin[EventMarin1]
entrypoint: None()
actions: ['TalkKeep', 'Talk', 'PlayAnimation', 'SetFacialExpression', 'AimCompassPoint', 'PlayAreaOriginCameraAnimation']
queries: []
params: None

Actor: Marin[EventMarin2]
entrypoint: None()
actions: ['BeCarried', 'Join', 'CancelCarried', 'PlayAnimation', 'SetFacialExpression', 'StopTailorOtherChannel']
queries: []
params: None

Actor: Marin[companion]
entrypoint: None()
actions: ['Talk', 'SetFacialExpression', 'PlayAnimation', 'AimPlayer', 'WarpToActor', 'AimCompassPoint']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'SetEquipmentVisibility', 'PlayAnimationEx', 'WarpToActor', 'PlayAnimation', 'GenericItemGetSequence', 'MoveToTargetLinkedPoint', 'AimCompassPoint', 'SetDisablePowerUpEffect', 'ClearPowerUp', 'CancelCarry', 'ResetAim', 'LookAtItemGettingPlayer', 'AimDegreeAngle', 'SetFacialExpression']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'SetFixedCamera', 'Shake']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump', 'RequestAutoSave']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'StopAllBGM', 'PlayZoneBGM', 'PlayOneshotSystemSE', 'PlayBGM', 'PlayJingleTimeWait', 'StopSE']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['InvokeStreamSyncTimeline', 'PreloadTimeline']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

Actor: Gull[Four]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Gull[Third]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Gull[Second]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Gull[First]
entrypoint: None()
actions: ['Activate', 'PlayOneshotSE']
queries: []
params: None

Actor: Gull[Five]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Gull[Six]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Gull[Seven]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['StashPopDepthOfField', 'StashSaveDepthOfField']
queries: []
params: None

Actor: EventTriggerTag
entrypoint: None()
actions: []
queries: []
params: None

void talk() {
    if !EventFlags.CheckFlag({'symbol': 'ShieldGet'}) {

        call marin_house_talk()

    } else {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        if !EventFlags.CheckFlag({'symbol': 'FirstClear'}) {

            call marin_house_talk()

        } else
        if !EventFlags.CheckFlag({'symbol': 'SwordGet'}) {

            call marin_house_talk()

        } else
        if !EventFlags.CheckFlag({'symbol': 'MarinJoin'}) {
            if !EventFlags.CheckFlag({'symbol': 'WalrusTalked'}) {
                if !EventFlags.CheckFlag({'symbol': 'PineappleGet'}) {
                    if !Inventory.HasItem({'itemType': 17, 'count': 1}) {

                        call town_talk_1()

                    } else
                    if !Inventory.HasItem({'itemType': 53, 'count': 1}) {

                        call Okarina_talk()

                    } else {

                        call OkarinaClear_talk2()

                    }
                } else {

                    call beach_talk()

                }
            } else {

                call beach_talk()

            }
        } else
        if !Inventory.HasItem({'itemType': 53, 'count': 1}) {

            call Okarina_talk()

        } else
        if !EventFlags.CheckFlag({'symbol': 'MarinRescueClear'}) {

            call OkarinaClear_talk()

        } else {

            call town_talk2()

        }
    }
}

void marin_house_talk() {

    fork {
        Marin.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Marin.SetFacialExpression({'expression': 'worry'})
    } {
        Marin.Talk({'message': 'Npc:MarinAfterOpening'})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_NPC_MARIN_003', 'volume': 1.0, 'pitch': 1.0})
    }

    Marin.SetFacialExpression({'expression': 'normal'})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void town_talk_1() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Audio.StopBGM({'label': 'BGM_MARINE_SING', 'duration': 0.5})

    fork {
        Link.AimActor({'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Marin.AimActor({'actor': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Marin.SetFacialExpression({'expression': 'smile'})
    }

    if !EventFlags.CheckFlag({'symbol': 'TailCaveShutterOpened'}) {

        fork {
            Marin.GenericTalkSequence({'selfTalkAnim': True, 'aimFromPlayer': False, 'playerTalkAnim': False, 'cameraLookAt': True, 'aimToPlayer': False, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Marin.Talk({'message': 'SubEvent:MarinSing1'})
        }

        Event161:

        fork {
            Marin.PlayAnimation({'name': 'sing_st', 'blendTime': 0.10000000149011612})
            Marin.PlayAnimationEx({'name': 'sing_lp', 'blendTime': 0.0, 'time': 0.0})
        } {
            Marin.Sing()
        } {
            Marin.SetFacialExpression({'expression': 'song'})
        }

        Timer.Wait({'time': 0.5})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Link.SetDisablePowerUpEffect({'sound': False, 'effect': False, 'materialAnim': False})
    } else
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {

        fork {
            Marin.GenericTalkSequence({'selfTalkAnim': True, 'playerTalkAnim': False, 'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            Marin.Talk({'message': 'SubEvent:MarinSing2'})
        }

    } else {

        fork {
            Marin.Talk({'message': 'Npc:MarinGetSong'})
        } {
            Marin.GenericTalkSequence({'selfTalkAnim': True, 'playerTalkAnim': False, 'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'cameraLookAt': True, 'distanceOffset': 0.0})
        }

    }
    goto Event161
}

void beach_talk() {
    Link.ClearPowerUp()

    fork {
        Marin.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Marin.TalkKeep({'message': 'Scenario:Lv4QuestMarinBeach1'})
    }

    Marin.SetFacialExpression({'expression': 'smile'})
    Marin.Talk({'message': 'Scenario:Lv4QuestMarinBeach2'})
    if !Dialog.GetLastResult() {
        Marin.SetFacialExpression({'expression': 'normal'})

        fork {
            Fade.StartPreset({'preset': 11})
        } {
            Audio.StopAllBGM({'duration': 2.0})
        }

        GameControl.RequestLevelJump({'level': 'EventMarin01', 'locator': 'EventMarin01', 'offsetX': 0.0, 'offsetZ': 0.0})
    } else {

        fork {
            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
        } {
            Marin.SetFacialExpression({'expression': 'depress'})
        }

        Marin.Talk({'message': 'Scenario:Lv4NoMarinBeach'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Marin.SetFacialExpression({'expression': 'normal'})
    }
}

void Okarina_talk() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Audio.StopBGM({'label': 'BGM_MARINE_SING', 'duration': 0.5})
    if !Inventory.HasItem({'itemType': 17, 'count': 1}) {
        if !EventFlags.CheckFlag({'symbol': 'WalrusAwaked'}) {

            call town_talk_1()

        } else {

            fork {
                Marin.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Marin.SetFacialExpression({'expression': 'smile'})
            } {
                Marin.Talk({'message': 'Npc:MarineAnimalVillage'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            Marin.SetFacialExpression({'expression': 'normal'})
        }
    } else {
        Audio.StopAllBGM({'duration': 0.0})
        Fade.StartPreset({'preset': 11})
        Marin.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': False, 'selfTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': False, 'cameraLookAt': False, 'distanceOffset': 0.0})
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
        Link.PlayAnimationEx({'time': 0.0, 'blendTime': 0.0, 'name': 'idle_bare'})
        Marin.AimDegreeAngle({'duration': 0.10000000149011612, 'angle': 60.0, 'withoutTurn': False})

        fork {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': True, 'flipper': False})
        } {
            Link.WarpToActor({'distance': 1.5, 'actor': ActorIdentifier(name="Marin"), 'offsetY': 0.0})
        }

        Marin.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})

        fork {
            Marin.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': False, 'selfTalkAnim': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
        } {
            Hud.PlayOutAnim()
        } {
            Link.SetFacialExpression({'expression': 'dream'})
        }

        Fade.StartPreset({'preset': 10})
        Link.PlayAnimation({'name': 'ev_TakeOkarina_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_TakeOkarina_lp', 'blendTime': 0.10000000149011612})
        FlowControl.PreloadTimeline({'filename': 'WindFishSong'})

        fork {
            Marin.Talk({'message': 'Scenario:StudyMarinSong'})
        } {
            Marin.SetFacialExpression({'expression': 'smile'})
        }

        Marin.SetTailorProperty({'propertyIndex': 0, 'value': 'Event', 'index': 0})
        Event24:
        FlowControl.InvokeStreamSyncTimeline({'label': 'BGM_OCARINA_FISH_OF_WIND', 'filename': 'WindFishSong', 'volume': 1.0})
        Link.PlayAnimation({'name': 'ev_TakeOkarina_lp', 'blendTime': 0.10000000149011612})
        Timer.Wait({'time': 1.399999976158142})

        fork {
            Marin.SetFacialExpression({'expression': 'smile'})
        } {
            Timer.Wait({'time': 0.30000001192092896})
        } {
            Marin.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }

        Link.AimActor({'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

        fork {
            Marin.Talk({'message': 'Scenario:QuestMarinSong'})
        } {
            Marin.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
        }

        Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        if !Dialog.GetLastResult() {
            Marin.SetFacialExpression({'expression': 'normal'})
            EventFlags.SetFlag({'value': True, 'symbol': 'MarinsongGet'})
            Inventory.AddItem({'itemType': 53, 'count': 1, 'autoEquip': False})

            fork {
                Link.GenericItemGetSequence({'keepCarry': False, 'itemType': 53, 'messageEntry': ''})
            } {
                Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
            } {
                Link.SetFacialExpression({'expression': 'get'})
            }

            Link.SetFacialExpression({'expression': 'normal'})
            Marin.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
            Link.AimActor({'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})

            fork {
                if !EventFlags.CheckFlag({'symbol': 'WalrusAwaked'}) {
                    Marin.Talk({'message': 'Scenario:YesMarinSong'})
                } else {
                    Marin.TalkKeep({'message': 'Npc:MarinGetSongAnimalVillage1'})
                    Marin.Talk({'message': 'Npc:MarinGetSongAnimalVillage2'})
                }
            } {
                Marin.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
                Marin.PlayAnimation({'name': 'talk2', 'blendTime': 0.10000000149011612})
            } {
                Marin.SetFacialExpression({'expression': 'smile'})
                Marin.SetFacialExpression({'expression': 'depress'})
            }


            fork {
                Marin.SetFacialExpression({'expression': 'smile'})
            } {
                Timer.Wait({'time': 1.0})
            } {
                Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.20000000298023224})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            if !EventFlags.CheckFlag({'symbol': 'WalrusAwaked'}) {

                fork {
                    Marin.SetFacialExpression({'expression': 'normal'})
                } {
                    Audio.PlayZoneBGM({'stopbgm': True})
                } {
                    Marin.SetTailorProperty({'propertyIndex': 0, 'value': 'Normal', 'index': 0})
                } {
                    Hud.PlayInAnim()
                }

                Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
            } else
            if !Inventory.HasItem({'itemType': 52, 'count': 1}) {

                fork {
                    Audio.PlayZoneBGM({'stopbgm': True})
                } {
                    Marin.SetTailorProperty({'propertyIndex': 0, 'value': 'Normal', 'index': 0})
                } {
                    Hud.PlayInAnim()
                } {
                    Marin.PlayAnimation({'name': 'sing_st', 'blendTime': 0.10000000149011612})
                    Marin.PlayAnimation({'name': 'sing_lp', 'blendTime': 0.0})
                } {
                    Marin.SetFacialExpression({'expression': 'song'})
                }

                Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
            } else {

                fork {
                    Marin.SetFacialExpression({'expression': 'normal'})
                } {
                    Audio.PlayZoneBGM({'stopbgm': True})
                } {
                    Marin.SetTailorProperty({'propertyIndex': 0, 'value': 'Normal', 'index': 0})
                } {
                    Hud.PlayInAnim()
                }

                Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
            }
        } else {
            Link.PlayAnimation({'name': 'ev_no', 'blendTime': 0.10000000149011612})
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            Timer.Wait({'time': 0.5})
            Marin.SetFacialExpression({'expression': 'discontent'})
            Marin.Talk({'message': 'Scenario:NoMarinSong'})
            Marin.SetFacialExpression({'expression': 'normal'})
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': True, 'flipper': False})
            goto Event24
        }
    }
}

void town_talk2() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'Town2talkClear'}) {
        EventFlags.SetFlag({'symbol': 'Town2talkClear', 'value': True})

        fork {
            Marin.SetFacialExpression({'expression': 'smile'})
        } {
            Marin.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Marin.Talk({'message': 'SubEvent:MarinAfterBridge'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Marin.SetFacialExpression({'expression': 'normal'})
    } else {

        fork {
            Marin.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Marin.SetFacialExpression({'expression': 'worry'})
        } {
            Marin.Talk({'message': 'SubEvent:MarinAfterBridge2'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Marin.SetFacialExpression({'expression': 'normal'})
    }
}

void MarinRescue() {
    Link.CancelCarry()
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.StopAllBGM({'duration': 1.5})
    Marin.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})

    fork {
        Marin.SetFacialExpression({'expression': 'worry'})
        Marin.Talk({'message': 'Scenario:Lv8MarinHappening1'})
    } {
        Marin.PlayAnimation({'name': 'tremble', 'blendTime': 0.10000000149011612})
    }

    Timer.Wait({'time': 2.0})
    Marin.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    Camera.Reset({'chaseRatio': 0.10000000149011612})
    Marin.SetFacialExpression({'expression': 'surprise'})
    Marin.Talk({'message': 'Scenario:Lv8MarinHappening2'})
    Marin.PlayAnimation({'name': 'depress_st', 'blendTime': 0.10000000149011612})

    fork {
        Marin.SetFacialExpression({'expression': 'worry'})
        Marin.TalkKeep({'message': 'Scenario:Lv8MarinHappening3'})
    } {
        Marin.PlayAnimation({'name': 'depress_lp', 'blendTime': 0.10000000149011612})
    }

    Marin.Talk({'message': 'Scenario:Lv8MarinHappening4'})
    EventFlags.SetFlag({'symbol': 'MarineRescue', 'value': True})
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void MarinRescueClear() {
    Link.ClearPowerUp()

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
    }


    fork {
        Marin.SetFacialExpression({'expression': 'surprise'})
        Marin.TalkKeep({'message': 'Scenario:Lv8MarinRescue1'})
    } {
        Marin.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    Marin.SetFacialExpression({'expression': 'smile'})
    Marin.Talk({'message': 'Scenario:Lv8MarinRescue2'})
    Marin.SetFacialExpression({'expression': 'worry'})
    Marin.PlayAnimation({'name': 'depress_st', 'blendTime': 0.10000000149011612})

    fork {
        Marin.TalkKeep({'message': 'Scenario:Lv8MarinRescue3'})
    } {
        Marin.PlayAnimation({'name': 'depress_lp', 'blendTime': 0.10000000149011612})
    }

    Marin.Talk({'message': 'Scenario:Lv8MarinRescue4'})
    Tarin[EventTarin].Activate()

    fork {
        Tarin[EventTarin].MoveToTargetActor({'distance': 4.0, 'speed': 0, 'actor': ActorIdentifier(name="Tarin", sub_name="EventTarin"), 'timeOut': 7.0})
    } {
        Tarin[EventTarin].PlayAnimation({'name': 'walk', 'blendTime': 0.10000000149011612})
    }


    fork {
        Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Tarin[EventTarin].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

    Tarin[EventTarin].LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    Timer.Wait({'time': 0.699999988079071})

    fork {
        Tarin[EventTarin].Talk({'message': 'Scenario:Lv8MarinRescue5'})
    } {
        Marin.AimActor({'actor': ActorIdentifier(name="Tarin", sub_name="EventTarin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Tarin", sub_name="EventTarin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    Tarin[EventTarin].PlayAnimationEx({'name': 'yobu', 'time': 3.0, 'blendTime': 0.10000000149011612})
    Camera.Reset({'chaseRatio': 0.10000000149011612})
    Marin.SetFacialExpression({'expression': 'surprise'})
    Marin.Talk({'message': 'Scenario:Lv8MarinRescue6'})
    Marin.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    Marin.SetFacialExpression({'expression': 'worry'})
    Marin.PlayAnimation({'name': 'depress_st', 'blendTime': 0.10000000149011612})

    fork {
        Marin.Talk({'message': 'Scenario:Lv8MarinRescue7'})
    } {
        Marin.PlayAnimation({'name': 'depress_lp', 'blendTime': 0.10000000149011612})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Marin.PlayAnimation({'name': 'depress_ed', 'blendTime': 0.10000000149011612})
    } {
        Link.AimActor({'withoutTurn': True, 'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'boneName': ''})
    }


    fork {

        fork {
            Marin.MoveToLinkedPoint({'speed': 0, 'index': 1, 'timeOut': 7.0})
            Marin.MoveToLinkedPoint({'speed': 0, 'index': 2, 'timeOut': 7.0})
        } {
            Marin.ResetAim()
        } {
            Link.MoveToTargetLinkedPoint({'speed': 0, 'actor': ActorIdentifier(name="Marin"), 'index': 0, 'timeOut': 7.0})
            Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
        }


        fork {
            Marin.AimPlayer({'withoutTurn': True, 'duration': 0.4000000059604645, 'boneName': ''})
        } {
            Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActor({'withoutTurn': True, 'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'boneName': ''})
        }

        Timer.Wait({'time': 2.0})
        Marin.ResetAim()
        Marin.MoveToLinkedPoint({'speed': 0, 'index': 3, 'timeOut': 7.0})
        Marin.MoveToLinkedPoint({'speed': 0, 'index': 4, 'timeOut': 7.0})

        fork {
            Marin.MoveToLinkedPoint({'speed': 0, 'index': 5, 'timeOut': 7.0})
        } {
            Timer.Wait({'time': 0.05000000074505806})
            Marin.PlayAnimation({'name': 'jump', 'blendTime': 0.10000000149011612})
            Timer.Wait({'time': 0.30000001192092896})
            Marin.PlayAnimation({'name': 'land', 'blendTime': 0.10000000149011612})
        }


        fork {
            Marin.TrailTargetActorRail({'speed': 0, 'railIndex': 6, 'actor': ActorIdentifier(name="Marin"), 'timeOut': 7.0})
        } {
            Marin.PlayAnimation({'name': 'walk', 'blendTime': 0.10000000149011612})
        }

        Marin.SetFacialExpression({'expression': 'normal'})
        Marin.Destroy()
    } {
        Tarin[EventTarin].TrailTargetActorRail({'railIndex': 0, 'speed': 0, 'actor': ActorIdentifier(name="Tarin", sub_name="EventTarin"), 'timeOut': 7.0})
        Tarin[EventTarin].Destroy()
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'MarinRescueClear'})

    fork {
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Link.ResetAim()
    }

}

void cocco_talk1() {

    fork {
        Marin.AimPlayer({'duration': 0.10000000149011612, 'withoutTurn': False, 'boneName': ''})
    } {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Marin.PlayAnimation({'name': 'scold_st', 'blendTime': 0.10000000149011612})
        Marin.PlayAnimation({'name': 'scold_lp', 'blendTime': 0.0})
    } {
        Marin.SetFacialExpression({'expression': 'discontent'})
    } {
        Marin.Talk({'message': 'SubEvent:MarinaAttackCocco1'})
    }

    Marin.SetFacialExpression({'expression': 'normal'})
}

void cocco_talk2() {

    fork {
        Marin.AimPlayer({'duration': 0.10000000149011612, 'withoutTurn': False, 'boneName': ''})
    } {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Marin.PlayAnimation({'name': 'exciting', 'blendTime': 0.10000000149011612})
    } {
        Marin.SetFacialExpression({'expression': 'excite'})
    } {
        Marin.Talk({'message': 'SubEvent:MarinAttackCocco2'})
    }


    fork {
        Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Marin.SetFacialExpression({'expression': 'normal'})
    }

}

void Pot_talk1() {

    fork {
        Marin.AimPlayer({'duration': 0.10000000149011612, 'withoutTurn': False, 'boneName': ''})
    } {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Marin.PlayAnimation({'name': 'scold_st', 'blendTime': 0.10000000149011612})
        Marin.PlayAnimation({'name': 'scold_lp', 'blendTime': 0.0})
    } {
        Marin.SetFacialExpression({'expression': 'discontent'})
    } {
        Marin.Talk({'message': 'SubEvent:MarinBreakPot1'})
    }

    Marin.SetFacialExpression({'expression': 'normal'})
}

void Pot_talk2() {

    fork {
        Marin.AimPlayer({'duration': 0.10000000149011612, 'withoutTurn': False, 'boneName': ''})
    } {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Marin.PlayAnimation({'name': 'exciting', 'blendTime': 0.10000000149011612})
    } {
        Marin.SetFacialExpression({'expression': 'excite'})
    } {
        Marin.Talk({'message': 'SubEvent:MarinBreakPot2'})
    }


    fork {
        Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Marin.SetFacialExpression({'expression': 'normal'})
    }

}

void Performance_talk() {
    Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    Marin.SetFacialExpression({'expression': 'discontent'})
    Marin.TalkKeep({'message': 'SubEvent:MarinOcarinaHetakuso'})
    Marin.SetFacialExpression({'expression': 'smile'})
    Marin.Talk({'message': 'SubEvent:MarinOcarinaHetakuso2'})
    Marin.SetFacialExpression({'expression': 'normal'})
}

void Dig_talk() {
    Marin.Talk({'message': 'SubEvent:MarinDigHole'})
}

void OkarinaClear_talk() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Audio.StopBGM({'label': 'BGM_MARINE_SING', 'duration': 1.0})
    if !Inventory.HasItem({'count': 1, 'itemType': 49}) {
        Event175:

        fork {
            Link.AimActor({'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin.AimActor({'actor': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin.SetFacialExpression({'expression': 'smile'})
        }


        fork {
            Marin.GenericTalkSequence({'selfTalkAnim': True, 'playerTalkAnim': False, 'aimFromPlayer': False, 'cameraLookAt': True, 'aimToPlayer': False, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Marin.TalkKeep({'message': 'Npc:MarinGetSongAnimalVillage1'})
        } {
            Marin.SetFacialExpression({'expression': 'depress'})
        }

        Marin.Talk({'message': 'Npc:MarinGetSongAnimalVillage2'})
        Marin.SetFacialExpression({'expression': 'normal'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        if !Inventory.HasItem({'itemType': 52, 'count': 1}) {

            fork {
                Marin.SetFacialExpression({'expression': 'song'})
            } {
                Marin.PlayAnimation({'name': 'sing_st', 'blendTime': 0.10000000149011612})
                Marin.PlayAnimation({'name': 'sing_lp', 'blendTime': 0.0})
            }

        }
        Event332:
        Link.SetDisablePowerUpEffect({'effect': False, 'sound': False, 'materialAnim': False})
    } else
    if !Inventory.HasItem({'itemType': 52, 'count': 1}) {
        goto Event175
    } else {

        fork {
            Link.AimActor({'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin.AimActor({'actor': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin.SetFacialExpression({'expression': 'depress'})
        }


        fork {
            Marin.GenericTalkSequence({'selfTalkAnim': True, 'playerTalkAnim': False, 'aimFromPlayer': False, 'cameraLookAt': True, 'aimToPlayer': False, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Marin.Talk({'message': 'Npc:MarinReturnAnimalVillage'})
        } {
            Marin.SetFacialExpression({'expression': 'normal'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Marin.SetFacialExpression({'expression': 'normal'})
        goto Event332
    }
}

void MarinPlayCrane() {

    fork {
        Audio.PlayOneshotSystemSE({'label': 'SE_MAP_CRANE_START', 'volume': 1.0, 'pitch': 1.0})
    } {
        Marin.ResetAim()
    }


    fork {
        Marin.PressCraneRightButton()
        Timer.Wait({'time': 1.600000023841858})
        Marin.PressCraneBothButtons()
        Timer.Wait({'time': 0.8999999761581421})
        Marin.PressCraneRightButton()
        Timer.Wait({'time': 0.6000000238418579})
        Marin.PressCraneLeftButton()
        Timer.Wait({'time': 1.0})
        Marin.PressCraneBothButtons()
    } {
        Timer.Wait({'time': 1.7999999523162842})
        Link.AimDegreeAngle({'withoutTurn': False, 'angle': -180.0, 'duration': 0.4000000059604645})
        Timer.Wait({'time': 1.2000000476837158})
        Link.AimDegreeAngle({'withoutTurn': False, 'angle': -225.0, 'duration': 0.4000000059604645})
        Timer.Wait({'time': 1.5})
        Link.AimDegreeAngle({'withoutTurn': False, 'angle': -270.0, 'duration': 0.4000000059604645})
    } {
        Timer.Wait({'time': 5.5})
    }

    Marin.EndPlayCraneGameEvent()

    fork {
        Timer.Wait({'time': 10.0})
        Link.AimDegreeAngle({'withoutTurn': False, 'angle': -225.0, 'duration': 0.4000000059604645})
        Timer.Wait({'time': 1.5})
        Link.AimDegreeAngle({'withoutTurn': False, 'angle': -180.0, 'duration': 0.4000000059604645})
        Timer.Wait({'time': 2.0})
        Link.AimDegreeAngle({'withoutTurn': False, 'angle': -135.0, 'duration': 0.4000000059604645})
        Timer.Wait({'time': 3.5})
        Link.AimDegreeAngle({'withoutTurn': False, 'angle': -90.0, 'duration': 0.4000000059604645})
    } {
        Timer.Wait({'time': 19.5})
    } {
        Link.SetFacialExpression({'expression': 'wakeup'})
    }

}

void BeachDate() {
    Link.ClearPowerUp()
    Audio.StopAllBGM({'duration': 1.0})

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Audio.PlayBGM({'label': 'BGM_EVENT_DATE', 'volume': 1.0})
    } {
        Marin.SetGravityEnable({'enable': False})
        Marin[EventMarin1].PlayAnimation({'name': 'sit', 'blendTime': 0.10000000149011612})
        Marin[EventMarin1].AimCompassPoint({'direction': 0, 'withoutTurn': True, 'duration': 0.4000000059604645})
    } {
        Link.PlayAnimation({'name': 'ev_sitlog_lp', 'blendTime': 0.10000000149011612})
    } {
        Hud.PlayOutAnim()
    }


    fork {
        Fade.StartPreset({'preset': 6})
    } {
        Marin[EventMarin1].PlayAreaOriginCameraAnimation({'name': 'MarineBeachDemo', 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    } {
        Gull[First].Activate()
    } {
        Gull[Second].Activate()
    } {
        Gull[Third].Activate()
    } {
        Gull[Four].Activate()
    } {
        Gull[Five].Activate()
    } {
        Gull[Six].Activate()
    } {
        Gull[Seven].Activate()
    } {
        Gull[First].PlayOneshotSE({'label': 'SE_ENV_SEAGULL1', 'volume': 1.0, 'pitch': 1.0})
    }

    Timer.Wait({'time': 2.0})
    Event490:
    Marin[EventMarin1].PlayAnimation({'name': 'coconutlock_st', 'blendTime': 0.10000000149011612})

    fork {
        Marin[EventMarin1].TalkKeep({'message': 'Scenario:Lv4MarinBeach1'})
        Marin[EventMarin1].Talk({'message': 'Scenario:Lv4MarinBeach2'})
    } {
        Marin[EventMarin1].PlayAnimation({'name': 'coconutlock_lp', 'blendTime': 0.10000000149011612})
    }

    Marin[EventMarin1].PlayAnimation({'name': 'coconutlock_ed', 'blendTime': 0.10000000149011612})

    fork {
        Marin[EventMarin1].PlayAnimation({'name': 'sit_talk', 'blendTime': 0.800000011920929})
    } {
        Marin[EventMarin1].Talk({'message': 'Scenario:Lv4MarinBeachPalm'})
    }


    fork {
        Marin[EventMarin1].SetFacialExpression({'expression': 'normal'})
    } {
        Marin[EventMarin1].PlayAnimation({'name': 'sit', 'blendTime': 0.10000000149011612})
    }

    Timer.Wait({'time': 2.0})
    Marin[EventMarin1].Talk({'message': 'Scenario:Lv4MarinBeach3'})
    Timer.Wait({'time': 2.0})

    fork {
        Marin[EventMarin1].PlayAnimation({'name': 'sit_talk', 'blendTime': 0.800000011920929})
    } {
        Marin[EventMarin1].Talk({'message': 'Scenario:Lv4MarinBeach4'})
    }


    fork {
        Marin[EventMarin1].PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'sit'})
    } {
        Timer.Wait({'time': 0.5})
    }


    fork {
        Marin[EventMarin1].SetFacialExpression({'expression': 'depress'})
    } {
        Marin[EventMarin1].PlayAnimation({'name': 'turn_face_st', 'blendTime': 0.10000000149011612})
    }

    Marin[EventMarin1].PlayAnimation({'name': 'turn_face_lp', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 2.0})
    Marin[EventMarin1].PlayAnimation({'name': 'turn_face_ed', 'blendTime': 0.10000000149011612})
    Marin[EventMarin1].PlayAnimation({'name': 'sit', 'blendTime': 0.10000000149011612})
    Marin[EventMarin1].Talk({'message': 'Scenario:Lv4MarinBeach5'})
    Timer.Wait({'time': 2.0})

    fork {
        Marin[EventMarin1].PlayAnimation({'name': 'sit_talk', 'blendTime': 0.800000011920929})
    } {
        Marin[EventMarin1].TalkKeep({'message': 'Scenario:Lv4MarinBeach6'})
        Marin[EventMarin1].Talk({'message': 'Scenario:Lv4MarinBeach7'})
    }


    fork {
        Marin[EventMarin1].PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'sit'})
    } {
        Timer.Wait({'time': 0.5})
    }

    Marin[EventMarin1].PlayAnimation({'name': 'turn_face_st', 'blendTime': 0.10000000149011612})
    Marin[EventMarin1].PlayAnimation({'name': 'turn_face_lp', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 2.0})
    Marin[EventMarin1].PlayAnimation({'name': 'turn_face_ed', 'blendTime': 0.10000000149011612})
    Marin[EventMarin1].PlayAnimation({'name': 'sit', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 3.0})
    Marin[EventMarin1].PlayAnimation({'name': 'turn_face_st', 'blendTime': 0.10000000149011612})

    fork {
        Marin[EventMarin1].SetFacialExpression({'expression': 'worry'})
        Marin[EventMarin1].Talk({'message': 'Scenario:Lv4MarinBeach8'})
    } {
        Marin[EventMarin1].PlayAnimation({'name': 'turn_face_lp', 'blendTime': 0.10000000149011612})
    }

    if !Dialog.GetLastResult() {
        Link.PlayAnimation({'name': 'ev_sitlog_face_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_sitlog_face_lp', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_sitlog_yes', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_sitlog_face_ed', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_sitlog_lp', 'blendTime': 0.10000000149011612})

        fork {
            Marin.SetFacialExpression({'expression': 'depress'})
        } {
            Marin[EventMarin1].PlayAnimation({'name': 'turn_face_ed', 'blendTime': 0.10000000149011612})
        }


        fork {
            Marin[EventMarin1].Talk({'message': 'Scenario:Lv4YesMarinBeach1'})
        } {
            Marin[EventMarin1].PlayAnimation({'name': 'sit_talk', 'blendTime': 0.10000000149011612})
        }

        Timer.Wait({'time': 1.0})

        fork {
            Marin[EventMarin1].Talk({'message': 'Scenario:Lv4YesMarinBeach2'})
        } {
            Marin[EventMarin1].SetFacialExpression({'expression': 'smile'})
        }

        Marin[EventMarin1].PlayAnimation({'name': 'sit', 'blendTime': 0.10000000149011612})
        Timer.Wait({'time': 3.0})
        Marin[EventMarin1].PlayAnimation({'name': 'turn_face_st', 'blendTime': 0.10000000149011612})

        fork {
            Marin[EventMarin1].Talk({'message': 'Scenario:Lv4MarinBeach11'})
        } {
            Marin[EventMarin1].PlayAnimation({'name': 'turn_face_lp', 'blendTime': 0.10000000149011612})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        } {
            Fade.StartPreset({'preset': 11})
        } {
            Audio.StopBGM({'label': 'BGM_EVENT_DATE', 'duration': 2.0})
        }

        Environment.StashPopDepthOfField({'duration': 0.5})
        Hud.PlayInAnim()
        GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_16F', 'offsetX': 0.0, 'offsetZ': 0.0})
    } else {
        Link.PlayAnimation({'name': 'ev_sitlog_face_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_sitlog_face_lp', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_sitlog_no', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_sitlog_face_ed', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_sitlog_lp', 'blendTime': 0.10000000149011612})

        fork {
            Marin.SetFacialExpression({'expression': 'depress'})
        } {
            Marin[EventMarin1].PlayAnimation({'name': 'turn_face_ed', 'blendTime': 0.10000000149011612})
        }


        fork {
            Marin[EventMarin1].Talk({'message': 'Scenario:Lv4NoMarinBeach4'})
        } {
            Marin[EventMarin1].PlayAnimation({'name': 'sit_talk', 'blendTime': 0.10000000149011612})
        }

        Marin[EventMarin1].SetFacialExpression({'expression': 'normal'})
        goto Event490
    }
}

void MarinGet() {
    Link.ClearPowerUp()
    Environment.StashSaveDepthOfField({'duration': 0.5})
    Link.PlayAnimationEx({'name': 'item_get_lp', 'time': 0.0, 'blendTime': 0.0})
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Marin[EventMarin2].BeCarried()
    Marin[EventMarin2].PlayAnimation({'blendTime': 0.0, 'name': 'marin_get'})
    Marin[EventMarin2].SetFacialExpression({'expression': 'normal'})
    Fade.StartPreset({'preset': 10})
    Link.LookAtItemGettingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})

    fork {
        Audio.PlayJingleTimeWait({'label': 'BGM_FANFARE_BIGITEM_GET', 'duration': 4.199999809265137, 'volume': 1.0})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_PL_ITEM_GET_LIGHT', 'volume': 1.0, 'pitch': 1.0})
    } {
        Dialog.Show({'message': 'Scenario:Lv4GetMarin'})
    }

    EventFlags.SetFlag({'symbol': 'MarinJoin', 'value': True})
    Marin[EventMarin2].StopTailorOtherChannel({'channel': 'Marin_get', 'index': 0})
    Marin[EventMarin2].CancelCarried()
    Marin[EventMarin2].PlayAnimation({'name': 'marin_get_ed', 'blendTime': 0.10000000149011612})
    Marin[EventMarin2].Join()
    Marin[EventMarin2].SetFacialExpression({'expression': 'normal'})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    Audio.PlayBGM({'label': 'BGM_FIELD_MARINE', 'volume': 1.0})
    GameControl.RequestAutoSave()
}

void CapeDate() {
    Link.ClearPowerUp()

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    } {
        Audio.StopAllBGM({'duration': 1.5})
    }

    Marin[companion].WarpToActor({'distance': 1.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
    Marin[companion].AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})

    fork {
        Marin[companion].PlayAnimation({'name': 'fluttering_wait', 'blendTime': 0.10000000149011612})
    } {
        Link.PlayAnimation({'name': 'fluttering_wait', 'blendTime': 0.10000000149011612})
    }

    Hud.PlayOutAnim()

    fork {
        Camera.SetFixedCamera({'posX': 16.009000778198242, 'posY': 5.890999794006348, 'posZ': 195.87899780273438, 'rotX': 3.571000099182129, 'rotY': 70.79199981689453, 'rotZ': 0.0, 'distanceToLookAt': 10.0, 'fieldOfViewY': 28.086000442504883, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    } {
        Fade.StartPreset({'preset': 2})
    } {
        Audio.PlayBGM({'label': 'BGM_EVENT_DATE', 'volume': 1.0})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_ENV_MISAKI_NEAR_WAVE', 'volume': 1.0, 'pitch': 1.0})
    }

    Timer.Wait({'time': 2.5})
    Marin[companion].Talk({'message': 'SubEvent:MarinCapeDate1'})

    fork {
        Marin[companion].Talk({'message': 'SubEvent:MarinCapeDate2'})
    } {
        Timer.Wait({'time': 3.0})
    } {
        Marin[companion].SetFacialExpression({'expression': 'normal_close'})
    }

    Marin[companion].PlayAnimation({'name': 'aim_wait_st', 'blendTime': 0.10000000149011612})

    fork {
        Marin[companion].SetFacialExpression({'expression': 'smile'})
    } {
        Marin[companion].PlayAnimation({'name': 'aim_wait_lp', 'blendTime': 0.10000000149011612})
    }

    Marin[companion].Talk({'message': 'SubEvent:MarinCapeDate3'})
    Marin[companion].PlayAnimation({'name': 'aim_wait_ed', 'blendTime': 0.10000000149011612})
    Marin[companion].PlayAnimation({'name': 'fluttering_wait', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 2.0})

    fork {
        Marin[companion].SetFacialExpression({'expression': 'dokidoki'})
    } {
        Timer.Wait({'time': 3.0})
    }

    Marin[companion].PlayAnimation({'name': 'aim_wait_st', 'blendTime': 0.10000000149011612})
    Marin[companion].PlayAnimation({'name': 'aim_wait_lp', 'blendTime': 0.0})
    Link.PlayAnimation({'name': 'aim_wait_st', 'blendTime': 0.10000000149011612})
    Link.PlayAnimation({'name': 'aim_wait_lp', 'blendTime': 0.10000000149011612})
    Marin[companion].Talk({'message': 'SubEvent:MarinCapeDate4'})
    Marin[companion].PlayAnimation({'name': 'aim_wait_ed', 'blendTime': 0.10000000149011612})
    Marin[companion].PlayAnimation({'name': 'fluttering_wait', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 2.0})
    Link.PlayAnimation({'name': 'aim_wait_ed', 'blendTime': 0.10000000149011612})
    Link.PlayAnimation({'name': 'fluttering_wait', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 3.0})
    EventFlags.SetFlag({'symbol': 'CapeDateClear', 'value': True})
    Fade.StartPreset({'preset': 9})
    Environment.StashPopDepthOfField({'duration': 0.5})

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_16A', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Marin[companion].SetFacialExpression({'expression': 'normal'})
    } {
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } {
        Hud.PlayInAnim()
    } {
        Audio.StopAllBGM({'duration': 2.0})
    } {
        Audio.StopSE({'label': 'SE_ENV_MISAKI_NEAR_WAVE', 'duration': 2.0})
    }

}

void MarinCrash() {

    fork {
        Marin[companion].PlayAnimation({'blendTime': 0.0, 'name': 'crash_link'})
        Marin[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Link.PlayAnimation({'name': 'ev_crash_marin', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'down_lp', 'blendTime': 0.30000001192092896})
    } {
        Camera.Shake({'power': 2, 'duration': 0.10000000149011612})
    }

    Marin[companion].Talk({'message': 'SubEvent:MarinFall1'})
    Timer.Wait({'time': 0.4000000059604645})
    Marin[companion].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    Marin[companion].SetFacialExpression({'expression': 'surprise'})

    fork {
        Marin[companion].Talk({'message': 'SubEvent:MarinFall2'})
    } {
        Marin[companion].PlayAnimation({'name': 'surprise_st', 'blendTime': 0.10000000149011612})
        Marin[companion].PlayAnimation({'name': 'surprise_lp', 'blendTime': 0.10000000149011612})
    }

    Link.PlayAnimation({'name': 'rise', 'blendTime': 0.10000000149011612})
    Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})

    fork {
        Marin[companion].SetFacialExpression({'expression': 'normal'})
    } {
        Marin[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }

    EventFlags.SetFlag({'symbol': 'MarinWell', 'value': True})
}

void MarinEvade() {

    fork {
        Marin[companion].SetFacialExpression({'expression': 'surprise'})
    } {
        Marin[companion].Talk({'message': 'SubEvent:MarinFall1'})
    }

    EventFlags.SetFlag({'symbol': 'MarinWell', 'value': True})
}

void OkarinaClear_talk2() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Audio.StopBGM({'label': 'BGM_MARINE_SING', 'duration': 0.5})

    fork {
        Link.AimActor({'actor': ActorIdentifier(name="Marin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Marin.AimActor({'actor': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Marin.SetFacialExpression({'expression': 'smile'})
    }


    fork {
        Marin.GenericTalkSequence({'selfTalkAnim': True, 'playerTalkAnim': False, 'aimFromPlayer': False, 'cameraLookAt': True, 'aimToPlayer': False, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Marin.Talk({'message': 'Scenario:YesMarinSong'})
    }

    Marin.SetFacialExpression({'expression': 'normal'})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}
