-------- Event timeline: DeguZol --------
actors: 2
clips: 3
oneshots: 3
cuts: 2
duration: 601.0
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

Actor: DeguZol[0]
x36: 4
actions: ['PlayAnimation', 'PlayAreaOriginCameraAnimation', 'PlayTailorOtherChannel', 'BossShowUI']
params: (none)


===== Timeline =====

[      0.0] E DeguZol[0] - PlayAnimation (#0, xc=0)
               duration: 630.0
               blendTime: 0.0
               name: demo_pop
[      0.0] E DeguZol[0] - PlayAreaOriginCameraAnimation (#1, xc=2)
               duration: 600.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[    360.0] E DeguZol[0] - PlayTailorOtherChannel (#2, xc=3)
               duration: 120.0
               channel: Radiant_Line
               index: 0
               restart: false
[    480.0] L DeguZol[0] - PlayTailorOtherChannel (#2, xc=3)
[    600.0] L DeguZol[0] - PlayAreaOriginCameraAnimation (#1, xc=2)
[    630.0] L DeguZol[0] - PlayAnimation (#0, xc=0)
