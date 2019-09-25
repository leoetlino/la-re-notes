-------- EventFlow: MasterStalfon --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show', 'ShowKeep']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopBGM', 'PlayZoneBGM', 'PlayBGM', 'StopAllBGM']
queries: []
params: None

Actor: MasterStalfon
entrypoint: None()
actions: ['BossRoomDoorOpen', 'PlayAnimation', 'PlayTailorOtherChannelEx', 'ModelVisibility', 'PlayAnimationEx', 'AimPlayer', 'BossRoomDoorClose', 'LookAtGimmick', 'SetActorSwitch', 'BossItemDrop']
queries: ['CheckSawTheFirstEvent']
params: None

Actor: Link
entrypoint: None()
actions: ['MoveZoneEnterDirection', 'SetDisablePowerUpEffect', 'AimActor', 'ResetAim']
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

Actor: Camera
entrypoint: None()
actions: ['WaitZeldaScroll', 'Reset']
queries: []
params: None

void MasterStalfon1End() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    } {
        Hud.PlayOutAnim()
    }


    fork {
        MasterStalfon.PlayAnimation({'name': 'damage', 'blendTime': 0.10000000149011612})
    } {
        MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.AimActor({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': 'n_hara', 'actor': ActorIdentifier(name="MasterStalfon")})
    }


    fork {
        MasterStalfon.PlayAnimation({'name': 'down_ed', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 1.0})
        MasterStalfon.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Dialog.Show({'message': 'Scenario:Lv5MiniBoss1'})
    } {
        MasterStalfon.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        MasterStalfon.PlayAnimationEx({'name': 'escape', 'time': 0.0, 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 2.0})
    } {
        Timer.Wait({'time': 1.5})
        Link.ResetAim()
    }


    fork {
        MasterStalfon.BossRoomDoorOpen()
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

void MasterStalfon1Start() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch MasterStalfon.CheckSawTheFirstEvent({'switchIndex': 2}) {
      case [0, 2, 3]:

        fork {
            Audio.StopAllBGM({'duration': 1.0})
        } {
            Hud.PlayOutAnim()
        }

        Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

        fork {
            MasterStalfon.BossRoomDoorClose()
        } {
            MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }


        fork {
            MasterStalfon.PlayAnimation({'name': 'pop', 'blendTime': 0.10000000149011612})
            MasterStalfon.PlayAnimation({'name': 'kyorokyoro', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActor({'withoutTurn': False, 'boneName': 'n_hara', 'duration': 0.5, 'actor': ActorIdentifier(name="MasterStalfon")})
        }


        fork {
            Timer.Wait({'time': 0.5})
        } {
            MasterStalfon.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }


        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        MasterStalfon.SetActorSwitch({'value': True, 'switchIndex': 2})
        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case 1:

        call MasterStalfon1Skip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void MasterStalfon2End() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    } {
        Hud.PlayOutAnim()
    }


    fork {
        MasterStalfon.PlayAnimation({'name': 'damage', 'blendTime': 0.10000000149011612})
    } {
        MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.AimActor({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': 'n_hara', 'actor': ActorIdentifier(name="MasterStalfon")})
    }


    fork {
        MasterStalfon.PlayAnimation({'name': 'down_ed', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 1.0})
        MasterStalfon.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Dialog.Show({'message': 'Scenario:Lv5MiniBoss1'})
    } {
        MasterStalfon.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        MasterStalfon.PlayAnimationEx({'name': 'escape', 'time': 0.0, 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 2.0})
    } {
        Timer.Wait({'time': 1.5})
        Link.ResetAim()
    }


    fork {
        MasterStalfon.BossRoomDoorOpen()
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

void MasterStalfon2Start() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch MasterStalfon.CheckSawTheFirstEvent({'switchIndex': 2}) {
      case [0, 2, 3]:

        fork {
            Audio.StopAllBGM({'duration': 1.0})
        } {
            Hud.PlayOutAnim()
        }

        Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

        fork {
            MasterStalfon.BossRoomDoorClose()
        } {
            MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            MasterStalfon.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        }


        fork {
            MasterStalfon.PlayAnimation({'name': 'pop', 'blendTime': 0.10000000149011612})
            MasterStalfon.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActor({'boneName': 'n_hara', 'duration': 0.5, 'actor': ActorIdentifier(name="MasterStalfon"), 'withoutTurn': False})
        }

        Dialog.Show({'message': 'Scenario:Lv5MiniBoss2'})
        Timer.Wait({'time': 0.5})

        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        MasterStalfon.SetActorSwitch({'value': True, 'switchIndex': 2})
        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case 1:

        call MasterStalfon1Skip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void MasterStalfon3End() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    } {
        Hud.PlayOutAnim()
    }


    fork {
        MasterStalfon.PlayAnimation({'name': 'damage', 'blendTime': 0.10000000149011612})
    } {
        MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.AimActor({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': 'n_hara', 'actor': ActorIdentifier(name="MasterStalfon")})
    }


    fork {
        MasterStalfon.PlayAnimation({'name': 'down_ed', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 1.0})
        MasterStalfon.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        Dialog.Show({'message': 'Scenario:Lv5MiniBoss1'})
    } {
        MasterStalfon.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        MasterStalfon.PlayAnimationEx({'name': 'escape', 'time': 0.0, 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 2.0})
    } {
        Timer.Wait({'time': 1.5})
        Link.ResetAim()
    }


    fork {
        MasterStalfon.BossRoomDoorOpen()
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

void MasterStalfon3Start() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch MasterStalfon.CheckSawTheFirstEvent({'switchIndex': 2}) {
      case [0, 2, 3]:

        fork {
            Audio.StopAllBGM({'duration': 1.0})
        } {
            Hud.PlayOutAnim()
        }

        Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

        fork {
            MasterStalfon.BossRoomDoorClose()
        } {
            MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            MasterStalfon.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        }


        fork {
            MasterStalfon.PlayAnimation({'name': 'pop', 'blendTime': 0.10000000149011612})
            MasterStalfon.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActor({'boneName': 'n_hara', 'duration': 0.5, 'actor': ActorIdentifier(name="MasterStalfon"), 'withoutTurn': False})
        }

        Dialog.Show({'message': 'Scenario:Lv5MiniBoss2'})
        Timer.Wait({'time': 0.5})

        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        MasterStalfon.SetActorSwitch({'value': True, 'switchIndex': 2})
        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case 1:

        call MasterStalfon1Skip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void MasterStalfon4End() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    } {
        Hud.PlayOutAnim()
    }


    fork {
        MasterStalfon.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    } {
        MasterStalfon.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    } {
        MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    MasterStalfon.ModelVisibility({'modelIndex': 0, 'visible': False})
    MasterStalfon.BossItemDrop()
    Timer.Wait({'time': 1.5})

    fork {
        MasterStalfon.BossRoomDoorOpen()
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

void MasterStalfon4Start() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch MasterStalfon.CheckSawTheFirstEvent({'switchIndex': 2}) {
      case [0, 2, 3]:

        fork {
            Audio.StopAllBGM({'duration': 1.0})
        } {
            Hud.PlayOutAnim()
        }

        Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

        fork {
            MasterStalfon.BossRoomDoorClose()
        } {
            MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }


        fork {
            MasterStalfon.PlayAnimation({'name': 'pop', 'blendTime': 0.10000000149011612})
            MasterStalfon.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Link.AimActor({'boneName': 'n_hara', 'duration': 0.5, 'actor': ActorIdentifier(name="MasterStalfon"), 'withoutTurn': False})
        }

        Timer.Wait({'time': 0.5})

        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        MasterStalfon.SetActorSwitch({'value': True, 'switchIndex': 2})
        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case 1:

        call MasterStalfon1Skip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void MasterStalfon1Skip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

    fork {
        MasterStalfon.BossRoomDoorClose()
    } {
        MasterStalfon.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        MasterStalfon.AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
    }


    fork {
        MasterStalfon.PlayAnimation({'name': 'pop', 'blendTime': 0.10000000149011612})
        MasterStalfon.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    } {
        Link.AimActor({'boneName': 'n_hara', 'duration': 0.5, 'actor': ActorIdentifier(name="MasterStalfon"), 'withoutTurn': False})
    }

    Dialog.ShowKeep({'message': 'Scenario:Lv5MiniBoss3'})
    Dialog.Show({'message': 'Scenario:Lv5MiniBoss4'})
    Timer.Wait({'time': 0.5})

    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.699999988079071})
    }

    Camera.WaitZeldaScroll()
    Hud.PlayInAnim()
    Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
}
