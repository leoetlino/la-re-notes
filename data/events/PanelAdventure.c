-------- EventFlow: PanelAdventure --------

Actor: GameControl
entrypoint: None()
actions: ['RequestLevelJump']
queries: []
params: None

Actor: PanelResultUI
entrypoint: None()
actions: ['Show']
queries: ['CheckNewReward']
params: None

Actor: PanelDungeon
entrypoint: None()
actions: ['EndAdventure']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM']
queries: []
params: None

Actor: Danpei
entrypoint: None()
actions: ['Talk']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void PanelClear() {
    PanelDungeon.EndAdventure()
    Timer.Wait({'time': 3.0})
    PanelResultUI.Show()
    if !PanelResultUI.CheckNewReward() {
        Audio.StopBGM({'duration': 1.5, 'label': 'BGM_PANEL_RESULT'})
        GameControl.RequestLevelJump({'level': 'PanelEdit', 'locator': 'PanelEdit', 'offsetX': 0.0, 'offsetZ': 0.0})
    } else {
        Audio.StopBGM({'duration': 1.5, 'label': 'BGM_PANEL_RESULT'})
        GameControl.RequestLevelJump({'level': 'DanpeiHouse', 'locator': 'DanpeiHouse_01A_b', 'offsetX': 0.0, 'offsetZ': 0.0})
    }
}

void PanelDeadEnd() {
    Danpei.Talk({'message': 'System:AdvDeadEnd'})
}
