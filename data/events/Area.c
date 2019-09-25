-------- EventFlow: Area --------

Actor: Marin[companion]
entrypoint: None()
actions: ['AimPlayer']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveToCompassPoint', 'PlayAnimation', 'MoveToTargetActor', 'SetGravityEnable', 'ResetVelocity', 'SetEquipmentVisibility', 'MoveLadder', 'AimCompassPoint', 'LookAtCharacter', 'SetFacialExpression', 'CancelCarry', 'ClearPowerUp', 'SetNpcFilter']
queries: ['IsPinch']
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump', 'RequestRestartWarp', 'RequestWarp']
queries: []
params: None

Actor: Area
entrypoint: None()
actions: []
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: []
queries: ['CompareString']
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

Actor: Ghost[companion]
entrypoint: None()
actions: ['SetFacialExpression', 'AimPlayer', 'Talk', 'PlayAnimation']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopZoneAudio', 'StopAllBGM', 'SetSeVolume']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Marin
entrypoint: None()
actions: ['Talk', 'SetFacialExpression', 'PlayAnimation']
queries: []
params: None

Actor: PanelDungeon
entrypoint: None()
actions: ['ShowRetireUi', 'Retire']
queries: ['CheckRetireResult']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: FlyingCucco
entrypoint: None()
actions: []
queries: ['IsCarried']
params: None

Actor: Character[companion]
entrypoint: None()
actions: ['PlayAnimation']
queries: []
params: None

void DefaultLevelOpen() {

    call FadeBGMAllOff()

}

void RunOut() {

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'speed': 0, 'distance': 1.0, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    }

}

void WalkIn() {

    fork {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 2.0, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    }

}

void WalkOut() {

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 0, 'distance': 3.0, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    }

}

void RunIn() {

    fork {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 2.0, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    }

}

void FallIn() {
    Audio.SetSeVolume({'label': 'SE_AMB_SAND_STREAM', 'duration': 0.5, 'volume': 1.0})

    fork {
        Link.PlayAnimation({'name': 'fall_antlion', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 5})
            GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
        } {
            Audio.StopZoneAudio()
        }

    }

}

void DeathBallVacuum_Warp() {

    fork {
        Link.PlayAnimation({'name': 'fall_deathball', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.5})
        Fade.StartPreset({'preset': 5})
        Link.ClearPowerUp()
        GameControl.RequestRestartWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    }

}

void DefaultDownStairsLvJump() {
    Link.SetNpcFilter({'enable': False})

    fork {
        Link.MoveToTargetActor({'actor': ActorIdentifier(name="Area"), 'speed': 0, 'distance': 0.0, 'timeOut': 7.0})
    } {

        fork {
            Fade.StartPreset({'preset': 9})
            Link.CancelCarry()
            GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
        } {
            Audio.StopZoneAudio()
        }

    }

}

void DefaultUpStairsLvJump() {
    Link.SetNpcFilter({'enable': False})

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': -5.0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
            Link.CancelCarry()
            GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
        } {
            Audio.StopZoneAudio()
        } {
            Audio.StopAllBGM({'duration': 0.10000000149011612})
        }

    }

}

void FallToLowerLevel() {

    fork {
        Link.SetGravityEnable({'enable': False})
        Link.ResetVelocity()
    } {

        fork {
            Fade.StartPreset({'preset': 9})
        } {
            Audio.StopZoneAudio()
        }

    }

    if !FlowControl.CompareString({'value1': 'levelName', 'value2': ''}) {
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 'offsetX', 'offsetZ': 'offsetZ'})
    } else {
        GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 'offsetX', 'offsetZ': 'offsetZ'})
    }
}

void FallToLowerLevelTopToSideOffset() {

    call FallToLowerLevel({'offsetZ': 0.0, 'levelName': 'levelName', 'locator': 'locator', 'offsetX': 'offsetZ'})

}

void DefaultDownDigStairsLvJump() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': -0.10000000149011612, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.5})

        call FadeBGMAllOff()

    }

}

