#include "Vampire.h"

Vampire::Vampire(const std::string& name, const std::string& type, const std::string& mutation, int health, int damage, bool isUndead) : Unit(type, new VampireState(name, health, damage, isUndead), new VampireAttack(), mutation) {
    std::cout << " creating Vampire " << std::endl;
}

Vampire::~Vampire() {
    std::cout << " deleting Vampire " << std::endl;
}

// std::ostream& operator<<(std::ostream& out, const Vampire& vampire) {
//     out << "Vampire [" << vampire.getState() << ']';
//     return out;
// }
