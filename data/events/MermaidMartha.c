-------- EventFlow: MermaidMartha --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['SetBGMVolume']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag', 'SetLevelFlag']
queries: ['CheckFlag', 'CheckLevelFlag']
params: None

Actor: MermaidMartha
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'SetFacialExpression', 'GenericTalkSequence', 'Destroy', 'PlayAnimationEx', 'MoveToCompassPoint', 'AimPlayer', 'ResetAim', 'SetCollision', 'AimCompassPoint', 'MoveToLinkedPoint', 'SetGravityEnable']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['SetWarashibeItem']
queries: ['HasItem']
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequence', 'PlayAnimation', 'SetDisablePowerUpEffect', 'ResetAim', 'AimActor']
queries: []
params: None

void talk() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    if !EventFlags.CheckFlag({'symbol': 'ScaleDrop'}) {
        Audio.SetBGMVolume({'volume': 0.25, 'duration': 0.800000011920929})
        if !Inventory.HasItem({'itemType': 41, 'count': 1}) {

            fork {
                MermaidMartha.Talk({'message': 'Warashibe:WantBra1'})
            } {
                MermaidMartha.SetFacialExpression({'expression': 'worry'})
            } {
                MermaidMartha.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }


            fork {
                MermaidMartha.Talk({'message': 'Warashibe:WantBra2'})
            } {
                MermaidMartha.SetFacialExpression({'expression': 'smile'})
            }

            MermaidMartha.SetFacialExpression({'expression': 'normal'})
            Event57:
            Audio.SetBGMVolume({'duration': 1.0, 'volume': 1.0})
            Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
        } else {

            fork {
                MermaidMartha.SetFacialExpression({'expression': 'blush'})
            } {
                MermaidMartha.Talk({'message': 'Warashibe:QuestBra'})
            } {
                MermaidMartha.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            if !Dialog.GetLastResult() {
                EventFlags.SetFlag({'value': True, 'symbol': 'ScaleDrop'})

                fork {
                    MermaidMartha.PlayAnimation({'name': 'water_wait', 'blendTime': 0.10000000149011612})
                } {
                    Link.PlayAnimation({'name': 'dive', 'blendTime': 0.10000000149011612})
                }

                Link.ResetAim()
                Link.PlayAnimation({'name': 'u_swim_wait', 'blendTime': 0.10000000149011612})
                Timer.Wait({'time': 3.0})
                MermaidMartha.Talk({'message': 'Warashibe:ClearBra'})

                fork {
                    Link.PlayAnimation({'name': 'float', 'blendTime': 0.10000000149011612})
                } {
                    Inventory.SetWarashibeItem({'itemType': 14})
                }

                Link.GenericItemGetSequence({'itemType': 43, 'keepCarry': False, 'messageEntry': ''})
                Link.AimActor({'actor': ActorIdentifier(name="MermaidMartha"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

                fork {
                    MermaidMartha.SetFacialExpression({'expression': 'normal'})
                } {
                    Link.PlayAnimation({'name': 'swim_wait', 'blendTime': 0.10000000149011612})
                }

                MermaidMartha.SetGravityEnable({'enable': False})

                fork {
                    MermaidMartha.PlayAnimationEx({'name': 'dive', 'time': 1.2999999523162842, 'blendTime': 0.10000000149011612})
                } {
                    MermaidMartha.ResetAim()
                } {
                    MermaidMartha.SetCollision({'enable': False})
                } {
                    Timer.Wait({'time': 0.20000000298023224})
                    MermaidMartha.MoveToCompassPoint({'direction': 0, 'speed': 1, 'distance': 2.5, 'timeOut': 7.0})
                }

                MermaidMartha.PlayAnimation({'name': 'swim', 'blendTime': 0.10000000149011612})
                if !EventFlags.CheckLevelFlag({'index': 81}) {
                    MermaidMartha.MoveToCompassPoint({'distance': 4.0, 'direction': 0, 'speed': 1, 'timeOut': 7.0})
                } else {
                    MermaidMartha.MoveToLinkedPoint({'speed': 1, 'index': 0, 'timeOut': 7.0})
                }
                Timer.Wait({'time': 1.5})
                MermaidMartha.Destroy()
                goto Event57
            } else {
                MermaidMartha.SetFacialExpression({'expression': 'worry'})
                MermaidMartha.Talk({'message': 'Warashibe:BadBra'})
                Audio.SetBGMVolume({'duration': 1.0, 'volume': 1.0})
                MermaidMartha.SetFacialExpression({'expression': 'normal'})
            }
        }
    } else {

        fork {
            MermaidMartha.GenericTalkSequence({'aimToPlayer': False, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            MermaidMartha.AimPlayer({'withoutTurn': True, 'duration': 0.4000000059604645, 'boneName': ''})
        } {
            MermaidMartha.Talk({'message': 'Npc:MermaidAfterWarashibe'})
        }

    }
}

void MermaidNear() {

    fork {

        fork {
            MermaidMartha.Talk({'message': 'SubEvent:MermaidNearDive'})
        } {
            MermaidMartha.SetFacialExpression({'expression': 'blush'})
        } {
            MermaidMartha.GenericTalkSequence({'playerTalkAnim': False, 'keepPersonalSpace': False, 'aimFromPlayer': False, 'aimToPlayer': True, 'selfTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        }

    } {
        Link.PlayAnimation({'blendTime': 0.5, 'name': 'u_swim_wait'})
    }

    Link.PlayAnimation({'name': 'float', 'blendTime': 0.10000000149011612})

    fork {

        fork {
            MermaidMartha.SetCollision({'enable': False})
        } {
            MermaidMartha.SetGravityEnable({'enable': False})
        }

        if !EventFlags.CheckLevelFlag({'index': 81}) {
            MermaidMartha.AimCompassPoint({'direction': 3, 'duration': 0.10000000149011612, 'withoutTurn': False})
            MermaidMartha.MoveToCompassPoint({'direction': 3, 'distance': 5.0, 'speed': 1, 'timeOut': 7.0})
            EventFlags.SetLevelFlag({'value': True, 'index': 81})
        } else {
            MermaidMartha.AimCompassPoint({'direction': 1, 'duration': 0.10000000149011612, 'withoutTurn': False})
            MermaidMartha.MoveToCompassPoint({'direction': 1, 'distance': 5.0, 'speed': 1, 'timeOut': 7.0})
            EventFlags.SetLevelFlag({'value': False, 'index': 81})
        }
    } {
        MermaidMartha.PlayAnimation({'name': 'dive', 'blendTime': 0.10000000149011612})
    } {
        MermaidMartha.ResetAim()
    } {
        Link.PlayAnimation({'name': 'swim_wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        MermaidMartha.PlayAnimation({'name': 'drop', 'blendTime': 0.0})
        MermaidMartha.PlayAnimation({'name': 'water_wait', 'blendTime': 0.20000000298023224})
        Timer.Wait({'time': 1.0})
    } {
        MermaidMartha.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    } {
        MermaidMartha.SetCollision({'enable': True})
    }

    MermaidMartha.SetFacialExpression({'expression': 'normal'})
}
