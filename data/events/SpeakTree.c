-------- EventFlow: SpeakTree --------

Actor: SpeakTree
entrypoint: None()
actions: ['Examine', 'PlayAnimation']
queries: []
params: None

void talk() {

    fork {
        SpeakTree.Examine({'message': 'Npc:TalkingTree'})
    } {
        SpeakTree.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
    }

}

void TalkingTree2() {

    fork {
        SpeakTree.Examine({'message': 'Npc:TalkingTree2'})
    } {
        SpeakTree.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
    }

}
