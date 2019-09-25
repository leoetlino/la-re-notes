-------- EventFlow: GrandpaUlrira --------

Actor: GrandpaUlrira
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
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
        GrandpaUlrira.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        GrandpaUlrira.Talk({'message': 'Npc:Ulrira'})
    }

    Dialog.Show({'message': 'Npc:Ulrira_2'})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}
