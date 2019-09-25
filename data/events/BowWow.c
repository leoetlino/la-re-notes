-------- EventFlow: BowWow --------

Actor: BowWow
entrypoint: None()
actions: ['Join', 'Talk', 'LookAtCharacter']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle', 'StopAllBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void rescue() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.StopAllBGM({'duration': 1.0})

    fork {
        BowWow.Talk({'message': 'Scenario:Lv2GetBowwow'})
    } {
        Audio.PlayJingle({'label': 'BGM_FANFARE_BIGITEM_GET', 'volume': 1.0})
    } {
        BowWow.Join()
    } {
        BowWow.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    }

    EventFlags.SetFlag({'symbol': 'BowWowJoin', 'value': True})
    Audio.PlayZoneBGM({'stopbgm': True})
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
}
