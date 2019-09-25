-------- EventFlow: Owl --------

Actor: BowWow[companion]
entrypoint: None()
actions: ['PlayAnimation', 'MoveToCompassPoint', 'AimActor']
queries: []
params: None

Actor: Danpei[OwlDanpei]
entrypoint: None()
actions: ['WarpToLinkedPointWithCompassPoint']
queries: []
params: None

Actor: Owl[egg]
entrypoint: None()
actions: ['AimPlayer', 'PlayAnimation', 'Talk', 'SetFacialExpression', 'Activate', 'PlayAnimationEx', 'AimCompassPoint', 'ResetAim']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'LookAt2ActorsCenterAsTalker', 'SetFixedCameraWithChase', 'SetLookAtOffsetAdditional']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['StashPopDepthOfField', 'StashSaveDepthOfField']
queries: []
params: None

Actor: Owl[Bowwow]
entrypoint: None()
actions: ['PlayAnimation', 'AimPlayer', 'Talk', 'SetFacialExpression']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveToTargetLinkedPoint', 'MoveToCompassPoint', 'SetDisablePowerUpEffect', 'CancelCarry', 'AimActor', 'PlayAnimation', 'ResetAim']
queries: []
params: None

Actor: Owl
entrypoint: None()
actions: ['Destroy', 'SetFacialExpression', 'PlayAnimation', 'Talk', 'AimPlayer', 'LookAtGimmicksLinkedPoint', 'LookAtTalkersLinkedPoint', 'ResetAim']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayZoneBGM', 'StopAllBGM', 'PlayBGM', 'StopBGM', 'CancelStopWindAmbienceSE']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayInAnim']
queries: []
params: None

