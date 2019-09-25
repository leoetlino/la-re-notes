-------- EventFlow: PotDemonKing --------

Actor: PotDemonPot
entrypoint: None()
actions: ['PlayAnimation', 'PlayAnimationEx', 'LookAtGimmick']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayBGM', 'StopAllBGM', 'StopBGM', 'PlayOneshotSystemSE', 'PlayZoneBGM']
queries: []
params: None

Actor: PotDemonKing
entrypoint: None()
actions: ['SetActorSwitch', 'LookAtGimmick', 'PlayTailorOtherChannelEx', 'PlayAnimation', 'PlayAnimationEx', 'BossRoomDoorClose', 'BossRoomDoorOpen', 'BossItemDrop', 'ModelVisibility', 'GenerateMagic']
queries: ['CheckSawTheFirstEvent', 'CheckKindBoss']
params: None

Actor: Camera
entrypoint: None()
actions: ['ApplyPreset']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: ['InvokeTimeline', 'PreloadTimeline']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'PlayInAnim']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetDisablePowerUpEffect', 'ClearPowerUp', 'MoveZoneEnterDirection']
queries: []
params: None

Actor: GameControl
entrypoint: None()
actions: ['RequestAutoSave']
queries: []
params: None

void PotDemonStart() {
    Link.SetDisablePowerUpEffect({'sound': True, 'effect': False, 'materialAnim': False})
    switch PotDemonKing.CheckSawTheFirstEvent({'switchIndex': 1}) {
      case 0:
        Audio.StopAllBGM({'duration': 1.0})
        Hud.PlayOutAnim()
        Link.MoveZoneEnterDirection({'distance': 1.5, 'mode': 0, 'timeOut': 5.0})

        fork {
            PotDemonKing.BossRoomDoorClose()
        } {
            Timer.Wait({'time': 0.800000011920929})
        } {
            FlowControl.PreloadTimeline({'filename': 'PotDemonKingPop'})
        }

        FlowControl.InvokeTimeline({'filename': 'PotDemonKingPop', 'rate': 1.0})
        PotDemonKing.SetActorSwitch({'switchIndex': 1, 'value': True})
        Camera.ApplyPreset({'name': 'PotDemonKing', 'chaseRatio': 0.02500000037252903})
        Hud.PlayInAnim()
        Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
      case [1, 2, 3]:

        call PotDemonSkip()

        Link.SetDisablePowerUpEffect({'effect': False, 'materialAnim': False, 'sound': False})
    }
}

void PotDemonEnd() {
    Link.ClearPowerUp()
    Hud.PlayOutAnim()
    Audio.StopBGM({'label': 'BGM_DUNGEON_BOSS', 'duration': 0.5})
    PotDemonKing.PlayAnimation({'name': 'dead', 'blendTime': 0.10000000149011612})
    PotDemonKing.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    PotDemonKing.PlayTailorOtherChannelEx({'channel': 'Dead_Boss', 'time': 4.0, 'restart': False, 'index': 0})
    PotDemonKing.ModelVisibility({'visible': False, 'modelIndex': 0})
    Timer.Wait({'time': 1.0})
    switch PotDemonKing.CheckKindBoss() {
      case 0:
        Audio.PlayBGM({'label': 'BGM_FANFARE_BOSS_HEART_GET', 'volume': 1.0})
        Timer.Wait({'time': 3.0})
        PotDemonKing.BossItemDrop()
        Timer.Wait({'time': 1.5})
        PotDemonKing.BossRoomDoorOpen()
        Hud.PlayInAnim()
        GameControl.RequestAutoSave()
      case 1:
        Audio.PlayBGM({'label': 'BGM_PANEL_RESULT', 'volume': 1.0})

        call PanelAdventure.PanelClear()

      case 2:
        Timer.Wait({'time': 1.0})
        PotDemonKing.BossRoomDoorOpen()
        Audio.PlayZoneBGM({'stopbgm': True})
        Hud.PlayInAnim()
        GameControl.RequestAutoSave()
    }
}

void PotDemonNoMove() {
    Dialog.Show({'message': 'Scenario:Lv2BossHint1'})
}

void PotDemonNoDamage() {

    fork {
        Dialog.Show({'message': 'Scenario:Lv2BossHint2'})
    } {
        PotDemonPot.PlayAnimation({'name': 'wait', 'blendTime': 0.10000000149011612})
    }

}

void PotDemonBreak() {
    Dialog.Show({'message': 'Scenario:Lv2BossBreakPot'})
}

void PotDemonSkip() {

    fork {
        Audio.StopAllBGM({'duration': 1.0})
    } {
        Hud.PlayOutAnim()
    }

    Link.MoveZoneEnterDirection({'mode': 0, 'distance': 1.5, 'timeOut': 5.0})

    fork {
        PotDemonKing.BossRoomDoorClose()
    } {
        PotDemonPot.LookAtGimmick({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    }


    fork {
        PotDemonPot.PlayAnimation({'name': 'pot_pop', 'blendTime': 0.10000000149011612})
    } {
        PotDemonKing.PlayAnimation({'name': 'pot_pop', 'blendTime': 0.10000000149011612})
    } {
        Timer.Wait({'time': 0.30000001192092896})
        Audio.PlayOneshotSystemSE({'label': 'SE_ENE_POT_DEMON_POP_1ST', 'volume': 1.0, 'pitch': 1.0})
    }


    fork {
        PotDemonPot.PlayAnimationEx({'name': 'attack_juggling', 'time': 0.0, 'blendTime': 0.0})
    } {
        PotDemonKing.PlayAnimationEx({'name': 'attack_juggling', 'time': 0.0, 'blendTime': 0.0})
    }

    PotDemonKing.GenerateMagic({'attachIndex': 2})
    Timer.Wait({'time': 0.13300000131130219})
    PotDemonKing.GenerateMagic({'attachIndex': 0})
    Timer.Wait({'time': 0.5299999713897705})
    PotDemonKing.GenerateMagic({'attachIndex': 1})
    Timer.Wait({'time': 1.309999942779541})
    Camera.ApplyPreset({'name': 'PotDemonKing', 'chaseRatio': 0.02500000037252903})
    Hud.PlayInAnim()
    Audio.PlayBGM({'label': 'BGM_DUNGEON_BOSS', 'volume': 1.0})
}
