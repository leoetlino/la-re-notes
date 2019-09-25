-------- EventFlow: Chest --------

Actor: Marin[companion]
entrypoint: None()
actions: ['Talk', 'AimPlayer', 'LookAtTalker']
queries: []
params: None

Actor: Tarin[Tarin]
entrypoint: None()
actions: ['Talk', 'AimPlayer', 'LookAtTalker']
queries: []
params: None

Actor: MadamMeowMeow[Madam]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: QuadrupletsMother[Mother]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Papahl[Father]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: DrWrite[DrWrite]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Richard[Richard]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: CrazyTracy[CrazyTracy]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: RibbonBowWow[RibbonBowWow]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: SmallBowWow[SmallBowWow]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['ResetAim']
queries: ['WithMarin']
params: None

Actor: EventFlags
entrypoint: None()
actions: []
queries: ['CheckFlag']
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Chest
entrypoint: None()
actions: ['Examine', 'LookAtInfomation']
queries: []
params: None

Actor: Marin[Marin]
entrypoint: None()
actions: ['Activate', 'AimPlayer', 'SetFacialExpression', 'PlayAnimation']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['LookAt3ActorsCenterAsTalker']
queries: []
params: None

void ChestA() {
    if !Link.WithMarin() {
        if !EventFlags.CheckFlag({'symbol': 'FirstClear'}) {
            Marin[Marin].Activate()

            fork {
                Tarin[Tarin].Talk({'message': 'Npc:TarinCheckDresser'})
            } {
                Tarin[Tarin].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
            } {
                Camera.LookAt3ActorsCenterAsTalker({'actor1': ActorIdentifier(name="Link"), 'actor2': ActorIdentifier(name="Tarin", sub_name="Tarin"), 'actor3': ActorIdentifier(name="Chest"), 'weight1': 1.0, 'weight2': 1.0, 'weight3': 1.0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
            } {
                Marin[Marin].SetFacialExpression({'expression': 'surprise'})
            } {
                Marin[Marin].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                Marin[Marin].PlayAnimation({'name': 'surprise_st', 'blendTime': 0.10000000149011612})
                Marin[Marin].PlayAnimation({'name': 'surprise_lp', 'blendTime': 0.10000000149011612})
            }

            Link.ResetAim()
            Marin[Marin].SetFacialExpression({'expression': 'normal'})
        } else
        if !Inventory.HasItem({'itemType': 46, 'count': 1}) {

            fork {
                Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
            } {
                Chest.Examine({'message': 'System:CheckDresser'})
            }

        } else
        if !EventFlags.CheckFlag({'symbol': 'StickDrop'}) {

            fork {
                Tarin[Tarin].Talk({'message': 'Npc:TarinCheckDresser'})
            } {
                Tarin[Tarin].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
            } {
                Tarin[Tarin].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
            }

            Link.ResetAim()
        } else {

            fork {
                Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
            } {
                Chest.Examine({'message': 'System:CheckDresser'})
            }

        }
    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.ResetAim()
    }
}

void ChestB() {
    if !Link.WithMarin() {

        fork {
            MadamMeowMeow[Madam].Activate()
        } {
            SmallBowWow[SmallBowWow].Activate()
        } {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckDresser'})
        } {
            RibbonBowWow[RibbonBowWow].Activate()
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.ResetAim()
    }
}

void ChestC() {
    if !Link.WithMarin() {

        fork {
            QuadrupletsMother[Mother].Activate()
        } {
            Papahl[Father].Activate()
        } {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckDresser'})
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            QuadrupletsMother[Mother].Activate()
        } {
            Papahl[Father].Activate()
        }

        Link.ResetAim()
    }
}

void ChestD() {
    if !Link.WithMarin() {

        fork {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckDresser'})
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.ResetAim()
    }
}

void ChestE() {
    if !Link.WithMarin() {

        fork {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckBookshelf'})
        } {
            DrWrite[DrWrite].Activate()
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            DrWrite[DrWrite].Activate()
        }

        Link.ResetAim()
    }
}

void ChestF() {
    if !Link.WithMarin() {

        fork {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckDresser'})
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.ResetAim()
    }
}

void ChestG() {
    if !Link.WithMarin() {

        fork {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckDresser'})
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.ResetAim()
    }
}

void ChestI() {
    if !Link.WithMarin() {

        fork {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckDresser'})
        } {
            Richard[Richard].Activate()
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            Richard[Richard].Activate()
        }

        Link.ResetAim()
    }
}

void ChestJ() {
    if !Link.WithMarin() {

        fork {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckShelf'})
        } {
            CrazyTracy[CrazyTracy].Activate()
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            CrazyTracy[CrazyTracy].Activate()
        }

        Link.ResetAim()
    }
}

void ChestK() {
    if !Link.WithMarin() {

        fork {
            Chest.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {
            Chest.Examine({'message': 'System:CheckGhostShelf'})
        }

    } else {

        fork {
            Marin[companion].Talk({'message': 'SubEvent:MarinCheckDresser'})
        } {
            Marin[companion].AimPlayer({'duration': 0.5, 'withoutTurn': False, 'boneName': ''})
        } {
            Marin[companion].LookAtTalker({'duration': 0.5, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.ResetAim()
    }
}
