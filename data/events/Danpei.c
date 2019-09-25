-------- EventFlow: Danpei --------

Actor: Danpei[Danpei]
entrypoint: None()
actions: ['Talk', 'ProcessDungeonAndPanelStone', 'RewardGetSequence', 'ConfirmedNewTheme', 'GenericTalkSequence', 'PlayAnimation', 'MoveToCompassPoint', 'MoveToTargetLinkedPoint', 'AimActorLinkedPoint', 'AimDegreeAngle', 'AimPlayer', 'ResetAim', 'ConfirmedSawRupeeEvent', 'Activate', 'Deactivate', 'WarpToActorWithCompassPoint']
queries: ['CheckNewDungeonSet', 'CheckNewPanelStone', 'CheckNewTheme', 'CheckNewReward', 'CheckNewThemeEx', 'CheckCompletedDungeon', 'CheckNewThemeFree', 'CheckNewPanelPlusChip', 'CheckSawRupeeEvent', 'CheckClearedDungeon']
params: None

Actor: Danpei[FirstDanpei]
entrypoint: None()
actions: ['Talk', 'AimCompassPoint']
queries: []
params: None

Actor: Danpei[OwlDanpei]
entrypoint: None()
actions: ['GenericTalkSequence', 'Talk']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'MoveToCompassPoint', 'PlayAnimationEx', 'PlayAnimation', 'AimActor', 'ResetAim']
queries: []
params: None

Actor: Danpei
entrypoint: None()
actions: ['GenericTalkSequence', 'Talk', 'PanelGetSequence', 'MoveToCompassPoint', 'Destroy', 'AmiiboPanelGetSequence', 'ShadowLinkPanelGetSequence', 'RupeePanelGetSequence', 'ExEnemyPanelGetSequence', 'PlayAnimation']
queries: ['CheckClearAllTheme']
params: None

Actor: Dialog
entrypoint: None()
actions: ['ShowSystemDialog']
queries: ['GetLastResult4']
params: None

Actor: PanelDungeon
entrypoint: None()
actions: ['ShowPanelMenuUi', 'ShowAmiiboUi', 'ShowAmiiboGiftUi', 'ShowAmiiboReceiveUi']
queries: ['CheckCompleteAmiiboGift', 'ResultAmiiboGift', 'CheckSpecialAmiiboGift', 'CheckCanReceiveDungeon', 'CheckPanelAddStone']
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSaveCaptureFirst']
queries: []
params: None

Actor: Character[companion]
entrypoint: None()
actions: ['MoveToCompassPoint', 'AimActor', 'ResetAim', 'WarpToActor', 'PlayAnimation']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayZoneAudio']
queries: []
params: None

Actor: EventTriggerTag
entrypoint: None()
actions: []
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Danpei[Danpei].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {
        Danpei[Danpei].Talk({'message': 'SubEvent:DanpeiPanelLead2'})
    } else
    if !EventFlags.CheckFlag({'symbol': 'DanpeiFirstTalked'}) {
        Danpei[Danpei].Talk({'message': 'Npc:DanpeiFirstContact1'})
        Danpei[Danpei].Talk({'message': 'Npc:DanpeiFirstContact2'})
        EventFlags.SetFlag({'symbol': 'DanpeiFirstTalked', 'value': True})
        if !Danpei[Danpei].CheckNewPanelStone()
        && Danpei[Danpei].CheckNewPanelPlusChip() {
            Danpei.Talk({'message': 'Npc:DanpeiFirstStone'})
        }
        if !Danpei[Danpei].CheckNewDungeonSet() {
            Event37:

            call RewardOdai()


            call PanelMenu()

        } else {
            Danpei[Danpei].Talk({'message': 'Npc:DanpeiNewPanel1'})

            fork {
                Link.PlayAnimationEx({'name': 'talk_danpei', 'time': 3.0, 'blendTime': 0.10000000149011612})
            } {
                Danpei.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            }

            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
            Event106:

            fork {
                Danpei[Danpei].PlayAnimation({'name': 'create', 'blendTime': 0.10000000149011612})
            } {
                Danpei[Danpei].AimDegreeAngle({'duration': 0.4000000059604645, 'angle': 165.0, 'withoutTurn': False})
            }

            Timer.Wait({'time': 3.0})

            fork {
                Danpei[Danpei].PlayAnimation({'name': 'give', 'blendTime': 0.10000000149011612})
            } {
                Danpei[Danpei].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            }

            Timer.Wait({'time': 1.0})
            if !Danpei[Danpei].CheckNewPanelStone()
            && Danpei[Danpei].CheckNewDungeonSet() {
                Danpei.PanelGetSequence()
            }
            if PanelDungeon.CheckPanelAddStone({'index': 13}) {
                Danpei.RupeePanelGetSequence()
            }
            if PanelDungeon.CheckPanelAddStone({'index': 24}) {
                Danpei.ExEnemyPanelGetSequence()
            }
            Danpei[Danpei].ProcessDungeonAndPanelStone()
            GameControl.RequestAutoSaveCaptureFirst()
            goto Event37
        }
    } else {
        Danpei[Danpei].Talk({'message': 'Npc:DanpeiGreeting'})
        if !Danpei[Danpei].CheckNewDungeonSet() {
            if !Danpei[Danpei].CheckNewPanelStone()
            && !Danpei[Danpei].CheckNewPanelPlusChip() {
                goto Event37
            } else {
                Event9:
                Danpei[Danpei].Talk({'message': 'Npc:DanpeiNewPanel2'})
                goto Event106
            }
        } else {
            Danpei[Danpei].Talk({'message': 'Npc:DanpeiNewPanel1'})

            fork {
                Link.PlayAnimationEx({'name': 'talk_danpei', 'time': 3.0, 'blendTime': 0.10000000149011612})
            } {
                Danpei.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            }

            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
            Danpei[Danpei].Talk({'message': 'Npc:DanpeiNewPanel1_2'})
            if !Danpei[Danpei].CheckNewPanelStone()
            && Danpei[Danpei].CheckNewPanelPlusChip() {
                goto Event9
            }
            goto Event106
        }
    }
}

