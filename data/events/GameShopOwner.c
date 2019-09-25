-------- EventFlow: GameShopOwner --------

Actor: Marin[companion]
entrypoint: None()
actions: ['Talk', 'SetFacialExpression', 'MoveToTargetLinkedPoint', 'AimActor', 'MoveToCompassPoint', 'PlayAnimation']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset']
queries: []
params: None

Actor: GameShopOwner
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetFacialExpression', 'SetActorSwitch', 'PopCraneFence', 'DepopCraneFence', 'ResumeCamera', 'LookAtTalker', 'MoveHookedInArmsPrizes']
queries: ['CheckPrizeEmpty', 'CheckActorSwitch', 'CheckPrizeHookedInArms']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: ['GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'AddRupee', 'MoveToCompassPoint', 'AimActor', 'SetFacialExpression', 'GenericItemGetSequenceByKey', 'AimCompassPoint', 'PlayAnimation']
queries: ['CheckRupee']
params: None

Actor: FlowControl
entrypoint: None()
actions: ['SetReturnValue']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['ShowRupee', 'PlayCraneOutAnim', 'PlayCraneInAnim', 'PlayInAnim', 'PlayOutAnim', 'SetOpenMenuEnable']
queries: []
params: None

Actor: Marin
entrypoint: None()
actions: ['SetFacialExpression', 'ResetAim']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Marin[Marin]
entrypoint: None()
actions: ['SetFacialExpression', 'PlayAnimation']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItemByKey']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag', 'SetLevelFlag']
queries: ['CheckFlag', 'CheckLevelFlag']
params: None

Actor: Audio
entrypoint: None()
actions: ['StopZoneAudio']
queries: []
params: None

void talk() {
    if !GameShopOwner.CheckActorSwitch({'switchIndex': 0}) {
        if !GameShopOwner.CheckPrizeEmpty() {
            GameShopOwner.SetFacialExpression({'expression': 'normal'})
            GameShopOwner.ResumeCamera()
            GameShopOwner.Talk({'message': 'Npc:CloseGameShop'})
            Hud.PlayInAnim()
            Hud.SetOpenMenuEnable({'enable': True})
            FlowControl.SetReturnValue({'value': 0})
        } else {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
            GameShopOwner.SetFacialExpression({'expression': 'normal'})
            GameShopOwner.GenericTalkSequence({'keepPersonalSpace': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})

            fork {
                Hud.PlayCraneInAnim()
            } {
                Hud.ShowRupee({'visible': True})
            }

            if !EventFlags.CheckFlag({'symbol': 'BowWowFigureGet'}) {
                GameShopOwner.Talk({'message': 'Npc:QuestGameShop'})
                if !Dialog.GetLastResult() {
                    if !Link.CheckRupee({'amount': 10}) {
                        GameShopOwner.Talk({'message': 'Npc:NoneMoneyToolShop'})
                        Hud.PlayCraneOutAnim()
                        FlowControl.SetReturnValue({'value': 0})
                    } else {
                        Link.AddRupee({'amount': -10})
                        GameShopOwner.SetActorSwitch({'switchIndex': 0, 'value': True})
                        GameShopOwner.Talk({'message': 'Npc:PlayGameShop'})

                        fork {
                            Hud.PlayCraneOutAnim()
                        } {
                            Camera.Reset({'chaseRatio': 0.10000000149011612})
                        }

                        GameShopOwner.PopCraneFence()
                        FlowControl.SetReturnValue({'value': -1})
                    }
                } else {
                    GameShopOwner.Talk({'message': 'Npc:NoGameShop'})
                    Hud.PlayCraneOutAnim()
                    FlowControl.SetReturnValue({'value': 0})
                }
            } else {
                GameShopOwner.Talk({'message': 'Npc:QuestGameShopCheap'})
                if !Dialog.GetLastResult() {
                    if !Link.CheckRupee({'amount': 5}) {
                        GameShopOwner.Talk({'message': 'Npc:NoneMoneyToolShop'})
                        Hud.PlayCraneOutAnim()
                        FlowControl.SetReturnValue({'value': 0})
                    } else {
                        Link.AddRupee({'amount': -5})
                        GameShopOwner.SetActorSwitch({'switchIndex': 0, 'value': True})
                        GameShopOwner.Talk({'message': 'Npc:PlayGameShop'})

                        fork {
                            Hud.PlayCraneOutAnim()
                        } {
                            Camera.Reset({'chaseRatio': 0.10000000149011612})
                        }

                        GameShopOwner.PopCraneFence()
                        FlowControl.SetReturnValue({'value': -1})
                    }
                } else {
                    GameShopOwner.Talk({'message': 'Npc:NoGameShop'})
                    Hud.PlayCraneOutAnim()
                    FlowControl.SetReturnValue({'value': 0})
                }
            }
        }
    } else {
        GameShopOwner.Talk({'message': 'Npc:PlayGameShop'})
        FlowControl.SetReturnValue({'value': -1})
    }
}

