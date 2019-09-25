-------- EventFlow: QuadrupletsMother --------

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

Actor: QuadrupletsMother
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetFacialExpression', 'PlayAnimation']
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

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'RibbonDrop'}) {
        if !Inventory.HasItem({'count': 1, 'itemType': 30}) {

            fork {
                QuadrupletsMother.SetFacialExpression({'expression': 'normal'})
            } {
                QuadrupletsMother.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                QuadrupletsMother.Talk({'message': 'Warashibe:WantYossy'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                QuadrupletsMother.SetFacialExpression({'expression': 'smile'})
            } {
                QuadrupletsMother.Talk({'message': 'Warashibe:QuestYossy'})
            } {
                QuadrupletsMother.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            if !Dialog.GetLastResult() {
                EventFlags.SetFlag({'value': True, 'symbol': 'RibbonDrop'})
                QuadrupletsMother.Talk({'message': 'Warashibe:ClearYossy'})
                Inventory.SetWarashibeItem({'itemType': 2})

                fork {
                    Link.GenericItemGetSequence({'itemType': 31, 'keepCarry': False, 'messageEntry': ''})
                } {
                    QuadrupletsMother.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                }

                QuadrupletsMother.SetFacialExpression({'expression': 'normal'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {
                QuadrupletsMother.SetFacialExpression({'expression': 'worry'})
                QuadrupletsMother.Talk({'message': 'Warashibe:BadYossy'})
                QuadrupletsMother.SetFacialExpression({'expression': 'normal'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        }
    } else
    if !Inventory.HasItem({'itemType': 47, 'count': 1}) {

        fork {
            QuadrupletsMother.SetFacialExpression({'expression': 'normal'})
        } {
            QuadrupletsMother.Talk({'message': 'Npc:4childMamaAfterWarashibe'})
        } {
            QuadrupletsMother.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !EventFlags.CheckFlag({'symbol': 'HibiscusDrop'}) {

        fork {
            QuadrupletsMother.SetFacialExpression({'expression': 'worry'})
        } {
            QuadrupletsMother.Talk({'message': 'SubEvent:Worry4childMama'})
        } {
            QuadrupletsMother.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        QuadrupletsMother.SetFacialExpression({'expression': 'normal'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            QuadrupletsMother.SetFacialExpression({'expression': 'normal'})
        } {
            QuadrupletsMother.Talk({'message': 'Npc:4childMamaAfterWarashibe'})
        } {
            QuadrupletsMother.GenericTalkSequence({'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}
