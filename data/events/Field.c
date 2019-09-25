-------- EventFlow: Field --------

Actor: Ghost[companion]
entrypoint: None()
actions: ['Talk', 'Destroy', 'MoveToTargetLinkedPoint', 'AimPlayer', 'PlayAnimation', 'SetFacialExpression', 'PlayMaterialAnimation']
queries: []
params: None

Actor: Character[companion]
entrypoint: None()
actions: ['PlayAnimation', 'WarpToActorWithCompassPoint']
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

Actor: Link
entrypoint: None()
actions: ['LeaveCompanion', 'PlayAnimation', 'LookAtTalker', 'PlayAnimationEx', 'MoveToCompassPoint', 'MoveToTargetActor', 'SetEquipmentVisibility', 'MoveToTargetLinkedPoint', 'GenericItemGetSequence', 'AimCompassPoint', 'ResetAim', 'SetDisablePowerUpEffect', 'WarpToActorWithCompassPoint', 'CancelCarry', 'ClearPowerUp', 'AimDegreeAngle', 'PlayCarryingMotion']
queries: []
params: None

Actor: EventTriggerTag
entrypoint: None()
actions: []
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestWarp', 'RequestLevelJump', 'RequestAutoSave']
queries: []
params: None

Actor: WarpUI
entrypoint: None()
actions: ['Show', 'JumpToSelectedLocation']
queries: ['GetResult']
params: None

Actor: WarpHoleEventBox[WarpHole]
entrypoint: None()
actions: []
queries: []
params: None

Actor: WarpHoleEventBox
entrypoint: None()
actions: ['PlayTailorOtherChannelEx']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopZoneAudio', 'StopAllBGM', 'PlayOneshotSystemSE']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddBottle']
queries: []
params: None

Actor: RapidflowGame
entrypoint: None()
actions: ['CancelGame']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: FlyingCucco
entrypoint: None()
actions: []
queries: ['IsCarried']
params: None

void GhostHouseApproach() {
    Ghost[companion].Talk({'message': 'Scenario:Lv5GhostNearHouse'})
    EventFlags.SetFlag({'symbol': 'Ghost2_Clear', 'value': True})
    Ghost[companion].SetFacialExpression({'expression': 'normal'})
}

