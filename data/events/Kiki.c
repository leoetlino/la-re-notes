-------- EventFlow: Kiki --------

Actor: Kiki[kobun1]
entrypoint: None()
actions: ['MoveToLinkedPoint', 'PlayAnimation', 'Destroy', 'Activate', 'AimActorLinkedPoint', 'AimCompassPoint', 'MoveToTargetLinkedPoint']
queries: []
params: None

Actor: Kiki
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'LookAtTalker', 'PlayAnimation', 'MoveToLinkedPoint', 'Destroy', 'PlayTailorOtherChannelEx', 'StopTailorOtherChannel', 'AimActorLinkedPoint', 'MoveToCompassPoint', 'AimCompassPoint', 'ResetAim', 'SetGravityEnable', 'WarReady', 'AimActor']
queries: []
params: None

Actor: Kiki[kobun2]
entrypoint: None()
actions: ['MoveToLinkedPoint', 'PlayAnimation', 'Destroy', 'Activate', 'AimActorLinkedPoint', 'AimCompassPoint', 'MoveToTargetLinkedPoint']
queries: []
params: None

Actor: Kiki[kobun3]
entrypoint: None()
actions: ['MoveToLinkedPoint', 'PlayAnimation', 'Destroy', 'Activate', 'AimActorLinkedPoint', 'AimPlayer']
queries: []
params: None

Actor: Kiki[kobun4]
entrypoint: None()
actions: ['MoveToLinkedPoint', 'PlayAnimation', 'Destroy', 'Activate', 'AimActorLinkedPoint', 'AimPlayer']
queries: []
params: None

Actor: Item[Stick]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'GenericItemGetSequence', 'MoveToTargetActor', 'SetDisablePowerUpEffect', 'MoveToCompassPoint', 'AimCompassPoint']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayOneshotSystemSE', 'SetBGMVolume', 'PlayBGM']
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

Actor: Camera
entrypoint: None()
actions: ['SetFixedCamera']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: Item
entrypoint: None()
actions: ['Destroy']
queries: []
params: None

Actor: Character[companion]
entrypoint: None()
actions: ['AimActor']
queries: []
params: None

