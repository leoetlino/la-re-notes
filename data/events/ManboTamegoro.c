-------- EventFlow: ManboTamegoro --------

Actor: ManbosFish[Left]
entrypoint: None()
actions: ['Activate', 'PlayAnimation']
queries: []
params: None

Actor: ManbosFish[Right]
entrypoint: None()
actions: ['Activate', 'PlayAnimation']
queries: []
params: None

Actor: ManboTamegoro
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'GenericTalkSequence']
queries: []
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
actions: ['PlayAnimation', 'SetGravityEnable', 'SetEquipmentVisibility', 'AddWarpPoint', 'GenericItemGetSequence', 'SetDisablePowerUpEffect', 'MoveToTargetLinkedPoint', 'AimActor']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['PreloadTimeline', 'InvokeStreamSyncTimeline']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset']
queries: []
params: None

void talk() {

    fork {
        Link.PlayAnimation({'name': 'wt_swim_wait', 'blendTime': 0.10000000149011612})
    } {
        Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})
    }

    Link.SetGravityEnable({'enable': False})
    if !Inventory.HasItem({'itemType': 54, 'count': 1}) {

        fork {
            ManboTamegoro.GenericTalkSequence({'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': True, 'selfTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
        } {
            ManboTamegoro.PlayAnimation({'name': 'talk', 'blendTime': 0.30000001192092896})
        } {
            ManboTamegoro.Talk({'message': 'Scenario:QuestManboSong'})
        }

        if !Dialog.GetLastResult() {
            if !Inventory.HasItem({'itemType': 17, 'count': 1}) {
                ManboTamegoro.Talk({'message': 'Scenario:NoneOcarinaManbo'})
            } else {
                Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
                ManboTamegoro.Talk({'message': 'Scenario:YesManboSong'})
                Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 2, 'actor': ActorIdentifier(name="ManboTamegoro"), 'timeOut': 7.0})
                Link.AimActor({'actor': ActorIdentifier(name="ManboTamegoro"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

                fork {
                    ManbosFish[Left].Activate()
                } {
                    ManbosFish[Right].Activate()
                }

                Hud.PlayOutAnim()
                Timer.Wait({'time': 0.5})
                FlowControl.PreloadTimeline({'filename': 'ManboTamegoro'})
                Audio.StopAllBGM({'duration': 1.0})
                Timer.Wait({'time': 0.5})
                FlowControl.InvokeStreamSyncTimeline({'filename': 'ManboTamegoro', 'label': 'BGM_OCARINA_MANBO', 'volume': 1.0})

                fork {
                    ManbosFish[Left].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                } {
                    ManbosFish[Right].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                } {
                    ManboTamegoro.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                }

                Link.GenericItemGetSequence({'itemType': 54, 'keepCarry': False, 'messageEntry': ''})
                Inventory.AddItem({'itemType': 54, 'count': 1, 'autoEquip': False})
                Link.AddWarpPoint({'key': 'MambogaPond'})

                fork {
                    Link.AimActor({'actor': ActorIdentifier(name="ManboTamegoro"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
                } {
                    Link.PlayAnimation({'name': 'wt_swim_wait', 'blendTime': 0.10000000149011612})
                } {
                    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': True})
                } {
                    Camera.Reset({'chaseRatio': 0.10000000149011612})
                }


                fork {
                    ManboTamegoro.PlayAnimation({'name': 'talk_smile', 'blendTime': 0.30000001192092896})
                } {
                    ManboTamegoro.Talk({'message': 'Npc:ManboGetSong'})
                }

                Hud.PlayInAnim()
                Audio.PlayZoneBGM({'stopbgm': True})
                Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
                GameControl.RequestAutoSave()
            }
        } else {
            ManboTamegoro.Talk({'message': 'Scenario:NoManboSong'})
        }
    } else {

        fork {
            ManboTamegoro.GenericTalkSequence({'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': True, 'selfTalkAnim': False, 'aimToPlayer': True, 'aimFromPlayer': True, 'distanceOffset': 0.0})
        } {
            ManboTamegoro.PlayAnimation({'name': 'talk_smile', 'blendTime': 0.30000001192092896})
        } {
            ManboTamegoro.Talk({'message': 'Npc:ManboGetSong'})
        }

    }
}
