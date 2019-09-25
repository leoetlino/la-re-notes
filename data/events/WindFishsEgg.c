-------- EventFlow: WindFishsEgg --------

Actor: SirenInstrument[Instruments]
entrypoint: None()
actions: ['Deactivate', 'Activate', 'PlayAnimationEx', 'WarpToActor', 'ShowNextInstrument', 'PlayTailorOtherChannelEx', 'PlayInstrumentTailorChannel', 'StopTailorOtherChannel']
queries: ['CheckStatus']
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['PlayAnimation', 'AimCompassPoint', 'SetEquipmentVisibility', 'ClearPowerUp', 'StopTailorOtherChannel', 'SetFacialExpression', 'PlayTailorOtherChannelEx', 'PlayTailorOtherChannelNoWait', 'MoveToTargetLinkedPoint', 'PlayAnimationEx']
queries: []
params: None

Actor: WindFishsEgg
entrypoint: None()
actions: ['Open', 'LookAtInfomation', 'PlayWorldOriginCameraAnimation', 'Crack', 'SetActorSwitch', 'PlayOrchestra', 'PlayOneshotSE', 'PlayTailorOtherChannelEx']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['StopZoneAudio', 'PlayZoneAudio', 'PlayJingle', 'StopAllBGM', 'StopWindAmbienceSE', 'CancelStopWindAmbienceSE', 'PlayZoneBaseAmbience']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Quake', 'Shake']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasAllInstruments']
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['ForbidLaunchApplet', 'UnforbidLaunchApplet']
queries: []
params: None

void orchestra() {
    GameControl.ForbidLaunchApplet()
    Link.ClearPowerUp()

    fork {

        fork {

            fork {
                Audio.StopZoneAudio()
                Timer.Wait({'time': 2.0})
            } {
                Audio.StopWindAmbienceSE({'duration': 1.0})
            }

        } {
            Link.MoveToTargetLinkedPoint({'speed': 0, 'index': 0, 'actor': ActorIdentifier(name="WindFishsEgg"), 'timeOut': 7.0})
            Link.AimCompassPoint({'duration': 0.10000000149011612, 'withoutTurn': False, 'direction': 0})

            fork {
                Link.PlayAnimationEx({'name': 'ev_TakeOkarina_wait', 'time': 0.10000000149011612, 'blendTime': 0.10000000149011612})
            } {
                Link.SetEquipmentVisibility({'visibility': False, 'ocarina': True, 'flipper': False})
            }

        } {
            Hud.PlayOutAnim()
        }

        Timer.Wait({'time': 0.15000000596046448})
        Link.SetFacialExpression({'expression': 'dream'})
        Timer.Wait({'time': 0.3499999940395355})

        fork {
            Audio.PlayJingle({'label': 'BGM_OCA_PLAY_FISH_OF_WIND', 'volume': 1.0})
        } {
            Link.PlayTailorOtherChannelNoWait({'channel': 'Ocarina_WindFish', 'restart': False, 'index': 0})
        } {
            Timer.Wait({'time': 4.300000190734863})
        } {
            Link.PlayAnimation({'name': 'ocarina_lp', 'blendTime': 0.10000000149011612})
        } {
            Link.SetFacialExpression({'expression': 'dream'})
        }

    } {
        WindFishsEgg.PlayWorldOriginCameraAnimation({'name': 'WindFishsEgg01', 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
    }


    fork {
        Link.PlayAnimation({'name': 'ev_TakeOkarina_wait', 'blendTime': 0.20000000298023224})
    } {

        call instrument_pop()

    }


    fork {

        fork {
            SirenInstrument[Instruments].PlayInstrumentTailorChannel({'index': 1, 'channel': 'note_violin'})
        } {
            SirenInstrument[Instruments].PlayInstrumentTailorChannel({'index': 2, 'channel': 'note_horn'})
        } {
            SirenInstrument[Instruments].PlayInstrumentTailorChannel({'index': 3, 'channel': 'note_bell'})
        } {
            SirenInstrument[Instruments].PlayInstrumentTailorChannel({'index': 4, 'channel': 'note_harp'})
        } {
            SirenInstrument[Instruments].PlayInstrumentTailorChannel({'index': 5, 'channel': 'note_marimba'})
        } {
            SirenInstrument[Instruments].PlayInstrumentTailorChannel({'index': 6, 'channel': 'note_triangle'})
        } {
            SirenInstrument[Instruments].PlayInstrumentTailorChannel({'index': 7, 'channel': 'note_organ'})
        } {
            SirenInstrument[Instruments].PlayInstrumentTailorChannel({'index': 8, 'channel': 'note_dram'})
        }

    } {

        fork {
            if Inventory.HasAllInstruments() {
                SirenInstrument[Instruments].PlayTailorOtherChannelEx({'channel': 'Playing', 'time': 0.0, 'restart': False, 'index': 0})
            }
        } {
            WindFishsEgg.PlayOrchestra({'wait': False})
            if !Inventory.HasAllInstruments() {

                fork {
                    Timer.Wait({'time': 39.400001525878906})
                } {
                    Timer.Wait({'time': 37.400001525878906})
                    Link.StopTailorOtherChannel({'channel': 'Ocarina_WindFish_Loop', 'index': 0})
                }

            } else {
                Timer.Wait({'time': 41.400001525878906})
            }
        } {
            Link.PlayTailorOtherChannelEx({'restart': True, 'time': 0.0, 'channel': 'Ocarina_WindFish_Loop', 'index': 0})
        } {
            Link.PlayAnimation({'name': 'ev_EggOkarina_lp', 'blendTime': 0.10000000149011612})
        }

    }


    fork {

        fork {
            SirenInstrument[Instruments].StopTailorOtherChannel({'index': 1, 'channel': 'note_violin'})
        } {
            SirenInstrument[Instruments].StopTailorOtherChannel({'index': 2, 'channel': 'note_horn'})
        } {
            SirenInstrument[Instruments].StopTailorOtherChannel({'index': 3, 'channel': 'note_bell'})
        } {
            SirenInstrument[Instruments].StopTailorOtherChannel({'index': 4, 'channel': 'note_harp'})
        } {
            SirenInstrument[Instruments].StopTailorOtherChannel({'index': 5, 'channel': 'note_marimba'})
        } {
            SirenInstrument[Instruments].StopTailorOtherChannel({'index': 6, 'channel': 'note_triangle'})
        } {
            SirenInstrument[Instruments].StopTailorOtherChannel({'index': 7, 'channel': 'note_organ'})
        } {
            SirenInstrument[Instruments].StopTailorOtherChannel({'index': 8, 'channel': 'note_dram'})
        }

    } {
        if !Inventory.HasAllInstruments() {

            fork {
                SirenInstrument[Instruments].StopTailorOtherChannel({'channel': 'Playing', 'index': 0})
            } {
                Fade.StartPreset({'preset': 11})
                SirenInstrument[Instruments].Deactivate()
                Timer.Wait({'time': 0.10000000149011612})

                fork {
                    Fade.StartPreset({'preset': 10})
                } {
                    Audio.PlayZoneAudio()
                } {
                    Audio.CancelStopWindAmbienceSE()
                }

            }

        } else {

            fork {
                SirenInstrument[Instruments].StopTailorOtherChannel({'channel': 'Playing', 'index': 0})
            } {
                Fade.StartPreset({'preset': 11})
                SirenInstrument[Instruments].Deactivate()
                Timer.Wait({'time': 0.10000000149011612})
                Link.StopTailorOtherChannel({'channel': 'Ocarina_WindFish_Loop', 'index': 0})
                Fade.StartPreset({'preset': 10})
            } {
                WindFishsEgg.PlayOneshotSE({'label': 'SE_ENV_EGG_WHITEOUT', 'volume': 1.0, 'pitch': 1.0})
            }

        }
    }


    fork {
        Link.PlayAnimation({'blendTime': 0.10000000149011612, 'name': 'ocarina_ed'})
    } {
        Link.SetFacialExpression({'expression': 'normal'})
    }

    if !Inventory.HasAllInstruments() {
        Hud.PlayInAnim()
        GameControl.UnforbidLaunchApplet()
    } else {
        Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})

        fork {
            Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
        } {
            Link.AimCompassPoint({'direction': 2, 'duration': 0.30000001192092896, 'withoutTurn': False})
        }


        fork {

            call oepn()

        } {
            WindFishsEgg.PlayWorldOriginCameraAnimation({'name': 'WindFishsEgg02', 'chaseRatio': 1.0, 'offsetX': 0.0, 'offsetY': 0.0, 'offsetZ': 0.0, 'lookAtDistanceCtrl': False, 'nearClipDistanceCtrl': False, 'farClipDistanceCtrl': False, 'aspectRatioCtrl': False})
        }

        GameControl.UnforbidLaunchApplet()

        call Owl.Fiveteen()

    }
}

