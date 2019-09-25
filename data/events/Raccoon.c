-------- EventFlow: Raccoon --------

Actor: Tarin[EventTarin]
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'PlayAnimationEx', 'SetFacialExpression', 'ResetAim', 'LookAtGimmick']
queries: []
params: None

Actor: Raccoon
entrypoint: None()
actions: ['Talk', 'PlayAnimationEx', 'GenericTalkSequence', 'AimCompassPoint', 'SetFacialExpression', 'Thrash', 'BodyChange', 'Destroy', 'PlayTailorOtherChannelEx', 'LookAtGimmicksLinkedPoint', 'PlayOneshotSE', 'StopTailorOtherChannel']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'AimActor', 'PlayAnimation', 'SetDisablePowerUpEffect']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestWarp', 'RequestAutoSave']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'PlayZoneAudio', 'PlayOneshotSystemSE', 'StopOtherThanSystemSE']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartParam']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Raccoon.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Raccoon.Talk({'message': 'Scenario:Lv1Raccoon1'})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void stoptalk() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Raccoon.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    Raccoon.SetFacialExpression({'expression': 'smile'})

    fork {
        Raccoon.PlayAnimationEx({'time': 0.0, 'name': 'raugh', 'blendTime': 0.10000000149011612})
    } {
        Raccoon.Talk({'message': 'Scenario:Lv1Raccoon2'})
    } {
        Raccoon.LookAtGimmicksLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    Audio.PlayOneshotSystemSE({'label': 'SE_ENV_TANUKI_WHITEOUT', 'volume': 1.0, 'pitch': 1.0})

    fork {
        Fade.StartParam({'mode': 1, 'time': 0.6000000238418579, 'colorR': 0.8999999761581421, 'colorG': 0.8999999761581421, 'colorB': 0.8999999761581421})
    } {
        GameControl.RequestWarp({'locator': 'Field_07D', 'offsetX': 'offsetX', 'offsetZ': 'offsetZ'})
    } {
        Audio.StopOtherThanSystemSE({'duration': 0.6000000238418579})
    }

}

void rescued() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.StopAllBGM({'duration': 0.0})
    Raccoon.PlayOneshotSE({'label': 'SE_NPC_TANUKI_003', 'volume': 1.0, 'pitch': 1.0})

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
    }

    Raccoon.LookAtGimmicksLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})

    fork {
        Raccoon.Thrash({'duration': 8.0})
    } {
        Raccoon.PlayOneshotSE({'label': 'SE_NPC_TANUKI_004', 'volume': 1.0, 'pitch': 1.0})
    } {
        Raccoon.SetFacialExpression({'expression': 'confuse'})
    }

    Raccoon.StopTailorOtherChannel({'channel': 'ac_Keep', 'index': 0})
    Raccoon.PlayTailorOtherChannelEx({'channel': 'Transform', 'time': 0.20000000298023224, 'restart': False, 'index': 0})
    Raccoon.BodyChange({'actor': ActorIdentifier(name="Tarin", sub_name="EventTarin")})
    Raccoon.Destroy()
    Tarin[EventTarin].SetFacialExpression({'expression': 'shock'})
    Tarin[EventTarin].ResetAim()

    fork {
        Tarin[EventTarin].PlayAnimationEx({'name': 'kurakura', 'time': 3.0, 'blendTime': 0.10000000149011612})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Tarin", sub_name="EventTarin"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Tarin[EventTarin].PlayAnimation({'name': 'buruburu', 'blendTime': 0.20000000298023224})
        EventFlags.SetFlag({'value': True, 'symbol': 'RescueTarin'})
    } {
        Tarin[EventTarin].SetFacialExpression({'expression': 'normal'})
    }


    fork {

        fork {
            Tarin[EventTarin].Talk({'message': 'Scenario:TarinAfterRaccoon'})
        } {
            Tarin[EventTarin].LookAtGimmick({'distanceOffset': -0.5, 'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612})
        }

        EventFlags.SetFlag({'symbol': 'TalkedForestTarin', 'value': True})
    } {
        Tarin[EventTarin].PlayAnimation({'name': 'sit_wait', 'blendTime': 0.10000000149011612})
    }

    Audio.PlayZoneAudio()
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
}
