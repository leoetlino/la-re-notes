-------- EventFlow: FieldObject --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle', 'PlayOneshotSystemSE', 'PlayBGM', 'SetBGMVolume']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['PlayAnimation', 'SetEquipmentVisibility', 'KeepDistanceFromActor', 'AimActor', 'SetDisablePowerUpEffect', 'MoveToTargetLinkedPoint', 'AimCompassPoint']
queries: ['WithNobody']
params: None

Actor: Door[Gate]
entrypoint: None()
actions: ['DoorOpen', 'PlayOneshotSE', 'PlayWorldOriginCameraAnimation']
queries: []
params: None

Actor: Door[Gata]
entrypoint: None()
actions: ['PlayWorldOriginCameraAnimation']
queries: []
params: None

Actor: Door
entrypoint: None()
actions: ['DoorOpen', 'PlayOneshotSE', 'PlayWorldOriginCameraAnimation']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Quake', 'SetFixedCamera', 'Reset', 'SetFixedCameraWithChase']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Block
entrypoint: None()
actions: ['Push']
queries: []
params: None

Actor: Lock
entrypoint: None()
actions: ['Unlock', 'PlayWorldOriginCameraAnimation']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void TailLockStatue_Unlock() {
    if !Inventory.HasItem({'itemType': 25, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchTailKeyhole'})
    } else {
        Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Lock"), 'timeOut': 7.0})
        Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})

        call TailEntranceLock_Open()

        GameControl.RequestAutoSave()
    }
}

void SlimeLockStatue_Unlock() {
    if !Inventory.HasItem({'itemType': 26, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchSlimeKeyhole'})
    } else {
        Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Lock"), 'timeOut': 7.0})
        Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})

        call SlimeEntranceLock_Open()

        GameControl.RequestAutoSave()
    }
}

void AnglersKeyhole_Unlock() {
    if !Inventory.HasItem({'itemType': 27, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchAnglerKeyhole'})
    } else {
        Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Lock"), 'timeOut': 7.0})
        Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})

        call AnglersEntranceLock_Open()

        GameControl.RequestAutoSave()
    }
}

void FaceLockStatue_Unlock() {
    if !Inventory.HasItem({'itemType': 28, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchFaceKeyhole'})
    } else {
        Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Lock"), 'timeOut': 7.0})
        Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})

        call FaceEntranceLock_Open()

        GameControl.RequestAutoSave()
    }
}

void EaglesLockRock_Unlock() {
    if !Inventory.HasItem({'itemType': 29, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchBirdKeyhole'})
    } else {
        Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Lock"), 'timeOut': 7.0})
        Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})

        call EaglesEntranceLock_Open()

        GameControl.RequestAutoSave()
    }
}

void Grave_Push() {
    Block.Push()
}

void Workbench_Push() {
    Block.Push()
}

void Grave_CantPush() {
    if !Link.WithNobody() {

        fork {
            Dialog.Show({'message': 'System:LockColorDungeon'})
        } {
            Timer.Wait({'time': 1.0})
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }

    } else
    if !Inventory.HasItem({'itemType': 14, 'count': 1}) {

        fork {
            Dialog.Show({'message': 'System:LockColorDungeon'})
        } {
            Timer.Wait({'time': 1.0})
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }

    }
}

