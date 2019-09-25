-------- EventFlow: Goriya --------

Actor: Goriya
entrypoint: None()
actions: ['Talk', 'ReturnItem', 'TakeItem', 'SetFacialExpression', 'GenericTalkSequence']
queries: ['GetEquipedItemKind', 'GetKeptItemKind']
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: ['HasItem']
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult4', 'GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'AddRupee', 'GenericItemGetSequence']
queries: ['CheckRupee']
params: None

Actor: Hud
entrypoint: None()
actions: ['ShowRupee']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 8, 'count': 1}) {

        fork {
            Goriya.GenericTalkSequence({'aimToPlayer': False, 'aimFromPlayer': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': False, 'selfTalkAnim': True, 'distanceOffset': 0.0})
        } {
            Goriya.Talk({'message': 'Warashibe:QuestBoomerang'})
        }

        switch Dialog.GetLastResult4() {
          case 0:

            call trade({'slotIndex': 1})

          case 1:

            call trade({'slotIndex': 0})

          case 2:

            call cancel()

        }
    } else {

        fork {
            Goriya.GenericTalkSequence({'aimToPlayer': False, 'aimFromPlayer': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': False, 'selfTalkAnim': True, 'distanceOffset': 0.0})
        } {

            call return()

        }

    }
}

void trade() {
    switch Goriya.GetEquipedItemKind({'slotIndex': 'slotIndex'}) {
      case [0, 1, 3]:
        Goriya.Talk({'message': 'Npc:BadBoomerangGoriya'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
      case [2, 4, 5]:
        Goriya.SetFacialExpression({'expression': 'smile'})
        Goriya.Talk({'message': 'Warashibe:ClearBoomerang'})
        Goriya.TakeItem({'slotIndex': 'slotIndex'})
        Inventory.AddItem({'itemType': 8, 'count': 1, 'autoEquip': True})
        Link.GenericItemGetSequence({'itemType': 8, 'messageEntry': 'Boomerang', 'keepCarry': False})
        Goriya.SetFacialExpression({'expression': 'normal'})
    }
}

void cancel() {

    fork {
        Goriya.GenericTalkSequence({'aimToPlayer': False, 'aimFromPlayer': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': False, 'selfTalkAnim': True, 'distanceOffset': 0.0})
    } {
        Goriya.SetFacialExpression({'expression': 'angry'})
    } {
        Goriya.Talk({'message': 'Warashibe:BadBoomerang'})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    Goriya.SetFacialExpression({'expression': 'normal'})
}

void returnSub() {
    Hud.ShowRupee({'visible': True})
    Goriya.Talk({'message': 'askMessage'})
    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 300}) {
            Goriya.Talk({'message': 'ngMessage'})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {
            Link.AddRupee({'amount': -300})
            Goriya.ReturnItem({'autoEquip': False})
            Link.GenericItemGetSequence({'itemType': 'itemKind', 'messageEntry': 'gettingMessage', 'keepCarry': False})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    } else {

        call cancel()

    }
}

void return() {
    switch Goriya.GetKeptItemKind() {
      case 0:
        Goriya.Talk({'message': 'Warashibe:Get2BoomerangAfter'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
      case 2:

        call returnSub({'itemKind': 10, 'askMessage': 'Warashibe:BuyBoomerang2', 'ngMessage': 'Warashibe:NoBuyBoomerang2', 'gettingMessage': 'Boomerang3'})

      case 4:

        call returnSub({'itemKind': 9, 'askMessage': 'Warashibe:BuyBoomerang4', 'ngMessage': 'Warashibe:NoBuyBoomerang4', 'gettingMessage': 'Boomerang5'})

      case 5:

        call returnSub({'itemKind': 5, 'askMessage': 'Warashibe:BuyBoomerang5', 'ngMessage': 'Warashibe:NoBuyBoomerang5', 'gettingMessage': 'Boomerang6'})

    }
}
