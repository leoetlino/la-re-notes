-------- EventFlow: MoriblinSword --------

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

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayOneshotSystemSE', 'PlayZoneAudio']
queries: []
params: None

Actor: Enemy
entrypoint: None()
actions: ['PlayAnimation']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void MoriblinSword() {

    fork {
        Timer.Wait({'time': 0.5})
    } {
        Enemy.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

    if !EventFlags.CheckFlag({'symbol': 'Lv1InstrumentGet'}) {
        Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    } else
    if !EventFlags.CheckFlag({'symbol': 'BowWowJoin'}) {
        if !EventFlags.CheckFlag({'symbol': 'MoriblinDemoClear'}) {
            Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
            Audio.PlayOneshotSystemSE({'label': 'SE_ENV_BOWWOW_VO3', 'volume': 1.0, 'pitch': 1.0})
            Dialog.Show({'message': 'Scenario:Lv2FirstMoblinCave'})
            EventFlags.SetFlag({'value': True, 'symbol': 'MoriblinDemoClear'})
            Audio.PlayZoneAudio()
            Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
        } else {
            Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
        }
    } else {
        Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    }
}
