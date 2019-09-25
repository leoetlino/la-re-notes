-------- EventFlow: Syrup --------

Actor: Inventory
entrypoint: None()
actions: ['RemoveItem', 'AddItem']
queries: ['HasItem']
params: None

Actor: Syrup
entrypoint: None()
actions: ['Talk', 'AimCompassPoint', 'PlayAnimationEx', 'SetMushroomVisibility', 'SetPowderVisibility', 'GenericTalkSequence', 'SetFacialExpression', 'PlayAnimation']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'AddRupee', 'GenericItemGetSequence']
queries: ['CheckRupee']
params: None

Actor: Dialog
entrypoint: None()
actions: []
queries: ['GetLastResult']
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM', 'PlayZoneBGM', 'StopBGM']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['ShowRupee']
queries: []
params: None

void talk() {
    if !EventFlags.CheckFlag({'symbol': 'MagicPowderFirstMessage'}) {
        if !Inventory.HasItem({'itemType': 11, 'count': 1}) {

            call No()

        } else {
            EventFlags.SetFlag({'symbol': 'MagicPowderFirstMessage', 'value': True})

            fork {
                Syrup.SetFacialExpression({'expression': 'smile'})
            } {
                Syrup.Talk({'message': 'Scenario:WitchHaveNeboketake'})
            } {
                Syrup.GenericTalkSequence({'playerTalkAnim': False, 'cameraLookAt': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'distanceOffset': 0.0})
            }

            Inventory.RemoveItem({'itemType': 11})

            call mix()

        }
    } else
    if !Inventory.HasItem({'itemType': 11, 'count': 1}) {

        call Second()

    } else {

        fork {
            Syrup.SetFacialExpression({'expression': 'smile'})
        } {
            Syrup.Talk({'message': 'Scenario:WitchHaveNeboketake'})
        } {
            Syrup.GenericTalkSequence({'playerTalkAnim': False, 'cameraLookAt': True, 'keepPersonalSpace': True, 'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'distanceOffset': 0.0})
        }

        Inventory.RemoveItem({'itemType': 11})

        call mix()

    }
}

void CandleCheck() {
    if EventFlags.CheckFlag({'symbol': 'MagicPowderFirstMessage'}) {
        Timer.Wait({'time': 1.0})
        Syrup.Talk({'message': 'Scenario:WitchUsePowder'})
        Syrup.AimCompassPoint({'direction': 0, 'duration': 0.8999999761581421, 'withoutTurn': False})
    }
}

void mix() {
    Audio.StopAllBGM({'duration': 1.0})

    fork {
        Syrup.PlayAnimationEx({'name': 'mix', 'blendTime': 0.20000000298023224, 'time': 5.900000095367432})
    } {
        Timer.Wait({'time': 2.0})
        Audio.PlayBGM({'label': 'BGM_SHOP_FAST', 'volume': 1.0})
    } {
        Timer.Wait({'time': 0.18000000715255737})
        Syrup.SetMushroomVisibility({'visible': True})
        Timer.Wait({'time': 0.800000011920929})
        Syrup.SetMushroomVisibility({'visible': False})
    } {
        Syrup.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
    } {
        Syrup.SetFacialExpression({'expression': 'normal'})
    }


    fork {
        Syrup.PlayAnimation({'name': 'give', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.07999999821186066})
        Syrup.SetPowderVisibility({'visible': True})
    }

    Timer.Wait({'time': 2.5})
    Syrup.Talk({'message': 'Scenario:WitchGetPowder'})
    Audio.StopBGM({'label': 'BGM_SHOP_FAST', 'duration': 0.5})
    Syrup.SetPowderVisibility({'visible': False})
    Syrup.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    Inventory.AddItem({'itemType': 12, 'count': 20, 'autoEquip': False})

    fork {
        Link.GenericItemGetSequence({'itemType': 12, 'messageEntry': 'MagicPowder_First', 'keepCarry': False})
    } {
        Timer.Wait({'time': 3.299999952316284})
        Audio.PlayZoneBGM({'stopbgm': True})
    }

}

void Second() {
    if !Inventory.HasItem({'itemType': 56, 'count': 40}) {
        if !Inventory.HasItem({'itemType': 12, 'count': 20}) {
            Hud.ShowRupee({'visible': True})
            Syrup.Talk({'message': 'Npc:Rupee50MagicPowder'})
            if !Dialog.GetLastResult() {
                if !Link.CheckRupee({'amount': 50}) {
                    Syrup.Talk({'message': 'Npc:NoRupee50MagicPowder'})
                } else {
                    Link.AddRupee({'amount': -50})
                    Timer.Wait({'time': 0.30000001192092896})
                    Inventory.AddItem({'itemType': 12, 'count': 20, 'autoEquip': False})
                    Link.GenericItemGetSequence({'itemType': 12, 'messageEntry': 'MagicPowder_Buy', 'keepCarry': False})
                }
            } else {
                Syrup.Talk({'message': 'Npc:WitchNoneNeboketa'})
            }
        } else {

            call No()

        }
    } else
    if !Inventory.HasItem({'itemType': 12, 'count': 40}) {
        Hud.ShowRupee({'visible': True})
        Syrup.Talk({'message': 'Npc:Rupee50MagicPowder'})
        if !Dialog.GetLastResult() {
            if !Link.CheckRupee({'amount': 50}) {
                Syrup.Talk({'message': 'Npc:NoRupee50MagicPowder'})
            } else {
                Link.AddRupee({'amount': -50})
                Timer.Wait({'time': 0.30000001192092896})
                Inventory.AddItem({'itemType': 12, 'count': 40, 'autoEquip': False})
                Link.GenericItemGetSequence({'itemType': 12, 'messageEntry': 'MagicPowder_Buy', 'keepCarry': False})
            }
        } else {
            Syrup.Talk({'message': 'Npc:WitchNoneNeboketa'})
        }
    } else {

        call No()

    }
}

void No() {
    Syrup.Talk({'message': 'Npc:WitchNoneNeboketa'})
    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
}
