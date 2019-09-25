-------- EventFlow: GreatFairy --------

Actor: Link
entrypoint: None()
actions: ['Heal', 'PlayTailorOtherChannelEx', 'SetDisablePowerUpEffect', 'MoveToTargetLinkedPoint', 'AimCompassPoint']
queries: ['CheckDamage']
params: None

Actor: GreatFairy
entrypoint: None()
actions: ['Destroy', 'Talk', 'SetFacialExpression', 'PlayAnimation', 'PlayOneshotSE']
queries: []
params: None

Actor: Timer
entrypoint: None()
actions: ['Wait']
queries: []
params: None

Actor: Hud
entrypoint: None()
actions: ['SetHeartUpdateEnable']
queries: []
params: None

void talk() {
    Link.MoveToTargetLinkedPoint({'speed': 0, 'index': 0, 'actor': ActorIdentifier(name="GreatFairy"), 'timeOut': 7.0})
    Link.AimCompassPoint({'direction': 2, 'duration': 0.4000000059604645, 'withoutTurn': False})
    if !Link.CheckDamage({'amount': 1}) {
        GreatFairy.Talk({'message': 'SubEvent:FairySpring2'})
    } else {
        Link.SetDisablePowerUpEffect({'sound': True, 'effect': True, 'materialAnim': True})
        GreatFairy.SetFacialExpression({'expression': 'smile'})
        GreatFairy.Talk({'message': 'SubEvent:FairySpring'})
        GreatFairy.SetFacialExpression({'expression': 'normal'})

        fork {
            GreatFairy.PlayAnimation({'name': 'heel_st', 'blendTime': 0.20000000298023224})
        } {
            Timer.Wait({'time': 0.30000001192092896})
            GreatFairy.PlayOneshotSE({'label': 'SE_NPC_GREATFAIRY_002', 'volume': 1.0, 'pitch': 1.0})
        }


        fork {
            GreatFairy.PlayAnimation({'name': 'heel_lp', 'blendTime': 0.20000000298023224})
        } {
            Timer.Wait({'time': 1.0})
        }

        Hud.SetHeartUpdateEnable({'enable': True})

        fork {
            Link.Heal({'amount': 99})
        } {
            Timer.Wait({'time': 1.2000000476837158})
        } {
            Link.PlayTailorOtherChannelEx({'time': 0.0, 'channel': 'GreatFairy_Heal', 'restart': False, 'index': 0})
        }

        GreatFairy.PlayAnimation({'blendTime': 0.20000000298023224, 'name': 'depop'})
        GreatFairy.Destroy()
        Link.SetDisablePowerUpEffect({'effect': False, 'sound': False, 'materialAnim': False})
    }
}
