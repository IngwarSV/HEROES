#include "WerewolfAttack.h"

WerewolfAttack::WerewolfAttack() {
            std::cout << " creating WerewolfAttack " << std::endl;
}

WerewolfAttack::~WerewolfAttack() {
            std::cout << " deleting WerewolfAttack " << std::endl;
}

void WerewolfAttack::mutationBite(Unit& enemy, Unit& attacker) {
    if ( enemy.getState().outOfHp() ) { return; }
    if ( enemy.getUnitMutation() == MUTATION::NONE ) {
        srand(time(NULL) + enemy.getState().getHp());
        int mutationBite = rand()%100;
        
                std::cout << "\tMutationBite:" << mutationBite << std::endl;
        if ( mutationBite < werewolfCreationProbability ) {
            enemy.creatureMutation(attacker.getUnitMutation(), nullptr, nullptr, new WerewolfState(enemy.getState().getName(), enemy.getState().getHp()*2, enemy.getState().getMaxHp()*2), new WerewolfAttack());
        }
    }
}

void WerewolfAttack::attack(Unit& enemy, Unit& attacker) {
    enemy.takeDamage(attacker.getState().getDmg());
    enemy.counterAttack(attacker);
    
    this->mutationBite(enemy, attacker);
}

void WerewolfAttack::counterAttack(Unit& enemy, Unit& counterAttacker) {
    enemy.takeDamage(counterAttacker.getState().getDmg() / 2);
}

