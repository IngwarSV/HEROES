#include "SpellCasterAttack.h"

SpellCasterAttack::SpellCasterAttack() { std::cout << " creating SpellCasterAttack " << std::endl; }

SpellCasterAttack::~SpellCasterAttack() { std::cout << " deleting SpellCasterAttack " << std::endl; }

// void SpellCasterAttack::magicAttack(Unit& enemy, SpellCaster& attacker) {
//     enemy.takeMagicDamage(attacker.getState().getMagicDmg());
// }

// void SpellCasterAttack::heal(Unit& ally, SpellCaster& healer) {
//     ally.takeTreatment(healer.getState().getTreatment());
// }
