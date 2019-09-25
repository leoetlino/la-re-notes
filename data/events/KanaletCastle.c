-------- EventFlow: KanaletCastle --------

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'SetFixedCamera']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle', 'StopZoneAudio', 'PlayZoneAudio', 'StopZoneBaseAmbience', 'PlayBaseAmbienceSe']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['LoadZone', 'RequestAutoSave']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['ChangeEnvironmentNonWait']
queries: []
params: None

void CanalettoSwitch() {
    EventFlags.SetFlag({'symbol': 'GateOpen_Switch_KanaletCastle_01B', 'value': False})
    Fade.StartPreset({'preset': 9})

    fork {
        GameControl.LoadZone({'zoneID': 1659})
    } {
        Camera.SetFixedCamera({'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 24.0, 'rotX': -45.0, 'fieldOfViewY': 28.1200008392334, 'posX': 143.31900024414062, 'posY': 25.17099952697754, 'posZ': 103.0459976196289, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})
    } {
        Environment.ChangeEnvironmentNonWait({'name': 'Field', 'duration': 0.5})
    } {
        Audio.StopZoneAudio()
    }

    Fade.StartPreset({'preset': 8})

    fork {
        EventFlags.SetFlag({'symbol': 'GateOpen_Switch_KanaletCastle_01B', 'value': True})
        Timer.Wait({'time': 2.0})
    } {
        Audio.PlayJingle({'label': 'SE_MAP_CASTLE_GATE_OPEN', 'volume': 1.0})
    } {
        Audio.PlayBaseAmbienceSe({'groupLabel': 'GROUP_AMB_EXTERIOR1', 'label': 'SE_AMB_EXTERIOR1_BG'})
    }

    Dialog.Show({'message': 'System:OpenKanaletGate'})
    Fade.StartPreset({'preset': 9})
    Audio.StopZoneBaseAmbience()

    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Environment.ChangeEnvironmentNonWait({'name': 'KanaletCastle', 'duration': 0.5})
    } {
        Audio.PlayZoneAudio()
    }

    Fade.StartPreset({'preset': 8})
    GameControl.RequestAutoSave()
}
