-------- EventFlow: Pot --------

Actor: Dialog
entrypoint: None()
actions: ['Show']
queries: []
params: None

void nolift_pot() {
    Dialog.Show({'message': 'System:TouchLiftHeavyObject'})
}
