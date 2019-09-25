-------- EventFlow: Fisherman --------

Actor: Fisherman
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetLureType', 'LookAtFishingPlayer', 'SetFishingVisibility', 'CancelCarried', 'BeCarried']
queries: ['GetFishKind', 'CheckFishSize']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: ['GetLastResult', 'GetLastResult4']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'AddRupee', 'GenericItemGetSequenceByKey', 'GenericItemGetSequence', 'LookAtItemGettingPlayer', 'ClearPowerUp', 'PlayAnimation', 'AimCompassPoint']
queries: ['CheckRupee']
params: None

Actor: Hud
entrypoint: None()
actions: ['ShowRupee']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['SetReturnValue']
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

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump', 'RequestAutoSave']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItemByKey', 'AddSecretShell', 'AddBottle']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['SetFixedCamera']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle', 'StopZoneAudio', 'PlayJingleTimeWait', 'StopAllBGM']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void talk() {
    if !EventFlags.CheckFlag({'symbol': 'UI_FieldMapIcon_FishingPond'}) {
        EventFlags.SetFlag({'symbol': 'UI_FieldMapIcon_FishingPond', 'value': True})
    }
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        Fisherman.GenericTalkSequence({'keepPersonalSpace': False, 'cameraLookAt': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})
    } {
        Hud.ShowRupee({'visible': True})
    } {
        Fisherman.Talk({'message': 'SubEvent:QuestFishing'})
    }

    if !Dialog.GetLastResult() {
        if !Link.CheckRupee({'amount': 10}) {
            Fisherman.Talk({'message': 'SubEvent:FishingNoMoney'})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else
        if !EventFlags.CheckFlag({'symbol': 'lure2Get'}) {
            if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {

                call lure1jumpfirst()

            } else {
                Fisherman.Talk({'message': 'SubEvent:Questlure3'})
                switch Dialog.GetLastResult4() {
                  case 0:

                    call lure1jumpfirst()

                  case 1:

                    call lure3jumpfirst()

                  case 2:
                    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                }
            }
        } else
        if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {
            Fisherman.Talk({'message': 'SubEvent:Questlure1'})
            switch Dialog.GetLastResult4() {
              case 0:

                call lure1jumpfirst()

              case 1:

                call lure2jumpfirst()

              case 2:
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        } else {
            Fisherman.Talk({'message': 'SubEvent:Questlure2'})
            switch Dialog.GetLastResult4() {
              case 0:

                call lure1jumpfirst()

              case 1:

                call lure2jumpfirst()

              case 2:

                call lure3jumpfirst()

              case 3:
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        }
    } else {
        Fisherman.Talk({'message': 'SubEvent:NoFishing'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}

void Retry() {
    Hud.ShowRupee({'visible': True})
    if !EventFlags.CheckFlag({'symbol': 'lure2Get'}) {
        if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {
            Fisherman.Talk({'message': 'SubEvent:FishingRetry2'})
            if !Dialog.GetLastResult() {
                if !Link.CheckRupee({'amount': 10}) {
                    Fisherman.Talk({'message': 'SubEvent:FishingNoMoney'})
                    Event109:

                    call EndFishing()

                } else {
                    Link.AddRupee({'amount': -10})
                    FlowControl.SetReturnValue({'value': 1})
                }
            } else {
                Fisherman.Talk({'message': 'SubEvent:FishingCancel'})
                goto Event109
            }
        } else {
            Event81:
            Fisherman.Talk({'message': 'SubEvent:FishingRetry'})
            switch Dialog.GetLastResult4() {
              case 0:
                if !Link.CheckRupee({'amount': 10}) {
                    Event129:
                    Fisherman.Talk({'message': 'SubEvent:FishingNoMoney'})
                    Event43:

                    call EndFishing()

                } else {
                    Link.AddRupee({'amount': -10})
                    FlowControl.SetReturnValue({'value': 1})
                }
              case 1:
                if !Link.CheckRupee({'amount': 10}) {
                    goto Event129
                } else {

                    call lureCheck()

                }
              case 2:
                Fisherman.Talk({'message': 'SubEvent:FishingCancel'})
                goto Event43
            }
        }
    } else
    if EventFlags.CheckFlag({'symbol': 'lure3Get'}) in [0, 1] {
        goto Event81
    }
}

void 50cmDown() {
    Fisherman.Talk({'message': 'SubEvent:FishingSmallfish'})
}

void 50cmUp() {
    Fisherman.Talk({'message': 'SubEvent:FishingBigfish'})
}

void 100cmUp() {
    Fisherman.Talk({'message': 'SubEvent:FishingMoreBigFish'})
}

void 150cmUp() {
    Fisherman.Talk({'message': 'SubEvent:FishingMegaFish'})
}

void FirstPukuPuku() {
    Dialog.Show({'message': 'SubEvent:lure3Get3'})
    Inventory.AddSecretShell({'index': 44})
    Fisherman.SetFishingVisibility({'visibility': False})
    Link.GenericItemGetSequence({'itemType': 23, 'messageEntry': 'Seashell', 'keepCarry': False})
    Camera.SetFixedCamera({'posX': 11.680000305175781, 'posY': 9.199999809265137, 'posZ': 27.0, 'rotX': 0.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 27.0, 'fieldOfViewY': 10.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    EventFlags.SetFlag({'value': True, 'symbol': 'BigFishFirstGet'})
}

void FirstGeso() {
    Fisherman.Talk({'message': 'SubEvent:lure3Get'})
    Link.LookAtItemGettingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    Fisherman.SetFishingVisibility({'visibility': False})

    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 's_item_get_st'})
    } {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    } {
        Timer.Wait({'time': 0.30000001192092896})
        Fisherman.BeCarried({'type': 3})
    }

    Link.PlayAnimation({'blendTime': 0.0, 'name': 's_item_get_lp'})
    Audio.PlayJingleTimeWait({'label': 'BGM_FANFARE_BIGITEM_GET', 'duration': 0.800000011920929, 'volume': 1.0})
    Dialog.Show({'message': 'SubEvent:lure3Get2'})
    Fisherman.CancelCarried()
    EventFlags.SetFlag({'value': True, 'symbol': 'lure3Get'})
    GameControl.RequestAutoSave()
}

void FirstMaster() {
    Dialog.Show({'message': 'SubEvent:PeaceGet'})
    Inventory.AddItemByKey({'count': 1, 'itemKey': 'PanelDungeonPiece', 'index': 12, 'autoEquip': False})
    Fisherman.SetFishingVisibility({'visibility': False})
    Link.GenericItemGetSequenceByKey({'messageEntry': 'PanelDungeonPiece', 'itemKey': 'PanelDungeonPiece', 'keepCarry': False})
    Camera.SetFixedCamera({'posX': 11.680000305175781, 'posY': 9.199999809265137, 'posZ': 27.0, 'rotX': 0.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 27.0, 'fieldOfViewY': 10.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    EventFlags.SetFlag({'value': True, 'symbol': 'FishingPanelGet'})
}

void FishingFirst50() {
    Fisherman.Talk({'message': 'SubEvent:FishingFirst50'})
    Fisherman.SetFishingVisibility({'visibility': False})
    Link.GenericItemGetSequenceByKey({'itemKey': 'HeartPiece', 'messageEntry': 'HeartPiece', 'keepCarry': False})
    Inventory.AddItemByKey({'count': 1, 'itemKey': 'HeartPiece', 'index': 27, 'autoEquip': False})
    Camera.SetFixedCamera({'posX': 11.680000305175781, 'posY': 9.199999809265137, 'posZ': 27.0, 'rotX': 0.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 27.0, 'fieldOfViewY': 10.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    EventFlags.SetFlag({'symbol': '50cmFirstGet', 'value': True})
}

void FishingFirst100() {
    Fisherman.Talk({'message': 'SubEvent:FishingFirst100'})
    Inventory.AddSecretShell({'index': 45})
    Fisherman.SetFishingVisibility({'visibility': False})
    Link.GenericItemGetSequence({'itemType': 23, 'messageEntry': 'Seashell', 'keepCarry': False})
    Camera.SetFixedCamera({'posX': 11.680000305175781, 'posY': 9.199999809265137, 'posZ': 27.0, 'rotX': 0.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 27.0, 'fieldOfViewY': 10.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    EventFlags.SetFlag({'symbol': '100cmFirstGet', 'value': True})
}

void FishingFirst150() {
    Fisherman.Talk({'message': 'SubEvent:FishingFirst150'})
    Inventory.AddItemByKey({'count': 1, 'itemKey': 'PanelDungeonPiece', 'index': 11, 'autoEquip': False})
    Fisherman.SetFishingVisibility({'visibility': False})
    Link.GenericItemGetSequenceByKey({'messageEntry': 'PanelDungeonPiece', 'itemKey': 'PanelDungeonPiece', 'keepCarry': False})
    Camera.SetFixedCamera({'posX': 11.680000305175781, 'posY': 9.199999809265137, 'posZ': 27.0, 'rotX': 0.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 27.0, 'fieldOfViewY': 10.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    EventFlags.SetFlag({'value': True, 'symbol': '150cmFirstGet'})
}

void Cut_String() {
    Fisherman.Talk({'message': 'SubEvent:FishingCutString'})

    call Retry()

}

void lure1jumpfirst() {
    Link.AddRupee({'amount': -10})
    Fisherman.Talk({'message': 'SubEvent:ExplanationFishing'})
    Fisherman.SetLureType({'type': 1})

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Fade.StartPreset({'preset': 9})
    } {
        Audio.StopZoneAudio()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.ClearPowerUp()
    GameControl.RequestLevelJump({'level': 'FishingPond', 'locator': 'FishingPond_01A', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void lure2jumpfirst() {
    Link.AddRupee({'amount': -10})
    Fisherman.Talk({'message': 'SubEvent:ExplanationFishing'})
    Fisherman.SetLureType({'type': 2})

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Fade.StartPreset({'preset': 9})
    } {
        Audio.StopZoneAudio()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.ClearPowerUp()
    GameControl.RequestLevelJump({'level': 'FishingPond', 'locator': 'FishingPond_01A', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void lure3jumpfirst() {
    Link.AddRupee({'amount': -10})
    Fisherman.Talk({'message': 'SubEvent:ExplanationFishing'})
    Fisherman.SetLureType({'type': 3})

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Fade.StartPreset({'preset': 9})
    } {
        Audio.StopZoneAudio()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.ClearPowerUp()
    GameControl.RequestLevelJump({'level': 'FishingPond', 'locator': 'FishingPond_01A', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void lureCheck() {
    if !EventFlags.CheckFlag({'symbol': 'lure2Get'}) {
        if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {

            call lure1jump()

        } else {
            Fisherman.Talk({'message': 'SubEvent:Questlure3'})
            switch Dialog.GetLastResult4() {
              case 0:
                Link.AddRupee({'amount': -10})

                call lure1jump()

              case 1:
                Link.AddRupee({'amount': -10})

                call lure3jump()

              case 2:

                call Retry()

            }
        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {
        Fisherman.Talk({'message': 'SubEvent:Questlure1'})
        switch Dialog.GetLastResult4() {
          case 0:
            Link.AddRupee({'amount': -10})

            call lure1jump()

          case 1:
            Link.AddRupee({'amount': -10})

            call lure2jump()

          case 2:

            call Retry()

        }
    } else {
        Fisherman.Talk({'message': 'SubEvent:Questlure2'})
        switch Dialog.GetLastResult4() {
          case 0:
            Link.AddRupee({'amount': -10})

            call lure1jump()

          case 1:
            Link.AddRupee({'amount': -10})

            call lure2jump()

          case 2:
            Link.AddRupee({'amount': -10})

            call lure3jump()

          case 3:

            call Retry()

        }
    }
}

void FishingClear() {
    Fisherman.LookAtFishingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612})
    Audio.PlayJingle({'label': 'BGM_FANFARE_ITEM_GET', 'volume': 1.0})
    switch Fisherman.GetFishKind() {
      case 0:
        Dialog.Show({'message': 'SubEvent:SmallFish'})

        call 50cmDown()

        Fisherman.Talk({'message': 'SubEvent:FishingRupee5'})
        Hud.ShowRupee({'visible': True})
        Link.AddRupee({'amount': 'fishRupee'})
        if !EventFlags.CheckFlag({'symbol': 'SmallFishFirstGet'}) {

            call FirstSmallFish()


            call Idle_pole()

            Event27:

            call Retry()

        } else {
            goto Event27
        }
      case 1:
        Dialog.Show({'message': 'SubEvent:BigFish'})

        call 50cmUp()

        Fisherman.Talk({'message': 'SubEvent:FishingRupee15'})
        Hud.ShowRupee({'visible': True})
        Link.AddRupee({'amount': 'fishRupee'})
        if !EventFlags.CheckFlag({'symbol': 'lure2Get'}) {

            call FirstBigFish()

            if !EventFlags.CheckFlag({'symbol': '50cmFirstGet'}) {
                Fisherman.SetFishingVisibility({'visibility': False})
                Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
                Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
                Event173:

                call FishingFirst50()

                Event141:

                call Idle_pole()

                goto Event27
            } else {
                goto Event141
            }
        } else
        if !EventFlags.CheckFlag({'symbol': '50cmFirstGet'}) {
            goto Event173
        } else {
            goto Event27
        }
      case 2:
        Dialog.Show({'message': 'SubEvent:PukuPuku'})
        if !Fisherman.CheckFishSize({'amount': 50}) {

            call 50cmDown()

        } else {

            call 50cmUp()

        }
        Fisherman.Talk({'message': 'SubEvent:FishingRupee20'})
        Hud.ShowRupee({'visible': True})
        Link.AddRupee({'amount': 'fishRupee'})
        if !EventFlags.CheckFlag({'symbol': 'BigFishFirstGet'}) {

            call FirstPukuPuku()

            if !Fisherman.CheckFishSize({'amount': 50}) {
                Event258:

                call Idle_pole()

                goto Event27
            } else
            Event218:
            if !EventFlags.CheckFlag({'symbol': '50cmFirstGet'}) {
                Event121:
                Fisherman.SetFishingVisibility({'visibility': False})
                Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
                Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})

                call FishingFirst50()

                goto Event258
            } else {
                goto Event258
            }
        } else
        if !Fisherman.CheckFishSize({'amount': 50}) {
            goto Event27
        } else
        if !EventFlags.CheckFlag({'symbol': '50cmFirstGet'}) {
            goto Event121
        } else {
            goto Event27
        }
      case 3:
        Dialog.Show({'message': 'SubEvent:Geso'})
        if !Fisherman.CheckFishSize({'amount': 100}) {

            call 50cmUp()

        } else {

            call 100cmUp()

        }
        Fisherman.Talk({'message': 'SubEvent:FishingRupee40'})
        Hud.ShowRupee({'visible': True})
        Link.AddRupee({'amount': 'fishRupee'})
        if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {

            call FirstGeso()

            if !Fisherman.CheckFishSize({'amount': 100}) {
                goto Event218
            } else
            Event230:
            if !EventFlags.CheckFlag({'symbol': '100cmFirstGet'}) {
                Fisherman.SetFishingVisibility({'visibility': False})
                Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
                Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
                Event231:

                call FishingFirst100()

                Event259:

                call Idle_pole()

                goto Event27
            } else {
                goto Event259
            }
        } else
        if !Fisherman.CheckFishSize({'amount': 100}) {
            goto Event218
        } else
        Event260:
        if !EventFlags.CheckFlag({'symbol': '100cmFirstGet'}) {
            goto Event231
        } else {
            goto Event27
        }
      case 4:
        Dialog.Show({'message': 'SubEvent:Master'})
        if !Fisherman.CheckFishSize({'amount': 150}) {

            call 100cmUp()

        } else {

            call 150cmUp()

        }
        Fisherman.Talk({'message': 'SubEvent:FishingRupee100'})
        Hud.ShowRupee({'visible': True})
        Link.AddRupee({'amount': 'fishRupee'})
        if !EventFlags.CheckFlag({'symbol': 'FishingPanelGet'}) {

            call FirstMaster()

            if !Fisherman.CheckFishSize({'amount': 150}) {
                goto Event230
            } else
            if !EventFlags.CheckFlag({'symbol': '150cmFirstGet'}) {
                Fisherman.SetFishingVisibility({'visibility': False})
                Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
                Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
                Event242:

                call FishingFirst150()

                Event263:

                call Idle_pole()

                goto Event27
            } else {
                goto Event263
            }
        } else
        if !Fisherman.CheckFishSize({'amount': 150}) {
            goto Event260
        } else
        if !EventFlags.CheckFlag({'symbol': '150cmFirstGet'}) {
            goto Event242
        } else {
            goto Event27
        }
    }
}

void FishingGetBottle() {
    Inventory.AddBottle({'index': 1})
    Fisherman.SetFishingVisibility({'visibility': False})
    Link.GenericItemGetSequence({'keepCarry': False, 'messageEntry': 'FishingBottle', 'itemType': 64})
    Camera.SetFixedCamera({'posX': 11.680000305175781, 'posY': 9.199999809265137, 'posZ': 27.0, 'rotX': 0.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 27.0, 'fieldOfViewY': 10.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})

    call Idle_pole()


    call Retry()

}

void lure1jump() {
    FlowControl.SetReturnValue({'value': 3})
}

void lure2jump() {
    FlowControl.SetReturnValue({'value': 4})
}

void lure3jump() {
    FlowControl.SetReturnValue({'value': 5})
}

void FirstSmallFish() {
    Dialog.Show({'message': 'SubEvent:lure2Get3'})
    Fisherman.SetFishingVisibility({'visibility': False})
    Link.GenericItemGetSequenceByKey({'itemKey': 'HeartPiece', 'messageEntry': 'HeartPiece', 'keepCarry': False})
    Inventory.AddItemByKey({'count': 1, 'itemKey': 'HeartPiece', 'index': 1, 'autoEquip': False})
    Camera.SetFixedCamera({'posX': 11.680000305175781, 'posY': 9.199999809265137, 'posZ': 27.0, 'rotX': 0.0, 'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 27.0, 'fieldOfViewY': 10.0, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    EventFlags.SetFlag({'value': True, 'symbol': 'SmallFishFirstGet'})
}

void FirstBigFish() {
    Fisherman.Talk({'message': 'SubEvent:lure2Get'})
    Link.LookAtItemGettingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    Fisherman.SetFishingVisibility({'visibility': False})

    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 's_item_get_st'})
    } {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    } {
        Timer.Wait({'time': 0.30000001192092896})
        Fisherman.BeCarried({'type': 2})
    }

    Link.PlayAnimation({'blendTime': 0.0, 'name': 's_item_get_lp'})
    Audio.PlayJingleTimeWait({'label': 'BGM_FANFARE_BIGITEM_GET', 'duration': 0.800000011920929, 'volume': 1.0})
    Dialog.Show({'message': 'SubEvent:lure2Get2'})
    Fisherman.CancelCarried()
    EventFlags.SetFlag({'symbol': 'lure2Get', 'value': True})
    GameControl.RequestAutoSave()
}

void Cut_Bottle() {
    Fisherman.Talk({'message': 'SubEvent:FishingCutBottle'})

    call Retry()

}

void Retry_2() {
    Hud.ShowRupee({'visible': True})
    if !EventFlags.CheckFlag({'symbol': 'lure2Get'}) {
        if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {
            Fisherman.Talk({'message': 'SubEvent:FishingRetry2'})
            if !Dialog.GetLastResult() {
                FlowControl.SetReturnValue({'value': 1})
            } else {
                Fisherman.Talk({'message': 'SubEvent:FishingCancel'})

                call EndFishing()

            }
        } else {
            Event272:
            Fisherman.Talk({'message': 'SubEvent:FishingRetry'})
            switch Dialog.GetLastResult4() {
              case 0:
                FlowControl.SetReturnValue({'value': 1})
              case 1:

                call lureCheckB()

              case 2:
                Fisherman.Talk({'message': 'SubEvent:FishingCancel'})

                call EndFishing()

            }
        }
    } else
    if EventFlags.CheckFlag({'symbol': 'lure3Get'}) in [0, 1] {
        goto Event272
    }
}

void Idle_pole() {
    Link.PlayAnimation({'name': 'idle_pole', 'blendTime': 0.10000000149011612})

    fork {
        Link.AimCompassPoint({'direction': 3, 'duration': 0.4000000059604645, 'withoutTurn': False})
    } {
        Fisherman.SetFishingVisibility({'visibility': True})
    }

}

void EndFishing() {

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Fade.StartPreset({'preset': 9})
    } {
        Audio.StopZoneAudio()
    }

    FlowControl.SetReturnValue({'value': 2})
}

void lureCheckB() {
    if !EventFlags.CheckFlag({'symbol': 'lure2Get'}) {
        if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {

            call lure1jump()

        } else {
            Fisherman.Talk({'message': 'SubEvent:Questlure3'})
            switch Dialog.GetLastResult4() {
              case 0:

                call lure1jump()

              case 1:

                call lure3jump()

              case 2:

                call Retry_2()

            }
        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'lure3Get'}) {
        Fisherman.Talk({'message': 'SubEvent:Questlure1'})
        switch Dialog.GetLastResult4() {
          case 0:

            call lure1jump()

          case 1:

            call lure2jump()

          case 2:

            call Retry_2()

        }
    } else {
        Fisherman.Talk({'message': 'SubEvent:Questlure2'})
        switch Dialog.GetLastResult4() {
          case 0:

            call lure1jump()

          case 1:

            call lure2jump()

          case 2:

            call lure3jump()

          case 3:

            call Retry_2()

        }
    }
}