void SecondPlay() {
    GameShopOwner.SetActorSwitch({'switchIndex': 0, 'value': False})
    if !GameShopOwner.CheckPrizeHookedInArms() {
        Event38:
        if !GameShopOwner.CheckPrizeEmpty() {
            GameShopOwner.SetFacialExpression({'expression': 'normal'})
            GameShopOwner.ResumeCamera()
            GameShopOwner.Talk({'message': 'Npc:CloseGameShop'})
            GameShopOwner.DepopCraneFence()
            Timer.Wait({'time': 0.75})
        } else {
            Hud.PlayInAnim()
            GameShopOwner.SetFacialExpression({'expression': 'normal'})
            Hud.ShowRupee({'visible': True})
            GameShopOwner.Talk({'message': 'Npc:ReplayGameShop'})
            if !Dialog.GetLastResult() {
                if !EventFlags.CheckFlag({'symbol': 'BowWowFigureGet'}) {
                    if !Link.CheckRupee({'amount': 10}) {
                        GameShopOwner.Talk({'message': 'Npc:NoneMoneyToolShop'})
                        GameShopOwner.ResumeCamera()
                        GameShopOwner.DepopCraneFence()
                        Hud.SetOpenMenuEnable({'enable': True})
                        FlowControl.SetReturnValue({'value': 0})
                    } else {
                        Link.AddRupee({'amount': -10})
                        GameShopOwner.Talk({'message': 'Npc:ContinueGameShop'})
                        Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
                        Hud.PlayOutAnim()
                        FlowControl.SetReturnValue({'value': 1})
                    }
                } else
                if !Link.CheckRupee({'amount': 5}) {
                    GameShopOwner.Talk({'message': 'Npc:NoneMoneyToolShop'})
                    GameShopOwner.ResumeCamera()
                    GameShopOwner.DepopCraneFence()
                    Timer.Wait({'time': 0.75})
                    Hud.SetOpenMenuEnable({'enable': True})
                    FlowControl.SetReturnValue({'value': 0})
                } else {
                    Link.AddRupee({'amount': -5})
                    GameShopOwner.Talk({'message': 'Npc:ContinueGameShop'})
                    Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
                    Hud.PlayOutAnim()
                    FlowControl.SetReturnValue({'value': 1})
                }
            } else {
                Hud.ShowRupee({'visible': False})
                GameShopOwner.Talk({'message': 'Npc:NoGameShop'})
                GameShopOwner.ResumeCamera()
                Timer.Wait({'time': 1.5})

                fork {
                    GameShopOwner.DepopCraneFence()
                } {
                    Hud.SetOpenMenuEnable({'enable': True})
                }

                Timer.Wait({'time': 0.75})
                FlowControl.SetReturnValue({'value': 0})
            }
        }
    } else {
        GameShopOwner.Talk({'message': 'Npc:TroubleGameShop'})
        Fade.StartPreset({'preset': 5})
        Timer.Wait({'time': 1.0})
        GameShopOwner.MoveHookedInArmsPrizes()
        Timer.Wait({'time': 2.0})
        Fade.StartPreset({'preset': 4})
        goto Event38
    }
}

