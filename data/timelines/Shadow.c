-------- Event timeline: Shadow --------
actors: 2
clips: 5
oneshots: 3
cuts: 2
duration: 1215.0
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

Actor: Link[0]
x36: 1
actions: ['PlayAnimation']
params: (none)

Actor: ShadowZol[0]
x36: 3
actions: ['PlayAnimation', 'PlayAreaOriginCameraAnimation', 'PlayTailorOtherChannelNoWait']
params: (none)


===== Timeline =====

[      0.0] E ShadowZol[0] - PlayAnimation (#3, xc=0)
               duration: 1215.0
               blendTime: 0.10000000149011612
               name: demo_pop
[      0.0] E ShadowZol[0] - PlayAreaOriginCameraAnimation (#4, xc=1)
               duration: 1215.0
               aspectRatioCtrl: false
               chaseRatio: 1.0
               farClipDistanceCtrl: false
               lookAtDistanceCtrl: false
               name: demo_pop
               nearClipDistanceCtrl: false
               offsetX: 0.0
               offsetY: 0.0
               offsetZ: 0.0
[     50.0] E Link[0] - PlayAnimation (#0, xc=0)
               duration: 30.0
               blendTime: 0.20000000298023224
               name: ev_look_shadow_st
[     80.0] L Link[0] - PlayAnimation (#0, xc=0)
[     80.0] E Link[0] - PlayAnimation (#1, xc=0)
               duration: 190.0
               blendTime: 0.10000000149011612
               name: ev_look_shadow
[    270.0] L Link[0] - PlayAnimation (#1, xc=0)
[    270.0] E Link[0] - PlayAnimation (#2, xc=0)
               duration: 945.0
               blendTime: 0.30000001192092896
               name: wait
[   1215.0] L Link[0] - PlayAnimation (#2, xc=0)
[   1215.0] L ShadowZol[0] - PlayAnimation (#3, xc=0)
[   1215.0] L ShadowZol[0] - PlayAreaOriginCameraAnimation (#4, xc=1)
