-------- EventFlow: Rabbit --------

Actor: Rabbit[RabbitA]
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetFacialExpression']
queries: []
params: None

Actor: Rabbit[RabbitC]
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetFacialExpression']
queries: []
params: None

Actor: Rabbit[RabbitB]
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetFacialExpression']
queries: []
params: None

Actor: Rabbit[RabbitD]
entrypoint: None()
actions: ['Talk', 'GenericTalkSequence', 'SetFacialExpression']
queries: []
params: None

Actor: Link
entrypoint: None()
actions: ['SetEquipmentVisibility']
queries: ['WithMarin']
params: None

Actor: Inventory
entrypoint: None()
actions: []
queries: ['HasItem']
params: None

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

Actor: EventFlags
entrypoint: None()
actions: []
queries: ['CheckFlag']
params: None

void talk_rabbitA() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'count': 1, 'itemType': 46}) {

        fork {
            Rabbit[RabbitA].Talk({'message': 'Npc:Rabbit1ReturnMarin'})
        } {
            Rabbit[RabbitA].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'count': 1, 'itemType': 50}) {
        if !Link.WithMarin() {
            if !EventFlags.CheckFlag({'symbol': 'MarinJoin'}) {

                fork {
                    Rabbit[RabbitA].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
                } {
                    Rabbit[RabbitA].Talk({'message': 'Npc:Rabbit1BeforeMarin'})
                }

                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {
                Event125:

                fork {
                    Rabbit[RabbitA].Talk({'message': 'Npc:Rabbit1ReturnMarin'})
                } {
                    Rabbit[RabbitA].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
                }

                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        } else {

            fork {
                Rabbit[RabbitA].SetFacialExpression({'expression': 'excite'})
            } {
                Rabbit[RabbitA].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Rabbit[RabbitA].Talk({'message': 'Npc:RabbitComeMarin'})
            }


            fork {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                Rabbit[RabbitA].SetFacialExpression({'expression': 'normal'})
            }

        }
    } else {
        goto Event125
    }
}

void talk_rabbitB() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {

        fork {
            Rabbit[RabbitB].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Rabbit[RabbitB].SetFacialExpression({'expression': 'weak'})
        } {
            Rabbit[RabbitB].Talk({'message': 'Npc:Rabbit2BeforeMarin'})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            Rabbit[RabbitB].SetFacialExpression({'expression': 'normal'})
        }

    } else
    if !Inventory.HasItem({'count': 1, 'itemType': 49}) {
        if !Link.WithMarin() {
            if !EventFlags.CheckFlag({'symbol': 'WalrusAwaked'}) {

                fork {
                    Rabbit[RabbitB].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
                } {
                    Rabbit[RabbitB].SetFacialExpression({'expression': 'weak'})
                } {
                    Rabbit[RabbitB].Talk({'message': 'Npc:Rabbit2BeforeMarin'})
                }


                fork {
                    Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
                } {
                    Rabbit[RabbitB].SetFacialExpression({'expression': 'normal'})
                }

            } else {
                Dialog.Show({'message': 'Npc:Animals'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        } else {

            fork {
                Rabbit[RabbitB].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Rabbit[RabbitB].SetFacialExpression({'expression': 'excite'})
            } {
                Rabbit[RabbitB].Talk({'message': 'Npc:RabbitComeMarin'})
            }


            fork {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                Rabbit[RabbitB].SetFacialExpression({'expression': 'normal'})
            }

        }
    } else {

        fork {
            Rabbit[RabbitB].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Rabbit[RabbitB].SetFacialExpression({'expression': 'weak'})
        } {
            Rabbit[RabbitB].Talk({'message': 'Npc:Rabbit2ReturnMarin'})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            Rabbit[RabbitB].SetFacialExpression({'expression': 'normal'})
        }

    }
}

void talk_rabbitC() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {

        fork {
            Rabbit[RabbitC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Rabbit[RabbitC].Talk({'message': 'Npc:Rabbit3BeforeMarin'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    } else
    if !Inventory.HasItem({'count': 1, 'itemType': 49}) {
        if !Link.WithMarin() {
            if !EventFlags.CheckFlag({'symbol': 'WalrusAwaked'}) {

                fork {
                    Rabbit[RabbitC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
                } {
                    Rabbit[RabbitC].Talk({'message': 'Npc:Rabbit3BeforeMarin'})
                }

                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } else {
                Dialog.Show({'message': 'Npc:Animals'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        } else {

            fork {
                Rabbit[RabbitC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Rabbit[RabbitC].SetFacialExpression({'expression': 'excite'})
            } {
                Rabbit[RabbitC].Talk({'message': 'Npc:RabbitComeMarin'})
            }


            fork {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                Rabbit[RabbitC].SetFacialExpression({'expression': 'normal'})
            }

        }
    } else {

        fork {
            Rabbit[RabbitC].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Rabbit[RabbitC].SetFacialExpression({'expression': 'weak'})
        } {
            Rabbit[RabbitC].Talk({'message': 'Npc:Rabbit3ReturnMarin'})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            Rabbit[RabbitC].SetFacialExpression({'expression': 'normal'})
        }

    }
}

void talk_rabbitD() {
    Link.SetEquipmentVisibility({'visibility': False, 'ocarina': False, 'flipper': False})
    if !Inventory.HasItem({'itemType': 46, 'count': 1}) {
        Event44:

        fork {
            Rabbit[RabbitD].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Rabbit[RabbitD].SetFacialExpression({'expression': 'weak'})
        } {
            Rabbit[RabbitD].Talk({'message': 'Npc:Rabbit4BeforeMarin'})
        }


        fork {
            Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
        } {
            Rabbit[RabbitD].SetFacialExpression({'expression': 'normal'})
        }

    } else
    if !Inventory.HasItem({'count': 1, 'itemType': 49}) {
        if !Link.WithMarin() {
            if !EventFlags.CheckFlag({'symbol': 'WalrusAwaked'}) {
                goto Event44
            } else {
                Dialog.Show({'message': 'Npc:Animals'})
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            }
        } else {

            fork {
                Rabbit[RabbitD].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
            } {
                Rabbit[RabbitD].SetFacialExpression({'expression': 'excite'})
            } {
                Rabbit[RabbitD].Talk({'message': 'Npc:RabbitComeMarin'})
            }


            fork {
                Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
            } {
                Rabbit[RabbitD].SetFacialExpression({'expression': 'normal'})
            }

        }
    } else {

        fork {
            Rabbit[RabbitD].GenericTalkSequence({'aimToPlayer': True, 'aimFromPlayer': True, 'selfTalkAnim': True, 'playerTalkAnim': True, 'cameraLookAt': True, 'keepPersonalSpace': True, 'distanceOffset': 0.0})
        } {
            Rabbit[RabbitD].Talk({'message': 'Npc:Rabbit4ReturnMarin'})
        }

        Link.SetEquipmentVisibility({'visibility': True, 'ocarina': False, 'flipper': False})
    }
}
