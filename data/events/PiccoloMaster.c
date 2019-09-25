-------- EventFlow: PiccoloMaster --------

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect', 'AimActor', 'MoveZoneEnterDirection']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayZoneBGM', 'StopBGM', 'StopAllBGM', 'PlayBGM']
queries: []
params: None

Actor: PiccoloMaster
entrypoint: None()
actions: ['PlayAnimation', 'BossRoomDoorOpen', 'BossRoomDoorClose', 'LookAtGimmick', 'SetActorSwitch', 'AimPlayer']
queries: ['CheckSawTheFirstEvent']
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'WaitZeldaScroll']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayInAnim', 'PlayOutAnim']
queries: []
params: None

void PiccoloStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch PiccoloMaster.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:

        fork {
            Hud.PlayOutAnim()
        } {
            Audio.StopAllBGM({'duration': 1.0})
        }

        Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

        fork {
            PiccoloMaster.BossRoomDoorClose()
        } {
            PiccoloMaster.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.AimActor({'actor': ActorIdentifier(name="PiccoloMaster"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

        fork {
            Timer.Wait({'time': 1.2000000476837158})
        } {
            PiccoloMaster.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }

        Dialog.Show({'message': 'Scenario:Lv7MiniBossCreeper'})

        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        PiccoloMaster.SetActorSwitch({'switchIndex': 1, 'value': True})
        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        fork {
            Hud.PlayOutAnim()
        } {
            Audio.StopAllBGM({'duration': 1.0})
        }

        Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

        fork {
            PiccoloMaster.BossRoomDoorClose()
        } {
            PiccoloMaster.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.AimActor({'actor': ActorIdentifier(name="PiccoloMaster"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

        fork {
            Timer.Wait({'time': 1.2000000476837158})
        } {
            PiccoloMaster.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void PiccoloMasterRestart() {
    Dialog.Show({'message': 'Scenario:Lv7MiniBossReplay'})
}

void PiccoloMasterEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    }


    fork {
        PiccoloMaster.PlayAnimation({'name': 'anger', 'blendTime': 0.10000000149011612})
    } {
        Dialog.Show({'message': 'Scenario:Lv7MiniBossClear'})
    } {
        PiccoloMaster.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        PiccoloMaster.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    } {
        Link.AimActor({'actor': ActorIdentifier(name="PiccoloMaster"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        PiccoloMaster.PlayAnimation({'name': 'escape', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 1.5})
    }


    fork {
        PiccoloMaster.BossRoomDoorOpen()
    } {
        Timer.Wait({'time': 1.0})
    }


    fork {
        Hud.PlayInAnim()
    } {
        Audio.PlayZoneBGM({'stopbgm': True})
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    GameControl.RequestAutoSave()
}
