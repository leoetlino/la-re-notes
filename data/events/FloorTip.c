-------- EventFlow: FloorTip --------

Actor: FloorTip[FloorTip]
entrypoint: None()
actions: ['PlayTailorOtherChannelNoWait']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: FloorTip
entrypoint: None()
actions: ['LookAtInfomation', 'SetModelVisibility']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingleTimeWait']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void FloorTipOpen() {
    FloorTip.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    Timer.Wait({'time': 1.0})
    FloorTip[FloorTip].PlayTailorOtherChannelNoWait({'restart': False, 'channel': 'Hide', 'index': 0})
    Timer.Wait({'time': 0.10000000149011612})
    FloorTip.SetModelVisibility({'visible': False})
    Timer.Wait({'time': 1.0})
    Audio.PlayJingleTimeWait({'label': 'BGM_NAZOTOKI_SEIKAI', 'duration': 1.6799999475479126, 'volume': 1.0})
    GameControl.RequestAutoSave()
}

void FloorTipOpenNoEffect() {
    FloorTip.SetModelVisibility({'visible': False})
    Timer.Wait({'time': 0.20000000298023224})
    FloorTip.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    Timer.Wait({'time': 0.5})
    Audio.PlayJingleTimeWait({'label': 'BGM_NAZOTOKI_SEIKAI', 'duration': 1.6799999475479126, 'volume': 1.0})
    GameControl.RequestAutoSave()
}

void FloorTipOpenNoEffectForPanel() {
    FloorTip.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    Timer.Wait({'time': 1.0})
    FloorTip.SetModelVisibility({'visible': False})
    Timer.Wait({'time': 1.0})
    Audio.PlayJingleTimeWait({'label': 'BGM_NAZOTOKI_SEIKAI', 'duration': 1.6799999475479126, 'volume': 1.0})
    GameControl.RequestAutoSave()
}
