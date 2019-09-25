-------- EventFlow: SmallBowWow --------

Actor: SmallBowWow
entrypoint: None()
actions: ['Talk', 'PlayOneshotSE', 'GenericTalkSequence']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        SmallBowWow.Talk({'message': 'Npc:Cancan'})
    } {
        SmallBowWow.PlayOneshotSE({'label': 'SE_MAP_CANCAN_VO1', 'volume': 1.0, 'pitch': 1.0})
    } {
        SmallBowWow.GenericTalkSequence({'playerTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}
