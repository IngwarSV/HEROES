#include "Fireball.h"

Fireball::Fireball(int magicDamage, int cost, const std::string& formula): Spell(magicDamage, cost, formula) {}

void Fireball::action(Unit* enemy, Unit* attacker, int magicDamage) {
    std::cout << "Fireball!" << std::endl;
    if ( enemy ) {
        enemy->takeMagicDamage(magicDamage);
    }
}


