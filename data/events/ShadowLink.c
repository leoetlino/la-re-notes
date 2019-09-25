-------- EventFlow: ShadowLink --------

Actor: ShadowLink
entrypoint: None()
actions: ['PopStart', 'LookAtCharacter', 'AimCompassPoint', 'PlayAnimation', 'PlayTailorOtherChannelEx']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void Appear() {

    fork {
        ShadowLink.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    } {
        ShadowLink.AimCompassPoint({'direction': 0, 'duration': 0.019999999552965164, 'withoutTurn': False})
        Timer.Wait({'time': 0.5})
        ShadowLink.PlayTailorOtherChannelEx({'channel': 'Sign', 'time': 1.25, 'restart': False, 'index': 0})
    }

    ShadowLink.PopStart()
    ShadowLink.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
}

void ShadowLinkEnd() {
    Timer.Wait({'time': 0.5})
    ShadowLink.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    Timer.Wait({'time': 3.0})
}
