-------- EventFlow: Ghost --------

Actor: Ghost[companion]
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'SetFacialExpression', 'MoveToCompassPoint']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility', 'MoveToCompassPoint', 'PlayAnimation', 'ClearPowerUp']
queries: ['WithGhost']
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

void GhostHouse() {
    if !Link.WithGhost() {

        call PlayerStart.EntranceIn()

    } else
    if !EventFlags.CheckFlag({'symbol': 'Ghost2_Clear'}) {

        call PlayerStart.EntranceIn()

    } else
    if !EventFlags.CheckFlag({'symbol': 'Ghost3_Clear'}) {
        Link.ClearPowerUp()
        Audio.PlayZoneAudio()
        Hud.PlayOutAnim()

        fork {
            Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        } {
            Link.MoveToCompassPoint({'direction': 2, 'distance': 1.0, 'speed': 0, 'timeOut': 7.0})
        } {
            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
        } {
            Ghost[companion].MoveToCompassPoint({'direction': 2, 'distance': 1.5, 'speed': 0, 'timeOut': 7.0})
        }


        fork {
            Ghost[companion].PlayAnimation({'name': 'eventmove_a', 'blendTime': 0.0})
        } {
            Fade.StartPreset({'preset': 8})
        }


        fork {
            Ghost[companion].SetFacialExpression({'expression': 'worry'})
        } {
            Ghost[companion].PlayAnimation({'name': 'lookdown', 'blendTime': 0.10000000149011612})
        } {
            Ghost[companion].Talk({'message': 'Scenario:Lv5GhostHouse1'})
        }

        Ghost[companion].PlayAnimation({'name': 'eventmove_b', 'blendTime': 0.20000000298023224})

        fork {
            Ghost[companion].PlayAnimation({'name': 'cry', 'blendTime': 0.20000000298023224})
        } {
            Ghost[companion].Talk({'message': 'Scenario:Lv5GhostHouse2'})
        }

        Ghost[companion].PlayAnimation({'name': 'eventmove_c', 'blendTime': 0.20000000298023224})

        fork {
            Ghost[companion].PlayAnimation({'name': 'talk', 'blendTime': 0.20000000298023224})
        } {
            Ghost[companion].Talk({'message': 'Scenario:Lv5GhostHouse3'})
        }

        EventFlags.SetFlag({'symbol': 'Ghost3_Clear', 'value': True})
        Ghost[companion].SetFacialExpression({'expression': 'normal'})

        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            Hud.PlayInAnim()
        }

        GameControl.RequestAutoSave()
    } else {

        call PlayerStart.EntranceIn()

    }
}
