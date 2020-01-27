#include "Werewolf.h"

Werewolf::Werewolf(const std::string& name, const std::string& type, const std::string& mutation, int health, int damage, int alterHealth, int alterDamage) : Unit(type, new SoldierState(name, health, damage), new UnitAttack(), mutation, new WerewolfState(name, alterHealth, alterHealth, alterDamage), new WerewolfAttack()) {
    std::cout << " creating Werewolf " << std::endl;
}

Werewolf::~Werewolf() {
    std::cout << " deleting Werewolf " << std::endl;
}

// std::ostream& operator<<(std::ostream& out, const Werewolf& werewolf) {
//     out << "Werewolf [" << werewolf.getState() << ']';
//     return out;
// }
