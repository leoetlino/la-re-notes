-------- EventFlow: CraneGameButton --------

Actor: CraneGameButton
entrypoint: None()
actions: ['StartManualPlay']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['MoveToTargetActor', 'AimDegreeAngle']
queries: []
params: None

Actor: GameShopOwner
entrypoint: None()
actions: []
queries: ['CheckActorSwitch']
params: None

Actor: Hud
entrypoint: None()
actions: ['PlayOutAnim', 'SetOpenMenuEnable']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: ['SetLevelFlag']
queries: []
params: None

Actor: Audio
entrypoint: None()
actions: ['PlayOneshotSystemSE']
queries: []
params: None

void examine() {
    if !GameShopOwner.CheckActorSwitch({'switchIndex': 0}) {
        EventFlags.SetLevelFlag({'index': 5, 'value': True})

        call GameShopOwner.talk_button()

        if GameShopOwner.CheckActorSwitch({'switchIndex': 0}) {
            Event1:
            Link.MoveToTargetActor({'speed': 0, 'distance': 1.2000000476837158, 'actor': ActorIdentifier(name="CraneGameButton"), 'timeOut': 7.0})
            Hud.PlayOutAnim()
            Link.AimDegreeAngle({'angle': 180.0, 'duration': 0.4000000059604645, 'withoutTurn': False})
            Hud.SetOpenMenuEnable({'enable': False})

            fork {
                CraneGameButton.StartManualPlay()
            } {
                Audio.PlayOneshotSystemSE({'label': 'SE_MAP_CRANE_START', 'volume': 1.0, 'pitch': 1.0})
            }

        }
    } else {
        goto Event1
    }
}