void First() {
    Link.CancelCarry()
    EventFlags.SetFlag({'symbol': 'FirstClear', 'value': True})

    call OwlSt2()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'normal'})
        } {
            Owl.PlayAnimation({'name': 'talk', 'blendTime': 0.8999999761581421})
            Owl.Talk({'message': 'Scenario:Lv1Owl1_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight1': 1.0, 'weight2': 0.800000011920929, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Second() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'SecondClear'})

    call OwlSt2()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'normal'})
        } {
            Owl.PlayAnimation({'name': 'talk', 'blendTime': 0.8999999761581421})
            Owl.Talk({'message': 'Scenario:Lv1Owl2_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'weight1': 1.0, 'weight2': 0.800000011920929, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Third() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'ThirdClear'})

    call OwlSt2()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'serious'})
        } {
            Owl.PlayAnimation({'name': 'serious_talk', 'blendTime': 1.2000000476837158})
            Owl.Talk({'message': 'Scenario:Lv1Owl3_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight1': 1.0, 'weight2': 1.0, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Fourth() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'FourthClear'})
    Environment.StashSaveDepthOfField({'duration': 0.5})
    Link.MoveToTargetLinkedPoint({'speed': 0, 'index': 1, 'actor': ActorIdentifier(name="Owl"), 'timeOut': 7.0})

    call OwlSt()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'normal'})
        } {
            Owl.PlayAnimation({'name': 'talk', 'blendTime': 0.8999999761581421})
            Owl.Talk({'message': 'Scenario:Lv2Owl1_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight1': 1.0, 'weight2': 0.800000011920929, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Fifth() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'FifthClear'})
    Environment.StashSaveDepthOfField({'duration': 0.5})
    BowWow[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    Owl[Bowwow].PlayAnimation({'name': 'hide_wait', 'blendTime': 0.10000000149011612})
    Owl[Bowwow].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})

    fork {

        fork {
            Owl[Bowwow].PlayAnimation({'blendTime': 0.0, 'name': 'fly_in_st_lp'})
        } {
            Timer.Wait({'time': 4.5})
        }

        Owl[Bowwow].PlayAnimation({'name': 'fly_in_st', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 1.0})
        Link.PlayAnimation({'name': 'ev_kyoro', 'blendTime': 0.10000000149011612})

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'speed': 0, 'distance': 1.5, 'timeOut': 7.0})
            Link.AimActor({'actor': ActorIdentifier(name="Owl"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            BowWow[companion].MoveToCompassPoint({'direction': 0, 'speed': 0, 'distance': 1.0, 'timeOut': 7.0})
            BowWow[companion].AimActor({'actor': ActorIdentifier(name="Owl"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            BowWow[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }

    } {
        Audio.StopAllBGM({'duration': 1.0})
        Timer.Wait({'time': 1.0})
        Audio.PlayBGM({'label': 'BGM_OWL', 'volume': 1.0})
    }


    fork {
        Owl[Bowwow].PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl[Bowwow].SetFacialExpression({'expression': 'normal'})
        } {
            Owl[Bowwow].PlayAnimation({'name': 'talk', 'blendTime': 0.8999999761581421})
            Owl[Bowwow].Talk({'message': 'Scenario:Lv2Owl2_1'})
        }

    } {
        Owl[Bowwow].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight1': 1.0, 'weight2': 0.800000011920929, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }

    Danpei[OwlDanpei].WarpToLinkedPointWithCompassPoint({'direction': 0, 'index': 1, 'offsetY': 0.0})

    call OwlEnd()

}

void Sixth() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'SixthClear'})
    Environment.StashSaveDepthOfField({'duration': 0.5})
    Owl.PlayAnimation({'name': 'hide_wait', 'blendTime': 0.10000000149011612})
    Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})

    fork {

        fork {
            Owl.PlayAnimation({'blendTime': 0.0, 'name': 'fly_in_st_lp'})
        } {
            Timer.Wait({'time': 4.5})
        }

        Owl.PlayAnimation({'name': 'fly_in_st', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 1.0})
        Link.PlayAnimation({'name': 'ev_kyoro', 'blendTime': 0.10000000149011612})
        Link.MoveToCompassPoint({'direction': 0, 'speed': 0, 'distance': 1.5, 'timeOut': 7.0})
        Link.AimActor({'actor': ActorIdentifier(name="Owl"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Audio.StopAllBGM({'duration': 1.0})
        Timer.Wait({'time': 1.0})
        Audio.PlayBGM({'label': 'BGM_OWL', 'volume': 1.0})
    }


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'normal'})
        } {
            Owl.PlayAnimation({'name': 'talk', 'blendTime': 0.8999999761581421})
            Owl.Talk({'message': 'Scenario:Lv4Owl1_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight2': 0.800000011920929, 'weight1': 1.0, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Seventh() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'SeventhClear'})

    call OwlSt2()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'serious'})
        } {
            Owl.PlayAnimation({'blendTime': 1.2000000476837158, 'name': 'serious_talk'})
            Owl.Talk({'message': 'Scenario:Lv4Owl2_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight1': 1.0, 'weight2': 0.800000011920929, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Eighth() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'EighthClear'})

    call OwlSt2()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'normal'})
        } {
            Owl.PlayAnimation({'name': 'talk', 'blendTime': 0.8999999761581421})
            Owl.Talk({'message': 'Scenario:Lv5Owl1_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight2': 0.800000011920929, 'weight1': 1.0, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Ninth() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'NinthClear'})

    call OwlSt_9()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'serious'})
        } {
            Owl.PlayAnimation({'blendTime': 1.2000000476837158, 'name': 'serious_talk'})
            Owl.Talk({'message': 'Scenario:Lv6Owl1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Owl.LookAtGimmicksLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Tenth() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'TenthClear'})
    Environment.StashSaveDepthOfField({'duration': 0.5})
    Link.MoveToCompassPoint({'direction': 0, 'speed': 0, 'distance': 1.0, 'timeOut': 7.0})

    call OwlSt()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'serious'})
        } {
            Owl.PlayAnimation({'blendTime': 1.2000000476837158, 'name': 'serious_talk'})
            Owl.Talk({'message': 'Scenario:Lv6Owl2_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Owl.LookAtTalkersLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void OwlEnd() {

    fork {
        Owl.SetFacialExpression({'expression': 'normal'})
    } {
        Owl.PlayAnimation({'name': 'wait', 'blendTime': 0.5})
    } {
        Timer.Wait({'time': 0.5})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {

        fork {
            Owl.PlayAnimation({'name': 'fly_out_st', 'blendTime': 0.10000000149011612})
            Owl.PlayAnimation({'name': 'fly_out_ed', 'blendTime': 0.0})
        } {
            Owl.ResetAim()
            Timer.Wait({'time': 2.5})
            Audio.StopBGM({'label': 'BGM_OWL', 'duration': 2.0})
        }

        Owl.Destroy()
        Link.ResetAim()
        Environment.StashPopDepthOfField({'duration': 0.5})
    } {
        Link.AimActor({'withoutTurn': True, 'boneName': 'aime', 'actor': ActorIdentifier(name="Owl"), 'duration': 0.4000000059604645})
    }

    Audio.PlayZoneBGM({'stopbgm': True})
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
}

void Eleventh() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'EleventhClear'})

    call OwlSt2()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'serious'})
        } {
            Owl.PlayAnimation({'blendTime': 1.2000000476837158, 'name': 'serious_talk'})
            Owl.Talk({'message': 'Scenario:Lv7Owl1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight2': 0.800000011920929, 'weight1': 1.0, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Twelve() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'TwelveClear'})

    call OwlSt2()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'serious'})
        } {
            Owl.PlayAnimation({'blendTime': 1.2000000476837158, 'name': 'serious_talk'})
            Owl.Talk({'message': 'Scenario:Lv7Owl2'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight2': 0.800000011920929, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'weight1': 1.0, 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Thirteen() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'ThirteenClear'})
    Audio.StopAllBGM({'duration': 0.5})
    Owl.PlayAnimation({'name': 'hide_wait', 'blendTime': 0.10000000149011612})
    Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    Link.PlayAnimation({'name': 'ev_kyoro', 'blendTime': 0.10000000149011612})

    fork {
        Owl.PlayAnimation({'name': 'fly_in_st', 'blendTime': 0.0})
    } {
        Link.AimActor({'boneName': 'aime', 'actor': ActorIdentifier(name="Owl"), 'duration': 0.6000000238418579, 'withoutTurn': False})
    } {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Owl.LookAtGimmicksLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'serious'})
        } {
            Owl.PlayAnimation({'blendTime': 1.2000000476837158, 'name': 'serious_talk'})
            Owl.Talk({'message': 'Scenario:Lv8Owl1_1'})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
        Owl.LookAtGimmicksLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }


    call OwlEnd()

}

