-------- EventFlow: FairyQueen --------

Actor: FairyQueen
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'SetTailorProperty', 'PlayTailorOtherChannelEx', 'PlayAnimationEx', 'StopTailorOtherChannel']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: ['GetLastResult4', 'GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'PlayTailorOtherChannelEx', 'ClearPowerUp', 'LookAtItemGettingPlayer', 'SetFacialExpression', 'PlayAnimation', 'AimCompassPoint', 'AimActor', 'MoveToTargetLinkedPoint']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: ['HasItem']
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump', 'RequestAutoSave']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['StashSaveIntensity', 'StashPopIntensity']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopZoneAudio', 'StopAllBGM']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset']
queries: []
params: None

void talk() {
    Link.ClearPowerUp()
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="FairyQueen"), 'timeOut': 7.0})
    Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
    if !EventFlags.CheckFlag({'symbol': 'FairyQueenFirstClear'}) {
        EventFlags.SetFlag({'symbol': 'FairyQueenFirstClear', 'value': True})
        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy1'})
        Event60:
        if !Inventory.HasItem({'itemType': 19, 'count': 1}) {
            if !Inventory.HasItem({'itemType': 20, 'count': 1}) {
                FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy1_2'})
                Event1:
                switch Dialog.GetLastResult4() {
                  case 0:
                    FairyQueen.Talk({'message': 'SubEvent:QuestRedCloth'})
                    if !Dialog.GetLastResult() {
                        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy3'})
                        if !Dialog.GetLastResult() {

                            call RedclothGet()

                        } else {
                            Event6:
                            FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy2'})
                            goto Event1
                        }
                    } else {
                        goto Event6
                    }
                  case 1:
                    FairyQueen.Talk({'message': 'SubEvent:QuestBlueCloth'})
                    if !Dialog.GetLastResult() {
                        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy3'})
                        if !Dialog.GetLastResult() {

                            call BlueclothGet()

                        } else {
                            goto Event6
                        }
                    } else {
                        goto Event6
                    }
                  case 2:
                    FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy6'})
                    if !Dialog.GetLastResult() {
                        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy8'})

                        call NoGet()

                    } else {
                        goto Event6
                    }
                }
            } else {
                FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy1_3'})
                Event44:
                switch Dialog.GetLastResult4() {
                  case 0:
                    FairyQueen.Talk({'message': 'SubEvent:QuestRedCloth'})
                    if !Dialog.GetLastResult() {
                        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy3'})
                        if !Dialog.GetLastResult() {

                            call RedclothGet()

                        } else {
                            Event121:
                            FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy4'})
                            goto Event44
                        }
                    } else {
                        goto Event121
                    }
                  case 1:
                    FairyQueen.Talk({'message': 'SubEvent:QuestGreenCloth'})
                    if !Dialog.GetLastResult() {
                        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy3'})
                        if !Dialog.GetLastResult() {

                            call GreenclothGet()

                        } else {
                            goto Event121
                        }
                    } else {
                        goto Event121
                    }
                  case 2:
                    FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy6'})
                    if !Dialog.GetLastResult() {
                        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy8'})

                        call NoGet()

                    } else {
                        goto Event121
                    }
                }
            }
        } else {
            FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy1_4'})
            Event65:
            switch Dialog.GetLastResult4() {
              case 0:
                FairyQueen.Talk({'message': 'SubEvent:QuestBlueCloth'})
                if !Dialog.GetLastResult() {
                    FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy3'})
                    if !Dialog.GetLastResult() {

                        call BlueclothGet()

                    } else {
                        Event16:
                        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy5'})
                        goto Event65
                    }
                } else {
                    goto Event16
                }
              case 1:
                FairyQueen.Talk({'message': 'SubEvent:QuestGreenCloth'})
                if !Dialog.GetLastResult() {
                    FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy3'})
                    if !Dialog.GetLastResult() {

                        call GreenclothGet()

                    } else {
                        goto Event16
                    }
                } else {
                    goto Event16
                }
              case 2:
                FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy6'})
                if !Dialog.GetLastResult() {
                    FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy8'})

                    call NoGet()

                } else {
                    goto Event16
                }
            }
        }
    } else {
        FairyQueen.Talk({'message': 'SubEvent:QuestGrandFairy7'})
        goto Event60
    }
}

void GreenclothGet() {
    FairyQueen.Talk({'message': 'SubEvent:AnswerGrandFairy_00'})
    FairyQueen.SetTailorProperty({'propertyIndex': 0, 'value': 'EV_Green_Effect', 'index': 0})
    FairyQueen.StopTailorOtherChannel({'channel': 'ac_Keep', 'index': 0})

    fork {
        FairyQueen.PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'give_st'})
        FairyQueen.PlayAnimationEx({'name': 'give_lp', 'blendTime': 0.0, 'time': 0.0})
    } {
        FairyQueen.PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'Change_Color_00', 'restart': False, 'index': 0})
        Timer.Wait({'time': 2.0})
    } {
        Environment.StashSaveIntensity({'duration': 3.0, 'attenuation': 0.5})
    }

    Link.PlayTailorOtherChannelEx({'time': 3.5799999237060547, 'channel': 'Change_Color_Green_00', 'restart': False, 'index': 0})

    fork {
        Environment.StashPopIntensity({'duration': 1.0})
    } {
        Inventory.AddItem({'count': 1, 'itemType': 18, 'autoEquip': False})
    }


    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_st'})
    } {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    }


    fork {
        Dialog.Show({'message': 'SubEvent:GetGreenCloth'})
    } {
        Link.LookAtItemGettingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.SetFacialExpression({'expression': 'get'})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_lp'})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_ed'})
    }


    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'idle_bare'})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="FairyQueen"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    FairyQueen.PlayTailorOtherChannelEx({'channel': 'ac_Keep', 'time': 0.0, 'restart': False, 'index': 0})
    FairyQueen.PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'wait'})
    FairyQueen.Talk({'message': 'SubEvent:ByebyeGrandFairy'})
    EventFlags.SetFlag({'symbol': 'Lv10DungeonClear', 'value': True})
    Link.PlayTailorOtherChannelEx({'channel': 'EV_Fadeout', 'time': 1.5, 'restart': False, 'index': 0})
    Fade.StartPreset({'preset': 3})

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Audio.StopZoneAudio()
    }

    GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_08H', 'offsetX': 0.0, 'offsetZ': 0.0})
    GameControl.RequestAutoSave()
}

