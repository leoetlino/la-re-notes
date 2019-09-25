-------- EventFlow: GoldenLeaf --------

Actor: GoldenLeaf
entrypoint: None()
actions: ['Fall', 'GenericGimmickSequence', 'Activate', 'Deactivate', 'Destroy', 'PlayOneshotSE']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddGoldenLeaf']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle']
queries: []
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

void take() {
    GoldenLeaf.Deactivate()
    Link.GenericItemGetSequence({'itemType': 24, 'keepCarry': False, 'messageEntry': ''})
    Inventory.AddGoldenLeaf({'index': 'index'})
    GoldenLeaf.Destroy()
}

void pop() {
    GoldenLeaf.GenericGimmickSequence({'cameraLookAt': True, 'distanceOffset': 0.0})
    GoldenLeaf.Activate()
    GoldenLeaf.PlayOneshotSE({'label': 'SE_SY_NAZOKAGI_DROP', 'volume': 1.0, 'pitch': 1.0})
    GoldenLeaf.Fall()
    Timer.Wait({'time': 3.0})
    Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
}
