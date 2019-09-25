-------- EventFlow: HippoModel --------

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility']
queries: []
params: None

Actor: HippoModel
entrypoint: None()
actions: ['Talk', 'SetFacialExpression', 'AimCompassPoint', 'PlayAnimation', 'GenericTalkSequence']
queries: ['TalkSelect']
params: None

void talk() {
    switch HippoModel.TalkSelect() {
      case 0:

        fork {
            HippoModel.GenericTalkSequence({'aimFromPlayer': True, 'aimToPlayer': False, 'selfTalkAnim': False, 'keepPersonalSpace': False, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            HippoModel.Talk({'message': 'Npc:Hippo'})
        }

      case 1:

        call talk2()

      case 2:

        call talk3()

    }
}

void talk2() {

    fork {
        HippoModel.Talk({'message': 'SubEvent:AngryHippo2'})
    } {
        HippoModel.GenericTalkSequence({'aimFromPlayer': True, 'aimToPlayer': True, 'selfTalkAnim': False, 'keepPersonalSpace': False, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
    } {
        HippoModel.SetFacialExpression({'expression': 'angry'})
    } {
        HippoModel.PlayAnimation({'name': 'angry_lp', 'blendTime': 0.10000000149011612})
    }


    fork {
        HippoModel.AimCompassPoint({'duration': 0.30000001192092896, 'direction': 0, 'withoutTurn': False})
    } {
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } {
        HippoModel.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        HippoModel.SetFacialExpression({'expression': 'normal'})
    }

}

void talk3() {

    fork {
        HippoModel.Talk({'message': 'SubEvent:AngryHippo1'})
    } {
        HippoModel.GenericTalkSequence({'aimFromPlayer': True, 'aimToPlayer': True, 'selfTalkAnim': True, 'keepPersonalSpace': False, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
    } {
        HippoModel.SetFacialExpression({'expression': 'angry'})
    }


    fork {
        HippoModel.AimCompassPoint({'duration': 0.30000001192092896, 'direction': 0, 'withoutTurn': False})
    } {
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } {
        HippoModel.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        HippoModel.SetFacialExpression({'expression': 'normal'})
    }

}
