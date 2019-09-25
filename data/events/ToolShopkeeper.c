-------- EventFlow: ToolShopkeeper --------

Actor: ToolShopkeeper[AngerKeeper]
entrypoint: None()
actions: ['TalkKeep', 'PlayAnimation', 'DecreasePlayerLife', 'SetFacialExpression', 'PlayOneshotSE', 'Talk']
queries: []
params: None

Actor: ToolShopkeeper
entrypoint: None()
actions: ['Talk', 'RemoveGoods', 'RestoreGoods', 'GenericTalkSequence', 'AddPanel']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['AddRupee', 'Heal', 'SetEquipmentVisibility', 'MoveToCompassPoint', 'PlayAnimation', 'PlayTailorOtherChannelNoWait', 'StopTailorOtherChannel', 'GenericItemGetSequence', 'GenericItemGetSequenceByKey']
queries: ['CheckRupee', 'CheckDamage']
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem', 'AddItemByKey']
queries: ['HasItem']
params: None

Actor: Hud
entrypoint: None()
actions: ['SetHeartUpdateEnable', 'ShowRupee']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'Npc:GreetingToolShop'})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void Take_Shield() {
    Hud.ShowRupee({'visible': True})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'System:BuyShield'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 20}) {
            ToolShopkeeper.Talk({'message': 'Npc:NoneMoneyToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else
        if !Inventory.HasItem({'itemType': 2, 'count': 1})
        && !Inventory.HasItem({'itemType': 3, 'count': 1}) {
            Link.AddRupee({'amount': -20})
            Inventory.AddItem({'count': 1, 'itemType': 2, 'autoEquip': False})
            ToolShopkeeper.RemoveGoods()
            ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
            Link.GenericItemGetSequence({'itemType': 2, 'messageEntry': 'ShopShield', 'keepCarry': False})
        } else {
            ToolShopkeeper.Talk({'message': 'Npc:HaveItemToolShop'})
            ToolShopkeeper.RestoreGoods()
        }
    } else {
        ToolShopkeeper.RestoreGoods()
    }
}

void Take_Bow() {
    Hud.ShowRupee({'visible': True})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'System:BuyBow'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 980}) {
            ToolShopkeeper.Talk({'message': 'Npc:NoneMoneyToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else
        if !Inventory.HasItem({'count': 1, 'itemType': 5}) {
            Link.AddRupee({'amount': -980})
            Inventory.AddItem({'itemType': 5, 'count': 1, 'autoEquip': False})
            Inventory.AddItem({'itemType': 6, 'count': 20, 'autoEquip': False})
            ToolShopkeeper.RemoveGoods()
            ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
            EventFlags.SetFlag({'value': True, 'symbol': 'BowGet'})
        } else {
            ToolShopkeeper.Talk({'message': 'Npc:HaveItemToolShop'})
            ToolShopkeeper.RestoreGoods()
        }
    } else {
        ToolShopkeeper.RestoreGoods()
    }
}

void Take_Arrow() {
    Hud.ShowRupee({'visible': True})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'System:BuyArrow'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 10}) {
            ToolShopkeeper.Talk({'message': 'Npc:NoneMoneyToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else
        if !Inventory.HasItem({'itemType': 58, 'count': 60}) {
            if !Inventory.HasItem({'itemType': 6, 'count': 30}) {
                Link.AddRupee({'amount': -10})
                Inventory.AddItem({'itemType': 6, 'count': 10, 'autoEquip': False})
                ToolShopkeeper.RestoreGoods()
                ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
            } else {
                ToolShopkeeper.Talk({'message': 'Npc:HaveItemToolShop'})
                ToolShopkeeper.RestoreGoods()
            }
        } else
        if !Inventory.HasItem({'itemType': 6, 'count': 60}) {
            Link.AddRupee({'amount': -10})
            Inventory.AddItem({'itemType': 6, 'count': 10, 'autoEquip': False})
            ToolShopkeeper.RestoreGoods()
            ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
        } else {
            ToolShopkeeper.Talk({'message': 'Npc:HaveItemToolShop'})
            ToolShopkeeper.RestoreGoods()
        }
    } else {
        ToolShopkeeper.RestoreGoods()
    }
}

void Take_Bomb() {
    Hud.ShowRupee({'visible': True})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'System:BuyBomb'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 10}) {
            ToolShopkeeper.Talk({'message': 'Npc:NoneMoneyToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else
        if !Inventory.HasItem({'itemType': 57, 'count': 60}) {
            if !Inventory.HasItem({'itemType': 4, 'count': 30}) {
                Link.AddRupee({'amount': -10})
                Inventory.AddItem({'count': 10, 'itemType': 4, 'autoEquip': False})
                ToolShopkeeper.RestoreGoods()
                ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
                EventFlags.SetFlag({'value': True, 'symbol': 'ShopBuyBomb'})
            } else {
                ToolShopkeeper.Talk({'message': 'Npc:HaveItemToolShop'})
                ToolShopkeeper.RestoreGoods()
            }
        } else
        if !Inventory.HasItem({'itemType': 4, 'count': 60}) {
            if !EventFlags.CheckFlag({'symbol': 'DevilPowder'}) {
                Event183:
                Link.AddRupee({'amount': -10})
                Inventory.AddItem({'itemType': 4, 'count': 10, 'autoEquip': False})
                ToolShopkeeper.RestoreGoods()
                ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
            } else
            if !EventFlags.CheckFlag({'symbol': 'ShopBuyBomb'}) {
                Link.AddRupee({'amount': -10})
                Inventory.AddItem({'itemType': 4, 'count': 60, 'autoEquip': False})
                ToolShopkeeper.RestoreGoods()
                ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
                EventFlags.SetFlag({'value': True, 'symbol': 'ShopBuyBomb'})
            } else {
                goto Event183
            }
        } else {
            ToolShopkeeper.Talk({'message': 'Npc:HaveItemToolShop'})
            ToolShopkeeper.RestoreGoods()
        }
    } else {
        ToolShopkeeper.RestoreGoods()
    }
}

void Take_Heart() {
    Hud.ShowRupee({'visible': True})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'System:BuyHeart'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 10}) {
            ToolShopkeeper.Talk({'message': 'Npc:NoneMoneyToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else
        if !Link.CheckDamage({'amount': 1}) {
            ToolShopkeeper.Talk({'message': 'Npc:HaveItemToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else {
            Link.AddRupee({'amount': -10})
            Link.Heal({'amount': 12})
            ToolShopkeeper.RestoreGoods()
            ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
        }
    } else {
        ToolShopkeeper.RestoreGoods()
    }
}

void AngerDad() {
    Audio.StopAllBGM({'duration': 0.0})

    fork {
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
    } {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.75, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        EventFlags.SetFlag({'symbol': 'ShopKeeperCounterattack', 'value': True})
    }

    ToolShopkeeper[AngerKeeper].TalkKeep({'message': 'SubEvent:DorobouComeShop1'})

    fork {
        ToolShopkeeper[AngerKeeper].Talk({'message': 'SubEvent:DorobouComeShop2'})
    } {
        ToolShopkeeper[AngerKeeper].SetFacialExpression({'expression': 'angry'})
    }

    Hud.SetHeartUpdateEnable({'enable': True})
    ToolShopkeeper[AngerKeeper].PlayAnimation({'name': 'beam_st', 'blendTime': 0.10000000149011612})

    fork {
        Link.PlayAnimation({'name': 'ev_dmg_elec_lp', 'blendTime': 0.10000000149011612})
    } {
        ToolShopkeeper[AngerKeeper].DecreasePlayerLife({'speed': 8.0})
    } {
        Timer.Wait({'time': 3.0})
    } {
        ToolShopkeeper[AngerKeeper].PlayAnimation({'name': 'beam_lp', 'blendTime': 0.10000000149011612})
    } {
        ToolShopkeeper[AngerKeeper].PlayOneshotSE({'label': 'SE_NPC_SHOP_005', 'volume': 1.0, 'pitch': 1.0})
    } {
        Link.PlayTailorOtherChannelNoWait({'channel': 'toolshopkeeper_dmg', 'restart': False, 'index': 0})
    }


    fork {
        ToolShopkeeper[AngerKeeper].SetFacialExpression({'expression': 'normal'})
    } {
        ToolShopkeeper[AngerKeeper].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Link.StopTailorOtherChannel({'channel': 'toolshopkeeper_dmg', 'index': 0})
    }

    EventFlags.SetFlag({'value': False, 'symbol': 'StealSuccess'})
}

void Take_Scoop() {
    Hud.ShowRupee({'visible': True})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'System:BuyScoop'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 200}) {
            ToolShopkeeper.Talk({'message': 'Npc:NoneMoneyToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else
        if !Inventory.HasItem({'itemType': 10, 'count': 1}) {
            Link.AddRupee({'amount': -200})
            Inventory.AddItem({'itemType': 10, 'count': 1, 'autoEquip': False})
            ToolShopkeeper.RemoveGoods()
            ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
            Link.GenericItemGetSequence({'itemType': 10, 'messageEntry': 'Shovel', 'keepCarry': False})
            EventFlags.SetFlag({'symbol': 'ScoopGet', 'value': True})
        } else {
            ToolShopkeeper.Talk({'message': 'Npc:HaveItemToolShop'})
            ToolShopkeeper.RestoreGoods()
        }
    } else {
        ToolShopkeeper.RestoreGoods()
    }
}

void detain() {

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'aimFromPlayer': False, 'playerTalkAnim': False, 'keepPersonalSpace': True, 'aimToPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'SubEvent:AngryShopkeeper'})
    }

    Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.5, 'timeOut': 7.0})
}

