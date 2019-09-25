-------- EventFlow: SchuleDonavitch --------

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: SchuleDonavitch
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'PlayAnimation', 'AimActorLinkedPoint', 'PlayOneshotSE', 'ChangeIdleAnimation']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 43, 'count': 1}) {
        if !Inventory.HasItem({'itemType': 44, 'count': 1}) {

            fork {
                SchuleDonavitch.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                SchuleDonavitch.Talk({'message': 'Npc:Schule'})
            }


            fork {
                SchuleDonavitch.AimActorLinkedPoint({'pointIndex': 0, 'duration': 0.30000001192092896, 'actor': ActorIdentifier(name="SchuleDonavitch"), 'withoutTurn': False})
            } {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                SchuleDonavitch.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            }

        } else {

            fork {
                SchuleDonavitch.PlayAnimation({'name': 'surprise_st', 'blendTime': 0.10000000149011612})
            } {
                SchuleDonavitch.PlayOneshotSE({'label': 'SE_NPC_DONAVITCH_005', 'volume': 1.0, 'pitch': 1.0})
            } {
                SchuleDonavitch.GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': False, 'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            }

            SchuleDonavitch.PlayAnimation({'name': 'surprise', 'blendTime': 0.10000000149011612})
            SchuleDonavitch.Talk({'message': 'Npc:SchuleGetLens'})

            fork {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                SchuleDonavitch.PlayAnimation({'name': 'surprised_wait', 'blendTime': 0.20000000298023224})
            } {
                SchuleDonavitch.ChangeIdleAnimation({'animName': 'surprised_wait'})
            }

        }
    } else {

        fork {
            SchuleDonavitch.PlayAnimation({'name': 'surprise_st', 'blendTime': 0.10000000149011612})
        } {
            SchuleDonavitch.PlayOneshotSE({'label': 'SE_NPC_DONAVITCH_003', 'volume': 1.0, 'pitch': 1.0})
        } {
            SchuleDonavitch.GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': False, 'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        SchuleDonavitch.PlayAnimation({'name': 'surprise', 'blendTime': 0.10000000149011612})
        SchuleDonavitch.Talk({'message': 'Npc:SchuleGetScale1'})

        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            SchuleDonavitch.PlayAnimation({'name': 'surprised_wait', 'blendTime': 0.20000000298023224})
        } {
            SchuleDonavitch.ChangeIdleAnimation({'animName': 'surprised_wait'})
        }

    }
}
