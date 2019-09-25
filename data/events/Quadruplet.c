-------- EventFlow: Quadruplet --------

Actor: Quadruplet[boyA]
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'SetFacialExpression']
queries: []
params: None

Actor: Quadruplet[boyB]
entrypoint: None()
actions: ['SetFacialExpression']
queries: []
params: None

Actor: Quadruplet[BoyA]
entrypoint: None()
actions: ['Talk', 'MoveToTargetLinkedPoint', 'PlayAnimation', 'AimPlayer', 'GenericTalkSequence', 'SetFacialExpression', 'WaitCatch', 'LookAtTalker', 'ResetAim']
queries: []
params: None

Actor: Quadruplet[BoyB]
entrypoint: None()
actions: ['Talk', 'AimPlayer', 'MoveToTargetLinkedPoint', 'PlayAnimation', 'GenericTalkSequence', 'SetFacialExpression', 'WaitCatch', 'LookAtTalker', 'ResetAim']
queries: []
params: None

Actor: Quadruplet[BoyC]
entrypoint: None()
actions: ['Talk', 'AimActor', 'PlayAnimation', 'SetFacialExpression', 'GenericTalkSequence']
queries: []
params: None

Actor: Quadruplet[BoyD]
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'SetFacialExpression', 'GenericTalkSequence']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'SetEquipmentVisibility', 'PlayAnimation', 'MoveToTargetLinkedPoint', 'SetDisablePowerUpEffect', 'CancelCarry']
queries: ['WithMarin']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'PlayBGM']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['ChangeEnvironment']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave', 'OverwriteZone']
queries: []
params: None

