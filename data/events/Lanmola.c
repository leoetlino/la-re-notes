-------- EventFlow: Lanmola --------

Actor: Camera
entrypoint: None()
actions: ['FocusCameraReset', 'SetFocusedCamera']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM', 'PlayZoneBGM', 'StopBGM', 'SetSeVolume']
queries: []
params: None

Actor: Lanmola
entrypoint: None()
actions: ['SetActorSwitch', 'PlayTailorOtherChannelEx', 'PlayAnimation', 'ModelVisibility', 'AwaitBattleEnd', 'LookAtGimmicksLinkedPoint', 'BossItemDrop']
queries: ['CheckSawTheFirstEvent']
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
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

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

void LanmolaStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Hud.PlayOutAnim()
    if !Lanmola.CheckSawTheFirstEvent({'switchIndex': 1}) {
        Audio.StopAllBGM({'duration': 1.0})
        Lanmola.LookAtGimmicksLinkedPoint({'pointIndex': 0, 'duration': 0.4000000059604645, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        Timer.Wait({'time': 1.5})
        Lanmola.SetActorSwitch({'switchIndex': 1, 'value': True})
        Dialog.Show({'message': 'Scenario:Lv4MiniBossLanmola'})

        fork {
            Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        } {
            Audio.SetSeVolume({'volume': 0.6000000238418579, 'label': 'SE_AMB_SAND_STREAM', 'duration': 0.5})
        }

        Timer.Wait({'time': 0.800000011920929})
        Camera.SetFocusedCamera({'rotZ': 0.0, 'posY': 26.67099952697754, 'rotY': 0.0, 'rotX': -55.0, 'distanceToLookAt': 20.0, 'posX': 217.4969940185547, 'posZ': 162.11900329589844, 'chaseRatio': 0.10000000149011612, 'duration': 0.699999988079071})
        Hud.PlayInAnim()
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    } else {

        call LanmolaBack()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void LanmolaEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Hud.PlayOutAnim()

    fork {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    } {
        Audio.SetSeVolume({'label': 'SE_AMB_SAND_STREAM', 'duration': 0.5, 'volume': 1.0})
    }


    fork {
        Lanmola.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    } {
        Lanmola.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    }

    Lanmola.ModelVisibility({'modelIndex': 0, 'visible': False})
    Lanmola.SetActorSwitch({'switchIndex': 0, 'value': True})
    Lanmola.BossItemDrop()
    Timer.Wait({'time': 1.5})
    Camera.FocusCameraReset({'chaseRatio': 0.10000000149011612})
    Audio.PlayZoneBGM({'stopbgm': True})
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    Hud.PlayInAnim()
    GameControl.RequestAutoSave()
}

void LanmolaEscape() {
    Audio.StopAllBGM({'duration': 1.0})
    Audio.PlayZoneBGM({'stopbgm': True})
    Camera.FocusCameraReset({'chaseRatio': 0.10000000149011612})
}

void LanmolaBack() {
    Audio.StopAllBGM({'duration': 1.0})
    Lanmola.AwaitBattleEnd()
    Camera.SetFocusedCamera({'rotZ': 0.0, 'posY': 26.67099952697754, 'rotY': 0.0, 'rotX': -55.0, 'distanceToLookAt': 20.0, 'posX': 217.4969940185547, 'posZ': 162.11900329589844, 'duration': 1.0, 'chaseRatio': 0.10000000149011612})

    fork {
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
    } {
        Audio.SetSeVolume({'label': 'SE_AMB_SAND_STREAM', 'volume': 0.6000000238418579, 'duration': 0.5})
    }

    Hud.PlayInAnim()
}
