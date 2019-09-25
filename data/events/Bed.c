-------- EventFlow: Bed --------

Actor: Bed[EventBed]
entrypoint: None()
actions: ['PlayAnimation', 'PlayAnimationEx']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['AimCompassPoint', 'PlayAnimation', 'PlayAnimationEx', 'MoveToTargetLinkedPoint', 'ResetAim', 'SetEquipmentVisibility', 'SetFacialExpression']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartParam']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

void BedRoomExamine() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Link.MoveToTargetLinkedPoint({'speed': 0, 'index': 0, 'actor': ActorIdentifier(name="Bed", sub_name="EventBed"), 'timeOut': 7.0})
    Link.AimCompassPoint({'direction': 1, 'duration': 0.4000000059604645, 'withoutTurn': False})

    fork {
        Link.PlayAnimation({'name': 'sleep_st', 'blendTime': 0.10000000149011612})

        fork {
            Link.SetFacialExpression({'expression': 'dream'})
        } {
            Link.PlayAnimationEx({'name': 'sleep_lp', 'time': 0.0, 'blendTime': 0.0})
        }

    } {
        Bed[EventBed].PlayAnimation({'name': 'ftn_sleep_st', 'blendTime': 0.10000000149011612})
        Bed[EventBed].PlayAnimationEx({'name': 'ftn_sleep_lp', 'time': 0.0, 'blendTime': 0.0})
    } {
        Audio.StopAllBGM({'duration': 1.0})
        Timer.Wait({'time': 1.600000023841858})
        Audio.PlayBGM({'label': 'BGM_DREAMSHRINE_BEDIN', 'volume': 1.0})
    }

    Link.ResetAim()

    fork {
        Fade.StartParam({'mode': 1, 'time': 1.7999999523162842, 'colorR': 1.0, 'colorG': 1.0, 'colorB': 1.0})
        Timer.Wait({'time': 4.5})
    } {
        EventFlags.SetFlag({'symbol': 'BedRoomLamp1', 'value': False})
        Timer.Wait({'time': 0.5})
        EventFlags.SetFlag({'value': False, 'symbol': 'BedRoomLamp2'})
        Timer.Wait({'time': 0.5})
        EventFlags.SetFlag({'value': False, 'symbol': 'BedRoomLamp3'})
        Timer.Wait({'time': 0.5})
        EventFlags.SetFlag({'value': False, 'symbol': 'BedRoomLamp4'})
        Timer.Wait({'time': 0.5})
    }


    fork {
        GameControl.RequestLevelJump({'level': 'DreamShrine', 'locator': 'DreamShrine_02A', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Link.SetFacialExpression({'expression': 'normal'})
    }

}
