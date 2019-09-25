-------- Event timeline: DeguFlame --------
actors: 2
clips: 3
oneshots: 5
cuts: 2
duration: 496.0
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

Actor: DeguFlame[0]
x36: 6
actions: ['PlayAreaOriginCameraAnimation', 'PlayAnimation', 'PlayTailorOtherChannel', 'BossShowUI', 'PlayTailorOtherChannelNoWait', 'ModelVisibility']
params: (none)


===== Timeline =====

[      0.0] E DeguFlame[0] - PlayAreaOriginCameraAnimation (#0, xc=0)
               duration: 519.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[      0.0] E DeguFlame[0] - PlayAnimation (#1, xc=1)
               duration: 519.0
               blendTime: 0.10000000149011612
               name: demo_pop
[    275.0] E DeguFlame[0] - PlayTailorOtherChannel (#2, xc=5)
               duration: 120.0
               channel: Radiant_Line
               index: 0
               restart: false
[    395.0] L DeguFlame[0] - PlayTailorOtherChannel (#2, xc=5)
[    519.0] L DeguFlame[0] - PlayAreaOriginCameraAnimation (#0, xc=0)
[    519.0] L DeguFlame[0] - PlayAnimation (#1, xc=1)
