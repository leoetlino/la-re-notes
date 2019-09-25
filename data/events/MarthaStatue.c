-------- EventFlow: MarthaStatue --------

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: MarthaStatue
entrypoint: None()
actions: ['PutMermaidScale', 'SetActorSwitch', 'SlideMove', 'LookAtCharacter', 'PlayOneshotSE', 'PlayTailorOtherChannelNoWait', 'StopTailorOtherChannel', 'GenericExamineSequence']
queries: ['CheckActorSwitch']
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

Actor: Link
entrypoint: None()
actions: ['PlayAnimation', 'SetEquipmentVisibility', 'SetDisablePowerUpEffect']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void examine() {
    if !MarthaStatue.CheckActorSwitch({'switchIndex': 0}) {
        if !Inventory.HasItem({'itemType': 43, 'count': 1}) {

            fork {
                Dialog.Show({'message': 'System:CheckMermaidFigure'})
            } {
                MarthaStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

        } else {
            Link.SetDisablePowerUpEffect({'sound': True, 'effect': True, 'materialAnim': True})
            MarthaStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            MarthaStatue.SetActorSwitch({'switchIndex': 0, 'value': True})
            MarthaStatue.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})

            fork {
                MarthaStatue.PutMermaidScale()
            } {
                Link.PlayAnimation({'name': 'ev_set', 'blendTime': 0.10000000149011612})
            } {
                Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
            } {
                MarthaStatue.PlayOneshotSE({'label': 'SE_MAP_OWL_BEAK_SET', 'volume': 1.0, 'pitch': 1.0})
            }

            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            Dialog.Show({'message': 'Warashibe:QuestScale'})
            Timer.Wait({'time': 1.0})

            fork {
                MarthaStatue.SlideMove({'speed': 1.0})
            } {
                Audio.PlayJingle({'label': 'SE_MAP_BLOCK_SLIDE_DIRT', 'volume': 1.0})
            } {
                MarthaStatue.PlayTailorOtherChannelNoWait({'channel': 'Move', 'restart': False, 'index': 0})
            }

            MarthaStatue.StopTailorOtherChannel({'channel': 'Move', 'index': 0})
            Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
            Timer.Wait({'time': 0.30000001192092896})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            EventFlags.SetFlag({'symbol': 'MarthaStatueOpened', 'value': True})
            Link.SetDisablePowerUpEffect({'effect': False, 'sound': False, 'materialAnim': False})
            GameControl.RequestAutoSave()
        }
    } else {

        fork {
            Dialog.Show({'message': 'System:CheckMermaidFigure2'})
        } {
            MarthaStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

    }
}
