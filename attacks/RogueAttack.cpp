#include "RogueAttack.h"

RogueAttack::RogueAttack() {}

RogueAttack::~RogueAttack() {}

void RogueAttack::attack(Unit& enemy, Unit& attacker) {
    enemy.takeDamage(attacker.getState().getDmg());
}

void RogueAttack::counterAttack(Unit& enemy, Unit& counterAttacker) {
    enemy.takeDamage(counterAttacker.getState().getDmg() / 2);
}
