#include "PriestAttack.h"

PriestAttack::PriestAttack() { std::cout << " creating PriestAttack " << std::endl; }

PriestAttack::~PriestAttack() { std::cout << " deleting PriestAttack " << std::endl; }

void PriestAttack::attack(Unit& enemy, Unit& attacker) {
    if ( enemy.getState().isUnDead ) {
        enemy.takeDamage(attacker.getState().getDmg() * 2);
    } else {
        enemy.takeDamage(attacker.getState().getDmg());
    }
    enemy.counterAttack(attacker);
}

void PriestAttack::counterAttack(Unit& enemy, Unit& counterAttacker) {
    if ( enemy.getState().isUnDead ) {
        enemy.takeDamage(counterAttacker.getState().getDmg());
    } else {
        enemy.takeDamage(counterAttacker.getState().getDmg() / 2);
    }
}
