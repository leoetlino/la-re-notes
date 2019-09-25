-------- EventFlow: ShellMansionMaster --------

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetFlag']
queries: ['CheckFlag']
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItem']
queries: []
params: None

Actor: Fade
entrypoint: None()
actions: ['StartPreset']
queries: []
params: None

Actor: ShellMansionMaster
entrypoint: None()
actions: ['StartGauge', 'FlashGauge', 'PopBox', 'Deactivate', 'PlayTailorOtherChannelEx', 'PlayOneshotSE']
queries: ['TestGiftCondition']
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingleTimeWait', 'StopSE']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: []
queries: ['Branch']
params: None

Actor: Link
entrypoint: None()
actions: ['PlayAnimation', 'LookAtItemGettingPlayer', 'ShowSwordOnly', 'PlayTailorOtherChannelEx', 'StopTailorOtherChannel', 'AimCompassPoint', 'SetEquipmentVisibility', 'SetFacialExpression']
queries: []
params: None

Actor: Camera
entrypoint: None()
actions: ['Reset']
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

void ShellMansionFirst() {
    Hud.PlayOutAnim()

    call FirstShell()

    Dialog.Show({'message': 'SubEvent:ShellMansionFirst2'})
    Hud.PlayInAnim()
}

void Shell50() {

    call FlashGauge()

    Hud.PlayOutAnim()

    fork {
        Fade.StartPreset({'preset': 11})
    } {
        ShellMansionMaster.PlayOneshotSE({'label': 'SE_MAP_SHELL_WHITEOUT', 'volume': 1.0, 'pitch': 1.0})
    }

    Fade.StartPreset({'preset': 10})
    Fade.StartPreset({'preset': 11})
    Fade.StartPreset({'preset': 10})
    Fade.StartPreset({'preset': 11})
    Dialog.Show({'message': 'SubEvent:PerfectShell1'})
    Dialog.Show({'message': 'SubEvent:PerfectShell2'})
    Dialog.Show({'message': 'SubEvent:PerfectShell3'})
    Fade.StartPreset({'preset': 10})
    ShellMansionMaster.PopBox({'pointIndex': 0, 'itemKey': 'PanelDungeonPiece', 'itemIndex': 13, 'flag': 'GetSeashell50'})
    Hud.PlayInAnim()
}

void Shell40() {

    call FlashGauge()

    Hud.PlayOutAnim()
    Camera.Reset({'chaseRatio': 0.10000000149011612})
    Dialog.Show({'message': 'SubEvent:40CompShell'})
    Link.AimCompassPoint({'direction': 0, 'duration': 0.10000000149011612, 'withoutTurn': False})

    fork {
        Link.ShowSwordOnly()
    } {
        Link.PlayAnimation({'name': 's_atk_up_st', 'blendTime': 0.10000000149011612})
    } {
        Link.SetFacialExpression({'expression': 'normal'})
    }

    Link.PlayAnimation({'name': 's_atk_up_lp', 'blendTime': 0.10000000149011612})
    Link.PlayTailorOtherChannelEx({'time': 2.0, 'channel': 'Lv2Sword_Ready', 'restart': False, 'index': 0})
    Inventory.AddItem({'itemType': 1, 'count': 1, 'autoEquip': False})
    EventFlags.SetFlag({'symbol': 'SwordLv2Get', 'value': True})
    EventFlags.SetFlag({'symbol': 'GetSeashell40', 'value': True})
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    Link.ShowSwordOnly()

    fork {
        Link.StopTailorOtherChannel({'channel': 'Lv2Sword_Ready', 'index': 0})
    } {
        Link.PlayTailorOtherChannelEx({'time': 3.299999952316284, 'channel': 'Lv2Sword_Appear', 'restart': False, 'index': 0})
    }


    fork {
        Link.LookAtItemGettingPlayer({'duration': 0.699999988079071, 'chaseRatio': 0.10000000149011612, 'distanceOffset': 0.0})
    } {
        Link.SetFacialExpression({'expression': 'get'})
    }


    fork {
        Dialog.Show({'message': 'SubEvent:GetLv2Sword'})
    } {
        Link.PlayTailorOtherChannelEx({'channel': 'Lv2Sword_Get', 'time': 0.4830000102519989, 'restart': False, 'index': 0})
        Audio.PlayJingleTimeWait({'label': 'BGM_FANFARE_BIGITEM_GET', 'duration': 0.800000011920929, 'volume': 1.0})
    }

    Link.StopTailorOtherChannel({'channel': 'Lv2Sword_Get', 'index': 0})

    fork {
        Link.SetFacialExpression({'expression': 'normal'})
    } {
        Link.PlayAnimation({'name': 's_atk_up_ed', 'blendTime': 0.10000000149011612})
    }


    call NextGift({'doNoShellEvent': False})

    Hud.PlayInAnim()
}

void Shell30() {

    call FlashGauge()

    ShellMansionMaster.PopBox({'pointIndex': 0, 'itemKey': 'PanelDungeonPiece', 'flag': 'GetSeashell30', 'itemIndex': 4})
}

void Shell20() {

    call FlashGauge()

    ShellMansionMaster.PopBox({'pointIndex': 0, 'itemKey': 'ShellRader', 'itemIndex': -1, 'flag': 'GetSeashell20'})
}

void Shell10() {

    call FlashGauge()

    ShellMansionMaster.PopBox({'pointIndex': 0, 'itemKey': 'HeartPiece', 'itemIndex': 22, 'flag': 'GetSeashell10'})
}

void NoShell() {
    Dialog.Show({'message': 'SubEvent:NoCompShell'})
}

void FirstShell() {
    Dialog.Show({'message': 'SubEvent:ShellMansionFirst1'})
    EventFlags.SetFlag({'symbol': 'FirstSeashell', 'value': True})
}

void FlashGauge() {
    Camera.Reset({'chaseRatio': 0.10000000149011612})
    ShellMansionMaster.FlashGauge()
    Link.PlayAnimation({'name': 'idle_bare', 'blendTime': 0.10000000149011612})
    Timer.Wait({'time': 1.399999976158142})
    Audio.PlayJingleTimeWait({'label': 'BGM_NAZOTOKI_SEIKAI', 'duration': 1.6799999475479126, 'volume': 1.0})
}

void NextGift() {
    Audio.StopSE({'label': 'SE_MAP_SHELL_GAUGE_LEVEL', 'duration': 0.30000001192092896})
    switch ShellMansionMaster.TestGiftCondition() {
      case 0:
        if FlowControl.Branch({'value': 'doNoShellEvent'}) {

            call NoShell()

        }
      case 1:

        call Shell10()

      case 2:

        call Shell20()

      case 3:

        call Shell30()

      case 4:

        call Shell40()

      case 5:

        call Shell50()

    }
}

void ShellMansion() {
    if !EventFlags.CheckFlag({'symbol': 'GetSeashell50'}) {
        Link.AimCompassPoint({'direction': 1, 'duration': 0.4000000059604645, 'withoutTurn': False})
        ShellMansionMaster.PlayTailorOtherChannelEx({'channel': 'Light', 'time': 1.0, 'restart': False, 'index': 0})
        ShellMansionMaster.StartGauge()

        call NextGift({'doNoShellEvent': True})

        ShellMansionMaster.Deactivate()
    }
}
