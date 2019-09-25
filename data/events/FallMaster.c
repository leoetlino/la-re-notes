-------- EventFlow: FallMaster --------

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestRestartWarp']
queries: []
params: None

Actor: FallMaster
entrypoint: None()
actions: ['PopStart', 'LookAtCharacter', 'LookAtFallMasterShadow']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset']
queries: []
params: None

void FM_Smashed() {
    Timer.Wait({'time': 1.0})
    Fade.StartPreset({'preset': 1})
    GameControl.RequestRestartWarp({'locator': 'FallMasterRestart', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void Appear() {
    FallMaster.LookAtFallMasterShadow({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967})
    Timer.Wait({'time': 1.0})
    FallMaster.PopStart()
}

void FM_End() {
    FallMaster.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    Timer.Wait({'time': 3.0})
    Camera.Reset({'chaseRatio': 0.10000000149011612})
}