void oepn() {
    Link.ClearPowerUp()
    WindFishsEgg.LookAtInfomation({'duration': 0.4000000059604645, 'chaseRatio': 0.08500000089406967, 'distanceOffset': 0.0})

    fork {
        Camera.Quake({'targetPower': 2, 'initPower': 0, 'duration': 0.25})
    } {
        WindFishsEgg.PlayOneshotSE({'label': 'SE_ENV_EGG_RUMBLE', 'volume': 1.0, 'pitch': 1.0})
    }

    Timer.Wait({'time': 6.0})

    fork {
        Camera.Shake({'duration': 0.25, 'power': 3})
    } {
        WindFishsEgg.Crack()
    } {
        WindFishsEgg.PlayTailorOtherChannelEx({'channel': 'Crack', 'time': 0.0, 'restart': False, 'index': 0})
    }

    Timer.Wait({'time': 1.2000000476837158})

    fork {
        Camera.Shake({'duration': 0.25, 'power': 3})
    } {
        WindFishsEgg.Open()
    } {
        WindFishsEgg.PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'Break', 'restart': False, 'index': 0})
    }

    WindFishsEgg.SetActorSwitch({'switchIndex': 0, 'value': True})
    Audio.StopAllBGM({'duration': 0.5})
    Timer.Wait({'time': 1.600000023841858})

    fork {
        Audio.PlayJingle({'label': 'BGM_NAZOTOKI_SEIKAI', 'volume': 1.0})
    } {
        Timer.Wait({'time': 2.0})
        Audio.PlayZoneBaseAmbience()
    }

}

void instrument_pop() {
    SirenInstrument[Instruments].Activate()
    SirenInstrument[Instruments].WarpToActor({'actor': ActorIdentifier(name="Link"), 'distance': 0.0, 'offsetY': 0.0})
    Event7:
    if !SirenInstrument[Instruments].CheckStatus() {
        Timer.Wait({'time': 0.5})
        Link.SetFacialExpression({'expression': 'dream'})
        SirenInstrument[Instruments].PlayAnimationEx({'blendTime': 0.0, 'time': 0.0, 'name': 'pop_egg_lp'})
    } else {
        SirenInstrument[Instruments].ShowNextInstrument()
        goto Event7
    }
}
