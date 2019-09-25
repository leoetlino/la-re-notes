-------- EventFlow: SmallKey --------

Actor: SmallKey
entrypoint: None()
actions: ['Fall', 'GenericGimmickSequence', 'Activate', 'PlayOneshotSE', 'PlayTailorOtherChannelEx', 'Destroy', 'Deactivate', 'SetActorSwitch']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle', 'PlayJingleTimeWait']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequenceByKey']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItemByKey']
queries: []
params: None

void pop() {
    SmallKey.GenericGimmickSequence({'cameraLookAt': True, 'distanceOffset': 0.0})
    SmallKey.Activate()
    SmallKey.PlayOneshotSE({'label': 'SE_SY_NAZOKAGI_DROP', 'volume': 1.0, 'pitch': 1.0})
    SmallKey.Fall()
    Timer.Wait({'time': 2.5999999046325684})
    Audio.PlayJingleTimeWait({'label': 'BGM_NAZOTOKI_SEIKAI', 'duration': 1.6799999475479126, 'volume': 1.0})
}

void Lv4_04E_pop() {
    SmallKey.GenericGimmickSequence({'cameraLookAt': True, 'distanceOffset': 0.0})
    SmallKey.Activate()
    SmallKey.PlayOneshotSE({'label': 'SE_SY_NAZOKAGI_DROP', 'volume': 1.0, 'pitch': 1.0})
    SmallKey.Fall()
    Timer.Wait({'time': 2.0})
    SmallKey.PlayTailorOtherChannelEx({'channel': 'Lv04_fall', 'time': 1.5, 'restart': False, 'index': 0})
    Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
    SmallKey.Destroy()
}

void take() {
    SmallKey.Deactivate()
    SmallKey.SetActorSwitch({'value': True, 'switchIndex': 1})
    Link.GenericItemGetSequenceByKey({'messageEntry': '', 'itemKey': 'SmallKey', 'keepCarry': False})
    SmallKey.Destroy()
    Inventory.AddItemByKey({'itemKey': 'SmallKey', 'count': 1, 'index': -1, 'autoEquip': False})
}
