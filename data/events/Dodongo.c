-------- EventFlow: Dodongo --------

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM', 'StopBGM', 'PlayZoneBGM']
queries: []
params: None

Actor: Dodongo
entrypoint: None()
actions: ['BossRoomDoorOpen', 'ModelVisibility', 'PlayAnimation', 'BossRoomDoorClose', 'BossItemDrop', 'LookAtGimmick']
queries: ['CheckKindBoss']
params: None

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect', 'MoveZoneEnterDirection', 'AimActor']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['WaitZeldaScroll', 'Reset']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

void DodongoEnd() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'duration': 0.5})
    }


    fork {
        Dodongo.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    } {
        Dodongo.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Timer.Wait({'time': 0.30000001192092896})
        Dodongo.BossItemDrop()
    }

    Dodongo.ModelVisibility({'modelIndex': 0, 'visible': False})
    Timer.Wait({'time': 1.5})

    fork {
        Dodongo.BossRoomDoorOpen()
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

void DodongoStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})

    fork {
        Hud.PlayOutAnim()
    } {
        Audio.StopAllBGM({'duration': 1.0})
    }

    Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})
    switch Dodongo.CheckKindBoss() {
      case 0:

        fork {
            Dodongo.BossRoomDoorClose()
        } {
            Dodongo.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
        }

        Link.AimActor({'actor': ActorIdentifier(name="Dodongo"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})

        fork {
            Camera.Reset({'chaseRatio': 0.10000000149011612})
        } {
            Timer.Wait({'time': 0.699999988079071})
        }

        Camera.WaitZeldaScroll()
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS_MIDDLE', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2]:
        Dodongo.BossRoomDoorClose()

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
