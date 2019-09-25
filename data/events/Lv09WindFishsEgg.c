-------- EventFlow: Lv09WindFishsEgg --------

Actor: Link
entrypoint: None()
actions: ['MoveToCompassPoint']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump']
queries: []
params: None

void StairsUp() {

    fork {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 3.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 9})
    }

    GameControl.RequestLevelJump({'level': 'Ending', 'locator': 'Lv09WindFishsEgg_05H', 'offsetX': 0.0, 'offsetZ': 0.0})
}
