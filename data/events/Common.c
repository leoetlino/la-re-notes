-------- EventFlow: Common --------

Actor: Character[companion]
entrypoint: None()
actions: ['PlayAnimation']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveToCompassPoint', 'PlayAnimation', 'SetEquipmentVisibility', 'PlayTailorOtherChannelNoWait', 'Heal', 'AddDeadCounter', 'AimCompassPoint', 'RequestInvincible', 'ResetAim', 'LookAtCharacter', 'SetDisablePowerUpEffect', 'ClearPowerUp', 'LookAtOcarina', 'SetRenderLayer']
queries: ['IsSideView']
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingle', 'SetBGMVolume', 'OnGameOver', 'StopAllBGM', 'PlayBGM', 'StopZoneAudio', 'PlayOneshotSystemSE', 'PlayJingleNotWait', 'PlayZoneBGM']
queries: []
params: None

Actor: WarpUI
entrypoint: None()
actions: ['JumpToSelectedLocation', 'Show']
queries: ['GetResult']
params: None

Actor: WarpHoleEventBox
entrypoint: None()
actions: ['PlayTailorOtherChannelEx']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['RemoveItem']
queries: ['HasItem']
params: None

Actor: GameOverUI
entrypoint: None()
actions: ['Show']
queries: ['GetResult']
params: None

Actor: GameControl
entrypoint: None()
actions: ['Retry', 'Quit', 'Save', 'GoToEnding', 'RequestAutoSave']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: RiverGate
entrypoint: None()
actions: ['CloseGate']
queries: []
params: None

Actor: RapidflowGame
entrypoint: None()
actions: ['StartTimerUI', 'CancelGame']
queries: ['GetGameMode']
params: None

Actor: Object
entrypoint: None()
actions: ['LookAtCharacter']
queries: []
params: None

Actor: PanelDungeon
entrypoint: None()
actions: ['RetryCommon', 'RetryTimeLimit']
queries: ['CheckPanelDungeon']
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset', 'WaitZeldaScroll']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim']
queries: []
params: None

void heavyObject() {
    if !Inventory.HasItem({'itemType': 15, 'count': 1}) {
        Dialog.Show({'message': 'System:TouchLiftRock'})
    } else {
        Dialog.Show({'message': 'System:TouchLiftHeavyObject'})
    }
}

void ObjBookshelf() {
    Dialog.Show({'message': 'System:CheckBookshelf'})
}

void ObjIceBlock() {
    Dialog.Show({'message': 'System:TouchIceBlock'})
}

void ObjMysteryLump() {
    Dialog.Show({'message': 'System:TouchAttackRock'})
}

void ObjCracked() {
    Dialog.Show({'message': 'System:TouchBombRock'})
}

void ZeldaScroll() {
    Link.MoveToCompassPoint({'direction': 'direction', 'speed': 0, 'distance': 0.75, 'timeOut': 7.0})
    Camera.WaitZeldaScroll()
}

