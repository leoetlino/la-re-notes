-------- EventFlow: Fox --------

Actor: Fox
entrypoint: None()
actions: ['Talk', 'LookAtTalker', 'AimPlayer']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['Damage', 'KeepDistanceFromActor', 'AimActor']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayOneshotSystemSE']
queries: []
params: None

void talk() {

    fork {
        Link.AimActor({'actor': ActorIdentifier(name="Fox"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Fox.Talk({'message': 'Npc:Fox'})
    } {
        Link.KeepDistanceFromActor({'distance': 1.5, 'animName': 'ev_talkback', 'actor': ActorIdentifier(name="Fox")})
    } {
        Fox.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Fox.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_MAP_FOX_VO', 'volume': 1.0, 'pitch': 1.0})
    }

}

void Fox_Attack() {
    Link.Damage({'amount': 1})
}

void Fox_Marinsong() {
    Fox.Talk({'message': 'Npc:Animals'})
}
