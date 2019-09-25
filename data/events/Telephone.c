-------- EventFlow: Telephone --------

Actor: Telephone
entrypoint: None()
actions: ['ExamineKeep', 'Examine', 'Attach', 'Detach', 'LookAtInfomation', 'LookAtObjectsLinkedPoint', 'JumpToAppropriateHintEntry']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'AimActor', 'PlayAnimation', 'ResetAim']
queries: ['WithWanwan', 'WithCucco']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['SetBGMTrackVolume']
queries: []
params: None

void examine() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Link.AimActor({'duration': 0.10000000149011612, 'actor': ActorIdentifier(name="Telephone"), 'withoutTurn': False, 'boneName': ''})
    Link.ResetAim()

    fork {
        Link.PlayAnimation({'name': 'ev_tell_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_tell_lp', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.26669999957084656})
        Telephone.Attach()
    } {
        Telephone.LookAtObjectsLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        Telephone.JumpToAppropriateHintEntry()
    } {
        Audio.SetBGMTrackVolume({'label': 'BGM_TELEPHONE', 'track': 0, 'volume': 0.0, 'duration': 0.10000000149011612})
        Audio.SetBGMTrackVolume({'label': 'BGM_TELEPHONE', 'track': 1, 'duration': 0.10000000149011612, 'volume': 1.0})
    }


    fork {
        Link.PlayAnimation({'name': 'ev_tell_ed', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.20000000298023224})
        Telephone.Detach()
    } {
        Audio.SetBGMTrackVolume({'label': 'BGM_TELEPHONE', 'track': 0, 'duration': 0.10000000149011612, 'volume': 1.0})
        Audio.SetBGMTrackVolume({'label': 'BGM_TELEPHONE', 'track': 1, 'volume': 0.0, 'duration': 0.10000000149011612})
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void examine_ulrira() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Link.PlayAnimation({'name': 'ev_tell_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ev_tell_lp', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.26669999957084656})
        Telephone.Attach()
    } {
        Telephone.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        Telephone.Examine({'message': 'Telephone:TelephoneUlriraHouse'})
        Dialog.Show({'message': 'Telephone:TelephoneUlriraHouse2'})
    }


    fork {
        Link.PlayAnimation({'name': 'ev_tell_ed', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.20000000298023224})
        Telephone.Detach()
    }

    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void Level1() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneFirst2'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneFirst3'})
    }
}

void Bossblin() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv1Clear1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv1Clear2'})
    }
}

void Level2() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneBowwow1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneBowwow2'})
    }
}

void Madam() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv2Clear1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv2Clear2'})
    }
}

void Richard() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneTurnBowwow1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneTurnBowwow2'})
    }
}

void Banana() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneRichardMeet1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneRichardMeet2'})
    }
}

void Golden1() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafBomb1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
        EventFlags.SetFlag({'symbol': 'TelephoneTalked', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafBomb2'})
        EventFlags.SetFlag({'symbol': 'TelephoneTalked', 'value': True})
    }
}

void Golden2() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafCrow1'})
        EventFlags.SetFlag({'symbol': 'TelephoneTalked2', 'value': True})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafCrow2'})
        EventFlags.SetFlag({'symbol': 'TelephoneTalked2', 'value': True})
    }
}

void Golden3() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafSoldier1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafSoldier2'})
    }
}

void Field() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafScoop1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafScoop2'})
    }
}

void Level3() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneGetLv3Key1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneGetLv3Key2'})
    }
}

void Desert() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv3Clear1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv3Clear2'})
    }
}

void Level4() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneGetAnglerKey1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneGetAnglerKey2'})
    }
}

void Ghost() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv4Clear1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv4Clear2'})
    }
}

void Level5() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneGhostClear1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneGhostClear2'})
    }
}

void AmosShrine() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneGetMamuSong1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneGetMamuSong2'})
    }
}

void Mamu() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv51'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv52'})
    }
}

void broomWrashibe() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneYahooGrandma1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneYahooGrandma2'})
    }
}

void FlyingCocco() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv6Clear1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv6Clear2'})
    }
}

void Level7Key() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneGetCocco1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneGetCocco2'})
    }
}