void Game_talk() {
    Hud.PlayCraneInAnim()
    GameShopOwner.SetFacialExpression({'expression': 'normal'})

    fork {
        Marin[companion].MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'actor': ActorIdentifier(name="GameShopOwner"), 'timeOut': 7.0})
        Marin[companion].AimActor({'actor': ActorIdentifier(name="Link"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Link.AimActor({'duration': 0.4000000059604645, 'actor': ActorIdentifier(name="Marin", sub_name="companion"), 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Marin[companion].SetFacialExpression({'expression': 'excite'})
    } {
        Marin[companion].PlayAnimation({'name': 'exciting', 'blendTime': 0.10000000149011612})
    } {
        Hud.ShowRupee({'visible': True})
    }

    Marin[companion].Talk({'message': 'SubEvent:WantPlayGameMarin1'})
    Dialog.Show({'message': 'SubEvent:WantPlayGameMarin3'})
    if Dialog.GetLastResult() {
        Marin[companion].Talk({'message': 'SubEvent:WantPlayGameMarin2'})
    }
    if !Link.CheckRupee({'amount': 10}) {
        GameShopOwner.Talk({'message': 'Npc:NoneMoneyToolShop'})
        Hud.PlayCraneOutAnim()
        FlowControl.SetReturnValue({'value': 0})
    } else {
        Link.AddRupee({'amount': -10})
        Marin.SetFacialExpression({'expression': 'normal'})

        fork {
            Marin.ResetAim()
        } {
            Marin[companion].MoveToCompassPoint({'speed': 0, 'direction': 2, 'distance': 0.800000011920929, 'timeOut': 7.0})
        }


        fork {
            Marin[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.15000000596046448})
        }

        Hud.PlayCraneOutAnim()
        GameShopOwner.PopCraneFence()
        EventFlags.SetFlag({'symbol': 'MarinGame', 'value': True})
        FlowControl.SetReturnValue({'value': 2})
    }
}

void Angry() {

    fork {
        Link.AimActor({'duration': 0.4000000059604645, 'actor': ActorIdentifier(name="GameShopOwner"), 'withoutTurn': False, 'boneName': ''})
    } {
        Marin[companion].AimActor({'actor': ActorIdentifier(name="GameShopOwner"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        GameShopOwner.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.SetFacialExpression({'expression': 'wakeup'})
    } {
        Marin[Marin].SetFacialExpression({'expression': 'surprise'})
    } {
        Marin[Marin].PlayAnimation({'name': 'surprise_st', 'blendTime': 0.10000000149011612})
        Marin[Marin].PlayAnimation({'name': 'surprise_lp', 'blendTime': 0.10000000149011612})
    }

    GameShopOwner.Talk({'message': 'SubEvent:AngryGameCreek'})
    Marin[companion].SetFacialExpression({'expression': 'normal'})

    fork {
        GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_12D', 'offsetX': 0.0, 'offsetZ': 0.0})
    } {
        Fade.StartPreset({'preset': 9})
    }


    fork {
        Link.SetFacialExpression({'expression': 'normal'})
    } {
        Marin[Marin].SetFacialExpression({'expression': 'normal'})
    } {
        Audio.StopZoneAudio()
    }

    Hud.PlayCraneOutAnim()
    FlowControl.SetReturnValue({'value': 0})
}

void ExitGameShop() {
    GameShopOwner.Talk({'message': 'Npc:ExitGameShop'})
    if !Dialog.GetLastResult() {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.5, 'timeOut': 7.0})
    } else {
        GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_12D', 'offsetX': 0.0, 'offsetZ': 0.0})
    }
}

void ForgetGameShop() {
    GameShopOwner.Talk({'message': 'Npc:ForgetGameShop'})
    if !Dialog.GetLastResult() {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.5, 'timeOut': 7.0})
    } else {
        GameControl.RequestLevelJump({'level': 'Field', 'locator': 'Field_12D', 'offsetX': 0.0, 'offsetZ': 0.0})
    }
}

void BowWowFigureGet() {

    fork {
        Camera.Reset({'chaseRatio': 0.20000000298023224})
    } {
        Link.AimActor({'duration': 0.4000000059604645, 'actor': ActorIdentifier(name="GameShopOwner"), 'withoutTurn': False, 'boneName': ''})
    } {
        Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

    GameShopOwner.Talk({'message': 'Npc:QuestGameShop10'})
    Inventory.AddItemByKey({'count': 1, 'itemKey': 'PanelDungeonPiece', 'index': 24, 'autoEquip': False})
    Link.GenericItemGetSequenceByKey({'messageEntry': 'PanelDungeonPiece', 'itemKey': 'PanelDungeonPiece', 'keepCarry': False})
    Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})

    fork {
        Camera.Reset({'chaseRatio': 0.20000000298023224})
    } {
        Link.AimActor({'duration': 0.4000000059604645, 'actor': ActorIdentifier(name="GameShopOwner"), 'withoutTurn': False, 'boneName': ''})
    }

    GameShopOwner.Talk({'message': 'Npc:QuestGameShopPanelService'})
    EventFlags.SetFlag({'symbol': 'BowWowFigureGet', 'value': True})
}