void Take_HeartPeace() {
    Hud.ShowRupee({'visible': True})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'System:BuyHeartPeace'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 200}) {
            ToolShopkeeper.Talk({'message': 'Npc:NoneMoneyToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else {
            Link.AddRupee({'amount': -200})
            ToolShopkeeper.RemoveGoods()
            ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
            Link.GenericItemGetSequenceByKey({'itemKey': 'HeartPiece', 'messageEntry': 'HeartPiece', 'keepCarry': False})
            Inventory.AddItemByKey({'count': 1, 'index': 24, 'itemKey': 'HeartPiece', 'autoEquip': False})
        }
    } else {
        ToolShopkeeper.RestoreGoods()
    }
}

void Take_PanelPeace() {
    Hud.ShowRupee({'visible': True})

    fork {
        ToolShopkeeper.GenericTalkSequence({'cameraLookAt': False, 'selfTalkAnim': True, 'playerTalkAnim': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
    } {
        ToolShopkeeper.Talk({'message': 'System:BuyPanelPeace'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 1280}) {
            ToolShopkeeper.Talk({'message': 'Npc:NoneMoneyToolShop'})
            ToolShopkeeper.RestoreGoods()
        } else {
            Link.AddRupee({'amount': -1280})
            ToolShopkeeper.AddPanel()
            ToolShopkeeper.RemoveGoods()
            ToolShopkeeper.Talk({'message': 'Npc:BuyToolShop'})
            Link.GenericItemGetSequenceByKey({'messageEntry': 'PanelDungeonPiece', 'itemKey': 'PanelDungeonPiece', 'keepCarry': False})
        }
    } else {
        ToolShopkeeper.RestoreGoods()
    }
}
