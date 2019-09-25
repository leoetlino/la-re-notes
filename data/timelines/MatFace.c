-------- Event timeline: MatFace --------
actors: 3
clips: 5
oneshots: 4
cuts: 2
duration: 1141.0
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

Actor: MatFace[0]
x36: 5
actions: ['PlayAreaOriginCameraAnimation', 'PlayAnimation', 'PlayTailorOtherChannel', 'BossShowUI']
params: (none)


===== Timeline =====

[      0.0] E MatFace[0] - PlayAreaOriginCameraAnimation (#2, xc=0)
               duration: 1140.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[      0.0] E MatFace[0] - PlayAnimation (#3, xc=2)
               duration: 1140.0
               blendTime: 0.10000000149011612
               name: demo_pop
[    360.0] E Dialog[0] - ShowTL (#0, xc=0)
               duration: 250.0
               message: Scenario:Lv6BossFacade1
[    610.0] L Dialog[0] - ShowTL (#0, xc=0)
[    630.0] E Dialog[0] - ShowTL (#1, xc=0)
               duration: 230.0
               message: Scenario:Lv6BossFacade2
[    860.0] L Dialog[0] - ShowTL (#1, xc=0)
[    900.0] E MatFace[0] - PlayTailorOtherChannel (#4, xc=4)
               duration: 120.0
               channel: Radiant_Line
               index: 0
               restart: false
[   1020.0] L MatFace[0] - PlayTailorOtherChannel (#4, xc=4)
[   1140.0] L MatFace[0] - PlayAreaOriginCameraAnimation (#2, xc=0)
[   1140.0] L MatFace[0] - PlayAnimation (#3, xc=2)