void DefaultUpDigStairsLvJump() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': -0.10000000149011612, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.5})

        call FadeBGMAllOff()

    }

}

void WaterTopIn() {
    Link.CancelCarry()
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})
    Link.MoveToTargetActor({'distance': 0.0, 'speed': 2, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})

    fork {
        Link.PlayAnimation({'name': 'u_swim_depth_in', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.5})

        call FadeBGMAllOff()

    }

}

void WaterSideIn() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 5, 'distance': 3.0, 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.5})

        call FadeBGMAllOff()

    }

}

void WaitIn() {

    call FadeBGMAllOff()

}

void DungeonOut() {

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 0, 'distance': 1.5, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    }

}

void WaterSideInRight() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'distance': 3.0, 'direction': 1, 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.5})

        call FadeBGMAllOff()

    }

}

void WaterTopInSwim() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

    fork {
        Link.MoveToTargetActor({'distance': 0.0, 'speed': 0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.25})

        call FadeBGMAllOff()

    }

}

void DungeonOutShort() {

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 0, 'distance': 0.699999988079071, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    }

}

void LadderUp() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Link.MoveLadder({'mode': 1, 'distance': 3.0})
    } {

        call FadeBGMAllOff()

    }

}

void LadderDown() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Link.MoveLadder({'mode': 2, 'distance': 3.0})
    } {

        call FadeBGMAllOff()

    }

}

void WaterSideInLeft() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'distance': 3.0, 'direction': 3, 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.5})

        call FadeBGMAllOff()

    }

}

void FallInCameraSet1() {

    fork {
        Fade.StartPreset({'preset': 5})
    } {
        Audio.StopZoneAudio()
    }

    GameControl.RequestLevelJump({'level': 'TownWell', 'locator': 'TownWell_01A', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void FallInCameraSet2() {

    fork {
        Fade.StartPreset({'preset': 5})
    } {
        Audio.StopZoneAudio()
    }

    GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void LevelDungeonIn_Ghost() {

    fork {
        Ghost[companion].SetFacialExpression({'expression': 'worry'})
    } {
        Ghost[companion].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Ghost[companion].PlayAnimation({'name': 'cry', 'blendTime': 0.10000000149011612})
    }

    Ghost[companion].Talk({'message': 'Scenario:Lv5GhostNoDungeon'})
    Link.MoveToCompassPoint({'speed': 0, 'direction': 0, 'distance': 1.5, 'timeOut': 7.0})
}

void LevelDungeonIn() {

    fork {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 2.0, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    }

}

void levelDownStairsJump() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="Area"), 'distance': 0.0, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    }

}

void levelDownStairsJump_Ghost() {

    fork {
        Ghost[companion].SetFacialExpression({'expression': 'worry'})
    } {
        Ghost[companion].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Ghost[companion].PlayAnimation({'name': 'cry', 'blendTime': 0.10000000149011612})
    }

    Ghost[companion].Talk({'message': 'Scenario:Lv5GhostNoDungeon'})
    Link.MoveToCompassPoint({'speed': 0, 'direction': 0, 'distance': 1.5, 'timeOut': 7.0})
}

void FallToLowerLevelContinueBGM() {

    fork {
        Link.SetGravityEnable({'enable': False})
        Link.ResetVelocity()
    } {
        Fade.StartPreset({'preset': 9})
    }

    if !FlowControl.CompareString({'value1': 'levelName', 'value2': ''}) {
        GameControl.RequestWarp({'locator': 'locator', 'offsetX': 'offsetX', 'offsetZ': 'offsetZ'})
    } else {
        GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 'offsetX', 'offsetZ': 'offsetZ'})
    }
}

void ShieldSteal() {
    Link.CancelCarry()

    fork {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    } {
        Link.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    } {
        Timer.Wait({'time': 0.4000000059604645})

        fork {
            Timer.Wait({'time': 0.30000001192092896})
            Dialog.Show({'message': 'SubEvent:LifeLikeSteal'})
            Link.SetFacialExpression({'expression': 'normal'})
        } {
            Link.PlayAnimation({'name': 'shield_nothing', 'blendTime': 0.10000000149011612})
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }

    }

}

