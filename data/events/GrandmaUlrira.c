-------- EventFlow: GrandmaUlrira --------

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Inventory
entrypoint: None()
actions: ['SetWarashibeItem']
queries: ['HasItem']
params: None

Actor: GrandmaUlrira
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetFacialExpression', 'PlayAnimation', 'SetItemVisibility', 'SetActorSwitch', 'ChangeIdleAnimation', 'AimCompassPoint', 'AimPlayer']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequence', 'SetEquipmentVisibility']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 45, 'count': 1}) {

        fork {
            GrandmaUlrira.SetFacialExpression({'expression': 'normal'})
        } {
            GrandmaUlrira.PlayAnimation({'name': 'talk_broom_st', 'blendTime': 0.10000000149011612})
            GrandmaUlrira.PlayAnimation({'name': 'talk_broom', 'blendTime': 0.0})
        } {
            GrandmaUlrira.GenericTalkSequence({'selfTalkAnim': False, 'cameraLookAt': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            GrandmaUlrira.Talk({'message': 'Npc:Yahoo'})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            GrandmaUlrira.PlayAnimation({'name': 'talk_broom_ed', 'blendTime': 0.10000000149011612})
        }

    } else
    if !Inventory.HasItem({'count': 1, 'itemType': 47}) {
        if !EventFlags.CheckFlag({'symbol': 'BowWowJoin'}) {

            fork {
                GrandmaUlrira.SetFacialExpression({'expression': 'normal'})
            } {
                GrandmaUlrira.PlayAnimation({'name': 'talk_broom_st', 'blendTime': 0.10000000149011612})
                GrandmaUlrira.PlayAnimation({'name': 'talk_broom', 'blendTime': 0.0})
            } {
                GrandmaUlrira.GenericTalkSequence({'selfTalkAnim': False, 'cameraLookAt': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                GrandmaUlrira.Talk({'message': 'Npc:YahooBeforeLv2'})
            }


            fork {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                GrandmaUlrira.PlayAnimation({'name': 'talk_broom_ed', 'blendTime': 0.10000000149011612})
            }

        } else {

            fork {
                GrandmaUlrira.SetFacialExpression({'expression': 'normal'})
            } {
                GrandmaUlrira.PlayAnimation({'name': 'talk_broom_st', 'blendTime': 0.10000000149011612})
                GrandmaUlrira.PlayAnimation({'name': 'talk_broom', 'blendTime': 0.0})
            } {
                GrandmaUlrira.GenericTalkSequence({'selfTalkAnim': False, 'cameraLookAt': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                GrandmaUlrira.Talk({'message': 'Npc:Yahoo'})
            }


            fork {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                GrandmaUlrira.PlayAnimation({'name': 'talk_broom_ed', 'blendTime': 0.10000000149011612})
            }

        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'FishhookDrop'}) {
        if !Inventory.HasItem({'count': 1, 'itemType': 39}) {

            fork {
                GrandmaUlrira.GenericTalkSequence({'cameraLookAt': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                GrandmaUlrira.Talk({'message': 'Warashibe:QuestBroom'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                GrandmaUlrira.GenericTalkSequence({'cameraLookAt': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                GrandmaUlrira.SetFacialExpression({'expression': 'happy'})
            } {
                GrandmaUlrira.Talk({'message': 'Warashibe:WantBroom'})
            }

            if !Dialog.GetLastResult() {
                GrandmaUlrira.SetItemVisibility({'visible': False})

                fork {
                    GrandmaUlrira.PlayAnimation({'name': 'item_get_lp', 'blendTime': 0.10000000149011612})
                } {
                    Timer.Wait({'time': 0.15000000596046448})
                    GrandmaUlrira.SetItemVisibility({'visible': True})
                    Timer.Wait({'time': 2.0})
                } {
                    GrandmaUlrira.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
                }

                GrandmaUlrira.SetItemVisibility({'visible': False})

                fork {
                    GrandmaUlrira.PlayAnimation({'name': 'talk_broom', 'blendTime': 0.10000000149011612})
                } {
                    Timer.Wait({'time': 0.10000000149011612})
                    GrandmaUlrira.SetItemVisibility({'visible': True})
                } {
                    GrandmaUlrira.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                }

                EventFlags.SetFlag({'value': True, 'symbol': 'FishhookDrop'})
                GrandmaUlrira.SetActorSwitch({'switchIndex': 0, 'value': True})

                fork {
                    GrandmaUlrira.GenericTalkSequence({'cameraLookAt': False, 'keepPersonalSpace': False, 'playerTalkAnim': False, 'aimFromPlayer': True, 'aimToPlayer': True, 'selfTalkAnim': False, 'distanceOffset': 0.0})
                } {
                    GrandmaUlrira.Talk({'message': 'Warashibe:ClearBroom'})
                }

                Inventory.SetWarashibeItem({'itemType': 11})

                fork {
                    GrandmaUlrira.PlayAnimation({'name': 'wait_broom', 'blendTime': 0.10000000149011612})
                } {
                    Link.GenericItemGetSequence({'itemType': 40, 'keepCarry': False, 'messageEntry': ''})
                }

                GrandmaUlrira.SetFacialExpression({'expression': 'normal'})
                GrandmaUlrira.ChangeIdleAnimation({'name': 'wait_broom'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {
                GrandmaUlrira.Talk({'message': 'Warashibe:BadBroom'})
                GrandmaUlrira.SetFacialExpression({'expression': 'normal'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        }
    } else {

        fork {
            GrandmaUlrira.SetFacialExpression({'expression': 'happy'})
        } {
            GrandmaUlrira.PlayAnimation({'name': 'talk_broom_st', 'blendTime': 0.10000000149011612})
            GrandmaUlrira.PlayAnimation({'name': 'talk_broom', 'blendTime': 0.0})
        } {
            GrandmaUlrira.GenericTalkSequence({'selfTalkAnim': False, 'cameraLookAt': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            GrandmaUlrira.Talk({'message': 'Npc:YahooAfterWarashibe'})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            GrandmaUlrira.PlayAnimation({'name': 'talk_broom_ed', 'blendTime': 0.10000000149011612})
        } {
            GrandmaUlrira.SetFacialExpression({'expression': 'normal'})
        }

    }
}
