-------- EventFlow: FieldOwlStatue --------

Actor: FieldOwlStatue
entrypoint: None()
actions: ['Examine', 'SetFlagFromLevelEditorArgument', 'PlayAnimation', 'GenericExamineSequence']
queries: ['CheckFlagFromLevelEditorArgument']
params: None

void examine_tarutaru() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:WestTalTalStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void examine_anaboko() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:PotholeStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void examine_ukuku() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:UkukuStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void examine_kouti() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:TalTalHeightStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void examine_area05() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:MarthaStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void examine_yana() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:YarnaStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void examine_kao() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:FaceStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void examine_sannmyaku() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:EastTalTalStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void examine_ride() {

    fork {

        call FieldOwlStatue_Common()

    } {
        FieldOwlStatue.Examine({'message': 'Hint:RapidsRideStoneOwl'})
    } {
        FieldOwlStatue.GenericExamineSequence({'examineLookAtMode': 4, 'aimFromPlayer': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
    }

}

void FieldOwlStatue_Common() {
    if !FieldOwlStatue.CheckFlagFromLevelEditorArgument({'argumentIndex': 1}) {
        FieldOwlStatue.PlayAnimation({'name': 'on', 'blendTime': 0.10000000149011612})
        FieldOwlStatue.PlayAnimation({'name': 'on_wait', 'blendTime': 0.10000000149011612})
        Event23:
        FieldOwlStatue.SetFlagFromLevelEditorArgument({'argumentIndex': 1, 'value': True})
    } else {
        goto Event23
    }
}
