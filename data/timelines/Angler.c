-------- Event timeline: Angler --------
actors: 3
clips: 5
oneshots: 5
cuts: 2
duration: 770.0
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

Actor: Angler[0]
x36: 5
actions: ['PlayAreaOriginCameraAnimation', 'PlayAnimation', 'PlayTailorOtherChannel', 'BossShowUI', 'ModelVisibility', 'PlayTailorOtherChannelNoWait']
params: (none)


===== Timeline =====

[      0.0] E Angler[0] - PlayAreaOriginCameraAnimation (#1, xc=0)
               duration: 745.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: true
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[      0.0] E Angler[0] - PlayAnimation (#3, xc=1)
               duration: 770.0
               blendTime: 0.0
               name: demo_pop
[    255.0] E Dialog[0] - ShowTL (#0, xc=0)
               duration: 250.0
               message: Scenario:Lv4BossAngler
[    505.0] L Dialog[0] - ShowTL (#0, xc=0)
[    545.0] E Angler[0] - PlayTailorOtherChannel (#4, xc=4)
               duration: 120.0
               channel: Radiant_Line
               index: 0
               restart: false
[    665.0] L Angler[0] - PlayTailorOtherChannel (#4, xc=4)
[    745.0] L Angler[0] - PlayAreaOriginCameraAnimation (#1, xc=0)
[    770.0] L Angler[0] - PlayAnimation (#3, xc=1)
[    824.0] E Angler[0] - PlayAreaOriginCameraAnimation (#2, xc=0)
               duration: 824.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[   1648.0] L Angler[0] - PlayAreaOriginCameraAnimation (#2, xc=0)
