-------- EventFlow: GhostsGrave --------

Actor: GhostsGrave
entrypoint: None()
actions: ['Examine', 'PlayTailorOtherChannelEx', 'StopTailorOtherChannel']
queries: []
params: None

void Use() {
    GhostsGrave.PlayTailorOtherChannelEx({'channel': 'Grave_Powder', 'time': 0.5, 'restart': False, 'index': 0})
    GhostsGrave.Examine({'message': 'Npc:GhostGrave'})
    GhostsGrave.StopTailorOtherChannel({'channel': 'Grave_Powder', 'index': 0})
}
