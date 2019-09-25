-------- EventFlow: RaftShopMan --------

Actor: RaftShopMan
entrypoint: None()
actions: ['Talk', 'MoveToCompassPoint', 'Destroy', 'AimCompassPoint', 'GenericTalkSequence', 'SetFacialExpression']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult', 'GetLastResult4']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'AddRupee', 'GenericItemGetSequenceByKey', 'GenericItemGetSequence', 'PlayAnimation']
queries: ['CheckRupee']
params: None

Actor: RapidflowGame
entrypoint: None()
actions: ['SetGameConfig', 'StartGame']
queries: ['IsPlaying', 'GetTimeAttackResult', 'IsNewRecrod']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItemByKey', 'AddSecretShell']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM']
queries: []
params: None

Actor: Raft
entrypoint: None()
actions: ['ReturnToHomePosition']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['ShowRupee']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJumpInCurrentLevel']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    RaftShopMan.GenericTalkSequence({'playerTalkAnim': False, 'cameraLookAt': False, 'aimFromPlayer': True, 'keepPersonalSpace': True, 'selfTalkAnim': True, 'aimToPlayer': True, 'distanceOffset': 0.0})
    if !RapidflowGame.IsPlaying() {
        Hud.ShowRupee({'visible': True})
        RaftShopMan.Talk({'message': 'Npc:QuestRaftShop'})
        if !Dialog.GetLastResult() {
            if !Link.CheckRupee({'amount': 100}) {
                RaftShopMan.Talk({'message': 'SubEvent:NoMoneyRaftShop'})
                Hud.ShowRupee({'visible': False})
            } else {
                RaftShopMan.Talk({'message': 'SubEvent:LectureRaftShop'})
                switch Dialog.GetLastResult4() {
                  case 0:
                    RapidflowGame.SetGameConfig({'mode': 1})
                    Event16:
                    Link.AddRupee({'amount': -100})
                    RaftShopMan.SetFacialExpression({'expression': 'smile'})
                    RaftShopMan.Talk({'message': 'Npc:PlayRaftShop'})

                    fork {
                        RapidflowGame.StartGame()
                    } {
                        Hud.ShowRupee({'visible': False})
                    }

                    RaftShopMan.SetFacialExpression({'expression': 'normal'})
                  case 1:
                    RapidflowGame.SetGameConfig({'mode': 2})
                    goto Event16
                  case 2:
                    Event14:
                    RaftShopMan.Talk({'message': 'Npc:NoRaftShop'})
                    Hud.ShowRupee({'visible': False})
                }
            }
        } else {
            goto Event14
        }
    } else {
        RaftShopMan.SetFacialExpression({'expression': 'smile'})
        RaftShopMan.Talk({'message': 'Npc:PlayRaftShop'})
        RaftShopMan.SetFacialExpression({'expression': 'normal'})
    }
}

