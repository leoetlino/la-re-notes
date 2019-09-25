-------- EventFlow: DesertBone --------

Actor: DesertBone
entrypoint: None()
actions: ['Examine', 'PlayAnimation']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['LookAtCharacter']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset']
queries: []
params: None

void Use() {

    fork {
        Link.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    } {
        DesertBone.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
        DesertBone.Examine({'message': 'Npc:TalkingDesertScull'})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        DesertBone.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

}
