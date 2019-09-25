-------- EventFlow: Richard --------

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'MoveToTargetLinkedPoint', 'AimCompassPoint']
queries: ['WithWanwan']
params: None

Actor: Richard
entrypoint: None()
actions: ['TalkKeep', 'Talk', 'GenericTalkSequence', 'SetFacialExpression', 'PlayAnimation', 'MoveOver', 'AimCompassPoint']
queries: []
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

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'GoldenLeafCount'}) {
        if !Link.WithWanwan() {
            EventFlags.SetFlag({'symbol': 'RichardTalked', 'value': True})

            fork {
                Richard.GenericTalkSequence({'playerTalkAnim': False, 'selfTalkAnim': False, 'cameraLookAt': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
            } {
                Richard.SetFacialExpression({'expression': 'normal'})
            } {
                Richard.PlayAnimation({'name': 'action', 'blendTime': 0.10000000149011612})
            }

            Richard.GenericTalkSequence({'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
            Richard.Talk({'message': 'Scenario:Lv3QuestRichard'})
            if !Dialog.GetLastResult() {
                EventFlags.SetFlag({'value': True, 'symbol': 'GoldenLeafCount'})
                Richard.SetFacialExpression({'expression': 'cool'})
                Richard.Talk({'message': 'Scenario:Lv3YesRichard'})

                call RichardTurn()

                GameControl.RequestAutoSave()
            } else {
                Richard.SetFacialExpression({'expression': 'angry'})

                fork {
                    Richard.PlayAnimation({'blendTime': 0.10000000149011612, 'name': 'speechless2'})
                    Richard.PlayAnimation({'name': 'wait', 'blendTime': 0.0})
                } {
                    Richard.Talk({'message': 'Scenario:Lv3NoRichard'})
                }


                call RichardTurn()

            }
        } else {

            fork {
                Richard.GenericTalkSequence({'playerTalkAnim': False, 'selfTalkAnim': False, 'cameraLookAt': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
            } {
                Richard.SetFacialExpression({'expression': 'angry'})
            } {
                Richard.TalkKeep({'message': 'SubEvent:RichardHateBowwow1'})
            }


            fork {
                Richard.PlayAnimation({'blendTime': 0.10000000149011612, 'name': 'speechless2'})
                Richard.PlayAnimation({'name': 'wait', 'blendTime': 0.0})
            } {
                Richard.Talk({'message': 'SubEvent:RichardHateBowwow2'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    } else
    if !Inventory.HasItem({'itemType': 24, 'count': 5}) {

        fork {
            Richard.GenericTalkSequence({'playerTalkAnim': False, 'selfTalkAnim': False, 'cameraLookAt': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
        } {
            Richard.SetFacialExpression({'expression': 'cool'})
        } {
            Richard.PlayAnimation({'name': 'action', 'blendTime': 0.10000000149011612})
        }

        if !Inventory.HasItem({'itemType': 24, 'count': 4}) {
            if !Inventory.HasItem({'itemType': 24, 'count': 3}) {
                if !Inventory.HasItem({'count': 2, 'itemType': 24}) {
                    if !Inventory.HasItem({'itemType': 24, 'count': 1}) {

                        fork {
                            Richard.GenericTalkSequence({'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
                        } {
                            Richard.Talk({'message': 'Npc:RichardGoldLeaf0'})
                        }


                        call RichardTurn()

                    } else {

                        fork {
                            Richard.GenericTalkSequence({'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
                        } {
                            Richard.Talk({'message': 'Npc:RichardGoldLeaf1'})
                        }


                        call RichardTurn()

                    }
                } else {

                    fork {
                        Richard.GenericTalkSequence({'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
                    } {
                        Richard.Talk({'message': 'Npc:RichardGoldLeaf1'})
                    }


                    call RichardTurn()

                }
            } else {

                fork {
                    Richard.GenericTalkSequence({'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
                } {
                    Richard.Talk({'message': 'Npc:RichardGoldLeaf1'})
                }


                call RichardTurn()

            }
        } else {

            fork {
                Richard.GenericTalkSequence({'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
            } {
                Richard.Talk({'message': 'Npc:RichardGoldLeaf1'})
            }


            call RichardTurn()

        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'GoldenLeafComplete'}) {
        Link.MoveToTargetLinkedPoint({'index': 2, 'speed': 0, 'actor': ActorIdentifier(name="Richard"), 'timeOut': 7.0})
        Link.AimCompassPoint({'direction': 2, 'duration': 0.10000000149011612, 'withoutTurn': False})
        EventFlags.SetFlag({'symbol': 'GoldenLeafComplete', 'value': True})

        fork {
            Richard.GenericTalkSequence({'playerTalkAnim': False, 'selfTalkAnim': False, 'cameraLookAt': True, 'keepPersonalSpace': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
        } {
            Richard.PlayAnimation({'name': 'action', 'blendTime': 0.10000000149011612})
        } {
            Richard.SetFacialExpression({'expression': 'cool'})
        }


        fork {
            Richard.GenericTalkSequence({'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
        } {
            Richard.Talk({'message': 'Scenario:Lv3ClearRichard'})
        }

        Richard.MoveOver()
        GameControl.RequestAutoSave()
    } else {

        fork {
            Richard.GenericTalkSequence({'playerTalkAnim': False, 'selfTalkAnim': False, 'cameraLookAt': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
        } {
            Richard.SetFacialExpression({'expression': 'cool'})
        } {
            Richard.PlayAnimation({'name': 'action', 'blendTime': 0.10000000149011612})
        }


        fork {
            Richard.GenericTalkSequence({'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
        } {
            Richard.Talk({'message': 'Npc:RichardCompGoldLeaf'})
        }


        call RichardTurn()

    }
}

void RichardTurn() {

    fork {
        Richard.AimCompassPoint({'duration': 0.30000001192092896, 'direction': 0, 'withoutTurn': False})
    } {
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } {
        Richard.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Richard.SetFacialExpression({'expression': 'normal'})
    }

}
