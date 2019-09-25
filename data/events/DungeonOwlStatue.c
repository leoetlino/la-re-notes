-------- EventFlow: DungeonOwlStatue --------

Actor: DungeonOwlStatue
entrypoint: None()
actions: ['Examine', 'PlayOneshotSE', 'SetActorSwitch', 'PlayTailorOtherChannelEx', 'StopTailorOtherChannel', 'LookAtGimmick']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'PlayAnimation', 'KeepDistanceFromActor']
queries: []
params: None

void examine_NoBeak() {
    DungeonOwlStatue.Examine({'message': 'Hint:NoBeakStoneOwl'})
}

void examine_Tail04B05F() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv1StoneOwl1'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Tail04C() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv1StoneOwl2'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Pod07E() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv2StoneOwl1'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Pod06G() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv2StoneOwl2'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Pod04C() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv2StoneOwl3'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Key03G() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv3StoneOwl1'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Key02D() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv3StoneOwl2'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Key01A() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv3StoneOwl3'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Angler05E() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv4StoneOwl'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Namazu06F() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv5StoneOwl1'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Namazu03C() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv5StoneOwl2'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Face04D() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv6StoneOwl1'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Face08G() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv6StoneOwl2'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Face03G() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv6StoneOwl3'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Eagle02D() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv7StoneOwl1'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Eagle05D() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv7StoneOwl2'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Eagle04B() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv7StoneOwl3'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Turtle06H() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv8StoneOwl1'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Turtle04G() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv8StoneOwl2'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Turtle04C() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Lv8StoneOwl3'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void examine_Color() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:ColorDungeonStoneOwl'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}

void Beak_st() {

    fork {
        DungeonOwlStatue.PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'On', 'restart': False, 'index': 0})
    } {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        DungeonOwlStatue.PlayOneshotSE({'label': 'SE_MAP_OWL_BEAK_SET', 'volume': 1.0, 'pitch': 1.0})
    } {
        DungeonOwlStatue.SetActorSwitch({'value': True, 'switchIndex': 0})
    } {
        DungeonOwlStatue.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'actor': ActorIdentifier(name="DungeonOwlStatue"), 'distance': 1.600000023841858})
    }

}

void Beak_ed() {

    fork {
        DungeonOwlStatue.SetActorSwitch({'value': False, 'switchIndex': 0})
    } {
        DungeonOwlStatue.StopTailorOtherChannel({'channel': 'On', 'index': 0})
    }

}

void examine_Panel_Pod04C() {
    if !Inventory.HasItem({'itemType': 63, 'count': 1}) {

        call examine_NoBeak()

    } else {

        fork {

            call Beak_st()

        } {
            DungeonOwlStatue.Examine({'message': 'Hint:Panel_Pod04C'})
        } {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        call Beak_ed()

    }
}
