-------- EventFlow: Christine --------

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Christine
entrypoint: None()
actions: ['Talk', 'SetFacialExpression', 'PlayAnimation', 'GenericTalkSequence', 'LookAtTalkersLinkedPoint']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['SetWarashibeItem', 'AddSecretShell']
queries: ['HasItem']
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

Actor: Item
entrypoint: None()
actions: ['SetActorSwitch']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'LetterDrop'}) {
        if !Inventory.HasItem({'itemType': 37, 'count': 1}) {

            fork {
                Christine.GenericTalkSequence({'keepPersonalSpace': False, 'aimToPlayer': True, 'cameraLookAt': False, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})
            } {
                Christine.LookAtTalkersLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
            } {
                Christine.Talk({'message': 'Warashibe:WantHibiscus'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {
            Item.SetActorSwitch({'switchIndex': 0, 'value': True})
            EventFlags.SetFlag({'symbol': 'HibiscusClear', 'value': True})
            Christine.Talk({'message': 'Warashibe:QuestHibiscus'})
            if !Dialog.GetLastResult() {
                Christine.PlayAnimation({'name': 'please', 'blendTime': 0.10000000149011612})

                fork {
                    Christine.Talk({'message': 'Warashibe:ClearHibiscus'})
                } {
                    Christine.SetFacialExpression({'expression': 'blush'})
                }

                Inventory.SetWarashibeItem({'itemType': 9})
                EventFlags.SetFlag({'symbol': 'LetterDrop', 'value': True})
                Link.GenericItemGetSequence({'itemType': 38, 'keepCarry': False, 'messageEntry': ''})
                Christine.SetFacialExpression({'expression': 'normal'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {
                Christine.SetFacialExpression({'expression': 'normal'})
                Christine.Talk({'message': 'Warashibe:BadHibiscus'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'BroomDrop'}) {
        Event45:

        fork {
            Christine.GenericTalkSequence({'keepPersonalSpace': False, 'aimToPlayer': True, 'cameraLookAt': False, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})
        } {
            Christine.LookAtTalkersLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            Christine.Talk({'message': 'Npc:ChristineAfterWarashibe'})
        } {
            Christine.SetFacialExpression({'expression': 'blush'})
        }

        Christine.SetFacialExpression({'expression': 'normal'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !EventFlags.CheckFlag({'symbol': 'SuruShell'}) {

        fork {
            Christine.GenericTalkSequence({'keepPersonalSpace': False, 'aimToPlayer': True, 'cameraLookAt': False, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})
        } {
            Christine.LookAtTalkersLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            Christine.Talk({'message': 'Npc:ChristineLetter'})
        }

        Inventory.AddSecretShell({'index': 35})

        fork {
            Link.GenericItemGetSequence({'itemType': 23, 'messageEntry': 'Seashell', 'keepCarry': False})
        } {
            Christine.PlayAnimation({'blendTime': 0.0, 'name': 'wait'})
        }

        EventFlags.SetFlag({'symbol': 'SuruShell', 'value': True})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {
        goto Event45
    }
}
