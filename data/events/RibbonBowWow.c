-------- EventFlow: RibbonBowWow --------

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

Actor: RibbonBowWow
entrypoint: None()
actions: ['Talk', 'TalkKeep', 'GenericTalkSequence', 'PlayOneshotSE', 'ShowRibbon']
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

Actor: Audio
entrypoint: None()
actions: ['PlayOneshotSystemSE']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'DogfoodDrop'}) {
        if !Inventory.HasItem({'count': 1, 'itemType': 31}) {

            fork {
                RibbonBowWow.Talk({'message': 'Warashibe:WantRibbon'})
            } {
                RibbonBowWow.PlayOneshotSE({'label': 'SE_MAP_CANCAN_VO1', 'volume': 1.0, 'pitch': 1.0})
            } {
                RibbonBowWow.GenericTalkSequence({'selfTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                RibbonBowWow.PlayOneshotSE({'label': 'SE_MAP_CANCAN_VO1', 'volume': 1.0, 'pitch': 1.0})
            } {
                RibbonBowWow.TalkKeep({'message': 'Warashibe:QuestRibbon1'})
            } {
                RibbonBowWow.GenericTalkSequence({'selfTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            RibbonBowWow.Talk({'message': 'Warashibe:QuestRibbon2'})
            if !Dialog.GetLastResult() {
                EventFlags.SetFlag({'value': True, 'symbol': 'DogfoodDrop'})

                fork {
                    RibbonBowWow.Talk({'message': 'Warashibe:ClearRibbon'})
                } {
                    RibbonBowWow.ShowRibbon()
                } {
                    Audio.PlayOneshotSystemSE({'label': 'SE_MAP_CANCAN_RIBBON', 'volume': 1.0, 'pitch': 1.0})
                }

                Inventory.SetWarashibeItem({'itemType': 3})
                Link.GenericItemGetSequence({'itemType': 32, 'keepCarry': False, 'messageEntry': ''})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {
                RibbonBowWow.Talk({'message': 'Warashibe:BadRibbon'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        }
    } else {

        fork {
            RibbonBowWow.Talk({'message': 'Npc:Cancan'})
        } {
            RibbonBowWow.PlayOneshotSE({'label': 'SE_MAP_CANCAN_VO1', 'volume': 1.0, 'pitch': 1.0})
        } {
            RibbonBowWow.GenericTalkSequence({'selfTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}
