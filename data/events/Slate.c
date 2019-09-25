-------- EventFlow: Slate --------

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Slate
entrypoint: None()
actions: ['Examine', 'ShowPicture', 'HidePicture']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['PlayAnimation', 'SetEquipmentVisibility', 'SetDisablePowerUpEffect']
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

Actor: Audio
entrypoint: None()
actions: ['SetBGMTrackVolume']
queries: []
params: None

void examine() {
    Link.SetEquipmentVisibility({'ocarina': False, 'visibility': False, 'flipper': False})
    if !EventFlags.CheckFlag({'symbol': 'LightOn_Lamp_ArmosShrine_01A'}) {
        Link.PlayAnimation({'name': 'ev_nazoru_st', 'blendTime': 0.10000000149011612})

        fork {
            Link.PlayAnimation({'name': 'ev_nazoru_lp', 'blendTime': 0.10000000149011612})
        } {
            Dialog.Show({'message': 'Scenario:Lv6ShrineStone'})
        }

        Link.PlayAnimation({'name': 'ev_nazoru_ed', 'blendTime': 0.10000000149011612})
    } else {
        Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
        Hud.PlayOutAnim()
        if !EventFlags.CheckFlag({'symbol': 'SlateEventClear'}) {
            Link.PlayAnimation({'name': 'ev_nazoru_st', 'blendTime': 0.10000000149011612})

            fork {
                Slate.ShowPicture()
            } {
                Slate.Examine({'message': 'Scenario:Lv6RadShrineStone'})
            } {
                Link.PlayAnimation({'name': 'ev_nazoru_lp', 'blendTime': 0.10000000149011612})
            } {
                Audio.SetBGMTrackVolume({'label': 'BGM_PLACE_OF_FACE_KEY', 'track': 0, 'volume': 0.0, 'duration': 5.0})
            } {
                Audio.SetBGMTrackVolume({'label': 'BGM_PLACE_OF_FACE_KEY', 'duration': 5.0, 'track': 1, 'volume': 1.0})
            }

            Slate.HidePicture()
            Dialog.Show({'message': 'Scenario:Lv6RadShrineStone2'})
            EventFlags.SetFlag({'symbol': 'SlateEventClear', 'value': True})
            Link.PlayAnimation({'name': 'ev_nazoru_ed', 'blendTime': 0.10000000149011612})
            Hud.PlayInAnim()
            Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
            GameControl.RequestAutoSave()
        } else {
            Link.PlayAnimation({'name': 'ev_nazoru_st', 'blendTime': 0.10000000149011612})

            fork {
                Slate.Examine({'message': 'Scenario:Lv6RadShrineStone'})
            } {
                Link.PlayAnimation({'name': 'ev_nazoru_lp', 'blendTime': 0.10000000149011612})
            } {
                Slate.ShowPicture()
            } {
                Audio.SetBGMTrackVolume({'label': 'BGM_PLACE_OF_FACE_KEY', 'track': 0, 'volume': 0.0, 'duration': 5.0})
            } {
                Audio.SetBGMTrackVolume({'label': 'BGM_PLACE_OF_FACE_KEY', 'duration': 5.0, 'track': 1, 'volume': 1.0})
            }

            Slate.HidePicture()
            Link.PlayAnimation({'name': 'ev_nazoru_ed', 'blendTime': 0.10000000149011612})
            Hud.PlayInAnim()
            Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
        }
    }
}