void FirstContact() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Danpei[OwlDanpei].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Danpei[OwlDanpei].Talk({'message': 'SubEvent:DanpeiPanelLead1'})
    EventFlags.SetFlag({'value': True, 'symbol': 'DanpeiTalkClear'})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}

void FieldGuidance() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Danpei.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !EventFlags.CheckFlag({'symbol': 'DanpeiLeadClear'}) {
        Danpei.Talk({'message': 'SubEvent:DanpeiPanelLeadClear1'})
        EventFlags.SetFlag({'value': True, 'symbol': 'DanpeiLeadClear'})
        Event25:
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {
        Danpei.Talk({'message': 'SubEvent:DanpeiPanelLeadClear2'})
        goto Event25
    }
}

void RewardResult() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Danpei[Danpei].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !Danpei[Danpei].CheckNewReward() {
        Event173:
        Danpei[Danpei].GenericTalkSequence({'aimToPlayer': False, 'selfTalkAnim': False, 'keepPersonalSpace': False, 'playerTalkAnim': True, 'aimFromPlayer': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        if !Danpei[Danpei].CheckSawRupeeEvent() {
            if !EventFlags.CheckFlag({'symbol': 'PanelCharengeClear01'}) {
                Event46:

                call RewardOdai()

                GameControl.RequestAutoSaveCaptureFirst()

                call PanelMenu()

                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {
                Danpei[Danpei].Talk({'message': 'Npc:DanpeiRewardRupee'})
                Danpei[Danpei].ConfirmedSawRupeeEvent()
                goto Event46
            }
        } else {
            goto Event46
        }
    } else {
        Danpei[Danpei].Talk({'message': 'Npc:DanpeiReward'})
        Event39:
        Danpei[Danpei].RewardGetSequence()
        if !Danpei[Danpei].CheckNewReward() {
            Danpei[Danpei].ProcessDungeonAndPanelStone()
            goto Event173
        } else {
            goto Event39
        }
    }
}

void RewardOdai() {
    if !Danpei[Danpei].CheckNewThemeFree() {
        Event52:
        if !Danpei[Danpei].CheckNewThemeEx() {
            Event41:
            if !Danpei[Danpei].CheckNewTheme() {
                Event40:
                Danpei[Danpei].ConfirmedNewTheme()
                if Danpei.CheckClearAllTheme()
                && !EventFlags.CheckFlag({'symbol': 'ModeOpenEvent03'}) {
                    Danpei[Danpei].Talk({'message': 'Npc:DanpeiComplete'})
                    EventFlags.SetFlag({'symbol': 'ModeOpenEvent03', 'value': True})
                }
            } else {
                Danpei[Danpei].PlayAnimation({'name': 'glitter', 'blendTime': 0.10000000149011612})

                fork {
                    Danpei[Danpei].Talk({'message': 'Npc:DanpeiNewTheme3'})
                } {
                    Danpei[Danpei].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
                }

                goto Event40
            }
        } else {
            Danpei[Danpei].PlayAnimation({'name': 'glitter', 'blendTime': 0.10000000149011612})

            fork {
                Danpei[Danpei].Talk({'message': 'Npc:DanpeiEX'})
            } {
                Danpei[Danpei].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
            }

            goto Event41
        }
    } else {
        Danpei[Danpei].PlayAnimation({'name': 'glitter', 'blendTime': 0.10000000149011612})

        fork {
            Danpei[Danpei].Talk({'message': 'Npc:DanpeiFree'})
        } {
            Danpei[Danpei].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
        }

        goto Event52
    }
}

void PanelMenu() {
    Event65:
    Danpei[Danpei].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    if !Danpei[Danpei].CheckCompletedDungeon() {
        Danpei[Danpei].Talk({'message': 'Npc:DanpeiPanelMenuNoData'})
        switch Dialog.GetLastResult4() {
          case 0:
            Fade.StartPreset({'preset': 9})
            PanelDungeon.ShowPanelMenuUi({'mode': True})
          case 1:
            Event67:
            Danpei[Danpei].Talk({'message': 'Npc:DanpeiAmiiboMenuNoData'})
            switch Dialog.GetLastResult4() {
              case 0:
                Event35:
                if !PanelDungeon.CheckCanReceiveDungeon() {
                    Dialog.ShowSystemDialog({'message': 'Npc:DanpeiDataMax'})
                } else {
                    PanelDungeon.ShowAmiiboReceiveUi()
                }
                goto Event65
              case 1:
                Event50:
                if !PanelDungeon.CheckCompleteAmiiboGift() {
                    PanelDungeon.ShowAmiiboGiftUi()
                    switch PanelDungeon.ResultAmiiboGift() {
                      case 0:
                        Danpei.AmiiboPanelGetSequence()
                        Danpei[Danpei].ProcessDungeonAndPanelStone()
                        if !PanelDungeon.CheckSpecialAmiiboGift() {
                            goto Event65
                        } else {
                            Event146:
                            Danpei.ShadowLinkPanelGetSequence()
                            Danpei[Danpei].ProcessDungeonAndPanelStone()
                            goto Event65
                        }
                      case 1:
                        Dialog.ShowSystemDialog({'message': 'Npc:DanpeiBenefitComplete1'})
                        goto Event65
                      case 2:
                        Dialog.ShowSystemDialog({'message': 'Npc:DanpeiNoBenefit'})
                        goto Event65
                      case 3:
                        goto Event146
                      case 4:
                        goto Event65
                      case 5:
                        Dialog.ShowSystemDialog({'message': 'Npc:DanpeiBenefitGotAllPanel'})
                        goto Event65
                      case 6:
                        Dialog.ShowSystemDialog({'message': 'Npc:DanpeiBenefitGotten'})
                        goto Event65
                    }
                } else {
                    Dialog.ShowSystemDialog({'message': 'Npc:DanpeiBenefitComplete1'})
                    goto Event65
                }
              case 2:
                goto Event65
            }
          case 2:
            Danpei.Talk({'message': 'Npc:DanpeiBenefitCancel'})
        }
    } else {
        Danpei[Danpei].Talk({'message': 'Npc:DanpeiPanelMenu'})
        switch Dialog.GetLastResult4() {
          case 0:
            Fade.StartPreset({'preset': 9})
            PanelDungeon.ShowPanelMenuUi({'mode': True})
          case 1:
            Fade.StartPreset({'preset': 9})
            PanelDungeon.ShowPanelMenuUi({'mode': False})
          case 2:
            if !Danpei[Danpei].CheckClearedDungeon() {
                goto Event67
            } else {
                Danpei[Danpei].Talk({'message': 'Npc:DanpeiAmiiboMenu'})
                switch Dialog.GetLastResult4() {
                  case 0:
                    Fade.StartPreset({'preset': 9})
                    PanelDungeon.ShowAmiiboUi({'mode': True})
                  case 1:
                    goto Event35
                  case 2:
                    goto Event50
                  case 3:
                    goto Event65
                }
            }
          case 3:
            Danpei.Talk({'message': 'Npc:DanpeiBenefitCancel'})
        }
    }
}

void FieldGuidanceHouse() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Danpei.GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Danpei.Talk({'message': 'SubEvent:DanpeiPanelLeadClear3'})
    Danpei.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 1.0, 'timeOut': 7.0})

    fork {
        Danpei.Destroy()
    } {
        EventFlags.SetFlag({'value': True, 'symbol': 'DanpeiLeadClear'})
    }

}

