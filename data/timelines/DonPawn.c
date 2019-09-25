-------- Event timeline: DonPawn --------
actors: 3
clips: 4
oneshots: 3
cuts: 2
duration: 656.0
params: (none)

===== Cuts =====

Cut: cut1
start time: 0.0
x4: 0
params: (none)

Cut: cut01
start time: 0.0
x4: 0
params: (none)


===== Actors =====

Actor: Camera[0]
x36: 1
actions: ['Reset']
params: (none)

Actor: Dialog[0]
x36: 1
actions: ['ShowTL']
params: (none)

Actor: DonPawn[0]
x36: 4
actions: ['PlayAreaOriginCameraAnimation', 'PlayAnimation', 'PlayTailorOtherChannel', 'BossShowUI']
params: (none)


===== Timeline =====

[      0.0] E DonPawn[0] - PlayAreaOriginCameraAnimation (#1, xc=0)
               duration: 630.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[      0.0] E DonPawn[0] - PlayAnimation (#2, xc=1)
               duration: 630.0
               blendTime: 0.10000000149011612
               name: demo_pop
[    235.0] E Dialog[0] - ShowTL (#0, xc=0)
               duration: 120.0
               message: SubEvent:BattleEvilOrb
[    355.0] L Dialog[0] - ShowTL (#0, xc=0)
[    415.0] E DonPawn[0] - PlayTailorOtherChannel (#3, xc=3)
               duration: 120.0
               channel: Radiant_Line
               index: 0
               restart: false
[    535.0] L DonPawn[0] - PlayTailorOtherChannel (#3, xc=3)
[    630.0] L DonPawn[0] - PlayAreaOriginCameraAnimation (#1, xc=0)
[    630.0] L DonPawn[0] - PlayAnimation (#2, xc=1)
