-------- EventFlow: SkeletalGuardRed --------

Actor: SkeletalGuardBlue[SkeletalGuardBlue]
entrypoint: None()
actions: ['MoveToLinkedPoint', 'Talk', 'AimCompassPoint', 'PlayAnimation']
queries: []
params: None

Actor: SkeletalGuardRed
entrypoint: None()
actions: ['MoveToLinkedPoint', 'Talk', 'GenericTalkSequence', 'AimCompassPoint', 'PlayAnimation']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'ResetAim']
queries: []
params: None

Actor: SkeletalGuardBlue
entrypoint: None()
actions: ['PlayAnimation', 'AimPlayer']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['SetFixedCameraWithChase', 'Reset']
queries: []
params: None

Actor: SkeletalGuardRed[SkeletalGuardRed]
entrypoint: None()
actions: ['PlayAnimation', 'AimPlayer']
queries: []
params: None

void talk() {
    if !EventFlags.CheckFlag({'symbol': 'Lv10VisitClear'}) {

        fork {
            SkeletalGuardRed.GenericTalkSequence({'keepPersonalSpace': True, 'cameraLookAt': False, 'selfTalkAnim': False, 'aimFromPlayer': True, 'aimToPlayer': False, 'playerTalkAnim': False, 'distanceOffset': 0.0})
        } {
            SkeletalGuardBlue[SkeletalGuardBlue].Talk({'message': 'SubEvent:BlueSkalGuard1'})
        } {
            SkeletalGuardBlue.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActor({'actor': ActorIdentifier(name="SkeletalGuardBlue"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Camera.SetFixedCameraWithChase({'posY': 19.17099952697754, 'posZ': 98.34200286865234, 'rotX': -65.0, 'distanceToLookAt': 19.5, 'fieldOfViewY': 28.1200008392334, 'posX': 36.75, 'chaseRatio': 0.06599999964237213, 'rotY': 0.0, 'rotZ': 0.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
        } {
            SkeletalGuardBlue.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        }


        fork {
            SkeletalGuardRed.Talk({'message': 'SubEvent:RedSkalGuard2'})
        } {
            SkeletalGuardRed[SkeletalGuardRed].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
        } {
            SkeletalGuardBlue.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActor({'actor': ActorIdentifier(name="SkeletalGuardRed"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Camera.SetFixedCameraWithChase({'posY': 19.17099952697754, 'posZ': 98.34200286865234, 'rotX': -65.0, 'distanceToLookAt': 19.5, 'fieldOfViewY': 28.1200008392334, 'posX': 38.25, 'chaseRatio': 0.06599999964237213, 'rotY': 0.0, 'rotZ': 0.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
        } {
            SkeletalGuardRed[SkeletalGuardRed].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        }


        fork {
            SkeletalGuardBlue[SkeletalGuardBlue].Talk({'message': 'SubEvent:BlueSkalGuard3'})
        } {
            SkeletalGuardBlue.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
        } {
            SkeletalGuardRed[SkeletalGuardRed].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActor({'actor': ActorIdentifier(name="SkeletalGuardBlue"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Camera.SetFixedCameraWithChase({'posY': 19.17099952697754, 'posZ': 98.34200286865234, 'rotX': -65.0, 'distanceToLookAt': 19.5, 'fieldOfViewY': 28.1200008392334, 'posX': 36.75, 'chaseRatio': 0.06599999964237213, 'rotY': 0.0, 'rotZ': 0.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
        }


        fork {
            SkeletalGuardRed.MoveToLinkedPoint({'speed': 0, 'index': 0, 'timeOut': 7.0})

            fork {
                SkeletalGuardRed.AimCompassPoint({'direction': 3, 'duration': 0.4000000059604645, 'withoutTurn': False})
            } {
                SkeletalGuardRed.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            }

        } {
            Link.ResetAim()
            Camera.Reset({'chaseRatio': 0.06599999964237213})
        } {
            SkeletalGuardBlue[SkeletalGuardBlue].MoveToLinkedPoint({'speed': 0, 'index': 0, 'timeOut': 7.0})

            fork {
                SkeletalGuardBlue[SkeletalGuardBlue].AimCompassPoint({'direction': 1, 'duration': 0.4000000059604645, 'withoutTurn': False})
            } {
                SkeletalGuardBlue[SkeletalGuardBlue].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            }

        }

        EventFlags.SetFlag({'value': True, 'symbol': 'Lv10VisitClear'})
    } else {

        fork {
            SkeletalGuardRed.GenericTalkSequence({'keepPersonalSpace': True, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': False, 'selfTalkAnim': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
        } {
            SkeletalGuardRed.PlayAnimation({'name': 'laugh', 'blendTime': 0.10000000149011612})
        } {
            SkeletalGuardRed.Talk({'message': 'SubEvent:RedSkalGuard4'})
        }

    }
}
