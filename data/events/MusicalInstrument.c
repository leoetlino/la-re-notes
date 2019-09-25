-------- EventFlow: MusicalInstrument --------

Actor: Item
entrypoint: None()
actions: ['Deactivate', 'PlayTailorGettingChannel']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show', 'ShowInstrumentMessage']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequenceByKey', 'PlayInstrumentShineEffect', 'ClearPowerUp']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItemByKey']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump', 'RequestAutoSave']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset', 'StartParam']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayAndWaitMusicalInstrument', 'StopAllBGM', 'StopOtherThanSystemSE', 'PlayOneshotSystemSE']
queries: []
params: None

void get() {
    Link.ClearPowerUp()
    Audio.StopAllBGM({'duration': 1.0})
    Item.Deactivate()
    Item.PlayTailorGettingChannel()
    Link.GenericItemGetSequenceByKey({'itemKey': 'itemKey', 'keepCarry': True, 'messageEntry': ''})
    Inventory.AddItemByKey({'itemKey': 'itemKey', 'count': 1, 'index': -1, 'autoEquip': False})

    fork {
        Audio.PlayAndWaitMusicalInstrument({'itemKey': 'itemKey'})
    } {
        Link.PlayInstrumentShineEffect()
    }

    Timer.Wait({'time': 2.0})

    fork {
        Fade.StartPreset({'preset': 3})
        Fade.StartParam({'time': 0.75, 'colorR': 0.8999999761581421, 'colorG': 0.8999999761581421, 'colorB': 0.8999999761581421, 'mode': 2})
    } {
        Audio.StopOtherThanSystemSE({'duration': 3.0})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_ENV_GET_INST_WHITEOUT2', 'volume': 1.0, 'pitch': 1.0})
    }

    Timer.Wait({'time': 2.0})
    Dialog.ShowInstrumentMessage()
    GameControl.RequestLevelJump({'level': 'level', 'locator': 'location', 'offsetX': 0.0, 'offsetZ': 0.0})
    GameControl.RequestAutoSave()
}

void FullMoonCello_Ann() {
    Dialog.Show({'message': 'Scenario:Lv1Clear'})
}

void ConchHorn_Ann() {
    Dialog.Show({'message': 'Scenario:Lv2Clear'})
}

void SeaLilysBell_Ann() {
    Dialog.Show({'message': 'Scenario:Lv3Clear'})
}

void SurfHarp_Ann() {
    Dialog.Show({'message': 'Scenario:Lv4Clear'})
}

void WindMarimba_Ann() {
    Dialog.Show({'message': 'Scenario:Lv5Clear'})
}

void CoralTriangle_Ann() {
    Dialog.Show({'message': 'Scenario:Lv6Clear'})
}

void EveningCalmOrgan_Ann() {
    Dialog.Show({'message': 'Scenario:Lv7Clear'})
}

void ThunderDrum_Ann() {
    Dialog.Show({'message': 'Scenario:Lv8Clear'})
}

void Uncompleted_Ann() {
    Dialog.Show({'message': 'Scenario:Instrument_Shortage'})
}