void TailEntranceLock_Open() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Timer.Wait({'time': 0.017000000923871994})
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.5})
    Timer.Wait({'time': 0.20000000298023224})
    Link.SetEquipmentVisibility({'ocarina': False, 'visibility': True, 'flipper': False})
    Link.AimActor({'duration': 0.10000000149011612, 'actor': ActorIdentifier(name="Lock"), 'withoutTurn': False, 'boneName': ''})

    fork {

        fork {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'key_open', 'blendTime': 0.10000000149011612})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'distance': 2.0, 'actor': ActorIdentifier(name="Lock")})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Lock.Unlock()
        Timer.Wait({'time': 1.5})
    } {
        Lock.PlayWorldOriginCameraAnimation({'name': 'unlock_taillockstatue_01', 'chaseRatio': 0.11999999731779099, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_MAP_TAIL_FLASH1', 'volume': 1.0, 'pitch': 1.0})
    }


    fork {
        Timer.Wait({'time': 3.0})
        Door[Gate].DoorOpen()
    } {
        Timer.Wait({'time': 1.0})
        Door[Gate].PlayOneshotSE({'label': 'SE_MAP_TAIL_FLASH3', 'volume': 1.0, 'pitch': 1.0})
    } {
        Door[Gate].PlayWorldOriginCameraAnimation({'name': 'unlock_taillockstatue_02', 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    }

    Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
    Timer.Wait({'time': 0.20000000298023224})

    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Audio.SetBGMVolume({'volume': 1.0, 'duration': 0.5})
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void SlimeEntranceLock_Open() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.5})
    Timer.Wait({'time': 0.20000000298023224})
    Link.SetEquipmentVisibility({'ocarina': False, 'visibility': True, 'flipper': False})
    Link.AimActor({'duration': 0.10000000149011612, 'actor': ActorIdentifier(name="Lock"), 'withoutTurn': False, 'boneName': ''})

    fork {

        fork {
            Link.SetEquipmentVisibility({'ocarina': False, 'visibility': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'key_open', 'blendTime': 0.10000000149011612})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'distance': 2.0, 'actor': ActorIdentifier(name="Lock")})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Lock.Unlock()
        Timer.Wait({'time': 1.5})
    } {
        Lock.PlayWorldOriginCameraAnimation({'name': 'unlock_slimelockstatue_01', 'chaseRatio': 0.11999999731779099, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    }


    fork {
        Timer.Wait({'time': 3.0})
        Door[Gate].DoorOpen()
    } {
        Timer.Wait({'time': 1.0})
        Door[Gate].PlayOneshotSE({'label': 'SE_MAP_KEY_CAVERN_RUMBLE', 'volume': 1.0, 'pitch': 1.0})
    } {
        Door[Gata].PlayWorldOriginCameraAnimation({'name': 'unlock_slimelockstatue_02', 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    }

    Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
    Timer.Wait({'time': 0.20000000298023224})

    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Audio.SetBGMVolume({'volume': 1.0, 'duration': 0.5})
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void AnglersEntranceLock_Open() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.5})
    Timer.Wait({'time': 0.20000000298023224})
    Link.SetEquipmentVisibility({'ocarina': False, 'visibility': True, 'flipper': False})
    Link.AimActor({'duration': 0.10000000149011612, 'actor': ActorIdentifier(name="Lock"), 'withoutTurn': False, 'boneName': ''})

    fork {

        fork {
            Link.SetEquipmentVisibility({'ocarina': False, 'visibility': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'key_open', 'blendTime': 0.10000000149011612})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'distance': 2.0, 'actor': ActorIdentifier(name="Lock")})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Lock.Unlock()
        Timer.Wait({'time': 1.5})
    } {
        Lock.PlayWorldOriginCameraAnimation({'name': 'unlock_anglerskeyhole_01', 'chaseRatio': 0.11999999731779099, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    }


    fork {

        fork {
            Timer.Wait({'time': 0.5})
            Audio.PlayBGM({'label': 'BGM_EVENT_BASIN_ANGLER_OPEN', 'volume': 1.0})
        } {
            Door.PlayOneshotSE({'label': 'SE_MAP_WATERFALL_STOP', 'volume': 1.0, 'pitch': 1.0})
        } {
            Door.PlayWorldOriginCameraAnimation({'name': 'unlock_anglerskeyhole_02', 'chaseRatio': 0.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
        }

        Timer.Wait({'time': 3.5})
        Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
        Timer.Wait({'time': 0.20000000298023224})

        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Audio.SetBGMVolume({'volume': 1.0, 'duration': 0.5})
        }

    } {
        Timer.Wait({'time': 2.0})
        Door.DoorOpen()
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void FaceEntranceLock_Open() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.5})
    Timer.Wait({'time': 0.20000000298023224})
    Link.SetEquipmentVisibility({'ocarina': False, 'visibility': True, 'flipper': False})
    Link.AimActor({'duration': 0.10000000149011612, 'actor': ActorIdentifier(name="Lock"), 'withoutTurn': False, 'boneName': ''})

    fork {

        fork {
            Link.SetEquipmentVisibility({'ocarina': False, 'visibility': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'key_open', 'blendTime': 0.10000000149011612})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'distance': 2.0, 'actor': ActorIdentifier(name="Lock")})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Lock.Unlock()
        Timer.Wait({'time': 1.5})
    } {
        Camera.SetFixedCameraWithChase({'posX': 191.22799682617188, 'posY': 20.885000228881836, 'posZ': 111.03199768066406, 'rotX': -45.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 19.0, 'fieldOfViewY': 28.1200008392334, 'chaseRatio': 0.11999999731779099, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    }

    Camera.SetFixedCamera({'rotZ': 0.0, 'rotY': 0.0, 'fieldOfViewY': 28.1200008392334, 'posX': 184.9969940185547, 'posY': 28.17060089111328, 'posZ': 117.88300323486328, 'rotX': -45.0, 'distanceToLookAt': 24.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})

    fork {
        Camera.Quake({'duration': 0.10000000149011612, 'targetPower': 1, 'initPower': 0})
        Timer.Wait({'time': 1.0})
        Door[Gate].DoorOpen()
        Timer.Wait({'time': 2.0})
        Camera.Quake({'targetPower': 0, 'initPower': 1, 'duration': 0.800000011920929})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_MAP_FAITH_APPEAR', 'volume': 1.0, 'pitch': 1.0})
    }

    Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
    Timer.Wait({'time': 0.20000000298023224})

    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Audio.SetBGMVolume({'volume': 1.0, 'duration': 0.5})
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void EaglesEntranceLock_Open() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.5})
    Timer.Wait({'time': 0.20000000298023224})
    Link.SetEquipmentVisibility({'ocarina': False, 'visibility': True, 'flipper': False})
    Link.AimActor({'duration': 0.10000000149011612, 'actor': ActorIdentifier(name="Lock"), 'withoutTurn': False, 'boneName': ''})

    fork {

        fork {
            Link.SetEquipmentVisibility({'ocarina': False, 'visibility': False, 'flipper': False})
        } {
            Link.PlayAnimation({'name': 'key_open', 'blendTime': 0.10000000149011612})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'distance': 2.0, 'actor': ActorIdentifier(name="Lock")})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Lock.Unlock()
        Timer.Wait({'time': 1.5})
    } {
        Camera.SetFixedCameraWithChase({'posX': 212.16799926757812, 'rotX': -45.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 19.0, 'fieldOfViewY': 28.1200008392334, 'posY': 37.3849983215332, 'posZ': 25.442100524902344, 'chaseRatio': 0.11999999731779099, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    }

    Camera.SetFixedCamera({'rotZ': 0.0, 'posX': 218.46499633789062, 'posY': 33.391998291015625, 'posZ': 37.849998474121094, 'rotX': -12.46399974822998, 'rotY': 0.0, 'distanceToLookAt': 24.0, 'fieldOfViewY': 28.1200008392334, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    Door.PlayOneshotSE({'label': 'SE_MAP_BIGTOWER_MOVE_START', 'volume': 2.0, 'pitch': 1.0})
    Camera.Quake({'duration': 0.10000000149011612, 'targetPower': 1, 'initPower': 0})
    Timer.Wait({'time': 1.0})
    Door.DoorOpen()
    Timer.Wait({'time': 2.0})
    Camera.Quake({'targetPower': 0, 'initPower': 1, 'duration': 0.800000011920929})
    Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
    Timer.Wait({'time': 0.20000000298023224})

    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Audio.SetBGMVolume({'volume': 1.0, 'duration': 0.5})
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void TouchWeathercock() {

    fork {
        Dialog.Show({'message': 'System:TouchWeathercock'})
    } {
        Timer.Wait({'time': 1.0})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

}
