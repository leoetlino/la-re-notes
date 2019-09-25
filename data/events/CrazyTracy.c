-------- EventFlow: CrazyTracy --------

Actor: CrazyTracy
entrypoint: None()
actions: ['Talk', 'AddBuyCount', 'ResetBuyCount', 'GenericTalkSequence', 'PlayAnimation', 'SetFacialExpression']
queries: ['TestBuyCount', 'TestEnemyKnockCountOddEven']
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: ['HasItem']
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['Heal', 'AddRupee', 'SetEquipmentVisibility']
queries: ['CheckRupee']
params: None

Actor: Hud
entrypoint: None()
actions: ['ShowRupee', 'SetHeartUpdateEnable']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

    fork {
        CrazyTracy.GenericTalkSequence({'aimFromPlayer': True, 'aimToPlayer': True, 'cameraLookAt': True, 'selfTalkAnim': True, 'keepPersonalSpace': True, 'playerTalkAnim': True, 'distanceOffset': 0.0})
    } {
        CrazyTracy.Talk({'message': 'SubEvent:GreetingTracy'})
    }

    if !Inventory.HasItem({'itemType': 22, 'count': 1}) {
        Hud.ShowRupee({'visible': True})
        if !CrazyTracy.TestEnemyKnockCountOddEven() {
            CrazyTracy.Talk({'message': 'SubEvent:Buy28RupeeDrag'})
            if !Dialog.GetLastResult() {
                if !CrazyTracy.TestBuyCount({'value': 8}) {
                    if !Link.CheckRupee({'amount': 28}) {
                        Event13:
                        CrazyTracy.Talk({'message': 'SubEvent:NoMoneyDrag'})
                        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                    } else {
                        Link.AddRupee({'amount': -28})
                        CrazyTracy.AddBuyCount()
                        Event14:
                        Inventory.AddItem({'itemType': 22, 'count': 1, 'autoEquip': False})
                        Hud.ShowRupee({'visible': False})
                        CrazyTracy.Talk({'message': 'SubEvent:TakeDrag'})
                        CrazyTracy.SetFacialExpression({'expression': 'wink'})
                        CrazyTracy.Talk({'message': 'SubEvent:TracyRecovery'})
                        Hud.SetHeartUpdateEnable({'enable': True})
                        Link.Heal({'amount': 99})
                        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                        CrazyTracy.SetFacialExpression({'expression': 'normal'})
                        GameControl.RequestAutoSave()
                    }
                } else {
                    Event5:
                    CrazyTracy.Talk({'message': 'SubEvent:Service7RupeeDrag'})
                    if !Link.CheckRupee({'amount': 7}) {
                        goto Event13
                    } else {
                        Link.AddRupee({'amount': -7})
                        CrazyTracy.ResetBuyCount()
                        goto Event14
                    }
                }
            } else {
                Event34:
                Hud.ShowRupee({'visible': False})
                CrazyTracy.SetFacialExpression({'expression': 'angry'})
                CrazyTracy.PlayAnimation({'name': 'sulky_st', 'blendTime': 0.0})

                fork {
                    CrazyTracy.PlayAnimation({'name': 'sulky', 'blendTime': 0.0})
                } {
                    CrazyTracy.Talk({'message': 'SubEvent:CancelBuyDrag'})
                }

                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                CrazyTracy.SetFacialExpression({'expression': 'normal'})
            }
        } else {
            CrazyTracy.Talk({'message': 'SubEvent:Buy42RupeeDrag'})
            if !Dialog.GetLastResult() {
                if !CrazyTracy.TestBuyCount({'value': 8}) {
                    if !Link.CheckRupee({'amount': 42}) {
                        goto Event13
                    } else {
                        Link.AddRupee({'amount': -42})
                        CrazyTracy.AddBuyCount()
                        goto Event14
                    }
                } else {
                    goto Event5
                }
            } else {
                goto Event34
            }
        }
    } else {
        CrazyTracy.SetFacialExpression({'expression': 'angry'})
        CrazyTracy.PlayAnimation({'name': 'sulky_st', 'blendTime': 0.0})

        fork {
            CrazyTracy.PlayAnimation({'name': 'sulky', 'blendTime': 0.0})
        } {
            CrazyTracy.Talk({'message': 'SubEvent:BadBuyDrag'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        CrazyTracy.SetFacialExpression({'expression': 'normal'})
    }
}
