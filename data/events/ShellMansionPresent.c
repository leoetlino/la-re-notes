-------- EventFlow: ShellMansionPresent --------

Actor: ShellMansionPresent
entrypoint: None()
actions: ['Activate', 'PlayAnimation', 'PlayAnimationEx', 'PlayTailorOtherChannelEx', 'Deactivate']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItemByKey']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequenceByKey', 'AimActor', 'SetFacialExpression']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: ShellMansionMaster
entrypoint: None()
actions: ['DropRupees', 'PlayOneshotSE']
queries: ['TestGiftCondition']
params: None

void open() {

    fork {
        Link.AimActor({'duration': 0.8999999761581421, 'actor': ActorIdentifier(name="ShellMansionPresent"), 'withoutTurn': False, 'boneName': ''})
    } {
        ShellMansionPresent.PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})
        ShellMansionPresent.PlayAnimationEx({'name': 'open_wait', 'time': 0.30000001192092896, 'blendTime': 0.10000000149011612})
    }

    Link.GenericItemGetSequenceByKey({'itemKey': 'itemKey', 'keepCarry': False, 'messageEntry': ''})
    Link.SetFacialExpression({'expression': 'normal'})
    Inventory.AddItemByKey({'itemKey': 'itemKey', 'index': 'itemIndex', 'count': 1, 'autoEquip': False})
    EventFlags.SetFlag({'value': True, 'symbol': 'gettingFlag'})
    ShellMansionPresent.PlayTailorOtherChannelEx({'channel': 'depop', 'time': 0.1599999964237213, 'restart': False, 'index': 0})
    ShellMansionPresent.Deactivate()

    call ShellMansionMaster.NextGift({'doNoShellEvent': False})

}

void pop() {
    ShellMansionPresent.Activate()
    ShellMansionPresent.PlayAnimation({'blendTime': 0.0, 'name': 'pop'})
    Timer.Wait({'time': 1.2000000476837158})
    if ShellMansionMaster.TestGiftCondition() == 5
    && !EventFlags.CheckFlag({'symbol': 'ShellMansionRupeeDrop'}) {
        ShellMansionMaster.PlayOneshotSE({'label': 'SE_MAP_SHELL_RUPY', 'volume': 1.0, 'pitch': 1.0})
        ShellMansionMaster.DropRupees({'pointIndex': 1, 'rupee50Count': 2, 'rupee100Count': 1, 'rupee20Count': 3, 'rupee300Count': 0, 'rupee5Count': 3, 'rupee1Count': 5, 'maxVelocity': 4.0})
        EventFlags.SetFlag({'symbol': 'ShellMansionRupeeDrop', 'value': True})
    }
}
