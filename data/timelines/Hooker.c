-------- Event timeline: Hooker --------
actors: 3
clips: 5
oneshots: 21
cuts: 2
duration: 1470.0
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

Actor: Camera[0]
x36: 1
actions: ['Reset']
params: (none)

Actor: Hooker[0]
x36: 14
actions: ['PlayAreaOriginCameraAnimation', 'PlayAnimation', 'PlayTailorOtherChannel', 'PlayOneshotSE', 'BossShowUI', 'BreakFloor', 'BreakWall', 'PlayTailorOtherChannelNoWait', 'ModelVisibility']
params: (none)


===== Timeline =====

[      0.0] E Hooker[0] - PlayAreaOriginCameraAnimation (#2, xc=0)
               duration: 1455.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[      0.0] E Hooker[0] - PlayAnimation (#3, xc=1)
               duration: 1470.0
               blendTime: 0.10000000149011612
               name: demo_pop
[     40.0] E Dialog[0] - ShowTL (#0, xc=0)
               duration: 240.0
               message: Scenario:Lv5BossSlimeEel1
[    280.0] L Dialog[0] - ShowTL (#0, xc=0)
[    300.0] E Dialog[0] - ShowTL (#1, xc=0)
               duration: 240.0
               message: Scenario:Lv5BossSlimeEel2
[    540.0] L Dialog[0] - ShowTL (#1, xc=0)
[   1160.0] E Hooker[0] - PlayTailorOtherChannel (#4, xc=4)
               duration: 120.0
               channel: Radiant_Line
               index: 0
               restart: false
[   1280.0] L Hooker[0] - PlayTailorOtherChannel (#4, xc=4)
[   1455.0] L Hooker[0] - PlayAreaOriginCameraAnimation (#2, xc=0)
[   1470.0] L Hooker[0] - PlayAnimation (#3, xc=1)