void timeAttackGoal() {
    Audio.StopBGM({'label': 'BGM_RAFTING_TIMEATTACK', 'duration': 0.0})
    RaftShopMan.Talk({'message': 'SubEvent:TimeRaftShop'})
    if RapidflowGame.IsNewRecrod() {
        RaftShopMan.Talk({'message': 'SubEvent:BestReftShop'})
    }
    switch RapidflowGame.GetTimeAttackResult() {
      case 0:
        RaftShopMan.Talk({'message': 'SubEvent:RecordRaftShop4'})
        if !EventFlags.CheckFlag({'symbol': '1minGaul'}) {

            call 1minfirst()

            Event18:
            RaftShopMan.Talk({'message': 'SubEvent:PlusRaftShop'})
            Link.AddRupee({'amount': 100})
            Event89:
            Hud.ShowRupee({'visible': True})
            RaftShopMan.Talk({'message': 'SubEvent:ReplayRaftShop'})
            if !Dialog.GetLastResult() {
                if !Link.CheckRupee({'amount': 100}) {
                    RaftShopMan.Talk({'message': 'SubEvent:NoMoneyRaftShop'})
                    Event90:
                    Hud.ShowRupee({'visible': False})
                    RaftShopMan.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
                    RaftShopMan.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 1.0, 'timeOut': 7.0})
                    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                    RaftShopMan.Destroy()
                } else {
                    Timer.Wait({'time': 0.5})
                    RaftShopMan.Talk({'message': 'SubEvent:LectureRaftShop'})
                    switch Dialog.GetLastResult4() {
                      case 0:
                        RapidflowGame.SetGameConfig({'mode': 1})
                        Event51:
                        Link.AddRupee({'amount': -100})
                        Timer.Wait({'time': 1.0})
                        Hud.ShowRupee({'visible': False})
                        Fade.StartPreset({'preset': 9})
                        Raft.ReturnToHomePosition()
                        RapidflowGame.StartGame()
                        GameControl.RequestLevelJumpInCurrentLevel({'locator': 'Field_04P', 'offsetX': 0.0, 'offsetZ': 0.0})
                      case 1:
                        RapidflowGame.SetGameConfig({'mode': 2})
                        goto Event51
                      case 2:
                        Event46:
                        RaftShopMan.Talk({'message': 'Npc:NoRaftShop'})
                        goto Event90
                    }
                }
            } else {
                goto Event46
            }
        } else
        if !EventFlags.CheckFlag({'symbol': '3minGaul'}) {

            call 3minfirst()

            goto Event18
        } else
        if !EventFlags.CheckFlag({'symbol': '5minGaul'}) {

            call 5minfirst()

            goto Event18
        } else {
            RaftShopMan.Talk({'message': 'SubEvent:GoldRaftShop'})
            Link.AddRupee({'amount': 300})
            goto Event89
        }
      case 1:
        RaftShopMan.Talk({'message': 'SubEvent:RecordRaftShop3'})
        if !EventFlags.CheckFlag({'symbol': '3minGaul'}) {

            call 3minfirst()

            goto Event89
        } else
        if !EventFlags.CheckFlag({'symbol': '5minGaul'}) {

            call 5minfirst()

            goto Event89
        } else {
            RaftShopMan.Talk({'message': 'SubEvent:SilverRaftShop'})
            Link.AddRupee({'amount': 100})
            goto Event89
        }
      case 2:
        RaftShopMan.Talk({'message': 'SubEvent:RecordRaftShop2'})
        if !EventFlags.CheckFlag({'symbol': '5minGaul'}) {

            call 5minfirst()

            goto Event89
        } else {
            RaftShopMan.Talk({'message': 'SubEvent:PurpleRaftShop'})
            Link.AddRupee({'amount': 50})
            goto Event89
        }
      case 3:
        RaftShopMan.Talk({'message': 'SubEvent:RecordRaftShop1'})
        goto Event89
    }
}

void 1minfirst() {
    RaftShopMan.Talk({'message': 'SubEvent:PeaceRaftShop'})
    Inventory.AddItemByKey({'count': 1, 'itemKey': 'PanelDungeonPiece', 'index': 8, 'autoEquip': False})
    Link.GenericItemGetSequenceByKey({'messageEntry': 'PanelDungeonPiece', 'itemKey': 'PanelDungeonPiece', 'keepCarry': False})
    Link.PlayAnimation({'name': 'raft_idle', 'blendTime': 0.10000000149011612})
    EventFlags.SetFlag({'symbol': '1minGaul', 'value': True})
}

void 3minfirst() {
    RaftShopMan.Talk({'message': 'SubEvent:ShellRaftShop'})
    Inventory.AddSecretShell({'index': 47})
    Link.GenericItemGetSequence({'itemType': 23, 'messageEntry': 'Seashell', 'keepCarry': False})
    Link.PlayAnimation({'name': 'raft_idle', 'blendTime': 0.10000000149011612})
    EventFlags.SetFlag({'symbol': '3minGaul', 'value': True})
}

void 5minfirst() {
    RaftShopMan.Talk({'message': 'SubEvent:HeartRaftShop'})
    Link.GenericItemGetSequenceByKey({'itemKey': 'HeartPiece', 'messageEntry': 'HeartPiece', 'keepCarry': False})
    Inventory.AddItemByKey({'count': 1, 'itemKey': 'HeartPiece', 'index': 29, 'autoEquip': False})
    Link.PlayAnimation({'name': 'raft_idle', 'blendTime': 0.10000000149011612})
    EventFlags.SetFlag({'symbol': '5minGaul', 'value': True})
}

void normalGoal() {
    Audio.StopBGM({'label': 'BGM_RAFTING_TIMEATTACK', 'duration': 0.0})
    RaftShopMan.Talk({'message': 'SubEvent:GatherRaftShop'})
    goto Event89
}