void DanpeiHouseFirst() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Danpei[Danpei].GenericTalkSequence({'aimToPlayer': False, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Danpei[FirstDanpei].Talk({'message': 'Npc:DanpeiPanelClosed'})
    Danpei[FirstDanpei].AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
}

void DanpeiHouseReturn() {
    if !EventFlags.CheckFlag({'symbol': 'DanpeiReturn'}) {
        Danpei[Danpei].WarpToActorWithCompassPoint({'direction': 2, 'offsetY': 1.0, 'distance': -4.0, 'actor': ActorIdentifier(name="EventTriggerTag")})
        Danpei[Danpei].Deactivate()

        fork {
            Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.75, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        }

        Timer.Wait({'time': 1.0})
        Danpei[Danpei].Activate()
        Danpei[Danpei].MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 1.5, 'timeOut': 7.0})

        fork {
            Timer.Wait({'time': 0.5})
            Link.MoveToCompassPoint({'speed': 1, 'direction': 3, 'distance': 1.0, 'timeOut': 7.0})
            Link.AimActor({'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            Danpei[Danpei].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            Timer.Wait({'time': 1.0})
            Danpei[Danpei].MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 1.0, 'timeOut': 7.0})
        } {
            Danpei[Danpei].ResetAim()
        }


        fork {
            Danpei[Danpei].MoveToTargetLinkedPoint({'speed': 0, 'index': 0, 'actor': ActorIdentifier(name="Danpei", sub_name="Danpei"), 'timeOut': 7.0})
            Danpei[Danpei].MoveToTargetLinkedPoint({'speed': 0, 'index': 1, 'actor': ActorIdentifier(name="Danpei", sub_name="Danpei"), 'timeOut': 7.0})
        } {
            Link.AimActor({'withoutTurn': True, 'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'boneName': ''})
            Timer.Wait({'time': 1.0})
            Link.AimActor({'withoutTurn': False, 'actor': ActorIdentifier(name="Danpei"), 'duration': 0.30000001192092896, 'boneName': ''})
        }

        Danpei[Danpei].AimActorLinkedPoint({'pointIndex': 2, 'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'withoutTurn': False})

        fork {
            Danpei[Danpei].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Danpei[Danpei].AimPlayer({'withoutTurn': True, 'duration': 0.4000000059604645, 'boneName': ''})
        }

        Link.ResetAim()
        if !Inventory.HasItem({'itemType': 46, 'count': 1}) {
            EventFlags.SetFlag({'value': True, 'symbol': 'DanpeiReturn'})
        } else {
            EventFlags.SetFlag({'value': True, 'symbol': 'DanpeiLeadClear'})
        }
    }
}

void DanpeiHouseReturn_Companion() {

    fork {

        call DanpeiHouseReturn()

    } {
        Character[companion].WarpToActor({'distance': -1.0, 'offsetY': 1.0, 'actor': ActorIdentifier(name="EventTriggerTag")})
        Character[companion].MoveToCompassPoint({'speed': 0, 'timeOut': 5.0, 'direction': 2, 'distance': 0.75})
        Timer.Wait({'time': 1.75})
        Character[companion].MoveToCompassPoint({'direction': 3, 'timeOut': 5.0, 'speed': 1, 'distance': 1.0})
        Character[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Character[companion].AimActor({'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        Timer.Wait({'time': 2.5})
        Character[companion].AimActor({'withoutTurn': True, 'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'boneName': ''})
        Timer.Wait({'time': 0.5})
        Character[companion].AimActor({'withoutTurn': False, 'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'boneName': ''})
        Timer.Wait({'time': 0.5})
    }

    Character[companion].ResetAim()
}

void DanpeiHouseReturn_FlyingCucco() {

    fork {

        call DanpeiHouseReturn()

    } {
        Character[companion].WarpToActor({'distance': -1.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Character[companion].MoveToCompassPoint({'speed': 0, 'timeOut': 5.0, 'direction': 2, 'distance': 0.75})
        Timer.Wait({'time': 1.75})
        Character[companion].MoveToCompassPoint({'direction': 3, 'timeOut': 5.0, 'speed': 1, 'distance': 1.0})
        Character[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        Character[companion].AimActor({'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        Timer.Wait({'time': 2.5})
        Character[companion].AimActor({'withoutTurn': True, 'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'boneName': ''})
        Timer.Wait({'time': 0.5})
        Character[companion].AimActor({'withoutTurn': False, 'actor': ActorIdentifier(name="Danpei"), 'duration': 0.4000000059604645, 'boneName': ''})
        Timer.Wait({'time': 0.5})
    }

    Character[companion].ResetAim()
}
