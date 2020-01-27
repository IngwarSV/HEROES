#include "Healing.h"

Healing::Healing(int magicDamage, int cost, const std::string& formula): Spell(magicDamage, cost, formula) {}

void Healing::action(Unit* ally, Unit* healer, int magicDamage) {
    std::cout << "Heal!" << std::endl;
    if ( ally ) {
        ally->takeTreatment(magicDamage);
    }
}