void Level7() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneGetBirdKey1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneGetBirdKey2'})
    }
}

void TurtleRock() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv7Clear1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv7Clear2'})
    }
}

void Level8() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv8Clear1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv8Clear2'})
    }
}

void Level9() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLv8Play1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLv8Play2'})
    }
}

void Level9maze() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneBreakEgg1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneBreakEgg2'})
    }
}

void Level2Sword() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLastNoGetLv2Sword1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLastNoGetLv2Sword2'})
    }
}

void Level2SwordComplete() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneLastGetLv2Sword1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneLastGetLv2Sword2'})
    }
}

void Telephone() {
    if !Inventory.HasItem({'itemType': 45, 'count': 1}) {

        call Level1()

    } else
    if !Link.WithWanwan() {
        if !Inventory.HasItem({'itemType': 46, 'count': 1}) {

            call Bossblin()

        } else
        if !EventFlags.CheckFlag({'symbol': 'GoldenLeaf1'}) {

            call Richard()

        } else
        if !EventFlags.CheckFlag({'symbol': 'GoldenLeafCount'}) {

            call Banana()

        } else
        if !EventFlags.CheckFlag({'symbol': 'GoldenLeafComplete'}) {
            if !EventFlags.CheckFlag({'symbol': 'TelephoneTalked'}) {

                call Golden1()

            } else
            if !EventFlags.CheckFlag({'symbol': 'TelephoneTalked2'}) {

                call Golden2()

            } else {

                call Golden3()

            }
        } else
        if !Inventory.HasItem({'itemType': 26, 'count': 1}) {

            call Field()

        } else
        if !Inventory.HasItem({'itemType': 47, 'count': 1}) {

            call Level3()

        } else
        if !Inventory.HasItem({'itemType': 27, 'count': 1}) {

            call Desert()

        } else
        if !Inventory.HasItem({'itemType': 48, 'count': 1}) {

            call Level4()

        } else
        if !EventFlags.CheckFlag({'symbol': 'Ghost4_Clear'}) {

            call Ghost()

        } else
        if !Inventory.HasItem({'itemType': 49, 'count': 1}) {

            call Level5()

        } else
        if !Inventory.HasItem({'itemType': 50, 'count': 1}) {
            if !Inventory.HasItem({'itemType': 28, 'count': 1}) {

                call AmosShrine()

            } else
            if !Inventory.HasItem({'itemType': 55, 'count': 1}) {

                call Mamu()

            } else
            if !Link.WithCucco() {

                call FlyingCocco()

            } else {

                call Level7Key()

            }
        } else
        if !Inventory.HasItem({'itemType': 29, 'count': 1}) {

            call broomWrashibe()

        } else
        if !Inventory.HasItem({'itemType': 51, 'count': 1}) {

            call Level7()

        } else
        if !EventFlags.CheckFlag({'symbol': 'FourteenClear'}) {

            call TurtleRock()

        } else
        if !Inventory.HasItem({'itemType': 52, 'count': 1}) {

            call Level8()

        } else
        if !EventFlags.CheckFlag({'symbol': 'FiveteenClear'}) {

            call Level9()

        } else
        if !EventFlags.CheckFlag({'symbol': 'ShadowBattle'}) {

            call Level9maze()

        } else
        if !Inventory.HasItem({'itemType': 1, 'count': 1}) {

            call Level2Sword()

        } else {

            call Level2SwordComplete()

        }
    } else
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {

        call Level2()

    } else {

        call Madam()

    }
}

void Golden4() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafSoldier3'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafSoldier4'})
    }
}

void Golden5() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafSoldier5'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephonGoldLeafSoldier6'})
    }
}

void Bridge() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneFishhook1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneFishhook2'})
    }
}

void MermaidMartha() {
    if !EventFlags.CheckFlag({'symbol': 'FirstContact'}) {
        Telephone.ExamineKeep({'message': 'Telephone:TelephoneFirst1'})
        Telephone.Examine({'message': 'Telephone:TelephoneMermaid1'})
        EventFlags.SetFlag({'symbol': 'FirstContact', 'value': True})
    } else {
        Telephone.Examine({'message': 'Telephone:TelephoneMermaid2'})
    }
}
