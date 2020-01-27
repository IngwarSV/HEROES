#include "Soldier.h"

Soldier::Soldier(const std::string& name, const std::string& type,const std::string& mutation, int health, int damage) : Unit(type, new SoldierState(name, health, damage), new UnitAttack(), mutation) {
    std::cout << " creating Soldier " << std::endl;
}

Soldier::~Soldier() {
    std::cout << " deleting Soldier " << std::endl;
}

// std::ostream& operator<<(std::ostream& out, const Soldier& soldier) {
//     out << "Soldier [" << soldier.getState() << ']';
//     return out;
// }