void Fourteen() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'FourteenClear'})
    Environment.StashSaveDepthOfField({'duration': 0.5})

    call OwlSt()


    fork {
        Owl.PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl.SetFacialExpression({'expression': 'normal'})
        } {
            Owl.PlayAnimation({'name': 'talk', 'blendTime': 0.8999999761581421})
            Owl.Talk({'message': 'Scenario:LastOwl1_1'})
        } {
            Camera.LookAt2ActorsCenterAsTalker({'chaseRatio': 0.10000000149011612, 'weight1': 1.0, 'weight2': 0.800000011920929, 'actor1': ActorIdentifier(name="Owl"), 'actor2': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'distanceOffset': 0.0})
        }

    } {
        Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
    }


    call OwlEnd()

}

void Fiveteen() {

    fork {
        Link.CancelCarry()
    } {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    }

    EventFlags.SetFlag({'value': True, 'symbol': 'FiveteenClear'})
    Timer.Wait({'time': 0.800000011920929})
    Owl[egg].PlayAnimation({'name': 'hide_wait', 'blendTime': 0.10000000149011612})
    Owl[egg].Activate()

    fork {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Camera.SetFixedCameraWithChase({'rotX': -45.0, 'rotY': 0.0, 'rotZ': 0.0, 'fieldOfViewY': 28.086000442504883, 'posX': 98.22200012207031, 'posY': 55.5, 'posZ': 29.0, 'distanceToLookAt': 24.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0, 'chaseRatio': 0.10000000149011612})
    }

    Owl[egg].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.5, 'timeOut': 7.0})

    fork {
        Timer.Wait({'time': 2.5})
    } {
        Timer.Wait({'time': 1.0})
        Link.PlayAnimation({'name': 'ev_kyoro', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Link.AimActor({'actor': ActorIdentifier(name="Owl"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Audio.StopAllBGM({'duration': 0.5})
        Timer.Wait({'time': 1.0})
        Audio.PlayBGM({'label': 'BGM_OWL_LAST', 'volume': 1.0})
    }


    fork {
        Owl[egg].PlayAnimation({'name': 'fly_in_ed', 'blendTime': 0.0})

        fork {
            Owl[egg].SetFacialExpression({'expression': 'normal'})
        } {
            Owl[egg].PlayAnimation({'name': 'talk', 'blendTime': 0.8999999761581421})
            Owl[egg].Talk({'message': 'Scenario:LastOwl2'})
        }

    } {
        Owl[egg].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 0.800000011920929})
    }

    Owl[egg].PlayAnimationEx({'name': 'wait', 'time': 0.0, 'blendTime': 0.4000000059604645})
    Owl[egg].AimCompassPoint({'direction': 0, 'withoutTurn': True, 'duration': 0.800000011920929})
    Owl[egg].ResetAim()
    Link.ResetAim()
    Audio.CancelStopWindAmbienceSE()
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
    Hud.PlayInAnim()
    Camera.SetLookAtOffsetAdditional()
    Camera.Reset({'chaseRatio': 0.10000000149011612})
}

void Sixteen() {
    Owl.Talk({'message': 'Scenario:EDOwl1'})
    Owl.Destroy()
}

void OwlSt2() {
    Owl.PlayAnimation({'name': 'hide_wait', 'blendTime': 0.10000000149011612})
    Audio.StopAllBGM({'duration': 1.5})
    Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    Environment.StashSaveDepthOfField({'duration': 0.5})

    fork {

        fork {
            Owl.PlayAnimation({'blendTime': 0.0, 'name': 'fly_in_st_lp'})
        } {
            Timer.Wait({'time': 2.5})
        }

        Owl.PlayAnimation({'name': 'fly_in_st', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 1.0})
        Link.PlayAnimation({'name': 'ev_kyoro', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Link.AimActor({'actor': ActorIdentifier(name="Owl"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 1.0})
        Audio.PlayBGM({'label': 'BGM_OWL', 'volume': 1.0})
    }

}

void OwlSt() {
    Owl.PlayAnimation({'name': 'hide_wait', 'blendTime': 0.10000000149011612})
    Audio.StopAllBGM({'duration': 1.5})
    Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})

    fork {

        fork {
            Owl.PlayAnimation({'blendTime': 0.0, 'name': 'fly_in_st_lp'})
        } {
            Timer.Wait({'time': 2.5})
        }

        Owl.PlayAnimation({'name': 'fly_in_st', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 1.0})
        Link.PlayAnimation({'name': 'ev_kyoro', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Link.AimActor({'actor': ActorIdentifier(name="Owl"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 1.0})
        Audio.PlayBGM({'label': 'BGM_OWL', 'volume': 1.0})
    }

}

void OwlSt_9() {
    Owl.PlayAnimation({'name': 'hide_wait', 'blendTime': 0.10000000149011612})
    Audio.StopAllBGM({'duration': 1.5})
    Owl.AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
    Environment.StashSaveDepthOfField({'duration': 0.5})

    fork {

        fork {
            Owl.PlayAnimation({'blendTime': 0.0, 'name': 'fly_in_st_lp'})
        } {
            Timer.Wait({'time': 2.5})
        }

        Owl.PlayAnimation({'name': 'fly_in_st', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 1.0})
        Link.AimActor({'actor': ActorIdentifier(name="Owl"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Timer.Wait({'time': 1.0})
        Audio.PlayBGM({'label': 'BGM_OWL', 'volume': 1.0})
    }

}
