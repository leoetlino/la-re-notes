-------- EventFlow: WindFish --------

Actor: Owl[EndingOwl]
entrypoint: None()
actions: ['TalkKeep', 'Destroy', 'Talk', 'PlayAnimation', 'SetFacialExpression']
queries: []
params: None

Actor: SirenInstrument[EndingInstruments]
entrypoint: None()
actions: ['Activate', 'PlayAnimationEx', 'Deactivate', 'WarpToActor', 'PlayTailorOtherChannelEx']
queries: []
params: None

Actor: Tarin[EndingTarin]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: DisappearIsland[EndingIsland]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Octorok[Ending1]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Octorok[Ending2]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Octorok[Ending3]
entrypoint: None()
actions: ['Activate']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: WindFish
entrypoint: None()
actions: ['TalkKeep', 'PlayAnimationEx', 'Talk', 'PlayAreaOriginCameraAnimation', 'SetModelVisibility', 'PlayMaterialAnimationNoWait', 'PlayTailorOtherChannelEx', 'StopTailorOtherChannel', 'PlayOneshotSE']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['AimCompassPoint', 'PlayAnimation', 'PlayAnimationEx', 'SetGravityEnable', 'PlayTailorOtherChannelEx', 'SetEquipmentVisibility', 'MoveToTargetLinkedPoint', 'SetFacialExpression']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartParam', 'StartPreset']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['PreloadTimeline', 'InvokeStreamSyncTimeline']
queries: ['Branch']
params: None

Actor: GameControl
entrypoint: None()
actions: ['SaveForGameClear', 'GoToEnding', 'LoadZone']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopZoneAudio', 'PlayOneshotSystemSE', 'StopBGM', 'PlayBGM']
queries: []
params: None

Actor: Owl
entrypoint: None()
actions: ['PlayTailorOtherChannelEx', 'StopTailorOtherChannel']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['SetLookAtEnvironmentNonWait']
queries: []
params: None

Actor: WindFish[fish]
entrypoint: None()
actions: ['SetModelVisibility']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['SetFixedCamera']
queries: []
params: None

Actor: EventTriggerTag
entrypoint: None()
actions: []
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

