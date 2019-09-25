-------- EventFlow: TurtleRock --------

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM', 'PlayZoneBGM', 'StopBGM', 'TurtleBgmHalfwayPlay', 'PlayOneshotSystemSE']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveToCompassPoint', 'SetDisablePowerUpEffect', 'MoveToTargetLinkedPoint', 'AimActor', 'PlayAnimation']
queries: ['IsInRect']
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['FocusCameraReset', 'SetFocusedCamera', 'Reset']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['PreloadTimeline', 'InvokeTimeline']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

Actor: TurtleRock
entrypoint: None()
actions: ['NotifyEscapeBattle', 'NotifyStartBattle', 'NotifyAwakeEvent', 'PlayAnimation', 'PlayMaterialAnim', 'BossItemDrop']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void TurtleRockSkip() {
    Audio.StopAllBGM({'duration': 1.0})
    Audio.PlayBGM({'label': 'BGM_DUNGEON_LV8_ENT_BATTLE', 'volume': 1.0})
    Camera.SetFocusedCamera({'rotZ': 0.0, 'rotY': 0.0, 'posX': 8.394000053405762, 'posY': 40.54600143432617, 'posZ': 29.1299991607666, 'rotX': -60.755001068115234, 'distanceToLookAt': 20.302000045776367, 'chaseRatio': 0.10000000149011612, 'duration': 1.0})
}

void TurtleRockEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Hud.PlayOutAnim()
    Audio.StopBGM({'label': 'BGM_DUNGEON_LV8_ENT_BATTLE', 'duration': 0.5})

    fork {
        FlowControl.PreloadTimeline({'filename': 'TurtleRockDead'})
    } {
        TurtleRock.PlayAnimation({'name': 'dead_st', 'blendTime': 0.10000000149011612})
    } {
        TurtleRock.PlayMaterialAnim({'name': 'fantHeadEye', 'frame': 0, 'layer': 2, 'isPause': False})
    }

    FlowControl.InvokeTimeline({'filename': 'TurtleRockDead', 'rate': 1.0})
    TurtleRock.BossItemDrop()
    Timer.Wait({'time': 1.5})
    Camera.FocusCameraReset({'chaseRatio': 0.10000000149011612})
    Hud.PlayInAnim()
    Audio.PlayZoneBGM({'stopbgm': True})
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
}

void TurtleRockEscape() {
    TurtleRock.NotifyEscapeBattle()
    Link.MoveToCompassPoint({'direction': 1, 'speed': 0, 'distance': 1.5, 'timeOut': 7.0})
    Audio.StopAllBGM({'duration': 2.0})
    Audio.PlayZoneBGM({'stopbgm': True})
    Camera.FocusCameraReset({'chaseRatio': 0.10000000149011612})
}

void TurtleRockBack() {

    fork {
        Timer.Wait({'time': 0.30000001192092896})
        TurtleRock.NotifyStartBattle()
    } {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 3, 'distance': 2.0, 'timeOut': 7.0})
        Camera.SetFocusedCamera({'rotZ': 0.0, 'rotY': 0.0, 'posX': 8.394000053405762, 'posY': 40.54600143432617, 'posZ': 29.1299991607666, 'rotX': -60.755001068115234, 'distanceToLookAt': 20.302000045776367, 'chaseRatio': 0.10000000149011612, 'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_ENE_KAMEIWA_REPOP', 'volume': 1.0, 'pitch': 1.0})
    }


    fork {
        Hud.PlayInAnim()
    } {
        Audio.TurtleBgmHalfwayPlay()
    }

}

void TurtleRockStart() {
    Audio.StopAllBGM({'duration': 0.0})
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        TurtleRock.NotifyAwakeEvent()
    } {
        if !Link.IsInRect({'minX': 6.440999984741211, 'maxX': 12.0, 'maxZ': 20.75, 'minZ': 17.0}) {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } else {

            fork {
                Link.MoveToTargetLinkedPoint({'index': 5, 'speed': 0, 'actor': ActorIdentifier(name="TurtleRock"), 'timeOut': 7.0})
            } {
                Link.AimActor({'withoutTurn': True, 'actor': ActorIdentifier(name="TurtleRock"), 'duration': 0.4000000059604645, 'boneName': ''})
            }

        }
        Link.AimActor({'actor': ActorIdentifier(name="TurtleRock"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }

    Hud.PlayOutAnim()
    FlowControl.PreloadTimeline({'filename': 'TurtleRock'})
    Camera.Reset({'chaseRatio': 0.10000000149011612})
    Audio.PlayBGM({'label': 'BGM_DUNGEON_LV8_ENT_BATTLE', 'volume': 1.0})
    FlowControl.InvokeTimeline({'filename': 'TurtleRock', 'rate': 1.0})

    fork {
        Camera.SetFocusedCamera({'rotZ': 0.0, 'rotY': 0.0, 'posY': 40.54600143432617, 'posZ': 29.1299991607666, 'rotX': -60.755001068115234, 'distanceToLookAt': 20.302000045776367, 'posX': 8.394000053405762, 'chaseRatio': 0.10000000149011612, 'duration': 1.0})
    } {
        Hud.PlayInAnim()
    }


    fork {
        EventFlags.SetFlag({'symbol': 'TurtleRockClear', 'value': True})
    } {
        TurtleRock.NotifyStartBattle()
    }

    GameControl.RequestAutoSave()
    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}
