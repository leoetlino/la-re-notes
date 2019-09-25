-------- EventFlow: RoosterBones --------

Actor: FlyingCucco[FlyCocco]
entrypoint: None()
actions: ['Join', 'PlayAnimation', 'Activate', 'BeCarried', 'CancelCarried', 'StopTailorOtherChannel']
queries: []
params: None

Actor: Environment
entrypoint: None()
actions: ['ChangeEnvironmentNonWait']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: RoosterBones
entrypoint: None()
actions: ['Destroy', 'PlayTailorOtherChannelEx', 'PlayAnimationEx']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopAllBGM', 'PlayBGM', 'StopBGM', 'PlayZoneBGM', 'PlayJingleTimeWait', 'PlayOneshotSystemSE']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['PlayAnimationEx', 'LookAtItemGettingPlayer', 'AimCompassPoint', 'MoveToTargetActor', 'SetEquipmentVisibility', 'SetDisablePowerUpEffect']
queries: []
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

void playSong() {
    Link.SetDisablePowerUpEffect({'effect': True, 'sound': True, 'materialAnim': True})
    Audio.StopAllBGM({'duration': 1.0})
    Audio.PlayBGM({'label': 'BGM_RESUSCITATION_OF_CHICKEN', 'volume': 1.0})
    Link.MoveToTargetActor({'distance': 1.5, 'speed': 0, 'actor': ActorIdentifier(name="RoosterBones"), 'timeOut': 7.0})
    Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
    Environment.ChangeEnvironmentNonWait({'name': 'DungeonSmallWaterDark', 'duration': 1.5})

    fork {
        Timer.Wait({'time': 9.0})
    } {
        RoosterBones.PlayAnimationEx({'time': 0.0, 'name': 'move_soul', 'blendTime': 0.10000000149011612})
    }


    fork {
        Timer.Wait({'time': 1.399999976158142})
    } {
        RoosterBones.PlayTailorOtherChannelEx({'channel': 'Light_up', 'time': 0.0, 'restart': False, 'index': 0})
    }

    Environment.ChangeEnvironmentNonWait({'name': 'DungeonSmallWater', 'duration': 0.5})

    fork {
        Fade.StartPreset({'preset': 11})
    } {
        Audio.StopBGM({'label': 'BGM_RESUSCITATION_OF_CHICKEN', 'duration': 1.0})
    } {
        Audio.PlayOneshotSystemSE({'label': 'SE_ENV_FLYING_CUCCO_WHITEOUT', 'volume': 1.0, 'pitch': 1.0})
    }

    RoosterBones.Destroy()
    FlyingCucco[FlyCocco].Activate()
    FlyingCucco[FlyCocco].PlayAnimation({'blendTime': 0.0, 'name': 'FlyingCocco_get'})
    Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
    Link.PlayAnimationEx({'time': 0.0, 'blendTime': 0.0, 'name': 'item_get_lp'})
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    FlyingCucco[FlyCocco].BeCarried()
    Fade.StartPreset({'preset': 10})
    Link.LookAtItemGettingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    Audio.PlayOneshotSystemSE({'label': 'SE_PL_ITEM_GET_LIGHT', 'volume': 1.0, 'pitch': 1.0})

    fork {
        Audio.PlayJingleTimeWait({'label': 'BGM_FANFARE_BIGITEM_GET', 'duration': 0.800000011920929, 'volume': 1.0})
    } {
        Timer.Wait({'time': 2.5})
        Audio.PlayOneshotSystemSE({'label': 'SE_MAP_FLY_CUCCO_GETUP', 'volume': 1.0, 'pitch': 1.0})
    }


    fork {
        Dialog.Show({'message': 'Scenario:GetFlyingCocco'})
        FlyingCucco[FlyCocco].StopTailorOtherChannel({'channel': 'FlyingCucco_get', 'index': 0})
        FlyingCucco[FlyCocco].PlayAnimation({'blendTime': 0.0, 'name': 'ev_glad_ed'})
        FlyingCucco[FlyCocco].CancelCarried()
        FlyingCucco[FlyCocco].Join()
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
        GameControl.RequestAutoSave()
    } {
        Timer.Wait({'time': 3.299999952316284})
        Audio.PlayZoneBGM({'stopbgm': True})
    }

}
