-------- EventFlow: PlayerStart --------

Actor: Bed[EventBed]
entrypoint: None()
actions: ['PlayAnimationEx', 'PlayAnimation', 'Disarray']
queries: []
params: None

Actor: WarpHoleEventBox[WarpHole]
entrypoint: None()
actions: ['PlayTailorOtherChannelEx']
queries: []
params: None

Actor: BowWow[companion]
entrypoint: None()
actions: ['Destroy', 'WarpToActor']
queries: []
params: None

Actor: Marin[Marin]
entrypoint: None()
actions: ['AimPlayer', 'Talk', 'TalkKeep', 'PlayAnimation', 'SetFacialExpression']
queries: []
params: None

Actor: Marin[companion]
entrypoint: None()
actions: ['Talk', 'PlayAnimation', 'AimPlayer', 'AimDegreeAngle', 'Activate', 'Deactivate', 'WarpToActorWithCompassPoint', 'ResetAim', 'LookAtCharacter', 'BeginStompMode']
queries: []
params: None

Actor: DungeonWarpHole[DungeonWarpHole]
entrypoint: None()
actions: ['PlayTailorOtherChannelEx']
queries: []
params: None

Actor: FlyingCucco[companion]
entrypoint: None()
actions: ['Destroy']
queries: []
params: None

Actor: Character[companion]
entrypoint: None()
actions: ['AimCompassPoint', 'PlayAnimation', 'WarpToActor', 'Deactivate', 'Activate', 'WarpToActorWithCompassPoint', 'MoveToTargetActor', 'MoveToCompassPoint', 'ResetAim']
queries: []
params: None

Actor: Ghost[companion]
entrypoint: None()
actions: ['WarpToActor']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveToCompassPoint', 'PlayAnimation', 'PlayAnimationEx', 'SetEquipmentVisibility', 'MoveLadder', 'AimCompassPoint', 'MoveToTargetActor', 'LeaveCompanion', 'PlayOneshotSE', 'AimDegreeAngle', 'ResetAim', 'SetFacialExpression', 'WarpToLinkedPoint', 'WarpToActor', 'SetDisablePowerUpEffect', 'SetGravityEnable']
queries: ['IsPinch']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartParam', 'StartPreset']
queries: []
params: None

Actor: WarpHoleEventBox
entrypoint: None()
actions: ['PlayTailorOtherChannelEx']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: EventTriggerTag
entrypoint: None()
actions: ['SetActorSwitch', 'LookAtGimmicksLinkedPoint']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayZoneAudio', 'PlayOneshotSystemSE', 'PlayBGM', 'StopZoneAudio', 'PlayZoneBaseAmbience', 'PlayBaseAmbienceSe']
queries: []
params: None

Actor: Tarin[Tarin]
entrypoint: None()
actions: ['PlayAnimation', 'AimPlayer']
queries: []
params: None

Actor: PanelResultUI
entrypoint: None()
actions: []
queries: ['CheckNewReward']
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave', 'RequestAutoSaveCaptureFirst', 'RequestWarp']
queries: ['ComparePreviousLevelTime']
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: PanelDungeon
entrypoint: None()
actions: ['ShowPanelTutorialUi']
queries: ['CheckRetryReason']
params: None

Actor: Marin
entrypoint: None()
actions: ['Talk']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: []
queries: ['Random']
params: None

Actor: Danpei[OwlDanpei]
entrypoint: None()
actions: ['WarpToLinkedPointWithCompassPoint']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['SetLookAtOffsetAdditional']
queries: []
params: None

void RunOut() {

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'speed': 1, 'distance': 0.75, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void WalkIn() {

    fork {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.75, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void WalkOut() {

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'direction': 0, 'distance': 3.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 4})
    } {
        Audio.PlayZoneAudio()
    }

}

void RunIn() {

    fork {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 4})
    } {
        Audio.PlayZoneAudio()
    }

}

void FallIn_Marin() {
    Marin[companion].Deactivate()

    fork {
        Link.PlayAnimation({'name': 'fall_from_top', 'blendTime': 0.0})
    } {
        Audio.PlayZoneAudio()
    } {
        Fade.StartPreset({'preset': 4})
    } {
        Marin[companion].WarpToActorWithCompassPoint({'direction': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 12.0})
        Marin[companion].Activate()
        Marin[companion].PlayAnimation({'blendTime': 0.0, 'name': 'fall'})
    }

    Marin[companion].BeginStompMode()
}

