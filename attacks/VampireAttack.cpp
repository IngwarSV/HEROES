#include "VampireAttack.h"

VampireAttack::VampireAttack() {
    std::cout << " creating VampireAttack " << std::endl;
}

VampireAttack::~VampireAttack() {
    std::cout << " deleting VampireAttack " << std::endl;
}

void VampireAttack::mutationBite(Unit& enemy, Unit& attacker) {
    if ( enemy.getState().outOfHp() ) { return; }
    if ( enemy.getUnitMutation() == MUTATION::NONE ) {
        srand(time(NULL) + enemy.getState().getHp());
        int mutationBite = rand()%100;
                std::cout << "\tMutationBite:" << mutationBite << std::endl;
        if ( mutationBite < vampireCreationProbability ) {
            enemy.creatureMutation(attacker.getUnitMutation(), nullptr, new VampireAttack());
            enemy.getState().setName(enemy.getState().getName() + "_Vamp");
            enemy.getState().isUnDead = true;
        }
    }
}

void VampireAttack::attack(Unit& enemy, Unit& attacker) {
    int bleeding = enemy.getState().getHp() / vampireBleedingDamage;
    enemy.takeDamage(attacker.getState().getDmg() + bleeding);
    attacker.takeTreatment(bleeding);
    
    std::cout << "\tbleeding:" << bleeding << std::endl;
    enemy.counterAttack(attacker);
    this->mutationBite(enemy, attacker);
}

void VampireAttack::counterAttack(Unit& enemy, Unit& counterAttacker) {
    int bleeding = enemy.getState().getHp() / vampireBleedingDamage;
    enemy.takeDamage(counterAttacker.getState().getDmg() / 2 + bleeding);
    counterAttacker.takeTreatment(bleeding);
}
