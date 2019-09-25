-------- EventFlow: Tarin --------

Actor: Inventory
entrypoint: None()
actions: ['AddItem', 'SetWarashibeItem']
queries: ['HasItem']
params: None

Actor: Tarin
entrypoint: None()
actions: ['Talk', 'TalkKeep', 'LookAtTalker', 'AimPlayer', 'PlayAnimation', 'Destroy', 'TrailTargetActorRail', 'GenericTalkSequence', 'SetFacialExpression', 'SetItemVisibility', 'AimDegreeAngle', 'PlayOneshotSE', 'ResetAim', 'PlayAnimationEx']
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

Actor: Honeycomb[EventHoneycomb]
entrypoint: None()
actions: ['Destroy', 'PlayOneshotSE', 'PlayAnimation', 'PlayAnimationEx']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['AimActor', 'MoveToTargetLinkedPoint', 'ResetAim', 'GenericItemGetSequence', 'SetEquipmentVisibility', 'PlayAnimation', 'SetFacialExpression', 'SetDisablePowerUpEffect', 'SetCharaCollisionEnabled', 'KeepDistanceFromActor']
queries: ['IsInRect']
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'SetLookAtOffsetAdditional', 'SetFixedCameraWithChase']
queries: []
params: None

void talk() {
    if EventFlags.CheckFlag({'symbol': 'ShieldGet'}) {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    }
    if !Inventory.HasItem({'itemType': 2, 'count': 1}) {
        Link.MoveToTargetLinkedPoint({'speed': 0, 'actor': ActorIdentifier(name="Tarin"), 'index': 1, 'timeOut': 7.0})

        fork {
            Tarin.GenericTalkSequence({'aimFromPlayer': False, 'keepPersonalSpace': False, 'aimToPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            Link.AimActor({'actor': ActorIdentifier(name="Tarin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        }

        Tarin.TalkKeep({'message': 'Scenario:Lv1FirstTarin1'})
        Tarin.Talk({'message': 'Scenario:Lv1FirstTarin2'})
        Tarin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Inventory.AddItem({'itemType': 2, 'count': 1, 'autoEquip': False})
        Link.GenericItemGetSequence({'itemType': 2, 'keepCarry': False, 'messageEntry': ''})
        EventFlags.SetFlag({'symbol': 'ShieldGet', 'value': True})
        Link.ResetAim()
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'itemType': 0, 'count': 1}) {

        fork {
            Tarin.GenericTalkSequence({'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            Tarin.Talk({'message': 'Npc:TarinAfterGetShield'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            Tarin.Talk({'message': 'Npc:TarinInForest'})
        } {
            Tarin.GenericTalkSequence({'keepPersonalSpace': True, 'aimFromPlayer': True, 'aimToPlayer': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}

void detain() {

    fork {
        Tarin.Talk({'message': 'Npc:TarinNoneShield'})
    } {
        Tarin.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Tarin.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Timer.Wait({'time': 0.5})
        Link.AimActor({'actor': ActorIdentifier(name="Tarin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    Link.ResetAim()
    Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="Tarin"), 'timeOut': 7.0})
}

void BedTarin1() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'TailCaveShutterOpened'}) {

        fork {
            Tarin.GenericTalkSequence({'keepPersonalSpace': True, 'aimFromPlayer': True, 'aimToPlayer': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            Tarin.Talk({'message': 'Npc:TarinInForest'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'itemType': 45, 'count': 1}) {

        fork {
            Tarin.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            Tarin.Talk({'message': 'Npc:TarinAfterRaccoon'})
        }

    } else
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {

        fork {
            Tarin.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            Tarin.Talk({'message': 'SubEvent:SleepingTarin'})
        }

    } else {

        fork {
            Tarin.SetFacialExpression({'expression': 'smile'})
        } {
            Tarin.Talk({'message': 'SubEvent:TarinEatBanana'})
        } {
            Tarin.GenericTalkSequence({'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        }

        Tarin.SetFacialExpression({'expression': 'normal'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}

void warashibe() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Tarin.GenericTalkSequence({'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
    } {
        Tarin.SetFacialExpression({'expression': 'smile'})
    } {
        Tarin.Talk({'message': 'Warashibe:QuestStick'})
    }


    fork {
        Tarin.SetFacialExpression({'expression': 'normal'})
    } {
        Tarin.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

    if !Dialog.GetLastResult() {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
        EventFlags.SetFlag({'symbol': 'HoneycombDrop', 'value': True})
        Link.AimActor({'withoutTurn': False, 'actor': ActorIdentifier(name="Tarin"), 'duration': 0.4000000059604645, 'boneName': ''})
        Audio.StopAllBGM({'duration': 1.0})
        if !Link.IsInRect({'maxX': 116.25, 'maxZ': 102.75, 'minX': 114.0, 'minZ': 101.0}) {
            Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'distance': 2.5, 'actor': ActorIdentifier(name="Tarin")})
        } else {
            Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'actor': ActorIdentifier(name="Tarin"), 'distance': 3.0})
        }
        Link.SetCharaCollisionEnabled({'enabled': False})
        Tarin.AimDegreeAngle({'withoutTurn': False, 'angle': 245.0, 'duration': 0.4000000059604645})

        fork {
            Tarin.PlayAnimation({'name': 'tutuku', 'blendTime': 0.10000000149011612})
        } {
            Tarin.SetItemVisibility({'visible': True})
        } {
            Timer.Wait({'time': 2.5})
        } {
            Honeycomb[EventHoneycomb].PlayAnimation({'name': 'shake', 'blendTime': 0.10000000149011612})
        }


        fork {
            Timer.Wait({'time': 0.4000000059604645})
        } {
            Tarin.SetItemVisibility({'visible': False})
        } {
            Tarin.PlayAnimationEx({'time': 0.699999988079071, 'name': 'wait', 'blendTime': 0.20000000298023224})
            Tarin.PlayAnimation({'name': 'wait_facedown', 'blendTime': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.800000011920929})
            Honeycomb[EventHoneycomb].PlayOneshotSE({'label': 'SE_ENV_HONEYCOMB_FALL', 'volume': 1.0, 'pitch': 1.0})
        } {
            Honeycomb[EventHoneycomb].PlayAnimationEx({'name': 'fall', 'blendTime': 0.10000000149011612, 'time': 1.0})
        }


        fork {
            Link.PlayAnimation({'name': 'ev_drawback_st', 'blendTime': 0.10000000149011612})
            Link.PlayAnimation({'name': 'ev_drawback_lp', 'blendTime': 0.10000000149011612})
        } {
            Link.SetFacialExpression({'expression': 'wakeup'})
        }

        Honeycomb[EventHoneycomb].PlayAnimationEx({'time': 1.0, 'name': 'fall_wait', 'blendTime': 0.10000000149011612})

        fork {
            Timer.Wait({'time': 1.2000000476837158})
        } {
            Honeycomb[EventHoneycomb].PlayAnimation({'name': 'pop', 'blendTime': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.6000000238418579})
            Audio.PlayBGM({'label': 'BGM_EVENT_BEE', 'volume': 1.0})
        } {
            Honeycomb[EventHoneycomb].PlayOneshotSE({'label': 'SE_ENV_TARIN_BEE', 'volume': 1.0, 'pitch': 1.0})
        }


        fork {
            Tarin.PlayAnimation({'name': 'odoroku', 'blendTime': 0.10000000149011612})
        } {
            Tarin.SetFacialExpression({'expression': 'surprise'})
        } {
            Camera.SetFixedCameraWithChase({'posX': 112.66200256347656, 'posY': 27.42099952697754, 'posZ': 119.93800354003906, 'rotX': -45.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 24.0, 'fieldOfViewY': 28.1200008392334, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0, 'chaseRatio': 0.10000000149011612})
        } {
            Tarin.PlayOneshotSE({'label': 'SE_NPC_TARIN_005', 'volume': 1.0, 'pitch': 1.0})
        } {
            Link.PlayAnimation({'name': 'ev_drawback_ed', 'blendTime': 0.10000000149011612})
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Tarin.ResetAim()
        }


        fork {
            Tarin.PlayOneshotSE({'label': 'SE_NPC_TARIN_006', 'volume': 1.0, 'pitch': 1.0})
            Tarin.TrailTargetActorRail({'speed': 1, 'railIndex': 0, 'actor': ActorIdentifier(name="Tarin"), 'timeOut': 7.0})
        } {
            Honeycomb[EventHoneycomb].PlayAnimation({'name': 'fall_wait', 'blendTime': 0.10000000149011612})
        }

        Timer.Wait({'time': 1.0})
        Tarin.SetFacialExpression({'expression': 'sleep'})
        Tarin.Destroy()
        Timer.Wait({'time': 1.0})
        Honeycomb[EventHoneycomb].Destroy()
        Link.SetFacialExpression({'expression': 'get'})
        Inventory.SetWarashibeItem({'itemType': 6})
        Link.GenericItemGetSequence({'itemType': 35, 'keepCarry': False, 'messageEntry': ''})
        Camera.Reset({'chaseRatio': 0.10000000149011612})
        Audio.PlayZoneBGM({'stopbgm': True})
        Link.SetFacialExpression({'expression': 'normal'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        Link.SetDisablePowerUpEffect({'effect': False, 'sound': False, 'materialAnim': False})
    } else {
        Tarin.Talk({'message': 'Warashibe:BadStick'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}

void BedTarin3() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Tarin.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Tarin.Talk({'message': 'Npc:TarinAfterWarashibe'})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void BananaTarin() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Tarin.GenericTalkSequence({'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
    } {
        Tarin.SetFacialExpression({'expression': 'smile'})
    } {
        Tarin.Talk({'message': 'SubEvent:TarinEatBanana'})
    }

    Tarin.SetFacialExpression({'expression': 'normal'})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}