void LevelDungeonIn_Marin() {
    if !Link.IsPinch() {
        EventFlags.SetFlag({'value': False, 'symbol': 'DamageMarinCheck'})
    } else {
        EventFlags.SetFlag({'value': True, 'symbol': 'DamageMarinCheck'})
    }

    fork {
        Marin.SetFacialExpression({'expression': 'worry'})
    } {
        Marin[companion].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Marin.Talk({'message': 'SubEvent:MarineAwaitDungeon'})
    } {
        Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 2.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
        GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Marin.SetFacialExpression({'expression': 'normal'})
    }

}

void DungeonIn_Lv7() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="Area"), 'distance': -3.0, 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.75})

        call FadeBGMAllOff()

    }

}

void DungeonOutWhite() {

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 0, 'distance': 1.5, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 11})
        GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    }

}

void PanelRetire() {
    PanelDungeon.ShowRetireUi()
    if !PanelDungeon.CheckRetireResult() {

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'speed': 0, 'distance': 1.5, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 9})
            PanelDungeon.Retire()
        } {
            Audio.StopZoneAudio()
        } {
            Audio.StopAllBGM({'duration': 1.0})
        }

    } else {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.75, 'timeOut': 7.0})
    }
}

void PanelRetireLv10() {
    PanelDungeon.ShowRetireUi()
    if !PanelDungeon.CheckRetireResult() {

        fork {
            Link.MoveToCompassPoint({'speed': 0, 'direction': 1, 'distance': 5.0, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 9})
            PanelDungeon.Retire()
        } {
            Audio.StopZoneAudio()
        } {
            Audio.StopAllBGM({'duration': 1.0})
        }

    } else {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 3, 'distance': 0.75, 'timeOut': 7.0})
    }
}

void FadeBGMAllOff() {

    fork {
        Fade.StartPreset({'preset': 9})
        GameControl.RequestLevelJump({'level': 'levelName', 'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

}

void levelDownStairsJump_Marin() {
    if !Link.IsPinch() {
        EventFlags.SetFlag({'value': False, 'symbol': 'DamageMarinCheck'})
    } else {
        EventFlags.SetFlag({'value': True, 'symbol': 'DamageMarinCheck'})
    }

    fork {
        Marin.SetFacialExpression({'expression': 'worry'})
    } {
        Marin[companion].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Marin.Talk({'message': 'SubEvent:MarineAwaitDungeon'})
    } {
        Marin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="Area"), 'distance': 0.0, 'timeOut': 7.0})
    } {

        call FadeBGMAllOff()

    } {
        Marin.SetFacialExpression({'expression': 'normal'})
    }

}

void WaterTopInSwim_Bridge() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})
    if !FlyingCucco.IsCarried() {
        Link.CancelCarry()

        fork {
            Link.MoveToTargetActor({'distance': 0.0, 'speed': 0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
        } {
            Timer.Wait({'time': 0.25})

            call FadeBGMAllOff()

        }

    } else {
        Link.CancelCarry()

        fork {
            Link.MoveToTargetActor({'distance': 0.0, 'speed': 0, 'actor': ActorIdentifier(name="Area"), 'timeOut': 7.0})
        } {
            Timer.Wait({'time': 0.25})

            call FadeBGMAllOff()

        } {
            Character[companion].PlayAnimation({'name': 'land', 'blendTime': 0.10000000149011612})
        }

    }
}

void DungeonIn_Lv7_Ghost() {

    fork {
        Ghost[companion].SetFacialExpression({'expression': 'worry'})
    } {
        Ghost[companion].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Ghost[companion].PlayAnimation({'name': 'cry', 'blendTime': 0.10000000149011612})
    }

    Ghost[companion].Talk({'message': 'Scenario:Lv5GhostNoDungeon'})
    Link.MoveToCompassPoint({'speed': 0, 'direction': 0, 'distance': 1.5, 'timeOut': 7.0})
}
