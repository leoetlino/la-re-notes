-------- EventFlow: DrWrite --------

Actor: Item[Broom]
entrypoint: None()
actions: ['Deactivate']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: DrWrite
entrypoint: None()
actions: ['Talk', 'TalkKeep', 'ShowPicture', 'SetFacialExpression', 'GenericTalkSequence', 'SetItemVisibility', 'PlayAnimation', 'AimPlayer', 'AimCompassPoint', 'PlayLetterAnimation']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['SetWarashibeItem']
queries: ['HasItem']
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequence', 'SetEquipmentVisibility']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'BroomDrop'}) {
        if !Inventory.HasItem({'count': 1, 'itemType': 38}) {

            fork {
                DrWrite.GenericTalkSequence({'keepPersonalSpace': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
            } {
                DrWrite.TalkKeep({'message': 'Warashibe:WantLetter1'})
            }

            DrWrite.Talk({'message': 'Warashibe:WantLetter2'})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                DrWrite.GenericTalkSequence({'keepPersonalSpace': False, 'aimToPlayer': False, 'selfTalkAnim': False, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
            } {
                DrWrite.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
            }


            fork {
                DrWrite.SetFacialExpression({'expression': 'excite'})
            } {
                DrWrite.PlayAnimation({'name': 'hold_st', 'blendTime': 0.10000000149011612})
            } {
                Timer.Wait({'time': 0.44999998807907104})
                DrWrite.SetItemVisibility({'visible': True})
            }

            DrWrite.PlayAnimation({'name': 'hold_lp', 'blendTime': 0.10000000149011612})
            DrWrite.Talk({'message': 'Warashibe:QuestLetter1'})
            Timer.Wait({'time': 0.4000000059604645})

            fork {
                DrWrite.PlayLetterAnimation()
            } {
                DrWrite.PlayAnimation({'name': 'open_st', 'blendTime': 0.10000000149011612})
                DrWrite.PlayAnimation({'name': 'open_lp', 'blendTime': 0.10000000149011612})
            }

            DrWrite.Talk({'message': 'Warashibe:QuestLetter2'})
            DrWrite.ShowPicture()
            DrWrite.SetFacialExpression({'expression': 'smile'})
            DrWrite.Talk({'message': 'Warashibe:QuestLetter3'})

            fork {
                DrWrite.PlayAnimation({'name': 'wait', 'blendTime': 0.25})
            } {
                DrWrite.SetFacialExpression({'expression': 'serious'})
            } {
                DrWrite.SetItemVisibility({'visible': False})
            } {
                Timer.Wait({'time': 0.75})
                DrWrite.AimPlayer({'withoutTurn': True, 'duration': 0.4000000059604645, 'boneName': ''})
            }

            DrWrite.Talk({'message': 'Warashibe:QuestLetter4'})
            Event5:
            if !Dialog.GetLastResult() {
                EventFlags.SetFlag({'value': True, 'symbol': 'BroomDrop'})
                Inventory.SetWarashibeItem({'itemType': 10})

                fork {
                    Item[Broom].Deactivate()
                } {
                    Link.GenericItemGetSequence({'itemType': 39, 'keepCarry': False, 'messageEntry': ''})
                } {
                    DrWrite.PlayAnimation({'name': 'wait', 'blendTime': 0.25})
                } {
                    DrWrite.SetFacialExpression({'expression': 'smile'})
                }

                DrWrite.SetFacialExpression({'expression': 'normal'})
            } else {
                DrWrite.Talk({'message': 'Warashibe:QuestLetter5'})
                goto Event5
            }
        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'DrWriteSecondTalked'}) {

        fork {
            DrWrite.GenericTalkSequence({'keepPersonalSpace': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            DrWrite.SetFacialExpression({'expression': 'excite'})
        } {
            DrWrite.Talk({'message': 'Npc:WriteGetLetter'})
        }

        EventFlags.SetFlag({'symbol': 'DrWriteSecondTalked', 'value': True})
        DrWrite.SetFacialExpression({'expression': 'normal'})
        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            DrWrite.GenericTalkSequence({'keepPersonalSpace': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            DrWrite.SetFacialExpression({'expression': 'excite'})
        } {
            DrWrite.Talk({'message': 'Npc:WriteAfterWarashibe'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}
