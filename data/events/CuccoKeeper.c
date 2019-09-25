-------- EventFlow: CuccoKeeper --------

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility']
queries: ['WithCucco']
params: None

Actor: CuccoKeeper
entrypoint: None()
actions: ['Talk', 'SetFacialExpression', 'GenericTalkSequence', 'AimDegreeAngle', 'PlayAnimation']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopZoneAudio']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 51, 'count': 1}) {
        if !Link.WithCucco() {

            fork {
                CuccoKeeper.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                CuccoKeeper.Talk({'message': 'Npc:CuccoKeeper'})
            }


            call cuccoTurn()

        } else {

            fork {
                CuccoKeeper.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                CuccoKeeper.SetFacialExpression({'expression': 'surprise'})
            } {
                CuccoKeeper.Talk({'message': 'Npc:CuccoKeeperWithCocco'})
            }


            call cuccoTurn()

        }
    } else {

        fork {
            CuccoKeeper.GenericTalkSequence({'playerTalkAnim': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            CuccoKeeper.SetFacialExpression({'expression': 'smile'})
        } {
            CuccoKeeper.Talk({'message': 'SubEvent:FlyingCoccoKeeper'})
        }

        CuccoKeeper.SetFacialExpression({'expression': 'normal'})
    }
}

void cuccoStrike1() {
    if !Inventory.HasItem({'itemType': 51, 'count': 1}) {

        fork {
            CuccoKeeper.GenericTalkSequence({'playerTalkAnim': False, 'keepPersonalSpace': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'distanceOffset': 0.0})
        } {
            CuccoKeeper.Talk({'message': 'Npc:CuccoKeeperAttack1'})
        }


        call cuccoTurn()

    } else {

        fork {
            CuccoKeeper.GenericTalkSequence({'playerTalkAnim': False, 'keepPersonalSpace': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'distanceOffset': 0.0})
        } {
            CuccoKeeper.Talk({'message': 'Npc:CuccoKeeperAttack1'})
        }

    }
}

void cuccoStrike5() {
    if !Inventory.HasItem({'itemType': 51, 'count': 1}) {

        fork {
            CuccoKeeper.GenericTalkSequence({'playerTalkAnim': False, 'keepPersonalSpace': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'distanceOffset': 0.0})
        } {
            CuccoKeeper.Talk({'message': 'Npc:CuccoKeeperAttack2'})
        }


        call cuccoTurn()

    } else {

        fork {
            CuccoKeeper.GenericTalkSequence({'playerTalkAnim': False, 'keepPersonalSpace': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'distanceOffset': 0.0})
        } {
            CuccoKeeper.Talk({'message': 'Npc:CuccoKeeperAttack2'})
        }

    }
}

void cuccoStrike10() {

    fork {
        CuccoKeeper.GenericTalkSequence({'playerTalkAnim': False, 'keepPersonalSpace': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'distanceOffset': 0.0})
    } {
        CuccoKeeper.Talk({'message': 'Npc:CuccoKeeperAttack4'})
    }


    fork {
        Fade.StartPreset({'preset': 5})
        GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_01K_a', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Audio.StopZoneAudio()
    }

}

void cuccoTurn() {

    fork {
        CuccoKeeper.AimDegreeAngle({'duration': 0.30000001192092896, 'angle': 310.0, 'withoutTurn': False})
    } {
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } {
        CuccoKeeper.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        CuccoKeeper.SetFacialExpression({'expression': 'normal'})
    }

}
