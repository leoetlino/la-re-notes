-------- EventFlow: MarthasBayFisherman --------

Actor: FishingBoat[Boat]
entrypoint: None()
actions: ['Activate', 'PlayAnimation']
queries: []
params: None

Actor: FishingBoat
entrypoint: None()
actions: ['AttachPlayer', 'DetachPlayer']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: MarthasBayFisherman
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'SetItemVisibility', 'GenericTalkSequence']
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
actions: ['SetEquipmentVisibility', 'GenericItemGetSequence', 'KeepDistanceFromActor', 'PlayAnimation']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Fisherman
entrypoint: None()
actions: []
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['SetBGMPitch']
queries: []
params: None

void talk() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    FishingBoat[Boat].Activate()
    if !EventFlags.CheckFlag({'symbol': 'BrassiereDrop'}) {
        if !Inventory.HasItem({'count': 1, 'itemType': 40}) {

            fork {
                MarthasBayFisherman.GenericTalkSequence({'aimFromPlayer': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': True, 'aimToPlayer': False, 'selfTalkAnim': False, 'distanceOffset': 0.0})
            } {
                MarthasBayFisherman.PlayAnimation({'name': 'talk_fishing_boat', 'blendTime': 0.15000000596046448})
            } {
                MarthasBayFisherman.Talk({'message': 'Warashibe:WantFishhook'})
            }

            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } else {

            fork {
                MarthasBayFisherman.Talk({'message': 'Warashibe:QuestFishhook'})
            } {
                MarthasBayFisherman.GenericTalkSequence({'aimFromPlayer': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': True, 'aimToPlayer': False, 'selfTalkAnim': False, 'distanceOffset': 0.0})
            } {
                MarthasBayFisherman.PlayAnimation({'name': 'talk_fishing_boat', 'blendTime': 0.15000000596046448})
            }

            if !Dialog.GetLastResult() {
                MarthasBayFisherman.PlayAnimation({'name': 'talk', 'blendTime': 0.15000000596046448})
                EventFlags.SetFlag({'value': True, 'symbol': 'BrassiereDrop'})
                MarthasBayFisherman.Talk({'message': 'Warashibe:ClearFishhook1'})
                Link.KeepDistanceFromActor({'distance': 1.0, 'animName': 'ev_talkback', 'actor': ActorIdentifier(name="Fisherman")})

                fork {
                    MarthasBayFisherman.PlayAnimation({'name': 'casting', 'blendTime': 0.10000000149011612})
                } {
                    FishingBoat.AttachPlayer()
                }

                Timer.Wait({'time': 2.0})
                Audio.SetBGMPitch({'label': 'BGM_FISHINGMAN', 'pitch': 2.0})

                fork {
                    MarthasBayFisherman.PlayAnimation({'name': 'fishing', 'blendTime': 0.10000000149011612})
                } {
                    FishingBoat[Boat].PlayAnimation({'name': 'casting', 'blendTime': 0.10000000149011612})
                }

                MarthasBayFisherman.Talk({'message': 'Warashibe:ClearFishhook2'})

                fork {
                    MarthasBayFisherman.PlayAnimation({'name': 'getting', 'blendTime': 0.10000000149011612})
                } {
                    Timer.Wait({'time': 0.800000011920929})
                    MarthasBayFisherman.SetItemVisibility({'visible': True})
                } {
                    FishingBoat[Boat].PlayAnimation({'name': 'getting', 'blendTime': 0.10000000149011612})
                }

                Inventory.SetWarashibeItem({'itemType': 12})
                MarthasBayFisherman.SetItemVisibility({'visible': False})
                FishingBoat.DetachPlayer()

                fork {
                    MarthasBayFisherman.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                } {
                    Link.GenericItemGetSequence({'itemType': 41, 'messageEntry': 'Necklace', 'keepCarry': False})
                } {
                    Audio.SetBGMPitch({'label': 'BGM_FISHINGMAN', 'pitch': 1.0})
                } {
                    FishingBoat[Boat].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                }

                Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {
                MarthasBayFisherman.Talk({'message': 'Warashibe:BadFishhook'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        }
    } else {

        fork {
            MarthasBayFisherman.Talk({'message': 'Npc:FisherAfterWarashibe'})
        } {
            MarthasBayFisherman.GenericTalkSequence({'aimFromPlayer': False, 'playerTalkAnim': False, 'cameraLookAt': False, 'keepPersonalSpace': True, 'aimToPlayer': False, 'selfTalkAnim': False, 'distanceOffset': 0.0})
        } {
            MarthasBayFisherman.PlayAnimation({'name': 'talk_fishing_boat', 'blendTime': 0.15000000596046448})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}