void OcarinaWarpOut() {

    fork {
        Link.PlayAnimation({'name': 'warp_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'warp_lp', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 2.25})
        if Link.IsSideView() {
            Link.SetRenderLayer({'enable': True})
        }
        WarpHoleEventBox.PlayTailorOtherChannelEx({'channel': 'WarpHole_Go_00', 'time': 0.10000000149011612, 'restart': False, 'index': 0})
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
        } {
            Audio.StopZoneAudio()
        }

        Link.SetRenderLayer({'enable': False})
    }

    RapidflowGame.CancelGame()
    WarpUI.JumpToSelectedLocation()
    GameControl.RequestAutoSave()
}

void OcarinaNull() {

    call OcarinaKamae_Base()


    fork {
        Audio.PlayJingle({'label': 'BGM_OCA_PLAY_NO_SKILL', 'volume': 1.0})
    } {
        Link.PlayTailorOtherChannelNoWait({'restart': False, 'channel': 'Ocarina_Heta', 'index': 0})
    } {
        Timer.Wait({'time': 3.299999952316284})
        Link.PlayAnimation({'name': 'ocarina_ed', 'blendTime': 0.10000000149011612})
    }

    Audio.SetBGMVolume({'duration': 0.12999999523162842, 'volume': 1.0})

    fork {
        Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
    } {
        Dialog.Show({'message': 'System:NotSongOcarina'})
    } {
        Link.SetEquipmentVisibility({'flipper': False, 'visibility': False, 'ocarina': False})
    }

    Link.SetDisablePowerUpEffect({'sound': False, 'effect': False, 'materialAnim': False})
}

void OcarinaWind() {

    call OcarinaKamae_Base()


    fork {
        Audio.PlayJingle({'label': 'BGM_OCA_PLAY_FISH_OF_WIND', 'volume': 1.0})
    } {
        Link.PlayTailorOtherChannelNoWait({'channel': 'Ocarina_WindFish', 'restart': False, 'index': 0})
    } {
        Timer.Wait({'time': 4.5})
        Link.PlayAnimation({'name': 'ocarina_ed', 'blendTime': 0.10000000149011612})
    }

    Audio.SetBGMVolume({'duration': 0.12999999523162842, 'volume': 1.0})
    Link.SetDisablePowerUpEffect({'sound': False, 'effect': False, 'materialAnim': False})
}

void OcarinaManbo_Base() {
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.12999999523162842})
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': True, 'flipper': False})
    if !Link.IsSideView() {

        fork {
            Link.PlayAnimation({'name': 'ocarina_st', 'blendTime': 0.10000000149011612})
            Link.PlayAnimation({'name': 'ocarina_lp', 'blendTime': 0.10000000149011612})
        } {
            Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
            Link.ResetAim()
        } {
            Link.LookAtOcarina({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        }

    } else {

        fork {
            Link.PlayAnimation({'name': 'ocarina_st', 'blendTime': 0.10000000149011612})
            Link.PlayAnimation({'name': 'ocarina_lp', 'blendTime': 0.10000000149011612})
        } {
            Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
            Link.ResetAim()
        }

    }

    fork {
        Audio.PlayJingleNotWait({'label': 'BGM_OCA_PLAY_MANBO', 'volume': 1.0})
    } {
        Link.PlayTailorOtherChannelNoWait({'channel': 'Ocarina_Manbo', 'restart': False, 'index': 0})
    } {
        Timer.Wait({'time': 4.099999904632568})
    }

    Link.PlayAnimation({'blendTime': 0.10000000149011612, 'name': 'ocarina_wait'})
}

void OcarinaFrog() {

    call OcarinaKamae_Base()


    fork {
        Audio.PlayJingle({'label': 'BGM_OCA_PLAY_SOUL', 'volume': 1.0})
    } {
        Link.PlayTailorOtherChannelNoWait({'channel': 'Ocarina_Mamu', 'restart': False, 'index': 0})
    } {
        Timer.Wait({'time': 4.0})
        Link.PlayAnimation({'name': 'ocarina_ed', 'blendTime': 0.10000000149011612})
    }

    Audio.SetBGMVolume({'duration': 0.12999999523162842, 'volume': 1.0})
    Link.SetDisablePowerUpEffect({'sound': False, 'effect': False, 'materialAnim': False})
}

void GameOver() {
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.12999999523162842})
    Link.PlayAnimation({'name': '$death', 'blendTime': 0.10000000149011612})
    Link.ClearPowerUp()
    Timer.Wait({'time': 2.0})
    if !EventFlags.CheckFlag({'symbol': 'ShopKeeperCounterattack'}) {
        if !Inventory.HasItem({'itemType': 22, 'count': 1}) {
            Event94:
            if !PanelDungeon.CheckPanelDungeon() {

                call GameOverCommon()

            } else {

                call GameOverPanel()

            }
        } else {
            Inventory.RemoveItem({'itemType': 22})
            Link.Heal({'amount': 99})
            Link.PlayAnimation({'blendTime': 0.0, 'name': '$resurrection'})
            Audio.SetBGMVolume({'duration': 0.5, 'volume': 1.0})
            Link.RequestInvincible()
        }
    } else {
        EventFlags.SetFlag({'symbol': 'ShopKeeperCounterattack', 'value': False})
        goto Event94
    }
}

void StartRapidFlow() {
    RiverGate.CloseGate()
    if RapidflowGame.GetGameMode() == 2 {
        Audio.StopAllBGM({'duration': 1.0})
        RapidflowGame.StartTimerUI()
        Timer.Wait({'time': 2.0})
        Audio.PlayBGM({'label': 'BGM_RAFTING_TIMEATTACK', 'volume': 1.0})
    }
}

void MarinLetter() {
    Object.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    Dialog.Show({'message': 'Npc:MarinLetter'})
}

void GameOverCommon() {
    Audio.OnGameOver()
    Link.AddDeadCounter()
    GameOverUI.Show()
    if !GameOverUI.GetResult() {
        GameControl.Retry()
        Event67:
        Audio.StopAllBGM({'duration': 1.0})
    } else {
        GameControl.Save()
        GameControl.Quit()
        goto Event67
    }
}

void GameOverPanel() {
    PanelDungeon.RetryCommon()
    Audio.StopAllBGM({'duration': 1.0})
    Fade.StartPreset({'preset': 9})
}

