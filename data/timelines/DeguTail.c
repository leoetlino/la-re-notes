-------- Event timeline: DeguTail --------
actors: 3
clips: 4
oneshots: 3
cuts: 2
duration: 626.0
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

Actor: DeguTail[0]
x36: 4
actions: ['PlayAreaOriginCameraAnimation', 'PlayAnimation', 'PlayTailorOtherChannel', 'BossShowUI']
params: (none)


===== Timeline =====

[      0.0] E DeguTail[0] - PlayAreaOriginCameraAnimation (#1, xc=0)
               duration: 705.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[      0.0] E DeguTail[0] - PlayAnimation (#2, xc=2)
               duration: 706.0
               blendTime: 0.10000000149011612
               name: demo_pop
[    125.0] E Dialog[0] - ShowTL (#0, xc=0)
               duration: 250.0
               message: Scenario:Lv1BossMoldorm
[    375.0] L Dialog[0] - ShowTL (#0, xc=0)
[    425.0] E DeguTail[0] - PlayTailorOtherChannel (#3, xc=3)
               duration: 120.0
               channel: Radiant_Line
               index: 0
               restart: false
[    545.0] L DeguTail[0] - PlayTailorOtherChannel (#3, xc=3)
[    705.0] L DeguTail[0] - PlayAreaOriginCameraAnimation (#1, xc=0)
[    706.0] L DeguTail[0] - PlayAnimation (#2, xc=2)
