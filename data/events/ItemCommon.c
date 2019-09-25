-------- EventFlow: ItemCommon --------

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequenceByKey']
queries: []
params: None

Actor: Item
entrypoint: None()
actions: ['Deactivate', 'Destroy', 'PlayTailorGettingChannel']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItemByKey']
queries: []
params: None

void get() {
    Item.Deactivate()
    Item.PlayTailorGettingChannel()
    Link.GenericItemGetSequenceByKey({'itemKey': 'itemKey', 'keepCarry': False, 'messageEntry': ''})
    Inventory.AddItemByKey({'itemKey': 'itemKey', 'count': 'itemCount', 'index': 'itemIndex', 'autoEquip': False})
    Item.Destroy()
}
