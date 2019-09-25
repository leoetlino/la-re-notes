-------- EventFlow: Stairs --------

Actor: GameControl
entrypoint: None()
actions: ['RequestWarp']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveToTargetActor', 'MoveLadder', 'SetEquipmentVisibility', 'MoveToCompassPoint', 'PlayAnimation', 'CancelCarry', 'AimCompassPoint', 'SetNpcFilter']
queries: []
params: None

Actor: Area
entrypoint: None()
actions: []
queries: []
params: None

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

Actor: EventFlags
entrypoint: None()
actions: []
queries: ['CheckFlag']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopZoneAudio']
queries: []
params: None

void DefaultDownStairs() {
    Link.SetNpcFilter({'enable': False})

    fork {
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="Area"), 'distance': 0.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
        Link.CancelCarry()
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    }

}

void DefaultUpStairs() {
    Link.SetNpcFilter({'enable': False})

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': -5.0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
            Link.CancelCarry()
            GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
        } {
            Audio.StopZoneAudio()
        }

    }

}

void Fall() {
    GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void LadderUp() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Link.MoveLadder({'mode': 1, 'distance': 3.0})
    } {
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
            GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
        } {
            Audio.StopZoneAudio()
        }

    }

}

void LadderDown() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Link.MoveLadder({'mode': 2, 'distance': 3.0})
    } {
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
            GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
        } {
            Audio.StopZoneAudio()
        }

    }

}

void DefaultDownDigStairs() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
        Link.CancelCarry()
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    }

}

void DefaultUpDigStairs() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="Area"), 'distance': 0.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
        Link.CancelCarry()
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    }

}

void DefaultFadeStairs() {
    Fade.StartPreset({'preset': 9})
    GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void WaterTopIn() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})
    Link.MoveToTargetActor({'distance': 0.0, 'speed': 2, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})

    fork {
        Link.PlayAnimation({'name': 'u_swim_depth_in', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
            GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
        } {
            Audio.StopZoneAudio()
        }

    }

}

void WaterSideIn() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

    fork {
        Link.MoveToCompassPoint({'direction': 5, 'speed': 0, 'distance': 1.5, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    }

}

void RunScrollWhiteLv09() {

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 'direction', 'distance': 1.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 5})
        GameControl.RequestWarp({'locator': 'Lv09WindFishsEgg_07C', 'offsetX': 0.0, 'offsetZ': 0.0})
    }

}

void Lv704C_UpStairs() {
    if !EventFlags.CheckFlag({'symbol': 'TowerPillarBrokenAll'}) {

        call DefaultUpStairsContinueBGM({'locator': 'locator'})

    } else {

        call DefaultUpStairsContinueBGM({'locator': 'Lv07EagleTower_04G'})

    }
}

void DefaultDownDigStairsContinueBGM() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
        Link.CancelCarry()
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    }

}

void DefaultUpDigStairsContinueBGM() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
        Link.CancelCarry()
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    }

}

void DefaultDownStairsContinueBGM() {
    Link.SetNpcFilter({'enable': False})

    fork {
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="Area"), 'distance': 0.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
        Link.CancelCarry()
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    }

}

void DefaultUpStairsContinueBGM() {
    Link.SetNpcFilter({'enable': False})

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': -5.0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.5})
        Fade.StartPreset({'preset': 9})
        Link.CancelCarry()
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    }

}

void Companion_Join() {
}

void DownDigStairsInLv7() {

    fork {
        Link.AimCompassPoint({'direction': 2, 'duration': 0.10000000149011612, 'withoutTurn': False})
        Link.PlayAnimation({'name': 'ev_stairs_down', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 1.0})
        Fade.StartPreset({'preset': 9})
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    }

}

void RunScrollLv06() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 5})
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    }

}
