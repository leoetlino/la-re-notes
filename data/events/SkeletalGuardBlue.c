-------- EventFlow: SkeletalGuardBlue --------

Actor: SkeletalGuardRed
entrypoint: None()
actions: []
queries: []
params: None

Actor: SkeletalGuardRed[SkeletalGuardRed]
entrypoint: None()
actions: ['MoveToLinkedPoint', 'Talk', 'AimCompassPoint', 'PlayAnimation', 'AimPlayer']
queries: []
params: None

Actor: SkeletalGuardBlue
entrypoint: None()
actions: ['Talk', 'MoveToLinkedPoint', 'GenericTalkSequence', 'AimCompassPoint', 'PlayAnimation']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: ['HasItem']
params: None

Actor: Link
entrypoint: None()
actions: ['AddRupee', 'AimActor', 'ResetAim']
queries: ['CheckRupee']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Hud
entrypoint: None()
actions: ['ShowRupee']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'SetFixedCameraWithChase']
queries: []
params: None

void talk() {
    if !EventFlags.CheckFlag({'symbol': 'Lv10VisitClear'}) {

        fork {
            SkeletalGuardBlue.GenericTalkSequence({'keepPersonalSpace': True, 'cameraLookAt': False, 'aimToPlayer': True, 'selfTalkAnim': True, 'aimFromPlayer': True, 'playerTalkAnim': False, 'distanceOffset': 0.0})
        } {
            SkeletalGuardBlue.Talk({'message': 'SubEvent:BlueSkalGuard1'})
        } {
            Link.AimActor({'actor': ActorIdentifier(name="SkeletalGuardBlue"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Camera.SetFixedCameraWithChase({'posY': 19.17099952697754, 'posZ': 98.34200286865234, 'rotX': -65.0, 'distanceToLookAt': 19.5, 'fieldOfViewY': 28.1200008392334, 'posX': 36.75, 'chaseRatio': 0.06599999964237213, 'rotY': 0.0, 'rotZ': 0.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
        }


        fork {
            SkeletalGuardRed[SkeletalGuardRed].Talk({'message': 'SubEvent:RedSkalGuard2'})
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
            SkeletalGuardBlue.Talk({'message': 'SubEvent:BlueSkalGuard3'})
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
            SkeletalGuardRed[SkeletalGuardRed].MoveToLinkedPoint({'speed': 0, 'index': 0, 'timeOut': 7.0})

            fork {
                SkeletalGuardRed[SkeletalGuardRed].AimCompassPoint({'direction': 3, 'duration': 0.4000000059604645, 'withoutTurn': False})
            } {
                SkeletalGuardRed[SkeletalGuardRed].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            }

        } {
            Link.ResetAim()
            Camera.Reset({'chaseRatio': 0.06599999964237213})
        } {
            SkeletalGuardBlue.MoveToLinkedPoint({'speed': 0, 'index': 0, 'timeOut': 7.0})

            fork {
                SkeletalGuardBlue.AimCompassPoint({'direction': 1, 'duration': 0.4000000059604645, 'withoutTurn': False})
            } {
                SkeletalGuardBlue.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            }

        }

        EventFlags.SetFlag({'value': True, 'symbol': 'Lv10VisitClear'})
    } else
    if !Inventory.HasItem({'itemType': 56, 'count': 40}) {
        if !Inventory.HasItem({'itemType': 12, 'count': 20}) {

            fork {
                SkeletalGuardBlue.GenericTalkSequence({'keepPersonalSpace': True, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})
            } {
                Hud.ShowRupee({'visible': True})
            } {
                SkeletalGuardBlue.Talk({'message': 'SubEvent:SellBlueGuard'})
            }

            if !Dialog.GetLastResult() {
                if !Link.CheckRupee({'amount': 100}) {
                    SkeletalGuardBlue.Talk({'message': 'SubEvent:MoneyBlueGuard'})
                } else {
                    Event17:
                    Link.AddRupee({'amount': -100})
                    SkeletalGuardBlue.PlayAnimation({'name': 'laugh', 'blendTime': 0.10000000149011612})
                    SkeletalGuardBlue.Talk({'message': 'SubEvent:CheckBlueGuard'})
                    Inventory.AddItem({'itemType': 12, 'count': 20, 'autoEquip': False})
                }
            } else {
                Event18:
                SkeletalGuardBlue.Talk({'message': 'SubEvent:NoBlueGuard'})
            }
        } else {

            fork {
                SkeletalGuardBlue.GenericTalkSequence({'keepPersonalSpace': True, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': False, 'selfTalkAnim': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
            } {
                SkeletalGuardBlue.PlayAnimation({'name': 'laugh', 'blendTime': 0.10000000149011612})
            } {
                SkeletalGuardBlue.Talk({'message': 'SubEvent:BadBlueGuard'})
            }

        }
    } else
    if !Inventory.HasItem({'itemType': 12, 'count': 40}) {

        fork {
            SkeletalGuardBlue.GenericTalkSequence({'keepPersonalSpace': True, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})
        } {
            Hud.ShowRupee({'visible': True})
        } {
            SkeletalGuardBlue.Talk({'message': 'SubEvent:SellBlueGuard'})
        }

        if !Dialog.GetLastResult() {
            if !Link.CheckRupee({'amount': 100}) {
                SkeletalGuardBlue.Talk({'message': 'SubEvent:MoneyBlueGuard'})
            } else {
                goto Event17
            }
        } else {
            goto Event18
        }
    } else {

        fork {
            SkeletalGuardBlue.GenericTalkSequence({'keepPersonalSpace': True, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': False, 'selfTalkAnim': False, 'playerTalkAnim': True, 'distanceOffset': 0.0})
        } {
            SkeletalGuardBlue.PlayAnimation({'name': 'laugh', 'blendTime': 0.10000000149011612})
        } {
            SkeletalGuardBlue.Talk({'message': 'SubEvent:BadBlueGuard'})
        }

    }
}