void DungeonWarpIn() {

    fork {
        Fade.StartPreset({'preset': 8})
    } {
        DungeonWarpHole[DungeonWarpHole].PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'Come', 'restart': False, 'index': 0})
    } {
        Link.PlayAnimation({'name': 'warp_d_ed', 'blendTime': 0.0})
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void FieldWarpIn() {

    fork {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
        Link.ResetAim()
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_ed'})
        Link.MoveToCompassPoint({'direction': 0, 'distance': 2.0, 'speed': 1, 'timeOut': 7.0})
    } {
        Timer.Wait({'time': 0.6299999952316284})
        WarpHoleEventBox[WarpHole].PlayTailorOtherChannelEx({'time': 0.10000000149011612, 'channel': 'WarpHole_Come_00', 'restart': False, 'index': 0})
    } {
        Timer.Wait({'time': 0.20000000298023224})
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void OcarinaWarpIn() {

    call FieldWarpIn()

}

void DungeonIn_Lv1() {
    Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv1Dungeon'})
}

void DungeonIn_Lv2() {
    Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv2Dungeon'})
}

void DungeonIn_Lv3() {
    Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv3Dungeon'})
}

void DungeonIn_Lv4() {
    Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv4Dungeon'})
}

void DungeonIn_Lv5() {
    Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv5Dungeon'})
}

void DungeonIn_Lv6() {
    Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv6Dungeon'})
}

void DungeonIn_Lv7() {
    Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv7Dungeon'})
}

void DungeonIn_Lv8() {
    Link.MoveToCompassPoint({'direction': 2, 'speed': 1, 'distance': 3.0, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv8Dungeon'})
}

void DungeonIn_Lv8_2() {
    Link.MoveToCompassPoint({'speed': 1, 'direction': 0, 'distance': 1.5, 'timeOut': 7.0})
    Dialog.Show({'message': 'Place:Lv8Dungeon'})
}

void default() {
    Fade.StartParam({'mode': 0, 'colorR': 0.0, 'colorG': 0.0, 'time': 0.30000001192092896, 'colorB': 1.0})
}

void WakeUp() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Link.SetFacialExpression({'expression': 'dream'})

    fork {
        Link.PlayAnimationEx({'name': 'sleep_lp', 'time': 0.0, 'blendTime': 0.0})
    } {
        Bed[EventBed].PlayAnimationEx({'name': 'ftn_sleep_lp', 'time': 0.0, 'blendTime': 0.0})
    } {
        Fade.StartPreset({'preset': 6})
    } {
        Audio.PlayZoneAudio()
    }


    fork {
        Link.PlayAnimation({'name': 'sleep_ed', 'blendTime': 0.0})
    } {
        Bed[EventBed].PlayAnimation({'name': 'ftn_sleep_ed', 'blendTime': 0.0})
    } {
        Link.SetFacialExpression({'expression': 'normal'})
    }

}

void FallInRot() {

    fork {
        Link.PlayAnimation({'name': 'fall_from_top_rot', 'blendTime': 0.10000000149011612})
    } {
        Fade.StartPreset({'preset': 8})
    }

}

void LadderUp() {

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        Link.MoveLadder({'mode': 1, 'distance': 1.5})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void LadderDown() {

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        Link.MoveLadder({'mode': 2, 'distance': 1.5})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void OcarinaWarpDungeonIn() {
    Link.AimCompassPoint({'direction': 0, 'duration': 0.05000000074505806, 'withoutTurn': False})
    Link.ResetAim()

    fork {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_ed'})
    } {
        Timer.Wait({'time': 0.6299999952316284})
        WarpHoleEventBox.PlayTailorOtherChannelEx({'time': 0.10000000149011612, 'channel': 'WarpHole_Come_00', 'restart': False, 'index': 0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void MarinEventJump1() {

    call Marin.BeachDate()

}

void MarinEventJump2() {

    call Marin.MarinGet()

}

void MarinEventJump3() {

    call Marin.CapeDate()

}

void ExitOut() {

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void EntranceIn() {

    fork {
        Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.75, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void WarpTutorial() {
    if !EventFlags.CheckFlag({'symbol': 'WarpTutorialClear'}) {
        Dialog.Show({'message': 'System:DungeonWarpTutorial'})
        EventFlags.SetFlag({'symbol': 'WarpTutorialClear', 'value': True})
    }
}

void OcarinaWarpDungeonInLv2() {

    call OcarinaWarpDungeonIn()

    EventTriggerTag.SetActorSwitch({'value': True, 'switchIndex': 0})
}

void DefaultDownStairsOut() {

    fork {
        Link.MoveToTargetActor({'distance': 1.5, 'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void DefaultUpStairsOut() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': 1.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void DefaultDownDigStairsOut() {

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'speed': 0, 'distance': 1.5, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void DefaultUpDigStairsOut() {

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'speed': 0, 'distance': 1.5, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void WaterSideOut() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})
    Link.MoveToTargetActor({'speed': 0, 'distance': 0.009999999776482582, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})

    fork {
        Fade.StartPreset({'preset': 8})
    } {
        Link.MoveToCompassPoint({'direction': 4, 'distance': 1.5, 'speed': 0, 'timeOut': 7.0})
    } {
        Audio.PlayZoneAudio()
    }

}

void WaterTopOut() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})
    Link.MoveToTargetActor({'speed': 2, 'distance': 0.009999999776482582, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})

    fork {
        Link.PlayAnimation({'name': 'u_swim_depth_out', 'blendTime': 0.10000000149011612})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void FallInWater() {

    fork {
        Link.PlayAnimation({'name': 'fall_to_water', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.019999999552965164})
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    } {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        Timer.Wait({'time': 0.6499999761581421})
        Link.SetEquipmentVisibility({'flipper': True, 'visibility': False, 'ocarina': False})
    }

}

void BayHouse_In() {

    call Ghost.GhostHouse()

}

void FishingMode() {

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void RunInWhiteLv09() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': 1.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    }

}

void WaitOut() {

    fork {
        Fade.StartPreset({'preset': 4})
    } {
        Audio.PlayZoneAudio()
    }

}

void DungeonIn() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': 1.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void WaterSideOutLeft() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

    fork {
        Fade.StartPreset({'preset': 8})
    } {
        Link.MoveToCompassPoint({'distance': 1.5, 'speed': 0, 'direction': 3, 'timeOut': 7.0})
    } {
        Audio.PlayZoneAudio()
    }

}

void WaterTopOutForward() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

    fork {
        Link.MoveToTargetActor({'speed': 0, 'distance': 1.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void OcarinaWarpInWait() {

    fork {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
        Link.ResetAim()
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_ed'})
    } {
        Timer.Wait({'time': 0.6299999952316284})
        WarpHoleEventBox.PlayTailorOtherChannelEx({'time': 0.10000000149011612, 'channel': 'WarpHole_Come_00', 'restart': False, 'index': 0})
    } {
        Timer.Wait({'time': 0.20000000298023224})
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

    Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
}

void DungeonInShort() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 0.75, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void WaitOutWell() {
    Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})

    fork {
        Link.PlayAnimation({'name': 'ev_well_out', 'blendTime': 0.0})
    } {
        Fade.StartPreset({'preset': 4})
    } {
        Audio.PlayZoneAudio()
    }

}

void RaccoonIn() {

    fork {
        Timer.Wait({'time': 0.699999988079071})
        Fade.StartParam({'mode': 0, 'colorR': 0.8999999761581421, 'colorG': 0.8999999761581421, 'colorB': 0.8999999761581421, 'time': 1.2999999523162842})
    } {
        Audio.PlayZoneAudio()
    } {
        EventTriggerTag.LookAtGimmicksLinkedPoint({'pointIndex': 0, 'duration': 0.0, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }

    Timer.Wait({'time': 0.8999999761581421})
    Camera.SetLookAtOffsetAdditional()
}

void WaterSideOutRight() {
    Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

    fork {
        Fade.StartPreset({'preset': 8})
    } {
        Link.MoveToCompassPoint({'distance': 1.5, 'speed': 0, 'direction': 1, 'timeOut': 7.0})
    } {
        Audio.PlayZoneAudio()
    }

}

void WaitOutWell_Companion() {

    fork {
        Link.WarpToActor({'distance': 1.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
    } {
        Character[companion].Deactivate()
        Character[companion].WarpToActor({'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Character[companion].AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
    }


    fork {
        Timer.Wait({'time': 0.10000000149011612})

        fork {
            Fade.StartPreset({'preset': 4})
        } {
            Audio.PlayZoneAudio()
        }

    } {
        Link.PlayAnimation({'name': 'ev_well_out_coop', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 0.5})
        Character[companion].Activate()
        Character[companion].PlayAnimation({'name': 'ev_well_out', 'blendTime': 0.0})
    }

}

void Level7DungeonIn_FlyingCucco() {
    if !EventFlags.CheckFlag({'symbol': 'Lv7InstrumentGet'}) {
        Character[companion].WarpToActorWithCompassPoint({'offsetY': -2.130000114440918, 'direction': 2, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 4.5})
        Character[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})

        call Level7DungeonIn()

    } else {
        Link.LeaveCompanion()
        FlyingCucco[companion].Destroy()

        call Level7DungeonIn()

    }
}

void Level7DungeonIn() {

    fork {
        Link.WarpToActor({'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 2.5, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void DungeonInMoriblin() {
    if !EventFlags.CheckFlag({'symbol': 'Lv1InstrumentGet'}) {
        Event570:

        fork {
            Link.MoveToTargetActor({'speed': 0, 'distance': 0.699999988079071, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        }

    } else
    if !EventFlags.CheckFlag({'symbol': 'BowWowJoin'}) {
        if !EventFlags.CheckFlag({'symbol': 'MoriblinDemoClear'}) {

            fork {
                Link.MoveToTargetActor({'speed': 0, 'distance': 0.699999988079071, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
            } {
                Fade.StartPreset({'preset': 8})
            }

        } else {

            fork {
                Link.MoveToTargetActor({'speed': 0, 'distance': 0.699999988079071, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
            } {
                Fade.StartPreset({'preset': 8})
            } {
                Audio.PlayOneshotSystemSE({'label': 'SE_ENV_BOWWOW_VO3', 'volume': 1.0, 'pitch': 1.0})
            }

            Audio.PlayZoneAudio()
        }
    } else {
        goto Event570
    }
}

void FieldWarpIn_Companion() {

    fork {

        call FieldWarpIn()

    } {
        Character[companion].WarpToActor({'distance': -1.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Character[companion].AimCompassPoint({'direction': 0, 'duration': 0.05000000074505806, 'withoutTurn': False})
        Character[companion].ResetAim()
        Timer.Wait({'time': 0.15000000596046448})
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_ed'})
        Timer.Wait({'time': 0.15000000596046448})
        Character[companion].MoveToCompassPoint({'direction': 0, 'distance': 2.0, 'speed': 1, 'timeOut': 7.0})
    }

}

void OcarinaWarpIn_Companion() {

    call FieldWarpIn_Companion()

}

void OcarinaWarpInWait_Companion() {

    fork {

        call OcarinaWarpInWait()

    } {
        Character[companion].AimCompassPoint({'direction': 0, 'duration': 0.05000000074505806, 'withoutTurn': False})
        Character[companion].ResetAim()
        Timer.Wait({'time': 0.15000000596046448})
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_ed'})
    }

}

void DefaultDownStairsOut_Companion() {

    fork {

        call DefaultDownStairsOut()

    } {
        Character[companion].WarpToActor({'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Character[companion].Deactivate()
        Timer.Wait({'time': 0.6000000238418579})
        Character[companion].Activate()
        Character[companion].MoveToTargetActor({'speed': 0, 'distance': 0.30000001192092896, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    }

}

void DefaultUpStairsOut_Companion() {

    fork {

        call DefaultUpStairsOut()

    } {
        Character[companion].WarpToActor({'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.5})
        Character[companion].Deactivate()
        Timer.Wait({'time': 0.6000000238418579})
        Character[companion].Activate()
        Character[companion].MoveToTargetActor({'speed': 0, 'distance': 0.30000001192092896, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    }

}

void DefaultDownDigStairsOut_Companion() {

    fork {

        call DefaultDownDigStairsOut()

    } {

        call NPC_Out_Dig()

    }

}

void DefaultUpDigStairsOut_Companion() {

    fork {

        call DefaultUpDigStairsOut()

    } {

        call NPC_Out_Dig()

    }

}

void FM_Restart() {

    fork {
        Link.PlayAnimation({'name': 'down_lp', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 1.25})
    } {
        Fade.StartPreset({'preset': 0})
    }

    Link.PlayAnimation({'name': 'rise', 'blendTime': 0.10000000149011612})
}

void op() {
    if !EventFlags.CheckFlag({'symbol': 'OpTalked'}) {

        fork {
            Link.PlayAnimation({'name': 'ev_sleep_lp', 'blendTime': 0.0})
        } {
            Bed[EventBed].PlayAnimation({'name': 'ftn_ev_sleep_lp', 'blendTime': 0.10000000149011612})
        } {
            Tarin[Tarin].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        }

        Timer.Wait({'time': 0.30000001192092896})
        Fade.StartPreset({'preset': 4})
        Timer.Wait({'time': 3.0})

        fork {

            fork {
                Link.SetFacialExpression({'expression': 'wakeup'})
            } {
                Link.PlayAnimation({'name': 'ev_wakeup_st', 'blendTime': 0.0})
            }

            Link.PlayAnimation({'name': 'ev_wakeup_lp', 'blendTime': 0.10000000149011612})
        } {
            Bed[EventBed].PlayAnimation({'name': 'ftn_ev_wakeup_st', 'blendTime': 0.10000000149011612})
            Bed[EventBed].PlayAnimation({'name': 'ftn_ev_wakeup_lp', 'blendTime': 0.10000000149011612})
        } {
            Audio.PlayOneshotSystemSE({'label': 'SE_PL_WAKEUP_BED', 'volume': 1.0, 'pitch': 1.0})
        }

        Audio.PlayBGM({'label': 'BGM_HOUSE_FIRST', 'volume': 1.0})
        Timer.Wait({'time': 0.5})
        Marin[Marin].SetFacialExpression({'expression': 'smile'})

        fork {
            Marin[Marin].Talk({'message': 'Scenario:Lv1FirstMarin1'})

            fork {
                Tarin[Tarin].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            } {
                Timer.Wait({'time': 0.5})
            }


            fork {
                Link.SetFacialExpression({'expression': 'normal'})
            } {
                Link.AimDegreeAngle({'withoutTurn': True, 'angle': 140.0, 'duration': 0.75})
            } {
                Timer.Wait({'time': 0.5})
            }

            Marin[Marin].PlayAnimation({'name': 'talk2', 'blendTime': 0.10000000149011612})
            Marin[Marin].SetFacialExpression({'expression': 'worry'})
            Marin[Marin].TalkKeep({'message': 'Scenario:Lv1FirstMarin2'})
            Marin[Marin].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
            Marin[Marin].SetFacialExpression({'expression': 'normal'})
            Marin[Marin].TalkKeep({'message': 'Scenario:Lv1FirstMarin3'})
            Marin[Marin].SetFacialExpression({'expression': 'worry'})
            Marin[Marin].Talk({'message': 'Scenario:Lv1FirstMarin4'})
            Marin[Marin].SetFacialExpression({'expression': 'normal'})
            Marin[Marin].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Marin[Marin].AimPlayer({'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
        }

        Link.ResetAim()

        fork {
            Link.PlayAnimation({'name': 'ev_outbed', 'blendTime': 0.0})
            Link.PlayAnimation({'name': 'idle', 'blendTime': 0.10000000149011612})
        } {
            Bed[EventBed].PlayAnimation({'name': 'ftn_ev_outbed', 'blendTime': 0.10000000149011612})
            Bed[EventBed].PlayAnimation({'name': 'ftn_ev_idle', 'blendTime': 0.10000000149011612})
        } {
            Link.PlayOneshotSE({'label': 'SE_PL_JUMP_BED', 'volume': 1.0, 'pitch': 1.0})
        }

        Bed[EventBed].Disarray({'animName': 'ftn_ev_idle'})
        Marin[Marin].SetFacialExpression({'expression': 'normal'})
        EventFlags.SetFlag({'symbol': 'OpTalked', 'value': True})
        EventFlags.SetFlag({'value': True, 'symbol': 'DoorOpen_Btl_MoriblinCave_2A'})
        EventFlags.SetFlag({'value': True, 'symbol': 'DoorOpen_Btl_MoriblinCave_1A'})
        GameControl.RequestAutoSave()
    } else {
        Link.WarpToLinkedPoint({'index': 0, 'offsetY': 0.0})
        Timer.Wait({'time': 0.20000000298023224})

        fork {
            Fade.StartPreset({'preset': 4})
        } {
            Audio.PlayZoneAudio()
        }

    }
}

void WaterFallOut() {

    fork {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'ev_waterfall_out'})
    } {
        Timer.Wait({'time': 0.019999999552965164})

        fork {
            Fade.StartPreset({'preset': 4})
        } {
            Audio.PlayZoneAudio()
        }

    }

}

void PanelRewardIn() {

    fork {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

    if !PanelResultUI.CheckNewReward() {
        GameControl.RequestAutoSaveCaptureFirst()

        call Danpei.PanelMenu()

    } else {

        call Danpei.RewardResult()

    }
}

void FallIn() {

    fork {
        Link.PlayAnimation({'name': 'fall_from_top', 'blendTime': 0.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void FallIn_Companion() {
    Character[companion].Deactivate()

    fork {

        call FallIn()

    } {
        Timer.Wait({'time': 0.30000001192092896})
        Character[companion].Activate()
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'fall_from_top'})
        Character[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

}

void WaterFallOut_Companion() {

    fork {

        call WaterFallOut()

    } {
        Character[companion].AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'ev_waterfall_out'})
    }

}

void NPC_Out_Dig() {
    Character[companion].WarpToActorWithCompassPoint({'direction': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 0.5, 'offsetY': 0.0})
    Character[companion].Deactivate()
    Timer.Wait({'time': 0.6000000238418579})
    Character[companion].Activate()
    Character[companion].MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 0.6000000238418579, 'timeOut': 7.0})
}

void FallInWater_Companion() {
    Character[companion].Deactivate()

    fork {

        call FallInWater()

    } {
        Timer.Wait({'time': 0.30000001192092896})
        Character[companion].Activate()
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'fall_from_top'})
        Character[companion].PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

}

void RunOut_Companion() {

    fork {

        call RunOut()

    } {

        call NPC_Out_Field()

    }

}

void WalkIn_Companion() {

    fork {

        call WalkIn()

    } {

        call NPC_Out_Field()

    }

}

void ExitOut_Companion() {

    fork {

        call ExitOut()

    } {

        call NPC_Out_Field()

    }

}

void EntranceIn_Companion() {

    fork {

        call EntranceIn()

    } {

        call NPC_Out_Field()

    }

}

void NPC_Out_Field() {
    Character[companion].WarpToActor({'distance': -0.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
    Character[companion].Deactivate()
    Timer.Wait({'time': 0.30000001192092896})
    Character[companion].Activate()
    Character[companion].MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
}

void DungeonInShort_Companion() {

    fork {

        call DungeonInShort()

    } {

        call NPC_Out_Field()

    }

}

void FieldWarpIn_Ghost() {

    fork {

        call FieldWarpIn()

    } {
        Ghost[companion].WarpToActor({'distance': -1.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 10.0})
    }

}

void FallInsub() {

    fork {
        Link.PlayAnimation({'name': 'fall_from_top', 'blendTime': 0.10000000149011612})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void WalkShell() {

    fork {
        Link.MoveToCompassPoint({'speed': 0, 'distance': 0.75, 'direction': 1, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void ExitOutMadam() {

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void ExitOutMadam_BowWow() {
    if !EventFlags.CheckFlag({'symbol': 'BowwowClear'}) {

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        }

    } else {
        BowWow[companion].Destroy()
        Link.LeaveCompanion()

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        }

    }
}

void Dungeon_talk() {

    fork {
        Marin[companion].LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    } {
        Marin[companion].PlayAnimation({'name': 'folded_legs_lp', 'blendTime': 0.10000000149011612})
    }

    Timer.Wait({'time': 0.800000011920929})

    fork {
        Timer.Wait({'time': 0.30000001192092896})
    } {
        Marin[companion].AimDegreeAngle({'withoutTurn': True, 'angle': -90.0, 'duration': 0.10000000149011612})
    }


    fork {
        Marin[companion].PlayAnimation({'name': 'folded_legs_ed', 'blendTime': 0.10000000149011612})
        Marin[companion].PlayAnimation({'blendTime': 0.10000000149011612, 'name': 'wait'})
    } {
        Timer.Wait({'time': 0.30000001192092896})
        Marin[companion].AimPlayer({'withoutTurn': False, 'duration': 0.8999999761581421, 'boneName': ''})
    }

    if !EventFlags.CheckFlag({'symbol': 'DamageMarinCheck'}) {
        if !Link.IsPinch() {
            Event261:
            Marin[companion].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
            if !GameControl.ComparePreviousLevelTime({'time': 136.52999877929688}) {
                Marin.Talk({'message': 'SubEvent:MarineWorry1'})
            } else {
                Marin.Talk({'message': 'SubEvent:MarineWorry2'})
            }
        } else {
            Marin[companion].PlayAnimation({'name': 'talk2', 'blendTime': 0.10000000149011612})
            Marin[companion].Talk({'message': 'SubEvent:MarineWorry3'})
            if !FlowControl.Random({'threshold': 0.015625}) {
                Marin[companion].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
                Marin[companion].Talk({'message': 'SubEvent:MarineWorry4'})
            }
        }
    } else {
        goto Event261
    }
}

void LevelDungeonExitOut_Marin() {
    Marin[companion].WarpToActorWithCompassPoint({'direction': 0, 'distance': 2.299999952316284, 'actor': ActorIdentifier(name="Link"), 'offsetY': 0.0})
    Marin[companion].ResetAim()

    fork {

        call ExitOut()

    } {

        call Dungeon_talk()

    }

}

void LevelDungeonExitOut() {

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void DungeonFromLv7() {

    fork {
        Link.WarpToActor({'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 3.0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void FallInRot_Lv2() {

    call FallInRot()

    EventTriggerTag.SetActorSwitch({'value': True, 'switchIndex': 0})
}

void DungeonWarpIn_Lv2() {

    call DungeonWarpIn()

    EventTriggerTag.SetActorSwitch({'value': True, 'switchIndex': 0})
}

void LadderUpShort() {

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        Link.MoveLadder({'mode': 1, 'distance': 1.5})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void LadderDownShort() {

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
        Link.MoveLadder({'mode': 2, 'distance': 1.5})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void ExitOutShop() {
    if !EventFlags.CheckFlag({'symbol': 'StealSuccess'}) {

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        }

    } else {

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        }


        fork {
            Link.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
        } {
            Dialog.Show({'message': 'SubEvent:SuccessDorobou'})
        }

    }
}

void WaitOutWell_Ghost() {

    fork {
        Link.WarpToActor({'distance': 1.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
    } {
        Character[companion].Deactivate()
        Character[companion].WarpToActor({'offsetY': -3.0, 'distance': -3.0, 'actor': ActorIdentifier(name="EventTriggerTag")})
        Character[companion].AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
    }


    fork {
        Timer.Wait({'time': 0.10000000149011612})

        fork {
            Fade.StartPreset({'preset': 4})
        } {
            Audio.PlayZoneAudio()
        }

    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'ev_well_out'})
    } {
        Timer.Wait({'time': 0.5})
        Character[companion].Activate()
    }

}

void FallIn_Ghost() {
    Character[companion].Deactivate()
    Character[companion].WarpToActor({'offsetY': 10.0, 'distance': -2.0, 'actor': ActorIdentifier(name="EventTriggerTag")})

    fork {

        call FallIn()

    } {
        Timer.Wait({'time': 0.30000001192092896})
        Character[companion].Activate()
    }

}

void OcarinaWarpInWait_Ghost() {

    fork {

        call OcarinaWarpInWait()

    } {
        Ghost[companion].WarpToActor({'distance': -1.0, 'offsetY': 20.0, 'actor': ActorIdentifier(name="EventTriggerTag")})
    }

}

void Ending() {
}

void DownDigStairsOutLv7() {

    fork {
        Link.AimCompassPoint({'duration': 0.10000000149011612, 'direction': 0, 'withoutTurn': False})
        Link.PlayAnimation({'name': 'ev_stairs_up', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.20000000298023224})
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneBaseAmbience()
    }

}

void DungeonInShortWhite() {

    fork {
        Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 0.75, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 10})
    } {
        Audio.PlayZoneAudio()
    }

}

void DungeonInGoria() {
    if !Inventory.HasItem({'itemType': 44, 'count': 1}) {

        fork {
            Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 0.75, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        } {
            Audio.PlayOneshotSystemSE({'label': 'SE_NPC_GORIYA_002', 'volume': 1.0, 'pitch': 1.0})
        }

    } else {

        call DungeonInShort()

    }
}

void EntranceInZora() {
    if !Inventory.HasItem({'itemType': 44, 'count': 1}) {

        fork {
            Link.MoveToCompassPoint({'direction': 2, 'speed': 0, 'distance': 0.75, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        } {
            Audio.PlayOneshotSystemSE({'label': 'SE_NPC_ZORA_001', 'volume': 1.0, 'pitch': 1.0})
        }

    } else {

        call EntranceIn()

    }
}

void LevelDungeon2ExitOut_Marin() {

    fork {

        call ExitOut()

    } {

        call Dungeon_talk2()

    }

}

void Dungeon_talk2() {
    Marin[companion].WarpToActorWithCompassPoint({'direction': 0, 'distance': 4.0, 'actor': ActorIdentifier(name="Link"), 'offsetY': 0.0})
    Marin[companion].ResetAim()
    Marin[companion].PlayAnimation({'name': 'folded_legs_lp', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 0.6000000238418579})

    fork {
        Timer.Wait({'time': 0.6000000238418579})
    } {
        Marin[companion].AimPlayer({'withoutTurn': True, 'duration': 0.30000001192092896, 'boneName': ''})
    }


    fork {
        Marin[companion].PlayAnimation({'name': 'folded_legs_ed', 'blendTime': 0.10000000149011612})
        Marin[companion].PlayAnimation({'blendTime': 0.10000000149011612, 'name': 'wait'})
    } {
        Timer.Wait({'time': 0.30000001192092896})
        Marin[companion].AimPlayer({'withoutTurn': False, 'duration': 0.8999999761581421, 'boneName': ''})
    }

    if !EventFlags.CheckFlag({'symbol': 'DamageMarinCheck'}) {
        if !Link.IsPinch() {
            Event940:
            Marin[companion].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
            if !GameControl.ComparePreviousLevelTime({'time': 136.52999877929688}) {
                Marin[companion].Talk({'message': 'SubEvent:MarineWorry1'})
            } else {
                Marin[companion].Talk({'message': 'SubEvent:MarineWorry2'})
            }
        } else {
            Marin[companion].PlayAnimation({'name': 'talk2', 'blendTime': 0.10000000149011612})
            Marin[companion].Talk({'message': 'SubEvent:MarineWorry3'})
            if !FlowControl.Random({'threshold': 0.015625}) {
                Marin[companion].Talk({'message': 'SubEvent:MarineWorry4'})
            }
        }
    } else {
        goto Event940
    }
}

void LevelDungeon2ExitOut() {

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void EventMarinJump() {

    fork {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void OcarinaWarpInWait_BowWow() {

    fork {

        call OcarinaWarpInWait()

    } {
        Character[companion].Deactivate()
        BowWow[companion].WarpToActor({'distance': -1.0, 'offsetY': 10.0, 'actor': ActorIdentifier(name="EventTriggerTag")})
        Character[companion].AimCompassPoint({'direction': 0, 'duration': 0.05000000074505806, 'withoutTurn': False})
        Timer.Wait({'time': 0.30000001192092896})
        Character[companion].Activate()
    }

}

void FieldWarpIn_BowWow() {

    fork {

        call FieldWarpIn()

    } {
        Character[companion].Deactivate()
        Character[companion].WarpToActor({'offsetY': 10.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': -1.25})
        Timer.Wait({'time': 0.30000001192092896})
        Character[companion].Activate()
        Timer.Wait({'time': 1.399999976158142})
        Character[companion].MoveToCompassPoint({'direction': 0, 'distance': 2.0, 'speed': 1, 'timeOut': 7.0})
    }

}

void PanelDungeonIn() {

    call DungeonIn()


    call PanelAdventureTutorial()

}

void PanelAdventureTutorial() {
    if !EventFlags.CheckFlag({'symbol': 'AdvTutorialFirst'}) {
        PanelDungeon.ShowPanelTutorialUi({'id': 100})
    }
    switch PanelDungeon.CheckRetryReason() {
      case 1:
        PanelDungeon.ShowPanelTutorialUi({'id': 101})
      case 2:
        PanelDungeon.ShowPanelTutorialUi({'id': 102})
    }
}

void PanelUpStairsOut() {

    call DefaultUpStairsOut()


    call PanelAdventureTutorial()

}

void DanpeiIn() {
    if !EventFlags.CheckFlag({'symbol': 'DanpeiTalkClear'}) {

        call EntranceIn()

    } else
    if !EventFlags.CheckFlag({'symbol': 'DanpeiLeadClear'}) {
        if !EventFlags.CheckFlag({'symbol': 'DanpeiReturn'}) {

            call Danpei.DanpeiHouseReturn()

        } else {

            call EntranceIn()

        }
    } else {

        call EntranceIn()

    }
}

void LadderDown_Kanalet() {
    if !EventFlags.CheckFlag({'symbol': 'GoldenLeaf1'}) {
        EventFlags.SetFlag({'value': True, 'symbol': 'GoldenLeaf1'})

        call LadderDown()

    } else {

        call LadderDown()

    }
}

void AmosShrineExitOut() {
    if !EventFlags.CheckFlag({'symbol': 'SlateEventClear'}) {
        Event217:

        call LevelDungeonExitOut()

    } else
    if !EventFlags.CheckFlag({'symbol': 'TenthClear'}) {

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.StopZoneAudio()
        }

    } else {
        goto Event217
    }
}

void FaceShrineExitOut() {
    if !EventFlags.CheckFlag({'symbol': 'EleventhClear'}) {
        if !Inventory.HasItem({'itemType': 50, 'count': 1}) {
            Event245:

            call LevelDungeonExitOut()

        } else {

            fork {
                Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
            } {
                Fade.StartPreset({'preset': 8})
            } {
                Audio.StopZoneAudio()
            }

        }
    } else {
        goto Event245
    }
}

void FallInLv9Boss() {

    fork {
        Link.PlayAnimation({'name': 'fall_from_top', 'blendTime': 0.10000000149011612})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneBaseAmbience()
    }

}

void ExitOutShop_Companion() {

    fork {

        call ExitOutShop()

    } {

        call NPC_Out_Field()

    }

}

void EntranceIn_Tool_Companion() {
    if !EventFlags.CheckFlag({'symbol': 'StealSuccess'}) {

        fork {

            call EntranceIn()

        } {

            call NPC_Out_Field()

        }

    } else {

        fork {

            call NPC_Out_Field()

        } {

            call ToolShopkeeper.AngerDad()

        }

    }
}

void AmosShrineExitOut_Marin() {

    fork {

        call AmosShrineExitOut()

    } {

        call Dungeon_talk2()

    }

}

void Lv10DungeonOut_Marin() {

    fork {

        call Lv10DungeonOut()

    } {

        call Dungeon_talk3()

    }

}

void Dungeon_talk3() {
    Marin[companion].WarpToActorWithCompassPoint({'direction': 0, 'distance': 3.0, 'actor': ActorIdentifier(name="Link"), 'offsetY': 0.0})
    Marin[companion].ResetAim()
    Marin[companion].PlayAnimation({'name': 'folded_legs_lp', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 0.6000000238418579})

    fork {
        Timer.Wait({'time': 0.6000000238418579})
    } {
        Marin[companion].AimPlayer({'withoutTurn': True, 'duration': 0.30000001192092896, 'boneName': ''})
    }


    fork {
        Marin[companion].PlayAnimation({'name': 'folded_legs_ed', 'blendTime': 0.10000000149011612})
        Marin[companion].PlayAnimation({'blendTime': 0.10000000149011612, 'name': 'wait'})
    } {
        Timer.Wait({'time': 0.30000001192092896})
        Marin[companion].AimPlayer({'withoutTurn': False, 'duration': 0.8999999761581421, 'boneName': ''})
    }

    if !EventFlags.CheckFlag({'symbol': 'DamageMarinCheck'}) {
        if !Link.IsPinch() {
            Event191:
            Marin[companion].PlayAnimation({'name': 'talk', 'blendTime': 0.10000000149011612})
            if !GameControl.ComparePreviousLevelTime({'time': 136.52999877929688}) {
                Marin[companion].Talk({'message': 'SubEvent:MarineWorry1'})
            } else {
                Marin[companion].Talk({'message': 'SubEvent:MarineWorry2'})
            }
        } else {
            Marin[companion].PlayAnimation({'name': 'talk2', 'blendTime': 0.10000000149011612})
            Marin[companion].Talk({'message': 'SubEvent:MarineWorry3'})
            if !FlowControl.Random({'threshold': 0.015625}) {
                Marin[companion].Talk({'message': 'SubEvent:MarineWorry4'})
            }
        }
    } else {
        goto Event191
    }
}

void EntranceIn_Tool() {
    if !EventFlags.CheckFlag({'symbol': 'StealSuccess'}) {

        call EntranceIn()

    } else {

        call ToolShopkeeper.AngerDad()

    }
}

void Lv10DungeonOut() {

    fork {
        Link.MoveToTargetActor({'distance': 1.5, 'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void BowwowExitOut() {
    if !EventFlags.CheckFlag({'symbol': 'FourthClear'}) {
        Event325:

        call ExitOut()

    } else
    if !EventFlags.CheckFlag({'symbol': 'BowWowJoin'}) {
        goto Event325
    } else
    if !EventFlags.CheckFlag({'symbol': 'FifthClear'}) {
        Danpei[OwlDanpei].WarpToLinkedPointWithCompassPoint({'index': 0, 'direction': 0, 'offsetY': 0.0})

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.StopZoneAudio()
        }


        call Owl.Fifth()

    } else {
        goto Event325
    }
}

void KeyCavernExitOut() {
    if !Inventory.HasItem({'itemType': 47, 'count': 1}) {
        Event331:

        call LevelDungeonExitOut()

    } else
    if !EventFlags.CheckFlag({'symbol': 'SixthClear'}) {

        fork {
            Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.StopZoneAudio()
        }

    } else {
        goto Event331
    }
}

void ExitOutMadam_Companion() {

    fork {

        call ExitOutMadam()

    } {

        call NPC_Out_Field()

    }

}

void EntranceInZora_Companion() {

    fork {

        call EntranceInZora()

    } {

        call NPC_Out_Field()

    }

}

void DungeonInGoria_Companion() {

    fork {

        call DungeonInGoria()

    } {

        call NPC_Out_Field()

    }

}

void LevelDungeon2ExitOut_FlyingCucco() {
    Character[companion].WarpToActor({'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 4.0, 'offsetY': 0.0})
    Character[companion].AimCompassPoint({'duration': 0.05000000074505806, 'direction': 2, 'withoutTurn': False})

    fork {
        Link.MoveToCompassPoint({'direction': 0, 'distance': 0.75, 'speed': 0, 'timeOut': 7.0})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

}

void WaterTopOutForward_FlyingCucco() {

    fork {
        Link.SetEquipmentVisibility({'visibility': False, 'flipper': True, 'ocarina': False})

        fork {
            Link.MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 2.25, 'timeOut': 7.0})
        } {
            Fade.StartPreset({'preset': 8})
        } {
            Audio.PlayZoneAudio()
        }

    } {
        Character[companion].WarpToActor({'distance': -0.5, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Character[companion].Deactivate()
        Timer.Wait({'time': 0.30000001192092896})
        Character[companion].Activate()
        Character[companion].MoveToTargetActor({'speed': 0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'distance': 1.25, 'timeOut': 7.0})
    }

}

void PanelEditIn() {
}

void DanpeiEntInComp_base() {

    fork {
        Character[companion].WarpToActor({'offsetY': 1.0, 'distance': -0.75, 'actor': ActorIdentifier(name="EventTriggerTag")})
        Character[companion].MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    } {

        call EntranceIn()

    }

}

void DanpeiIn_Companion() {
    if !EventFlags.CheckFlag({'symbol': 'DanpeiTalkClear'}) {

        call DanpeiEntInComp_base()

    } else
    if !EventFlags.CheckFlag({'symbol': 'DanpeiLeadClear'}) {
        if !EventFlags.CheckFlag({'symbol': 'DanpeiReturn'}) {

            call Danpei.DanpeiHouseReturn_Companion()

        } else {

            call DanpeiEntInComp_base()

        }
    } else {

        call DanpeiEntInComp_base()

    }
}

void DanpeiIn_FlyingCucco() {
    if !EventFlags.CheckFlag({'symbol': 'DanpeiTalkClear'}) {

        call DanpeiEntInCucco_base()

    } else
    if !EventFlags.CheckFlag({'symbol': 'DanpeiLeadClear'}) {
        if !EventFlags.CheckFlag({'symbol': 'DanpeiReturn'}) {

            call Danpei.DanpeiHouseReturn_FlyingCucco()

        } else {

            call DanpeiEntInCucco_base()

        }
    } else {

        call DanpeiEntInCucco_base()

    }
}

void DanpeiEntInCucco_base() {

    fork {
        Character[companion].WarpToActor({'distance': -0.75, 'actor': ActorIdentifier(name="EventTriggerTag"), 'offsetY': 0.0})
        Character[companion].MoveToTargetActor({'speed': 0, 'distance': 0.0, 'actor': ActorIdentifier(name="EventTriggerTag"), 'timeOut': 7.0})
    } {

        call EntranceIn()

    }

}

void PanelRewardUI() {

    fork {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    }

    if !PanelResultUI.CheckNewReward() {
        GameControl.RequestAutoSaveCaptureFirst()

        call Danpei.PanelMenu()

    } else {

        call Danpei.RewardResult()

    }
}

void FallInLv7() {

    fork {
        Link.SetGravityEnable({'enable': True})
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'fall_from_top'})
    } {
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayZoneAudio()
    } {
        Timer.Wait({'time': 0.5799999833106995})
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'fall_hole'})
    }

    Fade.StartPreset({'preset': 9})
    GameControl.RequestWarp({'locator': 'Lv07_06B_from_02B_02F', 'offsetX': 0.0, 'offsetZ': 0.0})
}

void KeyCavernExitOut_Marin() {
    Marin[companion].WarpToActorWithCompassPoint({'direction': 0, 'distance': 2.299999952316284, 'actor': ActorIdentifier(name="Link"), 'offsetY': 0.0})
    Marin[companion].ResetAim()

    fork {

        call LevelDungeonExitOut()

    } {

        call Dungeon_talk()

    }

}

void FaceShrineExitOut_Marin() {
    Marin[companion].WarpToActorWithCompassPoint({'direction': 0, 'distance': 2.299999952316284, 'actor': ActorIdentifier(name="Link"), 'offsetY': 0.0})
    Marin[companion].ResetAim()

    fork {

        call LevelDungeonExitOut()

    } {

        call Dungeon_talk()

    }

}

void DownDigStairsOut_PanelLv7() {

    fork {
        Link.AimCompassPoint({'duration': 0.10000000149011612, 'direction': 0, 'withoutTurn': False})
        Link.PlayAnimation({'name': 'ev_stairs_up', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.20000000298023224})
        Fade.StartPreset({'preset': 8})
    } {
        Audio.PlayBaseAmbienceSe({'label': 'SE_AMB_LV7_BOSS_BG', 'groupLabel': 'GROUP_AMB_LV7BOSS'})
    }

}