void GameOverPanelTimeLimit() {
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.12999999523162842})
    Link.ClearPowerUp()
    Audio.PlayOneshotSystemSE({'label': 'SE_SY_PN_TIME_OVER_WHISTLE', 'volume': 1.0, 'pitch': 1.0})
    Timer.Wait({'time': 2.0})
    Dialog.Show({'message': 'System:AdvTimeOver'})
    PanelDungeon.RetryTimeLimit()
    Audio.StopAllBGM({'duration': 1.0})
    Fade.StartPreset({'preset': 9})
}

void Panel4_ShiningPanel() {
    Timer.Wait({'time': 1.0})
}

void OcarinaWarpOut_Companion() {

    fork {
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_st'})
        Character[companion].PlayAnimation({'blendTime': 0.0, 'name': 'warp_lp'})
    } {
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_st'})
        Link.PlayAnimation({'blendTime': 0.0, 'name': 'warp_lp'})
    } {
        Timer.Wait({'time': 2.25})
        if Link.IsSideView() {
            Link.SetRenderLayer({'enable': True})
        }
        WarpHoleEventBox.PlayTailorOtherChannelEx({'channel': 'WarpHole_Go_00', 'time': 0.10000000149011612, 'restart': False, 'index': 0})
        Timer.Wait({'time': 0.5})

        fork {
            Fade.StartPreset({'preset': 9})
        } {
            Audio.StopZoneAudio()
        }

        Link.SetRenderLayer({'enable': False})
    }

    RapidflowGame.CancelGame()
    WarpUI.JumpToSelectedLocation()
    GameControl.RequestAutoSave()
}

void OcarinaManbo() {

    call OcarinaManbo_Base()

    if !EventFlags.CheckFlag({'symbol': 'WarpProhibition'}) {
        WarpUI.Show()
        if !WarpUI.GetResult() {
            Event28:

            fork {
                Timer.Wait({'time': 0.15000000596046448})
            } {
                Link.PlayAnimation({'blendTime': 0.10000000149011612, 'name': 'ocarina_ed'})
            }

            Audio.SetBGMVolume({'duration': 0.12999999523162842, 'volume': 1.0})
            Link.SetDisablePowerUpEffect({'sound': False, 'effect': False, 'materialAnim': False})
        } else {

            call OcarinaWarpOut()

        }
    } else {
        goto Event28
    }
}

void orchestra_Start() {
    Hud.PlayOutAnim()

    call WindFishsEgg.orchestra()

}

void TurtleRockStart() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': True, 'flipper': False})

    fork {
        Link.PlayAnimation({'name': 'ocarina_st', 'blendTime': 0.10000000149011612})
        Link.PlayAnimation({'name': 'ocarina_lp', 'blendTime': 0.10000000149011612})
    } {
        Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
    } {
        Link.LookAtCharacter({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
    }


    fork {
        Audio.PlayJingle({'label': 'BGM_OCA_PLAY_SOUL', 'volume': 1.0})
    } {
        Link.PlayTailorOtherChannelNoWait({'channel': 'Ocarina_Mamu', 'restart': False, 'index': 0})
    } {
        Timer.Wait({'time': 2.799999952316284})
    }


    call TurtleRock.TurtleRockStart()

}

void E3_AppQuit() {
    Fade.StartPreset({'preset': 1})
    GameControl.GoToEnding()
}

void OcarinaManbo_Companion() {

    call OcarinaManbo_Base()

    if !EventFlags.CheckFlag({'symbol': 'WarpProhibition'}) {
        WarpUI.Show()
        if !WarpUI.GetResult() {

            fork {
                Camera.Reset({'chaseRatio': 0.20000000298023224})
                Audio.SetBGMVolume({'duration': 0.12999999523162842, 'volume': 1.0})
                Audio.PlayZoneBGM({'stopbgm': True})
                Link.SetDisablePowerUpEffect({'sound': False, 'effect': False, 'materialAnim': False})
            } {
                Timer.Wait({'time': 0.15000000596046448})
                Link.PlayAnimation({'name': 'ocarina_ed', 'blendTime': 0.10000000149011612})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }

        } else {

            call OcarinaWarpOut_Companion()

        }
    }
}

void OcarinaKamae_Base() {
    Audio.SetBGMVolume({'volume': 0.0, 'duration': 0.12999999523162842})
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': True, 'flipper': False})
    if !Link.IsSideView() {

        fork {
            Link.LookAtOcarina({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})
        } {

            fork {
                Link.PlayAnimation({'name': 'ocarina_st', 'blendTime': 0.10000000149011612})
                Link.PlayAnimation({'name': 'ocarina_lp', 'blendTime': 0.0})
            } {
                Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
            }

        }

    } else {

        fork {
            Link.PlayAnimation({'name': 'ocarina_st', 'blendTime': 0.10000000149011612})
            Link.PlayAnimation({'name': 'ocarina_lp', 'blendTime': 0.0})
        } {
            Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})
        }

    }
}
