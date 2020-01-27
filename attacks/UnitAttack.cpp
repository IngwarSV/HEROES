#include "UnitAttack.h"

UnitAttack::UnitAttack() {
    std::cout << "\tcreating UnitAttack" << std::endl;
}

UnitAttack::~UnitAttack() {
    std::cout << "\tdeleting UnitAttack" << std::endl;
}

void UnitAttack::attack(Unit& enemy, Unit& attacker) {
    enemy.takeDamage(attacker.getState().getDmg());
    enemy.counterAttack(attacker);
}

void UnitAttack::counterAttack(Unit& enemy, Unit& counterAttacker) {
    enemy.takeDamage(counterAttacker.getState().getDmg() / 2);
}
