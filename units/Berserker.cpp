#include "Berserker.h"

Berserker::Berserker(const std::string& name, const std::string& type, int health, int damage) : Unit(type, new BerserkerState(name, health, damage), new UnitAttack()) {
    std::cout << " creating Berserker " << std::endl;
}

Berserker::~Berserker() {
    std::cout << " deleting Berserker " << std::endl;
}

// std::ostream& operator<<(std::ostream& out, const Berserker& berserker) {
//     out << "Berserker [" << berserker.getState() << ']';
//     return out;
// }
