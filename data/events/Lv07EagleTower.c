-------- EventFlow: Lv07EagleTower --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle', 'StopZoneAudio', 'PlayZoneAudio', 'PlayBaseAmbienceSe', 'StopZoneBaseAmbience']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'SetFixedCamera', 'Quake']
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
actions: ['SetLookAtEnvironmentNonWait']
queries: []
params: None

void BrokenPillar() {
    Timer.Wait({'time': 2.5})

    fork {
        GameControl.LoadZone({'zoneID': 948})
    } {
        Fade.StartPreset({'preset': 9})
    }

    Camera.SetFixedCamera({'rotY': 0.0, 'rotZ': 0.0, 'distanceToLookAt': 69.0, 'fieldOfViewY': 10.0, 'nearClipDistance': 0.10000000149011612, 'clipDistanceCtrl': True, 'farClipDistance': 1000.0, 'posZ': 116.3479995727539, 'posY': 9.787090301513672, 'posX': 218.23199462890625, 'rotX': 2.4209001064300537})
    Audio.StopZoneAudio()
    Timer.Wait({'time': 0.5})
    Environment.SetLookAtEnvironmentNonWait()
    Timer.Wait({'time': 0.5})

    fork {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayBaseAmbienceSe({'groupLabel': 'GROUP_AMB_LV7BOSS', 'label': 'SE_AMB_LV7_BOSS_BG'})
    }


    fork {
        EventFlags.SetFlag({'value': True, 'symbol': 'Lv7BrokenPillar'})
        Timer.Wait({'time': 8.0})
    } {
        Camera.Quake({'duration': 1.0, 'targetPower': 1, 'initPower': 0})
        Timer.Wait({'time': 0.699999988079071})
        Camera.Quake({'targetPower': 3, 'initPower': 1, 'duration': 0.20000000298023224})
        Camera.Quake({'targetPower': 0, 'initPower': 3, 'duration': 0.6000000238418579})
        Timer.Wait({'time': 0.30000001192092896})
        Camera.Quake({'targetPower': 2, 'duration': 1.0, 'initPower': 0})
        Timer.Wait({'time': 1.5})
        Camera.Quake({'targetPower': 3, 'duration': 0.0, 'initPower': 2})
        Timer.Wait({'time': 0.30000001192092896})
        Camera.Quake({'initPower': 3, 'targetPower': 0, 'duration': 1.0})
    }

    Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
    Fade.StartPreset({'preset': 9})

    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Audio.StopZoneBaseAmbience()
    }

    Environment.SetLookAtEnvironmentNonWait()
    Audio.PlayZoneAudio()
    Fade.StartPreset({'preset': 8})
    GameControl.RequestAutoSave()
}

void Broken3Pillar() {
    Timer.Wait({'time': 1.5})
    Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
    GameControl.RequestAutoSave()
}