void Graveyard_talk() {
    Link.ClearPowerUp()

    fork {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    } {
        Link.CancelCarry()
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'Ghost4_Clear'})
    Link.MoveToTargetLinkedPoint({'speed': 0, 'index': 1, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    Link.AimDegreeAngle({'angle': -155.0, 'duration': 0.5, 'withoutTurn': False})
    Ghost[companion].MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    Ghost[companion].AimPlayer({'duration': 2.0, 'withoutTurn': False, 'boneName': ''})

    fork {
        Ghost[companion].PlayAnimation({'name': 'happy', 'blendTime': 0.30000001192092896})
    } {
        Timer.Wait({'time': 1.0})
        Ghost[companion].Talk({'message': 'Scenario:Lv5GhostByebye'})
    } {
        Ghost[companion].SetFacialExpression({'expression': 'happy'})
    }


    fork {
        Timer.Wait({'time': 6.0})
    } {
        Ghost[companion].PlayMaterialAnimation({'name': 'fade'})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_ENV_GHOST_DEPOP', 'volume': 1.0, 'pitch': 1.0})
    }

    Ghost[companion].Destroy()
    Inventory.AddBottle({'index': 0})
    Link.GenericItemGetSequence({'messageEntry': 'Bottle', 'itemType': 64, 'keepCarry': False})
    Link.LeaveCompanion()
}

void Egg_Performance() {

    fork {
        Link.PlayAnimation({'name': '', 'blendTime': 0.10000000149011612})
    } {
        Link.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    EventFlags.SetFlag({'symbol': 'Egg_Performance', 'value': True})
}

void WarpOut() {
    Link.PlayAnimation({'name': 'warp_st', 'blendTime': 0.10000000149011612})
    Link.PlayAnimationEx({'time': 0.0, 'blendTime': 0.0, 'name': 'warp_lp'})
    GameControl.RequestWarp({'locator': 'locator', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void FieldWarpOut() {
    Link.MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole"), 'timeOut': 7.0})
    Timer.Wait({'time': 0.25})
    WarpUI.Show()
    if !WarpUI.GetResult() {
        Link.MoveToCompassPoint({'direction': 0, 'distance': 2.0, 'speed': 1, 'timeOut': 7.0})
    } else {

        call FieldWarpOut_Base()

    }
}

void FallOutAnt() {

    fork {
        Link.PlayAnimation({'name': 'fall_antlion', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.75})
        Fade.StartPreset({'preset': 9})
        GameControl.RequestLevelJump({'level': 'LanmolaCave', 'locator': 'LanmolaCave_02A', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    }

}

void cape_talk2() {

    fork {
        Fade.StartPreset({'preset': 11})
    } {
        Audio.StopAllBGM({'duration': 2.0})
    }

    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    GameControl.RequestLevelJump({'level': 'EventMarin02', 'locator': 'EventMarin02', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void FieldWarpOut_Companion() {
    Link.MoveToTargetActor({'distance': 0.0, 'speed': 0, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole"), 'timeOut': 7.0})
    Timer.Wait({'time': 0.25})
    WarpUI.Show()
    if !WarpUI.GetResult() {
        Link.MoveToCompassPoint({'direction': 0, 'distance': 2.0, 'speed': 1, 'timeOut': 7.0})
    } else {

        call FieldWarpOut_Comp_Base()

    }
}

void FieldWarpOut_Ghost() {

    call FieldWarpOut()

}

void FieldWarpOut_Base() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Link.WarpToActorWithCompassPoint({'direction': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole"), 'offsetY': 0.0})

    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_st'})
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_lp'})
    } {
        Timer.Wait({'time': 2.25})
        WarpHoleEventBox.PlayTailorOtherChannelEx({'channel': 'WarpHole_Go_00', 'time': 0.10000000149011612, 'restart': False, 'index': 0})
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
        } {
            Audio.StopZoneAudio()
        }

    }

    RapidflowGame.CancelGame()
    WarpUI.JumpToSelectedLocation()
    GameControl.RequestAutoSave()
}

void FieldWarpOutWait() {
    Link.MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole"), 'timeOut': 7.0})
    Timer.Wait({'time': 0.25})
    WarpUI.Show()
    if WarpUI.GetResult() {

        call FieldWarpOut_Base()

    }
}

void FieldWarpOut_Comp_Base() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Link.WarpToActorWithCompassPoint({'direction': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole"), 'offsetY': 0.0})
    } {
        if !FlyingCucco.IsCarried() {
            Character[companion].WarpToActorWithCompassPoint({'direction': 0, 'offsetY': 0.0, 'distance': -1.25, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole")})
        }
    }


    fork {
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_st'})
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_lp'})
    } {
        Link.PlayCarryingMotion()
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_st'})
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_lp'})
    } {
        Timer.Wait({'time': 2.25})
        WarpHoleEventBox.PlayTailorOtherChannelEx({'channel': 'WarpHole_Go_00', 'time': 0.10000000149011612, 'restart': False, 'index': 0})
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
        } {
            Audio.StopZoneAudio()
        }

    }

    WarpUI.JumpToSelectedLocation()
    GameControl.RequestAutoSave()
}

void FieldWarpOutWait_Companion() {
    Link.MoveToTargetActor({'distance': 0.0, 'speed': 0, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole"), 'timeOut': 7.0})
    Timer.Wait({'time': 0.25})
    WarpUI.Show()
    if WarpUI.GetResult() {

        call FieldWarpOut_Comp_Base()

    }
}

void FieldWarpOutReturn() {

    call FieldWarpOutReturn_Base()

    Link.MoveToCompassPoint({'direction': 0, 'speed': 1, 'distance': 2.75, 'timeOut': 7.0})
}

void FieldWarpOutReturn_Base() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Link.MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole"), 'timeOut': 7.0})
    Link.AimCompassPoint({'duration': 0.10000000149011612, 'direction': 0, 'withoutTurn': False})
    Link.ResetAim()

    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_st'})
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_lp'})
        Link.AimCompassPoint({'duration': 0.10000000149011612, 'direction': 0, 'withoutTurn': False})
        Link.ResetAim()
    } {
        Timer.Wait({'time': 2.25})
        WarpHoleEventBox.PlayTailorOtherChannelEx({'channel': 'WarpHole_Go_00', 'time': 0.10000000149011612, 'restart': False, 'index': 0})
        Timer.Wait({'time': 1.0})
    }

    Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_ed'})
    Link.SetDisablePowerUpEffect({'effect': False, 'sound': False, 'materialAnim': False})
    GameControl.RequestAutoSave()
}

void FieldWarpOutReturnWait() {

    call FieldWarpOutReturn_Base()

}

void FirstWarp() {
    Link.CancelCarry()
    Dialog.Show({'message': 'System:WarpPedestalActivate'})
}

void FirstOcarinaWarp() {
    Link.CancelCarry()
    Dialog.Show({'message': 'System:WarpPointActivate'})
}

void FieldWarpOutReturn_BowWow() {

    call FieldWarpOutReturn_Comp_Base()

    Link.MoveToCompassPoint({'direction': 0, 'speed': 1, 'distance': 2.75, 'timeOut': 7.0})
}

void FieldWarpOutReturnWait_BowWow() {

    call FieldWarpOutReturn_Comp_Base()

}

void FieldWarpOutReturn_Comp_Base() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Link.MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole"), 'timeOut': 7.0})
    Link.AimCompassPoint({'duration': 0.10000000149011612, 'direction': 0, 'withoutTurn': False})
    Link.ResetAim()

    fork {
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_st'})
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_lp'})
    } {
        Link.PlayCarryingMotion()
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_st'})
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_lp'})
        Link.AimCompassPoint({'duration': 0.10000000149011612, 'direction': 0, 'withoutTurn': False})
        Link.ResetAim()
    } {
        Timer.Wait({'time': 2.25})
        WarpHoleEventBox.PlayTailorOtherChannelEx({'channel': 'WarpHole_Go_00', 'time': 0.10000000149011612, 'restart': False, 'index': 0})
        Timer.Wait({'time': 1.0})
    }

    if FlyingCucco.IsCarried() {
        Link.CancelCarry()
    }
    Character[companion].WarpToActorWithCompassPoint({'direction': 0, 'offsetY': 0.0, 'distance': -1.25, 'actor': ActorIdentifier(name="WarpHoleEventBox", sub_name="WarpHole")})

    fork {
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_ed'})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_ed'})
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'sound': False, 'materialAnim': False})
    GameControl.RequestAutoSave()
}

void FieldWarpOutReturn_FlyingCucco() {
    if !FlyingCucco.IsCarried() {

        call FieldWarpOutReturn_Base()

    } else {

        call FieldWarpOutReturn_Comp_Base()

    }
    Link.MoveToCompassPoint({'direction': 0, 'speed': 1, 'distance': 2.75, 'timeOut': 7.0})
}

void FieldWarpOutReturnWait_FlyingCucco() {
    if !FlyingCucco.IsCarried() {

        call FieldWarpOutReturn_Base()

    } else {

        call FieldWarpOutReturn_Comp_Base()

    }
}

void FieldWarpOutWait_Ghost() {

    call FieldWarpOutWait()

}
