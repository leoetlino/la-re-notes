-------- EventFlow: MadBatter --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: MadBatter
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'PlayTailorOtherChannelEx', 'SetActorSwitch', 'Destroy', 'PlayAnimationEx']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: ['HasItem']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'PlayAnimation', 'PlayTailorOtherChannelEx', 'SetDisablePowerUpEffect', 'WarpToActor', 'AimActor', 'StopTailorOtherChannel']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['SetFixedCamera']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM', 'StopBGM', 'PlayZoneAudio']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

void end() {
    MadBatter.PlayAnimation({'name': 'beam_st', 'blendTime': 0.10000000149011612})

    fork {
        Link.PlayAnimation({'name': 'ev_dmg_elec_lp', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 3.0})
    } {
        Link.PlayTailorOtherChannelEx({'channel': 'madbatter_dmg', 'time': 0.10000000149011612, 'restart': False, 'index': 0})
    } {
        MadBatter.PlayAnimation({'name': 'beam_lp', 'blendTime': 0.0})
    }


    fork {
        Link.StopTailorOtherChannel({'channel': 'madbatter_dmg', 'index': 0})
        Link.PlayAnimation({'name': 'ev_dmg_elec_ed', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'wait', 'blendTime': 1.0})
    } {
        MadBatter.PlayAnimationEx({'name': 'wait', 'blendTime': 0.0, 'time': 0.0})
        MadBatter.Talk({'message': 'SubEvent:ByebyeMadBatter'})
    }

}

void talk2() {
    Fade.StartPreset({'preset': 11})
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.StopAllBGM({'duration': 0.0})
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
    Camera.SetFixedCamera({'posX': 6.75, 'rotY': 0.0, 'rotZ': 0.0, 'fieldOfViewY': 28.1200008392334, 'distanceToLookAt': 17.5, 'posY': 15.5, 'rotX': -50.0, 'posZ': 16.799999237060547, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})

    fork {
        Link.WarpToActor({'distance': 2.0, 'actor': ActorIdentifier(name="MadBatter"), 'offsetY': 0.0})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="MadBatter"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    Fade.StartPreset({'preset': 10})

    fork {
        MadBatter.PlayAnimation({'name': 'pop', 'blendTime': 0.0})
    } {
        Audio.PlayBGM({'label': 'BGM_MADBATTER', 'volume': 1.0})
    }

    MadBatter.PlayAnimation({'name': 'wait', 'blendTime': 0.0})
    MadBatter.Talk({'message': 'SubEvent:AwakeMadBatter'})
    Event7:
    if !Inventory.HasItem({'itemType': 56, 'count': 1}) {
        MadBatter.Talk({'message': 'SubEvent:AddMagicPowder'})
        if !Dialog.GetLastResult() {

            call end()

            Inventory.AddItem({'itemType': 56, 'count': 1, 'autoEquip': False})
            Inventory.AddItem({'itemType': 12, 'count': 40, 'autoEquip': False})
        } else
        Event8:
        if !Inventory.HasItem({'itemType': 57, 'count': 1}) {
            MadBatter.Talk({'message': 'SubEvent:AddBomb'})
            if !Dialog.GetLastResult() {

                call end()

                if !Inventory.HasItem({'count': 1, 'itemType': 4}) {
                    Inventory.AddItem({'itemType': 57, 'count': 1, 'autoEquip': False})
                    EventFlags.SetFlag({'value': True, 'symbol': 'DevilPowder'})
                } else {
                    Inventory.AddItem({'itemType': 57, 'count': 1, 'autoEquip': False})
                    Inventory.AddItem({'itemType': 4, 'count': 60, 'autoEquip': False})
                }
            } else
            Event9:
            if !Inventory.HasItem({'itemType': 58, 'count': 1}) {
                MadBatter.Talk({'message': 'SubEvent:AddArrow'})
                if !Dialog.GetLastResult() {

                    call end()

                    if !Inventory.HasItem({'count': 1, 'itemType': 6}) {
                        Inventory.AddItem({'itemType': 58, 'count': 1, 'autoEquip': False})
                    } else {
                        Inventory.AddItem({'itemType': 58, 'count': 1, 'autoEquip': False})
                        Inventory.AddItem({'count': 60, 'itemType': 6, 'autoEquip': False})
                    }
                } else
                goto Event7
            } else
            goto Event7
        } else
        goto Event9
    } else
    goto Event8
}

void end2() {
    Audio.StopBGM({'label': 'BGM_MADBATTER', 'duration': 0.5})
    Timer.Wait({'time': 0.15000000596046448})
    MadBatter.PlayTailorOtherChannelEx({'channel': 'Depop', 'time': 0.0, 'restart': False, 'index': 0})
    Timer.Wait({'time': 0.10000000149011612})
    MadBatter.PlayAnimation({'name': 'wait_lower', 'blendTime': 0.0})
    Audio.PlayZoneAudio()
    GameControl.RequestAutoSave()
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    Timer.Wait({'time': 0.5})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    MadBatter.SetActorSwitch({'switchIndex': 0, 'value': True})
    MadBatter.Destroy()
}

void talk() {

    call talk2()


    call end2()

}
