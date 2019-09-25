-------- EventFlow: Toucan --------

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Toucan
entrypoint: None()
actions: ['GenericTalkSequence']
queries: []
params: None

void talk() {
    Toucan.GenericTalkSequence({'aimToPlayer': False, 'selfTalkAnim': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Dialog.Show({'message': 'Npc:Animals'})
}