void talk_button() {
    if !GameShopOwner.CheckActorSwitch({'switchIndex': 0}) {
        if !GameShopOwner.CheckPrizeEmpty() {
            GameShopOwner.SetFacialExpression({'expression': 'normal'})
            GameShopOwner.ResumeCamera()
            GameShopOwner.Talk({'message': 'Npc:CloseGameShop'})
            Hud.PlayInAnim()
            Hud.SetOpenMenuEnable({'enable': True})
            FlowControl.SetReturnValue({'value': 0})
        } else {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
            GameShopOwner.SetFacialExpression({'expression': 'normal'})
            GameShopOwner.GenericTalkSequence({'keepPersonalSpace': False, 'cameraLookAt': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})

            fork {
                Hud.PlayCraneInAnim()
            } {
                Hud.ShowRupee({'visible': True})
            }

            if !EventFlags.CheckFlag({'symbol': 'BowWowFigureGet'}) {
                GameShopOwner.Talk({'message': 'Npc:QuestGameShop'})
                if !Dialog.GetLastResult() {
                    if !Link.CheckRupee({'amount': 10}) {
                        GameShopOwner.Talk({'message': 'Npc:NoneMoneyToolShop'})
                        Hud.PlayCraneOutAnim()
                        FlowControl.SetReturnValue({'value': 0})
                    } else {
                        Link.AddRupee({'amount': -10})
                        GameShopOwner.SetActorSwitch({'switchIndex': 0, 'value': True})
                        if !EventFlags.CheckLevelFlag({'index': 5}) {
                            GameShopOwner.Talk({'message': 'Npc:PlayGameShop'})
                            Event202:

                            fork {
                                Hud.PlayCraneOutAnim()
                            } {
                                Camera.Reset({'chaseRatio': 0.10000000149011612})
                            }

                            GameShopOwner.PopCraneFence()
                            FlowControl.SetReturnValue({'value': -1})
                        } else {
                            GameShopOwner.Talk({'message': 'Npc:PlayGameShopDirectly'})
                            EventFlags.SetLevelFlag({'index': 5, 'value': False})
                            goto Event202
                        }
                    }
                } else {
                    GameShopOwner.Talk({'message': 'Npc:NoGameShop'})
                    Hud.PlayCraneOutAnim()
                    FlowControl.SetReturnValue({'value': 0})
                }
            } else {
                GameShopOwner.Talk({'message': 'Npc:QuestGameShopCheap'})
                if !Dialog.GetLastResult() {
                    if !Link.CheckRupee({'amount': 5}) {
                        GameShopOwner.Talk({'message': 'Npc:NoneMoneyToolShop'})
                        Hud.PlayCraneOutAnim()
                        FlowControl.SetReturnValue({'value': 0})
                    } else {
                        Link.AddRupee({'amount': -5})
                        GameShopOwner.SetActorSwitch({'switchIndex': 0, 'value': True})
                        GameShopOwner.Talk({'message': 'Npc:PlayGameShop'})

                        fork {
                            Hud.PlayCraneOutAnim()
                        } {
                            Camera.Reset({'chaseRatio': 0.10000000149011612})
                        }

                        GameShopOwner.PopCraneFence()
                        FlowControl.SetReturnValue({'value': -1})
                    }
                } else {
                    GameShopOwner.Talk({'message': 'Npc:NoGameShop'})
                    Hud.PlayCraneOutAnim()
                    FlowControl.SetReturnValue({'value': 0})
                }
            }
        }
    } else {
        GameShopOwner.Talk({'message': 'Npc:PlayGameShop'})
        FlowControl.SetReturnValue({'value': -1})
    }
}
