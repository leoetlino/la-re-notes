-------- EventFlow: Book --------

Actor: Book[Blue4]
entrypoint: None()
actions: ['Examine', 'PlayAnimation']
queries: []
params: None

Actor: Book[Green1]
entrypoint: None()
actions: ['Examine', 'PlayAnimation']
queries: []
params: None

Actor: Book[Orange2]
entrypoint: None()
actions: ['Examine', 'PlayAnimation']
queries: []
params: None

Actor: Book[red3]
entrypoint: None()
actions: ['PlayAnimation']
queries: []
params: None

Actor: Book[Red3]
entrypoint: None()
actions: ['Examine']
queries: []
params: None

Actor: Book[Blue2]
entrypoint: None()
actions: ['Examine', 'PlayAnimation']
queries: []
params: None

Actor: Book[Red1]
entrypoint: None()
actions: ['Examine', 'PlayAnimation', 'ShowMap']
queries: []
params: None

Actor: Book[Green3]
entrypoint: None()
actions: ['Examine']
queries: []
params: None

Actor: Book[Orange4]
entrypoint: None()
actions: ['Examine', 'PlayAnimation']
queries: []
params: None

Actor: Book[TackleBook]
entrypoint: None()
actions: ['Examine', 'PlayAnimation']
queries: []
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: ['GetLastResult']
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Book
entrypoint: None()
actions: ['GenericExamineSequence']
queries: []
params: None

void examine_Blue4() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[Blue4].Examine({'message': 'System:CheckShieldBook'})
        if !Dialog.GetLastResult() {
            Book[Blue4].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})

            fork {
                Dialog.Show({'message': 'System:ReadShieldBook'})
            } {
                Book[Blue4].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
            }

            Book[Blue4].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}

void examine_Green1() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[Green1].Examine({'message': 'System:CheckItemSelect'})
        if !Dialog.GetLastResult() {
            Book[Green1].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})

            fork {
                Dialog.Show({'message': 'System:ReadItemSelect'})
            } {
                Book[Green1].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
            }

            Book[Green1].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}

void examine_Orange2() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[Orange2].Examine({'message': 'System:CheckMapandMemo'})
        if !Dialog.GetLastResult() {
            Book[Orange2].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})

            fork {
                Dialog.Show({'message': 'System:ReadMapandMemo'})
            } {
                Book[Orange2].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
            }

            Book[Orange2].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}

void examine_Red3() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[Red3].Examine({'message': 'System:CheckTurnAttack'})
        if !Dialog.GetLastResult() {
            Book[red3].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})

            fork {
                Dialog.Show({'message': 'System:ReadTurnAttack'})
            } {
                Book[red3].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
            }

            Book[red3].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}

void examine_Blue2() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[Blue2].Examine({'message': 'System:CheckWarpRule'})
        if !Dialog.GetLastResult() {
            Book[Blue2].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})

            fork {
                Dialog.Show({'message': 'System:ReadWarpRule'})
            } {
                Book[Blue2].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
            }

            Book[Blue2].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}

void examine_Red1() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[Red1].Examine({'message': 'System:CheckLiftBomb'})
        if !Dialog.GetLastResult() {
            Book[Red1].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})

            fork {
                Dialog.Show({'message': 'System:ReadLiftBomb'})
            } {
                Book[Red1].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
            }

            Book[Red1].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}

void examine_Green3() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[Green3].Examine({'message': 'System:CheckIslandMap'})
        if !Dialog.GetLastResult() {
            Book[Red1].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})

            fork {
                Book[Red1].ShowMap()
            } {
                Book[Red1].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
            }

            Book[Red1].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}

void examine_Orange4() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[Orange4].Examine({'message': 'System:CheckSecretBook'})
        if !Dialog.GetLastResult() {
            Book[Orange4].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})
            if !Inventory.HasItem({'itemType': 44, 'count': 1}) {

                fork {
                    Dialog.Show({'message': 'System:BadSecretBook'})
                } {
                    Book[Orange4].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
                }

            } else {

                fork {
                    Dialog.Show({'message': 'System:CheckSecretBook1'})
                } {
                    Book[Orange4].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
                }

            }
            Book[Orange4].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}

void examine_TackleBook() {

    fork {
        Book.GenericExamineSequence({'examineLookAtMode': 5, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    } {
        Book[TackleBook].Examine({'message': 'System:CheckColorPower'})
        if !Dialog.GetLastResult() {
            Book[TackleBook].PlayAnimation({'name': 'open', 'blendTime': 0.10000000149011612})

            fork {
                Dialog.Show({'message': 'System:ReadColorPower'})
            } {
                Book[TackleBook].PlayAnimation({'name': 'open_wait', 'blendTime': 0.10000000149011612})
            }

            Book[TackleBook].PlayAnimation({'name': 'close', 'blendTime': 0.10000000149011612})
        }
    }

}
