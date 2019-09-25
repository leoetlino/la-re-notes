-------- EventFlow: SinkingSword --------

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: []
params: None

Actor: SinkingSword
entrypoint: None()
actions: ['Destroy']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequence', 'RequestSwordRolling', 'PlayAnimationEx']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM']
queries: []
params: None

void examine() {
    EventFlags.SetFlag({'value': True, 'symbol': 'SwordGet'})

    fork {
        Link.GenericItemGetSequence({'itemType': 0, 'keepCarry': False, 'messageEntry': ''})
    } {
        Audio.StopAllBGM({'duration': 1.0})
        Inventory.AddItem({'itemType': 0, 'count': 1, 'autoEquip': False})
    } {
        SinkingSword.Destroy()
    }


    fork {
        Audio.PlayBGM({'label': 'BGM_FIELD_NORMAL_INTRO', 'volume': 1.0})
    } {
        Link.RequestSwordRolling()
        Link.PlayAnimationEx({'name': 'slash_hold_lp', 'time': 0.800000011920929, 'blendTime': 0.10000000149011612})
    }

}