void BlueclothGet() {
    FairyQueen.Talk({'message': 'SubEvent:AnswerGrandFairy_00'})
    FairyQueen.SetTailorProperty({'propertyIndex': 0, 'value': 'EV_Blue_Effect', 'index': 0})
    FairyQueen.StopTailorOtherChannel({'channel': 'ac_Keep', 'index': 0})

    fork {
        FairyQueen.PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'give_st'})
        FairyQueen.PlayAnimationEx({'name': 'give_lp', 'blendTime': 0.0, 'time': 0.0})
    } {
        FairyQueen.PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'Change_Color_00', 'restart': False, 'index': 0})
        Timer.Wait({'time': 2.0})
    } {
        Environment.StashSaveIntensity({'duration': 3.0, 'attenuation': 0.5})
    }

    Link.PlayTailorOtherChannelEx({'time': 3.5799999237060547, 'channel': 'Change_Color_Blue_00', 'restart': False, 'index': 0})

    fork {
        Environment.StashPopIntensity({'duration': 1.0})
    } {
        Inventory.AddItem({'count': 1, 'itemType': 20, 'autoEquip': False})
    }


    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_st'})
    } {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    }


    fork {
        Dialog.Show({'message': 'SubEvent:GetBlueCloth'})
    } {
        Link.LookAtItemGettingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.SetFacialExpression({'expression': 'get'})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_lp'})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_ed'})
    }


    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'idle_bare'})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="FairyQueen"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    FairyQueen.PlayTailorOtherChannelEx({'channel': 'ac_Keep', 'time': 0.0, 'restart': False, 'index': 0})
    FairyQueen.PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'wait'})
    FairyQueen.Talk({'message': 'SubEvent:ByebyeGrandFairy'})
    EventFlags.SetFlag({'symbol': 'Lv10DungeonClear', 'value': True})
    Link.PlayTailorOtherChannelEx({'channel': 'EV_Fadeout', 'time': 1.5, 'restart': False, 'index': 0})
    Fade.StartPreset({'preset': 3})

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Audio.StopZoneAudio()
    }

    GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_08H', 'offsetX': 0.0, 'offsetZ': 0.0})
    GameControl.RequestAutoSave()
}

void RedclothGet() {
    FairyQueen.Talk({'message': 'SubEvent:AnswerGrandFairy_00'})
    FairyQueen.SetTailorProperty({'propertyIndex': 0, 'value': 'EV_Red_Effect', 'index': 0})
    FairyQueen.StopTailorOtherChannel({'channel': 'ac_Keep', 'index': 0})

    fork {
        FairyQueen.PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'give_st'})
        FairyQueen.PlayAnimationEx({'name': 'give_lp', 'blendTime': 0.0, 'time': 0.0})
    } {
        FairyQueen.PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'Change_Color_00', 'restart': False, 'index': 0})
        Timer.Wait({'time': 2.0})
    } {
        Environment.StashSaveIntensity({'duration': 3.0, 'attenuation': 0.5})
    }

    Link.PlayTailorOtherChannelEx({'time': 3.5799999237060547, 'channel': 'Change_Color_Red_00', 'restart': False, 'index': 0})

    fork {
        Environment.StashPopIntensity({'duration': 1.0})
    } {
        Inventory.AddItem({'count': 1, 'itemType': 19, 'autoEquip': False})
    }


    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_st'})
    } {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    }


    fork {
        Dialog.Show({'message': 'SubEvent:GetRedCloth'})
    } {
        Link.LookAtItemGettingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.SetFacialExpression({'expression': 'get'})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_lp'})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'item_get_ed'})
    }


    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'idle_bare'})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="FairyQueen"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    FairyQueen.PlayTailorOtherChannelEx({'channel': 'ac_Keep', 'time': 0.0, 'restart': False, 'index': 0})
    FairyQueen.PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'wait'})
    FairyQueen.Talk({'message': 'SubEvent:ByebyeGrandFairy'})
    EventFlags.SetFlag({'symbol': 'Lv10DungeonClear', 'value': True})
    Link.PlayTailorOtherChannelEx({'channel': 'EV_Fadeout', 'time': 1.5, 'restart': False, 'index': 0})
    Fade.StartPreset({'preset': 3})

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Audio.StopZoneAudio()
    }

    GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_08H', 'offsetX': 0.0, 'offsetZ': 0.0})
    GameControl.RequestAutoSave()
}

void NoGet() {
    FairyQueen.Talk({'message': 'SubEvent:ByebyeGrandFairy'})
    EventFlags.SetFlag({'symbol': 'Lv10DungeonClear', 'value': True})
    Link.PlayTailorOtherChannelEx({'channel': 'EV_Fadeout', 'time': 1.5, 'restart': False, 'index': 0})
    Fade.StartPreset({'preset': 3})

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Audio.StopZoneAudio()
    }

    GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_08H', 'offsetX': 0.0, 'offsetZ': 0.0})
    GameControl.RequestAutoSave()
}
