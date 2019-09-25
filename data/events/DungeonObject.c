-------- EventFlow: DungeonObject --------

Actor: Door[oppositeSideDoor]
entrypoint: None()
actions: ['PlayAnimation', 'PlayAnimationEx']
queries: []
params: None

Actor: Door[frontSideDoor]
entrypoint: None()
actions: ['PlayAnimation']
queries: []
params: None

Actor: Lock
entrypoint: None()
actions: ['Unlock', 'LookAtInfomation']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['DecrementSmallKey']
queries: ['HasItem']
params: None

Actor: Switch
entrypoint: None()
actions: ['SwitchOn']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Block
entrypoint: None()
actions: ['Push']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Door
entrypoint: None()
actions: ['DoorOpen', 'DoorClose']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveToTargetActor', 'AimCompassPoint', 'ResetAim', 'PlayAnimation', 'SetEquipmentVisibility', 'PlayAnimationEx', 'SetDisablePowerUpEffect']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayOneshotSystemSE']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestRestartWarp', 'RequestAutoSave']
queries: []
params: None

Actor: WarpUI
entrypoint: None()
actions: ['Show', 'JumpToSelectedLocation']
queries: ['GetResult']
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

void LockDoor_Do() {
    if !Inventory.HasItem({'itemType': 59, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchNormalDoor'})
    } else {

        fork {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'key_open', 'blendTime': 0.10000000149011612})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})

        fork {
            Lock.Unlock()
        } {
            Audio.PlayOneshotSystemSE({'label': 'SE_MAP_OPEN_KEY', 'volume': 1.0, 'pitch': 1.0})
        }

        Inventory.DecrementSmallKey({'count': 1})
        GameControl.RequestAutoSave()
    }
}

void LockBlock_Do() {
    if !Inventory.HasItem({'itemType': 59, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchKeyBlock'})
    } else {

        fork {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'key_open', 'blendTime': 0.10000000149011612})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        fork {
            Lock.Unlock()
        } {
            Audio.PlayOneshotSystemSE({'label': 'SE_MAP_KEYBLOCK_OFF', 'volume': 1.0, 'pitch': 1.0})
        }

        Inventory.DecrementSmallKey({'count': 1})
        GameControl.RequestAutoSave()
    }
}

void BossDoor_Do() {
    if !Inventory.HasItem({'itemType': 60, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchBossDoor'})
    } else {

        fork {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'key_open', 'blendTime': 0.10000000149011612})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})

        fork {
            Lock.Unlock()
        } {
            Lock.LookAtInfomation({'duration': 0.8999999761581421, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        }

        GameControl.RequestAutoSave()
    }
}

void FootSwitch_On() {
    Switch.SwitchOn()
    Timer.Wait({'time': 0.10000000149011612})
}

void SquareBlock_Push() {
    Block.Push()
}

void CaveRock_Push() {
    Block.Push()
}

void ClosedDoor_Open() {
    Door.DoorOpen()
}

void ClosedDoor_Close() {
    Door.DoorClose()
}

void OnewayDoorOpen() {
    Link.MoveToTargetActor({'speed': 0, 'distance': 0.5950000286102295, 'actor': ActorIdentifier(name="Door", sub_name="frontSideDoor"), 'timeOut': 7.0})
    Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
    Link.ResetAim()

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        Link.PlayAnimation({'name': 'revodoor_in', 'blendTime': 0.10000000149011612})
    } {
        Door[frontSideDoor].PlayAnimation({'name': 'turn', 'blendTime': 0.0})
    } {
        Door[oppositeSideDoor].PlayAnimation({'name': 'open1', 'blendTime': 0.0})
        Door[oppositeSideDoor].PlayAnimationEx({'blendTime': 0.0, 'name': 'open_wait1', 'time': 0.0})
    }

    Door[oppositeSideDoor].PlayAnimation({'blendTime': 0.0, 'name': 'close1'})
    Door[oppositeSideDoor].PlayAnimationEx({'blendTime': 0.0, 'name': 'close_wait1', 'time': 0.0})
}

void Warp() {

    fork {
        Link.PlayAnimation({'name': 'warp_d_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimationEx({'name': 'warp_d_lp', 'time': 0.0, 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 2.0})
        Fade.StartPreset({'preset': 9})
        GameControl.RequestRestartWarp({'locator': 'location', 'offsetX': 0.0, 'offsetZ': 0.0})
    }

}

void DungeonWarpOut() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    WarpUI.Show()
    if WarpUI.GetResult() {

        fork {
            Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_d_st'})
            Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_d_lp'})
        } {
            Timer.Wait({'time': 1.0})
            Fade.StartPreset({'preset': 5})
            WarpUI.JumpToSelectedLocation()
        }

    }
}

void LockBlock_Open() {

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Link.PlayAnimation({'name': 'key_open_u', 'blendTime': 0.10000000149011612})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
}
