-------- EventFlow: Papahl --------

Actor: ClothBag
entrypoint: None()
actions: ['ChangeIdleAnimation']
queries: []
params: None

Actor: ClothBag[ClothBag]
entrypoint: None()
actions: ['PlayAnimation', 'Open']
queries: []
params: None

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

Actor: Inventory
entrypoint: None()
actions: ['SetWarashibeItem']
queries: ['HasItem']
params: None

Actor: Papahl
entrypoint: None()
actions: ['Talk', 'PlayAnimationEx', 'ChangeIdleAnimation', 'SetFacialExpression', 'SetPineappleStatus', 'GenericTalkSequence', 'PlayAnimation', 'ResetAim', 'AimPlayer']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequence', 'SetEquipmentVisibility', 'PlayAnimation', 'SetDisablePowerUpEffect', 'MoveToTargetLinkedPoint']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Papahl.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !Inventory.HasItem({'itemType': 47, 'count': 1}) {

        fork {
            Papahl.SetFacialExpression({'expression': 'normal'})
        } {
            Papahl.Talk({'message': 'Npc:Papahl'})
        }

    } else {

        fork {
            Papahl.SetFacialExpression({'expression': 'normal'})
        } {
            Papahl.Talk({'message': 'Npc:PapahlAfterWarashibe'})
        }

    }
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void warashibe() {
    Papahl.ResetAim()
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Papahl"), 'timeOut': 7.0})
    if !EventFlags.CheckFlag({'symbol': 'HibiscusDrop'}) {
        if !Inventory.HasItem({'itemType': 36, 'count': 1}) {

            fork {
                Papahl.PlayAnimation({'name': 'sit', 'blendTime': 0.10000000149011612})
            } {
                Papahl.Talk({'message': 'Warashibe:WantPineapple'})
            } {
                Papahl.SetFacialExpression({'expression': 'weaken'})
            } {
                Papahl.GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': False, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
            }

            if Dialog.GetLastResult() in [0, 1] {
                Event13:
                Papahl.Talk({'message': 'Warashibe:BadPineapple'})
                Papahl.SetFacialExpression({'expression': 'normal'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        } else {

            fork {
                Papahl.PlayAnimation({'name': 'sit', 'blendTime': 0.10000000149011612})
            } {
                Papahl.Talk({'message': 'Warashibe:QuestPineapple'})
            } {
                Papahl.SetFacialExpression({'expression': 'weaken'})
            } {
                Papahl.GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            if !Dialog.GetLastResult() {
                Link.SetDisablePowerUpEffect({'sound': True, 'effect': True, 'materialAnim': True})
                Audio.SetBGMVolume({'duration': 1.0, 'volume': 0.25})
                EventFlags.SetFlag({'symbol': 'HibiscusDrop', 'value': True})
                Papahl.SetFacialExpression({'expression': 'smile'})

                fork {
                    Papahl.ResetAim()
                } {
                    Papahl.PlayAnimationEx({'name': 'get_st', 'time': 0.0, 'blendTime': 0.0})
                } {
                    Timer.Wait({'time': 0.08299999684095383})
                    Papahl.SetPineappleStatus({'status': 2})
                }

                Papahl.PlayAnimationEx({'blendTime': 0.0, 'name': 'get', 'time': 1.0})
                Papahl.Talk({'message': 'Warashibe:ClearPineapple1'})

                fork {
                    Papahl.PlayAnimationEx({'name': 'eat', 'time': 3.0, 'blendTime': 0.10000000149011612})
                } {
                    Timer.Wait({'time': 0.019999999552965164})
                    Papahl.SetPineappleStatus({'status': 1})
                }


                fork {
                    Papahl.Talk({'message': 'Warashibe:ClearPineapple2'})
                } {
                    Papahl.PlayAnimationEx({'name': 'hold', 'time': 0.0, 'blendTime': 0.0})
                } {
                    Papahl.AimPlayer({'duration': 0.10000000149011612, 'withoutTurn': True, 'boneName': 'head'})
                }


                fork {
                    Papahl.PlayAnimation({'name': 'pass', 'blendTime': 0.0})
                } {
                    ClothBag[ClothBag].PlayAnimation({'name': 'pass', 'blendTime': 0.0})
                } {
                    Timer.Wait({'time': 0.2800000011920929})
                    ClothBag[ClothBag].Open()
                } {
                    Papahl.ResetAim()
                }

                ClothBag.ChangeIdleAnimation({'animName': 'pass_wait'})
                Papahl.PlayAnimationEx({'name': 'eat', 'time': 0.0, 'blendTime': 0.0})
                Inventory.SetWarashibeItem({'itemType': 8})
                Link.GenericItemGetSequence({'itemType': 37, 'keepCarry': False, 'messageEntry': ''})
                Timer.Wait({'time': 0.6000000238418579})

                fork {
                    Papahl.Talk({'message': 'Npc:EattingPapahl'})
                } {
                    Papahl.PlayAnimationEx({'name': 'hold', 'time': 0.0, 'blendTime': 0.10000000149011612})
                } {
                    Papahl.AimPlayer({'duration': 0.10000000149011612, 'withoutTurn': True, 'boneName': 'head'})
                } {
                    Papahl.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': False, 'selfTalkAnim': False, 'aimToPlayer': False, 'aimFromPlayer': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
                } {
                    Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
                }


                fork {
                    Papahl.PlayAnimationEx({'name': 'eat', 'time': 2.0, 'blendTime': 0.0})
                } {
                    Papahl.ResetAim()
                }


                fork {
                    Papahl.PlayAnimationEx({'name': 'sit', 'time': 1.0, 'blendTime': 0.10000000149011612})
                } {
                    Papahl.SetPineappleStatus({'status': 0})
                }

                Papahl.ChangeIdleAnimation({'name': 'sit'})
                Audio.SetBGMVolume({'duration': 1.0, 'volume': 1.0})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                Link.SetDisablePowerUpEffect({'effect': False, 'sound': False, 'materialAnim': False})
            } else {
                goto Event13
            }
        }
    } else {

        call thankyou()

    }
}

void thankyou() {

    fork {
        Papahl.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Papahl.SetFacialExpression({'expression': 'normal'})
    } {
        Papahl.Talk({'message': 'Npc:PapahlRightAfterWarashibe'})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}
