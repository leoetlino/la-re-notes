-------- EventFlow: Sale --------

Actor: Item[Banana]
entrypoint: None()
actions: ['Deactivate']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Sale
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'AimCompassPoint', 'AimPlayer', 'GenericTalkSequence', 'SetItemVisibility', 'LookAtTalkersLinkedPoint', 'LookAtTalker', 'SetFacialExpression']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['SetWarashibeItem']
queries: ['HasItem']
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequence']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle']
queries: []
params: None

void talk() {
    if !EventFlags.CheckFlag({'symbol': 'BananaDrop'}) {
        if !Inventory.HasItem({'count': 1, 'itemType': 32}) {

            fork {
                Sale.Talk({'message': 'Warashibe:WantCan'})
            } {
                Sale.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

        } else {

            fork {
                Sale.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Sale.Talk({'message': 'Warashibe:QuestCan'})
            }

            if !Dialog.GetLastResult() {
                EventFlags.SetFlag({'value': True, 'symbol': 'BananaDrop'})
                Sale.SetFacialExpression({'expression': 'joy'})
                Sale.Talk({'message': 'Warashibe:ClearCan1'})
                Sale.AimCompassPoint({'direction': 3, 'duration': 0.4000000059604645, 'withoutTurn': False})

                fork {
                    Sale.PlayAnimation({'name': 'eat', 'blendTime': 0.10000000149011612})
                } {
                    Timer.Wait({'time': 0.30000001192092896})
                    Sale.SetItemVisibility({'visible': True})

                    fork {
                        Timer.Wait({'time': 2.700000047683716})
                    } {
                        Timer.Wait({'time': 0.800000011920929})
                        Sale.LookAtTalkersLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
                    }


                    fork {
                        Sale.SetItemVisibility({'visible': False})
                    } {
                        Sale.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
                    }

                }


                fork {
                    Sale.PlayAnimation({'name': 'swallow', 'blendTime': 0.10000000149011612})
                    Sale.PlayAnimation({'name': 'wait', 'blendTime': 0.0})
                } {
                    Audio.PlayJingle({'label': 'SE_ENV_SALE_SWALLOW', 'volume': 1.0})
                    Timer.Wait({'time': 0.5})
                    Audio.PlayJingle({'label': 'SE_ENV_SALE_PON', 'volume': 1.0})
                }

                Sale.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                Sale.PlayAnimation({'name': 'talk', 'blendTime': 0.20000000298023224})
                Sale.Talk({'message': 'Warashibe:ClearCan2'})
                Sale.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                Inventory.SetWarashibeItem({'itemType': 4})

                fork {
                    Link.GenericItemGetSequence({'itemType': 33, 'keepCarry': False, 'messageEntry': ''})
                } {
                    Item[Banana].Deactivate()
                }

                Sale.SetFacialExpression({'expression': 'normal'})
            } else {
                Sale.Talk({'message': 'Warashibe:BadCan'})
            }
        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'SaleSecondTalked'}) {

        fork {
            Sale.Talk({'message': 'Npc:SaleAfterEatCan'})
        } {
            Sale.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Sale.SetFacialExpression({'expression': 'joy'})
        }

        EventFlags.SetFlag({'value': True, 'symbol': 'SaleSecondTalked'})
        Sale.SetFacialExpression({'expression': 'normal'})
    } else {

        fork {
            Sale.Talk({'message': 'Npc:SaleAfterWarashibe'})
        } {
            Sale.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Sale.SetFacialExpression({'expression': 'joy'})
        }

        Sale.SetFacialExpression({'expression': 'normal'})
    }
}