void talk_boyA() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Quadruplet[BoyA].WaitCatch()
    if !Inventory.HasItem({'itemType': 45, 'count': 1}) {

        fork {
            Quadruplet[BoyA].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyA].Talk({'message': 'Npc:MabeGreenChild1'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {
        if !EventFlags.CheckFlag({'symbol': 'BowWowJoin'}) {

            fork {
                Quadruplet[BoyA].GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Quadruplet[BoyA].Talk({'message': 'Scenario:Lv2ChildHappening9'})
            }

            Dialog.Show({'message': 'Scenario:Lv2ChildHappening7'})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                Quadruplet[BoyA].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Quadruplet[BoyA].Talk({'message': 'Npc:MabeGreenChild2'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    } else
    if !Link.WithMarin() {

        fork {
            Quadruplet[BoyA].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyA].Talk({'message': 'Npc:MabeGreenChild2'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            Quadruplet[BoyA].GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[boyA].SetFacialExpression({'expression': 'smile'})
        } {
            Quadruplet[boyA].PlayAnimation({'name': 'tease', 'blendTime': 0.10000000149011612})
        } {
            Quadruplet[boyA].Talk({'message': 'SubEvent:TeaseChild'})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            Quadruplet[boyA].SetFacialExpression({'expression': 'normal'})
        }

    }
}

void talk_boyB() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Quadruplet[BoyB].WaitCatch()
    if !Inventory.HasItem({'itemType': 45, 'count': 1}) {

        fork {
            Quadruplet[BoyB].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyB].Talk({'message': 'Npc:MabeRedChild1'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {
        if !EventFlags.CheckFlag({'symbol': 'BowWowJoin'}) {

            fork {
                Quadruplet[BoyB].GenericTalkSequence({'selfTalkAnim': False, 'cameraLookAt': True, 'playerTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Quadruplet[BoyB].Talk({'message': 'Scenario:Lv2ChildHappening8'})
            }

            Dialog.Show({'message': 'Scenario:Lv2ChildHappening7'})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                Quadruplet[BoyB].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Quadruplet[BoyB].Talk({'message': 'Npc:MabeRedChild2'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    } else
    if !Link.WithMarin() {

        fork {
            Quadruplet[BoyB].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyB].Talk({'message': 'Npc:MabeRedChild2'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            Quadruplet[BoyB].GenericTalkSequence({'cameraLookAt': True, 'playerTalkAnim': False, 'selfTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[boyB].SetFacialExpression({'expression': 'smile'})
        } {
            Quadruplet[BoyB].PlayAnimation({'name': 'tease', 'blendTime': 0.10000000149011612})
        } {
            Quadruplet[BoyB].Talk({'message': 'SubEvent:TeaseChild'})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            Quadruplet[boyB].SetFacialExpression({'expression': 'normal'})
        }

    }
}

void talk_boyC() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'FirstClear'}) {

        fork {
            Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyC].Talk({'message': 'Npc:ToolShopChlid1'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {
        if !EventFlags.CheckFlag({'symbol': 'HintYosshi'}) {

            call PleaseYosshi()

        } else {

            call GetRibbon()

        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'HintYosshi'}) {

        call PleaseYosshi()

    } else
    if !EventFlags.CheckFlag({'symbol': 'RibbonDrop'}) {

        fork {
            Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyC].Talk({'message': 'Npc:WantYosshi3'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Link.WithMarin() {
        if !EventFlags.CheckFlag({'symbol': 'MarinJoin'}) {
            if !EventFlags.CheckFlag({'symbol': 'WalrusTalked'})
            && !EventFlags.CheckFlag({'symbol': 'PineappleGet'}) {

                fork {
                    Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
                } {
                    Quadruplet[BoyC].Talk({'message': 'Npc:WeathercockChlid1'})
                }

                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {

                fork {
                    Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
                } {
                    Quadruplet[BoyC].Talk({'message': 'Npc:WeathercockChlid2'})
                }

                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        } else
        if !Inventory.HasItem({'itemType': 49, 'count': 1}) {

            fork {
                Quadruplet[BoyC].Talk({'message': 'Npc:ToolShopChlid2'})
            } {
                Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                Quadruplet[BoyC].Talk({'message': 'SubEvent:NoneYahooGranma'})
            } {
                Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    } else {

        fork {
            Quadruplet[BoyC].GenericTalkSequence({'selfTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyC].SetFacialExpression({'expression': 'smile'})
        } {
            Quadruplet[BoyC].PlayAnimation({'name': 'tease', 'blendTime': 0.10000000149011612})
        } {
            Quadruplet[BoyC].Talk({'message': 'SubEvent:TeaseChild'})
        }


        fork {
            Quadruplet[BoyC].SetFacialExpression({'expression': 'normal'})
        } {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }

    }
}

void talk_boyD() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 45, 'count': 1}) {

        fork {
            Quadruplet[BoyD].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyD].Talk({'message': 'Npc:DreamshrineChild1'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {

        fork {
            Quadruplet[BoyD].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyD].Talk({'message': 'Npc:DreamshrineChild2'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Link.WithMarin() {
        if !Inventory.HasItem({'itemType': 49, 'count': 1}) {

            fork {
                Quadruplet[BoyD].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Quadruplet[BoyD].Talk({'message': 'Npc:DreamshrineChild3'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                Quadruplet[BoyD].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Quadruplet[BoyD].Talk({'message': 'Npc:MabeRedChild2'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    } else {

        fork {
            Quadruplet[BoyD].GenericTalkSequence({'selfTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyD].SetFacialExpression({'expression': 'smile'})
        } {
            Quadruplet[BoyD].PlayAnimation({'name': 'tease', 'blendTime': 0.10000000149011612})
        } {
            Quadruplet[BoyD].Talk({'message': 'SubEvent:TeaseChild'})
        }


        fork {
            Quadruplet[BoyD].SetFacialExpression({'expression': 'normal'})
        } {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }

    }
}

void detain() {
    Link.CancelCarry()
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Quadruplet[BoyA].ResetAim()
    Quadruplet[BoyB].ResetAim()

    fork {
        Quadruplet[BoyA].MoveToTargetLinkedPoint({'speed': 1, 'index': 0, 'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyA"), 'timeOut': 7.0})
    } {
        Quadruplet[BoyB].MoveToTargetLinkedPoint({'speed': 1, 'index': 1, 'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyB"), 'timeOut': 7.0})
    } {
        Quadruplet[BoyA].SetFacialExpression({'expression': 'excite'})
    } {
        Quadruplet[BoyB].SetFacialExpression({'expression': 'excite'})
    } {
        Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyB"), 'timeOut': 7.0})
    }

    Audio.StopAllBGM({'duration': 1.0})
    Audio.PlayBGM({'label': 'BGM_EVENT_RESCUE_BOWBOW', 'volume': 0.5})
    EventFlags.SetFlag({'symbol': 'BowWowEvent', 'value': True})

    fork {
        Quadruplet[BoyB].AimPlayer({'duration': 0.10000000149011612, 'withoutTurn': False, 'boneName': ''})
    } {
        Quadruplet[BoyB].LookAtTalker({'distanceOffset': 1.0, 'duration': 0.10000000149011612, 'chaseRatio': 0.029999999329447746})
    } {
        Quadruplet[BoyB].Talk({'message': 'Scenario:Lv2ChildHappening1'})
    } {
        Quadruplet[BoyA].PlayAnimation({'name': 'panic', 'blendTime': 0.10000000149011612})
    } {
        Quadruplet[BoyB].PlayAnimation({'name': 'panic2', 'blendTime': 0.10000000149011612})
    } {
        Quadruplet[BoyA].AimPlayer({'duration': 0.10000000149011612, 'withoutTurn': False, 'boneName': ''})
    } {
        Environment.ChangeEnvironment({'name': 'FieldBowWow', 'duration': 0.5})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyB"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Quadruplet[BoyA].Talk({'message': 'Scenario:Lv2ChildHappening2'})
    } {
        Quadruplet[BoyA].LookAtTalker({'distanceOffset': 1.0, 'chaseRatio': 0.029999999329447746, 'duration': 0.44999998807907104})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyA"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Quadruplet[BoyB].Talk({'message': 'Scenario:Lv2ChildHappening3'})
    } {
        Quadruplet[BoyB].LookAtTalker({'distanceOffset': 1.0, 'chaseRatio': 0.029999999329447746, 'duration': 0.44999998807907104})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyB"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Quadruplet[BoyA].Talk({'message': 'Scenario:Lv2ChildHappening4'})
    } {
        Quadruplet[BoyA].LookAtTalker({'distanceOffset': 1.0, 'chaseRatio': 0.029999999329447746, 'duration': 0.44999998807907104})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyA"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Quadruplet[BoyB].Talk({'message': 'Scenario:Lv2ChildHappening5'})
    } {
        Quadruplet[BoyB].LookAtTalker({'distanceOffset': 1.0, 'chaseRatio': 0.029999999329447746, 'duration': 0.44999998807907104})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyB"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Quadruplet[BoyA].Talk({'message': 'Scenario:Lv2ChildHappening6'})
    } {
        Quadruplet[BoyA].LookAtTalker({'distanceOffset': 1.0, 'chaseRatio': 0.029999999329447746, 'duration': 0.44999998807907104})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyA"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    Dialog.Show({'message': 'Scenario:Lv2ChildHappening7'})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    EventFlags.SetFlag({'symbol': 'DoorOpen_Btl_MoriblinCave_2A', 'value': False})
    EventFlags.SetFlag({'symbol': 'DoorOpen_Btl_MoriblinCave_1A', 'value': False})
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
    GameControl.OverwriteZone({'conditionName': 'BowWowKidnap'})
}

void Yosshi_boyC() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Quadruplet[BoyC].Talk({'message': 'Npc:WantYosshi2'})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Quadruplet", sub_name="BoyC"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Quadruplet[BoyC].AimActor({'actor': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    EventFlags.SetFlag({'symbol': 'HintYosshi', 'value': True})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void PleaseYosshi() {

    fork {
        Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Quadruplet[BoyC].Talk({'message': 'Npc:WantYosshi1'})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void GetRibbon() {
    if !EventFlags.CheckFlag({'symbol': 'RibbonDrop'}) {

        fork {
            Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Quadruplet[BoyC].Talk({'message': 'Npc:WantYosshi3'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'itemType': 45, 'count': 1}) {

        fork {
            Quadruplet[BoyC].Talk({'message': 'Npc:ToolShopChlid1'})
        } {
            Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            Quadruplet[BoyC].Talk({'message': 'Npc:ToolShopChlid2'})
        } {
            Quadruplet[BoyC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}
