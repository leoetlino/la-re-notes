-------- EventFlow: Pedestal --------

Actor: Pedestal
entrypoint: None()
actions: ['PutFigure', 'LookAtInfomation']
queries: ['HasFigure', 'IsPutFigure']
params: None

Actor: Link
entrypoint: None()
actions: ['Talk', 'AimActor', 'KeepDistanceFromActor', 'ResetAim']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

void UFOSmallBowWow() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:CheckCanCam'})
        } else {
            Link.Talk({'message': 'System:CheckCanCam'})
            Link.Talk({'message': 'System:QuestCanCam'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'symbol': 'SmallBowWowFigure', 'value': True})
            }
        }
    } else {
        Link.Talk({'message': 'System:SeeCanCam'})
    }
}

void UFOKuribo() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:Checkkuribo'})
        } else {
            Link.Talk({'message': 'System:Checkkuribo'})
            Link.Talk({'message': 'System:Questkuribo'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'KuriboFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:Seekuribo'})
    }
}

void UFOTogezo() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:Checktogezo'})
        } else {
            Link.Talk({'message': 'System:Checktogezo'})
            Link.Talk({'message': 'System:Questtogezo'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'TogezoFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:Seetogezo'})
    }
}

void UFOTeresa() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:Checkteresa'})
        } else {
            Link.Talk({'message': 'System:Checkteresa'})
            Link.Talk({'message': 'System:Questteresa'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'TeresaFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:Seeteresa'})
    }
}

void UFOPukuPuku() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:Checkpukupuku'})
        } else {
            Link.Talk({'message': 'System:Checkpukupuku'})
            Link.Talk({'message': 'System:Questpukupuku'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'PukuPukuFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:Seepukupuku'})
    }
}

void UFOGesso() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:CheckGeso'})
        } else {
            Link.Talk({'message': 'System:CheckGeso'})
            Link.Talk({'message': 'System:QuestGeso'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'GessoFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:SeeGeso'})
    }
}

void UFOHeiho() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:CheckHeiho'})
        } else {
            Link.Talk({'message': 'System:CheckHeiho'})
            Link.Talk({'message': 'System:QuestHeiho'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'HeihoFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:SeeHeiho'})
    }
}

void UFOPakkun() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:CheckPakkun'})
        } else {
            Link.Talk({'message': 'System:CheckPakkun'})
            Link.Talk({'message': 'System:QuestPakkun'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'PakkunFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:SeePakkun'})
    }
}

void UFOPokey() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:CheckSanbo'})
        } else {
            Link.Talk({'message': 'System:CheckSanbo'})
            Link.Talk({'message': 'System:QuestSanbo'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'PokeyFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:SeeSanbo'})
    }
}

void UFOBowWow() {

    call UFOCommon()

    if !Pedestal.IsPutFigure() {
        if !Pedestal.HasFigure() {
            Link.Talk({'message': 'System:CheckBowwow'})
        } else {
            Link.Talk({'message': 'System:CheckBowwow'})
            Link.Talk({'message': 'System:QuestBowwow'})
            if !Dialog.GetLastResult() {
                Pedestal.PutFigure()
                EventFlags.SetFlag({'value': True, 'symbol': 'BowWowFigure'})
            }
        }
    } else {
        Link.Talk({'message': 'System:SeeBowwow'})
    }
}

void UFOCommon() {

    fork {
        Pedestal.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="Pedestal"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Link.ResetAim()
    } {
        Link.KeepDistanceFromActor({'animName': 'ev_talkback', 'actor': ActorIdentifier(name="Pedestal"), 'distance': 1.5})
    }

}
