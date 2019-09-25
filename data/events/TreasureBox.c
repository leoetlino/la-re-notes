-------- EventFlow: TreasureBox --------

Actor: TreasureBox
entrypoint: None()
actions: ['GenericGimmickSequence', 'Activate', 'SetActorSwitch', 'PopEnemy', 'GenericExamineSequence', 'PlayAnimation', 'PopItem', 'PlayAnimationEx', 'PlayTailorOtherChannelEx', 'PlayOneshotSE', 'SetCollisionDisable', 'SetCollisionEnable']
queries: ['ContainsEnemy', 'CheckSameGrid', 'IsShockTriggerBox']
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Inventory
entrypoint: None()
actions: ['AddItemByKey']
queries: ['HasItem']
params: None

Actor: Link
entrypoint: None()
actions: ['GenericItemGetSequenceByKey', 'AimActor', 'MoveToTargetActor', 'ResetAim']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayJingleTimeWait']
queries: []
params: None

Actor: FlowControl
entrypoint: None()
actions: []
queries: ['CompareString']
params: None

void TreasureBox_Open() {
    if !TreasureBox.IsShockTriggerBox() {
        TreasureBox.SetActorSwitch({'value': True, 'switchIndex': 1})
        if !TreasureBox.ContainsEnemy() {

            call BoxOpen({'channel': 'open'})

            if !FlowControl.CompareString({'value1': 'itemKey', 'value2': 'SecretMedicine'}) {
                if !Inventory.HasItem({'itemType': 22, 'count': 1}) {
                    Event0:
                    Link.GenericItemGetSequenceByKey({'itemKey': 'itemKey', 'keepCarry': False, 'messageEntry': ''})
                    Inventory.AddItemByKey({'itemKey': 'itemKey', 'index': 'itemIndex', 'count': 'itemNum', 'autoEquip': False})
                } else {
                    Link.GenericItemGetSequenceByKey({'itemKey': 'itemKey', 'messageEntry': 'SecretMedicine2', 'keepCarry': False})

                    call BoxClose()

                    TreasureBox.SetActorSwitch({'switchIndex': 1, 'value': False})
                }
            } else {
                goto Event0
            }
        } else {

            fork {

                call BoxOpen({'channel': 'open_Miss'})

            } {
                Timer.Wait({'time': 0.8299999833106995})
                TreasureBox.PopEnemy()
            }

            Timer.Wait({'time': 0.5})
        }
    } else {

        call TreasureBox_NoShock()

    }
}

void TreasureBox_Pop() {

    fork {
        TreasureBox.GenericGimmickSequence({'cameraLookAt': True, 'distanceOffset': 0.0})
    } {
        if TreasureBox.CheckSameGrid({'actor': ActorIdentifier(name="Link")}) {
            Link.MoveToTargetActor({'speed': 1, 'distance': 1.5, 'actor': ActorIdentifier(name="TreasureBox"), 'timeOut': 7.0})
            Link.AimActor({'actor': ActorIdentifier(name="TreasureBox"), 'duration': 0.4000000059604645, 'withoutTurn': False, 'boneName': ''})
            Link.ResetAim()
        }
    }

    TreasureBox.SetCollisionDisable()
    TreasureBox.Activate()

    fork {
        TreasureBox.PlayAnimation({'name': 'appear', 'blendTime': 0.0})
    } {
        Timer.Wait({'time': 1.2000000476837158})
        TreasureBox.SetCollisionEnable({'adjust': True})
    }

    Timer.Wait({'time': 1.2000000476837158})
    Audio.PlayJingleTimeWait({'label': 'BGM_NAZOTOKI_SEIKAI', 'duration': 1.6799999475479126, 'volume': 1.0})
}

void MasterStalfonLetter() {

    fork {
        Link.AimActor({'duration': 0.8999999761581421, 'actor': ActorIdentifier(name="TreasureBox"), 'withoutTurn': False, 'boneName': ''})
    } {
        TreasureBox.PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})
        TreasureBox.PlayAnimationEx({'name': 'open_wait', 'time': 0.30000001192092896, 'blendTime': 0.10000000149011612})
    } {
        TreasureBox.PlayOneshotSE({'label': 'SE_MAP_TBOX_OPEN', 'volume': 1.0, 'pitch': 1.0})
    }

    TreasureBox.SetActorSwitch({'value': True, 'switchIndex': 1})
    TreasureBox.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    Dialog.Show({'message': 'Scenario:Lv5MiniBossLetter'})
}

void TreasureBox_ShockOpen() {

    call BoxOpen({'channel': 'open'})

    TreasureBox.SetActorSwitch({'value': True, 'switchIndex': 1})
    TreasureBox.PopItem()
    Link.GenericItemGetSequenceByKey({'itemKey': 'itemKey', 'keepCarry': False, 'messageEntry': ''})
    Inventory.AddItemByKey({'itemKey': 'itemKey', 'index': 'itemIndex', 'count': 'itemNum', 'autoEquip': False})
}

void BoxOpen() {

    fork {
        Link.AimActor({'duration': 0.8999999761581421, 'actor': ActorIdentifier(name="TreasureBox"), 'withoutTurn': False, 'boneName': ''})
    } {
        TreasureBox.PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})
        TreasureBox.PlayAnimationEx({'name': 'open_wait', 'time': 0.30000001192092896, 'blendTime': 0.10000000149011612})
    } {
        TreasureBox.PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'channel', 'restart': False, 'index': 0})
    }

}

void BoxClose() {
    Link.AimActor({'duration': 0.8999999761581421, 'actor': ActorIdentifier(name="TreasureBox"), 'withoutTurn': False, 'boneName': ''})
    TreasureBox.PlayAnimation({'name': 'close', 'blendTime': 0.0})
    TreasureBox.PlayAnimationEx({'blendTime': 0.0, 'name': 'close_wait', 'time': 0.30000001192092896})
}

void TreasureBox_NoShock() {

    fork {
        Link.AimActor({'duration': 0.8999999761581421, 'actor': ActorIdentifier(name="TreasureBox"), 'withoutTurn': False, 'boneName': ''})
    } {
        TreasureBox.PlayAnimation({'name': 'not_open', 'blendTime': 0.0})
        TreasureBox.PlayAnimationEx({'time': 0.30000001192092896, 'name': 'close_wait', 'blendTime': 0.0})
    }

}
