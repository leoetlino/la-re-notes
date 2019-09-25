-------- EventFlow: ChefBear --------

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequence', 'AimActor', 'SetEquipmentVisibility', 'PlayAnimation', 'SetFacialExpression']
queries: ['WithMarin']
params: None

Actor: ChefBear
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetFacialExpression', 'PlayAnimation', 'AimActorLinkedPoint', 'AimPlayer']
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

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'PineappleGet'}) {
        if !Inventory.HasItem({'count': 1, 'itemType': 35}) {

            fork {
                ChefBear.GenericTalkSequence({'selfTalkAnim': True, 'aimFromPlayer': True, 'aimToPlayer': False, 'keepPersonalSpace': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
            } {
                ChefBear.Talk({'message': 'Warashibe:WantHoney'})
            } {
                ChefBear.AimPlayer({'withoutTurn': True, 'duration': 0.4000000059604645, 'boneName': ''})
            }

        } else {

            fork {
                ChefBear.GenericTalkSequence({'selfTalkAnim': False, 'cameraLookAt': True, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                ChefBear.PlayAnimation({'name': 'surprise_st', 'blendTime': 0.10000000149011612})

                fork {
                    ChefBear.PlayAnimation({'name': 'surprise', 'blendTime': 0.0})
                } {
                    ChefBear.Talk({'message': 'Warashibe:QuestHoney'})
                }

            }

            if !Dialog.GetLastResult() {
                EventFlags.SetFlag({'symbol': 'PineappleGet', 'value': True})
                Inventory.SetWarashibeItem({'itemType': 7})
                Link.GenericItemGetSequence({'itemType': 36, 'keepCarry': False, 'messageEntry': ''})
                Timer.Wait({'time': 0.6000000238418579})

                fork {
                    ChefBear.GenericTalkSequence({'keepPersonalSpace': False, 'cameraLookAt': True, 'playerTalkAnim': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'distanceOffset': 0.0})
                } {
                    Link.SetFacialExpression({'expression': 'normal'})
                } {
                    Link.AimActor({'actor': ActorIdentifier(name="ChefBear"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                }

                ChefBear.SetFacialExpression({'expression': 'joy'})
                Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
                if !EventFlags.CheckFlag({'symbol': 'MarinJoin'}) {
                    ChefBear.Talk({'message': 'Warashibe:ClearHoney'})

                    call TurnBear()

                } else {
                    ChefBear.Talk({'message': 'Warashibe:ClearHoney2'})

                    call TurnBear()

                }
            } else {

                fork {
                    ChefBear.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'selfTalkAnim': True, 'cameraLookAt': False, 'distanceOffset': 0.0})
                } {
                    ChefBear.Talk({'message': 'Warashibe:BadHoney'})
                }


                call TurnBear()

            }
        }
    } else
    if !Link.WithMarin() {

        fork {
            ChefBear.GenericTalkSequence({'selfTalkAnim': True, 'aimFromPlayer': True, 'aimToPlayer': False, 'keepPersonalSpace': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            ChefBear.SetFacialExpression({'expression': 'joy'})
        } {
            ChefBear.Talk({'message': 'Npc:BearAfterWarashibe'})
        } {
            ChefBear.AimPlayer({'withoutTurn': True, 'duration': 0.4000000059604645, 'boneName': ''})
        }

        ChefBear.SetFacialExpression({'expression': 'normal'})
    } else {

        fork {
            ChefBear.GenericTalkSequence({'selfTalkAnim': True, 'aimFromPlayer': True, 'aimToPlayer': False, 'keepPersonalSpace': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            ChefBear.SetFacialExpression({'expression': 'joy'})
        } {
            ChefBear.Talk({'message': 'Npc:BearWithMarin'})
        } {
            ChefBear.AimPlayer({'withoutTurn': True, 'duration': 0.4000000059604645, 'boneName': ''})
        }

        ChefBear.SetFacialExpression({'expression': 'normal'})
    }
}

void TurnBear() {

    fork {
        ChefBear.AimActorLinkedPoint({'pointIndex': 0, 'duration': 0.30000001192092896, 'actor': ActorIdentifier(name="ChefBear"), 'withoutTurn': False})
    } {
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } {
        ChefBear.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        ChefBear.SetFacialExpression({'expression': 'normal'})
    }

}
