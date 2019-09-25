-------- EventFlow: Moosh --------

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Moosh
entrypoint: None()
actions: ['GenericTalkSequence']
queries: []
params: None

void talk() {
    Moosh.GenericTalkSequence({'aimToPlayer': False, 'aimFromPlayer': True, 'selfTalkAnim': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Dialog.Show({'message': 'Npc:Animals'})
}