void ending_part2() {
    Audio.PlayBGM({'label': 'BGM_DEMO_AFTER_LASTBOSS_WIND_FISH', 'volume': 1.0})
    WindFish.PlayMaterialAnimationNoWait({'name': 'hide', 'blendTime': 0.0})
    WindFish.PlayAnimationEx({'name': 'talk', 'time': 0.0, 'blendTime': 0.0})
    WindFish.SetModelVisibility({'visible': True})
    WindFish.PlayTailorOtherChannelEx({'channel': 'Pop', 'time': 1.5, 'restart': False, 'index': 0})
    WindFish.PlayMaterialAnimationNoWait({'name': 'appear', 'blendTime': 0.0})
    Timer.Wait({'time': 4.5})
    WindFish.TalkKeep({'message': 'Scenario:EDKazenoSakana1'})
    WindFish.TalkKeep({'message': 'Scenario:EDKazenoSakana2'})
    WindFish.TalkKeep({'message': 'Scenario:EDKazenoSakana3'})
    WindFish.TalkKeep({'message': 'Scenario:EDKazenoSakana4'})
    WindFish.TalkKeep({'message': 'Scenario:EDKazenoSakana5'})
    WindFish.Talk({'message': 'Scenario:EDKazenoSakana6'})
    WindFish.Talk({'message': 'Scenario:EDKazenoSakana7'})
    Audio.PlayOneshotSystemSE({'label': 'SE_ENV_ED_FISH_DISAPPEAR', 'volume': 1.0, 'pitch': 1.0})

    fork {
        Audio.StopBGM({'label': 'BGM_DEMO_AFTER_LASTBOSS', 'duration': 2.0})
    } {
        Audio.StopBGM({'label': 'BGM_DEMO_AFTER_LASTBOSS_WIND_FISH', 'duration': 2.0})
    }

    WindFish.PlayMaterialAnimationNoWait({'name': 'disappear', 'blendTime': 0.0})
    Timer.Wait({'time': 0.5})
    WindFish.PlayTailorOtherChannelEx({'channel': 'Depop', 'time': 0.5, 'restart': False, 'index': 0})
    WindFish.SetModelVisibility({'visible': False})
    Audio.StopZoneAudio()
    Timer.Wait({'time': 3.0})

    fork {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.4000000059604645, 'withoutTurn': False})
    } {
        Link.PlayAnimation({'name': 'instrument_get_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimationEx({'time': 0.0, 'blendTime': 0.0, 'name': 'instrument_get_lp'})
    } {
        Timer.Wait({'time': 0.3330000042915344})
        SirenInstrument[EndingInstruments].WarpToActor({'actor': ActorIdentifier(name="Link"), 'distance': 0.0, 'offsetY': 0.0})
        SirenInstrument[EndingInstruments].Activate()
        SirenInstrument[EndingInstruments].PlayAnimationEx({'blendTime': 0.0, 'name': 'pop_windfish', 'time': 2.5})
        SirenInstrument[EndingInstruments].PlayTailorOtherChannelEx({'channel': 'EV_Fadeout_SirenInstrument', 'time': 0.4000000059604645, 'restart': False, 'index': 0})
    } {
        Link.SetFacialExpression({'expression': 'normal'})
    }

    Fade.StartParam({'mode': 1, 'colorR': 1.0, 'colorG': 1.0, 'colorB': 1.0, 'time': 3.0})
    Timer.Wait({'time': 1.0})
    SirenInstrument[EndingInstruments].Deactivate()
}

void ending_part1() {

    fork {
        WindFish.PlayAreaOriginCameraAnimation({'name': 'WindFishTalk01_02', 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    } {

        fork {
            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
        } {
            Timer.Wait({'time': 1.5})
            Owl[EndingOwl].PlayAnimation({'blendTime': 0.0, 'name': 'fly_dm_st_lp'})
        }

        Owl[EndingOwl].PlayAnimation({'name': 'fly_dm_st', 'blendTime': 0.0})
    }

    Owl[EndingOwl].PlayAnimation({'blendTime': 0.0, 'name': 'fly_dm'})
    Owl[EndingOwl].PlayAnimation({'name': 'fly_talk', 'blendTime': 0.10000000149011612})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl2'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl3'})
    Owl[EndingOwl].SetFacialExpression({'expression': 'serious'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl4'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl5'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl6'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl7'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl8'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl9'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl10'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl11'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl12'})
    Owl[EndingOwl].TalkKeep({'message': 'Scenario:EDOwl13'})

    fork {
        Owl[EndingOwl].SetFacialExpression({'expression': 'smile'})
    } {
        Owl[EndingOwl].Talk({'message': 'Scenario:EDOwl14'})
    }

    Timer.Wait({'time': 2.0})
    Owl.PlayTailorOtherChannelEx({'channel': 'Depop', 'time': 0.08299999684095383, 'restart': False, 'index': 0})
    Owl[EndingOwl].Destroy()
    Timer.Wait({'time': 0.31700000166893005})
    Fade.StartPreset({'preset': 7})
    Owl.StopTailorOtherChannel({'channel': 'Depop', 'index': 0})
    WindFish.PlayAreaOriginCameraAnimation({'name': 'WindFishTalk01_03', 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    Fade.StartPreset({'preset': 2})
    Timer.Wait({'time': 0.800000011920929})
}

void ending() {
    Audio.StopBGM({'label': 'BGM_LASTBOSS_WIN', 'duration': 0.5})
    Hud.PlayOutAnim()

    fork {
        WindFish[fish].SetModelVisibility({'visible': False})
    } {
        WindFish.PlayMaterialAnimationNoWait({'name': 'hide', 'blendTime': 0.0})
    } {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Timer.Wait({'time': 1.2000000476837158})
    }


    fork {
        Timer.Wait({'time': 0.10000000149011612})
        Fade.StartPreset({'preset': 4})
    } {
        Link.MoveToTargetLinkedPoint({'index': 0, 'speed': 0, 'timeOut': 10.0, 'actor': ActorIdentifier(name="EventTriggerTag")})
    } {
        Audio.PlayBGM({'label': 'BGM_DEMO_AFTER_LASTBOSS', 'volume': 1.0})
    }


    call CheckParticipants()


    fork {

        call ending_part1()


        call ending_part2()

    } {
        FlowControl.PreloadTimeline({'filename': 'Ending'})
        GameControl.LoadZone({'zoneID': 223})
        GameControl.LoadZone({'zoneID': 224})
        GameControl.LoadZone({'zoneID': 225})
        GameControl.LoadZone({'zoneID': 226})
    }

    FlowControl.InvokeStreamSyncTimeline({'filename': 'Ending', 'label': 'BGM_DEMO_BEFORE_ENDING_SE_MIX', 'volume': 1.0})

    call ending_part3()


    fork {
        Timer.Wait({'time': 3.0})
    } {
        GameControl.SaveForGameClear()
    }

    GameControl.GoToEnding()
}

void ending_part3() {
    Camera.SetFixedCamera({'posX': 217.43499755859375, 'posY': 45.30799865722656, 'posZ': 160.35800170898438, 'rotX': -20.433000564575195, 'rotY': 0.0, 'rotZ': 0.0, 'fieldOfViewY': 28.086000442504883, 'distanceToLookAt': 26.5, 'clipDistanceCtrl': False, 'nearClipDistance': 0.10000000149011612, 'farClipDistance': 100.0})

    fork {
        Link.AimCompassPoint({'direction': 2, 'duration': 0.10000000149011612, 'withoutTurn': False})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'idle_bare'})
    }

    Environment.SetLookAtEnvironmentNonWait()
    Link.SetGravityEnable({'enable': False})
    Fade.StartPreset({'preset': 6})
    WindFish.PlayOneshotSE({'label': 'SE_ENV_ED_WATER1', 'volume': 1.0, 'pitch': 1.0})

    fork {
        WindFish.PlayAreaOriginCameraAnimation({'name': 'WindFishTalk02', 'offsetY': 0.0, 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    } {
        Timer.Wait({'time': 2.6670000553131104})
        Link.PlayTailorOtherChannelEx({'channel': 'ev_hydrocannon', 'time': 0.3330000042915344, 'restart': False, 'index': 0})
        WindFish.PlayTailorOtherChannelEx({'channel': 'Fountain', 'time': 0.0, 'restart': False, 'index': 0})
        WindFish.StopTailorOtherChannel({'channel': 'ac_Keep', 'index': 0})
        Link.PlayAnimation({'name': 'ev_hydrocannon', 'blendTime': 0.10000000149011612})
    } {
        Link.SetFacialExpression({'expression': 'abyss'})
    }

    Fade.StartParam({'mode': 1, 'time': 3.0, 'colorR': 0.0, 'colorG': 0.0, 'colorB': 0.0})
    Link.SetGravityEnable({'enable': True})
    EventFlags.SetFlag({'symbol': 'WarpProhibition', 'value': False})
    EventFlags.SetFlag({'symbol': 'ShadowClear', 'value': True})
}

void CheckParticipants() {
    if FlowControl.Branch({'value': False}) {
        Octorok[Ending1].Activate()
        Octorok[Ending2].Activate()
        Octorok[Ending3].Activate()
        Tarin[EndingTarin].Activate()
        DisappearIsland[EndingIsland].Activate()
    }
}
