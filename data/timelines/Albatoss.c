-------- Event timeline: Albatoss --------
actors: 6
clips: 7
oneshots: 7
cuts: 2
duration: 1288.0
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

Actor: AlbatossPiccolo[Right]
x36: 1
actions: ['PlayAnimation']
params: (none)

Actor: AlbatossPiccolo[Left]
x36: 1
actions: ['PlayAnimation']
params: (none)

Actor: Dialog[0]
x36: 1
actions: ['ShowTL']
params: (none)

Actor: Albatoss[0]
x36: 4
actions: ['PlayAreaOriginCameraAnimation', 'PlayAnimation', 'PlayTailorOtherChannel', 'ModelVisibility', 'BossShowUI']
params: (none)

Actor: Link[0]
x36: 1
actions: ['AimActorLinkedPoint', 'ResetAim']
params: (none)


===== Timeline =====

[      0.0] E AlbatossPiccolo[Right] - PlayAnimation (#0, xc=0)
               duration: 1288.0
               blendTime: 0.10000000149011612
               name: demo_pop
[      0.0] E AlbatossPiccolo[Left] - PlayAnimation (#1, xc=0)
               duration: 1288.0
               blendTime: 0.10000000149011612
               name: demo_pop_2
[      0.0] E Albatoss[0] - PlayAreaOriginCameraAnimation (#4, xc=0)
               duration: 1288.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: true
               lookAtDistanceCtrl: true
               name: demo_pop
               nearClipDistanceCtrl: true
               offsetX: 2.0
               offsetY: 10.0
               offsetZ: 0.0
[      0.0] E Albatoss[0] - PlayAnimation (#5, xc=2)
               duration: 1288.0
               blendTime: 0.10000000149011612
               name: demo_pop
[     20.0] E Dialog[0] - ShowTL (#2, xc=0)
               duration: 240.0
               message: Scenario:Lv7BossEvilEagle1
[    260.0] L Dialog[0] - ShowTL (#2, xc=0)
[    280.0] E Dialog[0] - ShowTL (#3, xc=0)
               duration: 240.0
               message: Scenario:Lv7BossEvilEagle2
[    520.0] L Dialog[0] - ShowTL (#3, xc=0)
[    930.0] E Albatoss[0] - PlayTailorOtherChannel (#6, xc=3)
               duration: 120.0
               channel: Radiant_Line
               index: 0
               restart: false
[   1050.0] L Albatoss[0] - PlayTailorOtherChannel (#6, xc=3)
[   1288.0] L AlbatossPiccolo[Right] - PlayAnimation (#0, xc=0)
[   1288.0] L AlbatossPiccolo[Left] - PlayAnimation (#1, xc=0)
[   1288.0] L Albatoss[0] - PlayAreaOriginCameraAnimation (#4, xc=0)
[   1288.0] L Albatoss[0] - PlayAnimation (#5, xc=2)
