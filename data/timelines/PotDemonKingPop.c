-------- Event timeline: PotDemonKingPop --------
actors: 4
clips: 5
oneshots: 6
cuts: 2
duration: 1122.0
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

Actor: Dialog[0]
x36: 1
actions: ['ShowTL']
params: (none)

Actor: PotDemonPot[0]
x36: 1
actions: ['PlayAnimation']
params: (none)

Actor: Camera[0]
x36: 1
actions: ['ApplyPreset']
params: (none)

Actor: PotDemonKing[0]
x36: 5
actions: ['PlayAreaOriginCameraAnimation', 'PlayAnimation', 'PlayTailorOtherChannel', 'BossShowUI', 'GenerateMagic']
params: (none)


===== Timeline =====

[      0.0] E PotDemonPot[0] - PlayAnimation (#1, xc=0)
               duration: 1122.0
               blendTime: 0.0
               name: demo_pop
[      0.0] E PotDemonKing[0] - PlayAreaOriginCameraAnimation (#2, xc=0)
               duration: 1042.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[      0.0] E PotDemonKing[0] - PlayAnimation (#3, xc=1)
               duration: 1122.0
               blendTime: 0.0
               name: demo_pop
[    350.0] E Dialog[0] - ShowTL (#0, xc=0)
               duration: 240.0
               message: Scenario:Lv2BossGenie
[    590.0] L Dialog[0] - ShowTL (#0, xc=0)
[    650.0] E PotDemonKing[0] - PlayTailorOtherChannel (#4, xc=4)
               duration: 180.0
               channel: Radiant_Line
               index: 0
               restart: false
[    830.0] L PotDemonKing[0] - PlayTailorOtherChannel (#4, xc=4)
[   1042.0] L PotDemonKing[0] - PlayAreaOriginCameraAnimation (#2, xc=0)
[   1122.0] L PotDemonPot[0] - PlayAnimation (#1, xc=0)
[   1122.0] L PotDemonKing[0] - PlayAnimation (#3, xc=1)
