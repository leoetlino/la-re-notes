-------- EventFlow: SecretZora --------

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: SecretZora
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'GenericTalkSequence', 'LookAtTalker']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'GenericItemGetSequence', 'AimActor', 'PlayAnimation']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddSecretShell']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'ZoraTalked'}) {

        fork {
            SecretZora.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            SecretZora.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'selfTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
        } {
            SecretZora.PlayAnimation({'name': 'surprise_st', 'blendTime': 0.0})
            SecretZora.PlayAnimation({'name': 'surprise', 'blendTime': 0.0})
        } {
            SecretZora.Talk({'message': 'Npc:Zora1'})
        }

        Inventory.AddSecretShell({'index': 36})

        fork {
            Link.GenericItemGetSequence({'itemType': 23, 'messageEntry': 'Seashell', 'keepCarry': False})
        } {
            SecretZora.PlayAnimation({'blendTime': 0.0, 'name': 'wait'})
        }

        Timer.Wait({'time': 0.6000000238418579})

        fork {
            Link.AimActor({'actor': ActorIdentifier(name="SecretZora"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
        } {
            SecretZora.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }


        fork {
            SecretZora.PlayAnimation({'blendTime': 0.0, 'name': 'talk'})
        } {
            SecretZora.Talk({'message': 'Npc:Zora2'})
            SecretZora.Talk({'message': 'Npc:Zora4'})
        }

        EventFlags.SetFlag({'symbol': 'ZoraTalked', 'value': True})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            SecretZora.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'distanceOffset': 0.0})
        } {
            SecretZora.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            SecretZora.Talk({'message': 'Npc:Zora3'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}