Actor: BowWow
entrypoint: None()
actions: []
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="Kiki"), 'distance': 3.0, 'timeOut': 7.0})
    if !Inventory.HasItem({'count': 1, 'itemType': 33}) {

        fork {
            Kiki.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        } {
            Kiki.Talk({'message': 'Warashibe:WantBanana'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else {

        fork {
            Kiki.Talk({'message': 'Warashibe:QuestBanana'})
        } {
            Kiki.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'cameraLookAt': True, 'distanceOffset': 0.0})
        }

        if !Dialog.GetLastResult() {
            Link.SetDisablePowerUpEffect({'sound': True, 'effect': True, 'materialAnim': True})
            Audio.SetBGMVolume({'volume': 0.0, 'duration': 1.0})
            Inventory.SetWarashibeItem({'itemType': 0})
            Kiki.PlayAnimation({'name': 'yorokobu', 'blendTime': 0.10000000149011612})
            Kiki.Talk({'message': 'Warashibe:ClearBanana'})

            fork {
                Kiki.MoveToCompassPoint({'speed': 1, 'direction': 0, 'distance': 2.75, 'timeOut': 7.0})
                Kiki.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
                Kiki.PlayAnimation({'name': 'jump', 'blendTime': 0.10000000149011612})
                Kiki.PlayAnimation({'name': 'wait_short', 'blendTime': 0.10000000149011612})
            } {
                Timer.Wait({'time': 4.0})
            } {
                Camera.SetFixedCamera({'rotY': 0.0, 'rotZ': 0.0, 'fieldOfViewY': 28.1200008392334, 'posX': 172.00399780273438, 'posY': 26.229999542236328, 'rotX': -45.0, 'distanceToLookAt': 24.0, 'posZ': 107.99099731445312, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
            } {
                Audio.PlayBGM({'label': 'BGM_EVENT_MONKEY', 'volume': 1.0})
            } {
                Timer.Wait({'time': 0.30000001192092896})
                Link.MoveToCompassPoint({'direction': 0, 'distance': 1.25, 'speed': 1, 'timeOut': 7.0})
                Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
            }


            fork {
                Kiki[kobun1].Activate()
            } {
                Kiki[kobun2].Activate()
            } {
                Kiki[kobun3].Activate()
            } {
                Kiki[kobun4].Activate()
            }


            fork {
                Kiki[kobun1].MoveToLinkedPoint({'speed': 1, 'index': 1, 'timeOut': 7.0})
            } {
                Kiki[kobun2].MoveToLinkedPoint({'speed': 1, 'index': 1, 'timeOut': 7.0})
            } {
                Kiki[kobun3].AimActorLinkedPoint({'duration': 0.0, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun3"), 'pointIndex': 2, 'withoutTurn': False})
                Kiki[kobun3].MoveToLinkedPoint({'speed': 1, 'index': 2, 'timeOut': 7.0})
            } {
                Kiki[kobun4].AimActorLinkedPoint({'duration': 0.0, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun4"), 'pointIndex': 2, 'withoutTurn': False})
                Kiki[kobun4].MoveToLinkedPoint({'speed': 1, 'index': 2, 'timeOut': 7.0})
            } {
                Kiki.PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'Event_Make_Bridge', 'restart': False, 'index': 0})
            }

            Timer.Wait({'time': 5.0})

            fork {
                EventFlags.SetFlag({'value': True, 'symbol': 'StickDrop'})
            } {
                Audio.PlayOneshotSystemSE({'label': 'SE_ENV_SARUKIKI_BRIDGE', 'volume': 1.0, 'pitch': 1.0})
            }


            fork {
                Kiki[kobun1].AimActorLinkedPoint({'pointIndex': 0, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun1"), 'duration': 0.4000000059604645, 'withoutTurn': False})
                Kiki[kobun1].MoveToLinkedPoint({'index': 0, 'speed': 0, 'timeOut': 7.0})
                Kiki[kobun1].AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
            } {
                Kiki[kobun2].AimActorLinkedPoint({'pointIndex': 0, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun2"), 'duration': 0.4000000059604645, 'withoutTurn': False})
                Kiki[kobun2].MoveToLinkedPoint({'index': 0, 'speed': 0, 'timeOut': 7.0})
                Kiki[kobun2].AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
            } {
                Kiki[kobun3].AimActorLinkedPoint({'pointIndex': 0, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun3"), 'duration': 0.4000000059604645, 'withoutTurn': False})
                Kiki[kobun3].MoveToLinkedPoint({'index': 0, 'speed': 0, 'timeOut': 7.0})
                Kiki[kobun3].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            } {
                Kiki[kobun4].AimActorLinkedPoint({'pointIndex': 0, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun4"), 'duration': 0.4000000059604645, 'withoutTurn': False})
                Kiki[kobun4].MoveToLinkedPoint({'index': 0, 'speed': 0, 'timeOut': 7.0})
                Kiki[kobun4].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            } {
                Kiki.StopTailorOtherChannel({'channel': 'Event_Make_Bridge', 'index': 0})
            } {
                Timer.Wait({'time': 1.0})
                Kiki.MoveToCompassPoint({'speed': 1, 'direction': 2, 'distance': 1.5, 'timeOut': 7.0})
                Kiki.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
                Kiki.PlayAnimation({'name': 'wait_short', 'blendTime': 0.10000000149011612})
            }


            fork {
                Kiki.PlayAnimation({'name': 'yorokobu', 'blendTime': 0.10000000149011612})
            } {
                Kiki[kobun1].PlayAnimation({'name': 'yorokobu', 'blendTime': 0.10000000149011612})
            } {
                Kiki[kobun2].PlayAnimation({'name': 'yorokobu', 'blendTime': 0.10000000149011612})
            } {
                Kiki[kobun3].PlayAnimation({'name': 'yorokobu', 'blendTime': 0.10000000149011612})
            } {
                Kiki[kobun4].PlayAnimation({'name': 'yorokobu', 'blendTime': 0.10000000149011612})
            }

            Timer.Wait({'time': 4.0})

            fork {
                Kiki.Talk({'message': 'Warashibe:GetBridge'})
            } {
                Kiki.GenericTalkSequence({'keepPersonalSpace': False, 'playerTalkAnim': False, 'selfTalkAnim': False, 'aimFromPlayer': False, 'aimToPlayer': False, 'cameraLookAt': True, 'distanceOffset': 0.0})
            }

            Kiki.ResetAim()

            fork {

                fork {
                    Kiki.AimActorLinkedPoint({'pointIndex': 0, 'actor': ActorIdentifier(name="Kiki"), 'duration': 0.4000000059604645, 'withoutTurn': False})
                } {
                    Kiki.SetGravityEnable({'enable': False})
                    Kiki.MoveToLinkedPoint({'speed': 1, 'index': 0, 'timeOut': 7.0})
                }

                Kiki.Destroy()
            } {
                Kiki[kobun1].MoveToTargetLinkedPoint({'speed': 1, 'index': 2, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun1"), 'timeOut': 7.0})
                Kiki[kobun1].Destroy()
            } {
                Kiki[kobun2].MoveToTargetLinkedPoint({'speed': 1, 'index': 2, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun2"), 'timeOut': 7.0})
                Kiki[kobun2].Destroy()
            } {
                Kiki[kobun3].AimActorLinkedPoint({'pointIndex': 1, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun3"), 'duration': 0.4000000059604645, 'withoutTurn': False})
                Kiki[kobun3].MoveToLinkedPoint({'speed': 1, 'index': 1, 'timeOut': 7.0})
                Kiki[kobun3].Destroy()
            } {
                Kiki[kobun4].AimActorLinkedPoint({'pointIndex': 1, 'actor': ActorIdentifier(name="Kiki", sub_name="kobun4"), 'duration': 0.4000000059604645, 'withoutTurn': False})
                Kiki[kobun4].MoveToLinkedPoint({'speed': 1, 'index': 1, 'timeOut': 7.0})
                Kiki[kobun4].Destroy()
            } {
                Timer.Wait({'time': 0.30000001192092896})
                Item[Stick].Activate()
            } {
                Audio.PlayOneshotSystemSE({'label': 'SE_ENV_SARUKIKI_BRIDGE_BUILD4', 'volume': 1.0, 'pitch': 1.0})
            }

            Inventory.SetWarashibeItem({'itemType': 5})

            fork {
                Link.GenericItemGetSequence({'itemType': 34, 'messageEntry': 'Stick', 'keepCarry': False})
            } {
                Item.Destroy()
            }


            fork {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                Audio.SetBGMVolume({'duration': 1.5, 'volume': 1.0})
            }

            Link.SetDisablePowerUpEffect({'effect': False, 'sound': False, 'materialAnim': False})
        } else {
            Kiki.Talk({'message': 'Warashibe:WantBanana'})
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        }
    }
}

void Bowwow_talk() {
    Character[companion].AimActor({'actor': ActorIdentifier(name="Kiki"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

    fork {
        Kiki.LookAtTalker({'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Kiki.PlayAnimation({'name': 'jump', 'blendTime': 0.10000000149011612})
    } {
        Kiki.AimActor({'actor': ActorIdentifier(name="BowWow"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Kiki.Talk({'message': 'SubEvent:KiKiVSBowwow'})
    } {
        Kiki.PlayAnimation({'name': 'ikaku', 'blendTime': 0.20000000298023224})
    }

    Kiki.WarReady()
}
