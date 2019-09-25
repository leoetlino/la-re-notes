-------- EventFlow: BossBlob --------

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveZoneEnterDirection', 'AimActor', 'SetDisablePowerUpEffect']
queries: []
params: None

Actor: BossBlob
entrypoint: None()
actions: ['BossRoomDoorClose', 'LookAtGimmick', 'SetActorSwitch', 'PlayAnimation', 'PlayTailorOtherChannelEx', 'ModelVisibility', 'BossRoomDoorOpen', 'BossItemDrop']
queries: ['CheckSawTheFirstEvent']
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'WaitZeldaScroll']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM', 'PlayZoneBGM', 'StopBGM']
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

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

void BossBlobSkip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})
    BossBlob.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    Link.AimActor({'duration': 0.4000000059604645, 'actor': ActorIdentifier(name="BossBlob"), 'withoutTurn': False, 'boneName': ''})

    fork {
        BossBlob.BossRoomDoorClose()
    } {
        BossBlob.PlayAnimation({'name': 'demo_pop', 'blendTime': 0.10000000149011612})
    }


    fork {
        Timer.Wait({'time': 0.5})
    } {
        BossBlob.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }


    fork {
        Camera.Reset({'chaseRatio': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.699999988079071})
    }

    Camera.WaitZeldaScroll()
    Hud.PlayInAnim()
    Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
}

void BossBlobEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    } {
        Hud.PlayOutAnim()
    }


    fork {
        BossBlob.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    } {
        BossBlob.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
        BossBlob.ModelVisibility({'visible': False, 'modelIndex': 0})
    } {
        BossBlob.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    BossBlob.ModelVisibility({'modelIndex': 0, 'visible': False})
    BossBlob.BossItemDrop()
    Timer.Wait({'time': 1.5})

    fork {
        BossBlob.BossRoomDoorOpen()
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

void BossBlobNoDamage() {
    Dialog.Show({'message': 'SubEvent:AttackBossBlob'})
}

void BossBlobStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch BossBlob.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:

        fork {
            Hud.PlayOutAnim()
        } {
            Audio.StopAllBGM({'duration': 1.0})
        }

        BossBlob.PlayAnimation({'name': 'demo_pop', 'blendTime': 0.10000000149011612})
        Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

        fork {
            Link.AimActor({'actor': ActorIdentifier(name="BossBlob"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        } {
            BossBlob.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        } {
            BossBlob.BossRoomDoorClose()
        }

        Dialog.Show({'message': 'SubEvent:BattleBossBlob'})
        BossBlob.SetActorSwitch({'switchIndex': 1, 'value': True})
        Camera.Reset({'chaseRatio': 0.10000000149011612})
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call BossBlobSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}
