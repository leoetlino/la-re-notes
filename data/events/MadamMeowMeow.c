-------- EventFlow: MadamMeowMeow --------

Actor: MadamMeowMeow
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'PlayAnimation', 'LookAtTalker', 'SetFacialExpression']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'PlayAnimation', 'SetFacialExpression', 'AimCompassPoint', 'Heal', 'LeaveCompanion', 'WarpToActorWithCompassPoint']
queries: ['WithWanwan']
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

Actor: Hud
entrypoint: None()
actions: ['SetHeartUpdateEnable']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show', 'ShowKeep']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'count': 1, 'itemType': 45}) {
        if !Inventory.HasItem({'itemType': 31, 'count': 1}) {

            fork {
                MadamMeowMeow.GenericTalkSequence({'selfTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                MadamMeowMeow.Talk({'message': 'Npc:MadamTalk'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                MadamMeowMeow.GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                MadamMeowMeow.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
            } {
                MadamMeowMeow.Talk({'message': 'Npc:WantRibbon1'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    } else
    if !Inventory.HasItem({'count': 1, 'itemType': 46}) {
        if !Link.WithWanwan() {

            fork {
                MadamMeowMeow.GenericTalkSequence({'selfTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                MadamMeowMeow.Talk({'message': 'Scenario:Lv2MadamHappening'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else
        if !Inventory.HasItem({'itemType': 31, 'count': 1}) {

            fork {
                MadamMeowMeow.GenericTalkSequence({'selfTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                MadamMeowMeow.Talk({'message': 'Npc:MadamBeforeLv2'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                MadamMeowMeow.GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                MadamMeowMeow.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
            } {
                MadamMeowMeow.Talk({'message': 'Npc:WantRibbon1'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    } else
    if !EventFlags.CheckFlag({'symbol': 'BowwowClear'}) {
        Fade.StartPreset({'preset': 9})

        fork {
            Link.WarpToActorWithCompassPoint({'direction': 2, 'distance': 1.7999999523162842, 'actor': ActorIdentifier(name="MadamMeowMeow"), 'offsetY': 0.0})
        } {
            MadamMeowMeow.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
        }

        Fade.StartPreset({'preset': 8})
        EventFlags.SetFlag({'symbol': 'BowwowClear', 'value': True})
        MadamMeowMeow.GenericTalkSequence({'keepPersonalSpace': False, 'cameraLookAt': False, 'playerTalkAnim': False, 'aimToPlayer': True, 'selfTalkAnim': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
        MadamMeowMeow.Talk({'message': 'Scenario:Lv3ReturnBowwow1'})

        fork {
            Timer.Wait({'time': 1.7000000476837158})
            MadamMeowMeow.Talk({'message': 'Scenario:Lv3ReturnBowwow2'})
        } {

            fork {
                MadamMeowMeow.PlayAnimation({'name': 'kiss', 'blendTime': 0.10000000149011612})
            } {
                MadamMeowMeow.SetFacialExpression({'expression': 'kiss'})
            }


            fork {
                MadamMeowMeow.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
            } {
                MadamMeowMeow.SetFacialExpression({'expression': 'normal'})
            }

        }


        fork {
            Hud.SetHeartUpdateEnable({'enable': True})
        } {
            Link.Heal({'amount': 32})
        } {
            Dialog.ShowKeep({'message': 'Scenario:Lv3ReturnBowwow3'})
        }

        Dialog.ShowKeep({'message': 'Scenario:Lv3ReturnBowwow4'})

        fork {
            Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
        } {
            Link.SetFacialExpression({'expression': 'excite'})
        } {
            Dialog.Show({'message': 'Scenario:Lv3ReturnBowwow5'})
        } {
            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
        }


        fork {
            Link.SetFacialExpression({'expression': 'normal'})
        } {
            EventFlags.SetFlag({'symbol': 'MadamClear', 'value': True})
        }

        Link.LeaveCompanion()
        GameControl.RequestAutoSave()
    } else
    if !Inventory.HasItem({'itemType': 31, 'count': 1}) {

        fork {
            MadamMeowMeow.GenericTalkSequence({'selfTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            MadamMeowMeow.PlayAnimation({'name': 'laugh', 'blendTime': 0.10000000149011612})
        } {
            MadamMeowMeow.Talk({'message': 'Npc:MadamTalk'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            MadamMeowMeow.GenericTalkSequence({'selfTalkAnim': False, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            MadamMeowMeow.PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
        } {
            MadamMeowMeow.Talk({'message': 'Npc:WantRibbon1'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}
