-------- EventFlow: PrizeCommon --------

Actor: Link
entrypoint: None()
actions: ['PrizeGetSequenceByKey']
queries: []
params: None

Actor: Item
entrypoint: None()
actions: ['Deactivate', 'Destroy']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddPrizeByKey']
queries: ['HasPrize']
params: None

Actor: EventFlags
entrypoint: None()
actions: []
queries: ['CheckFlag']
params: None

void get() {
    Item.Deactivate()
    Link.PrizeGetSequenceByKey({'prizeKey': 'prizeKey'})
    Inventory.AddPrizeByKey({'count': 'itemCount', 'index': 'itemIndex', 'prizeKey': 'prizeKey'})
    if !Inventory.HasPrize({'prizeType': 19, 'count': 1}) {
        Item.Destroy()
    } else
    if !EventFlags.CheckFlag({'symbol': 'BowWowFigureGet'}) {

        call GameShopOwner.BowWowFigureGet()

        Item.Destroy()
    } else {
        Item.Destroy()
    }
}
