#include "Demon.h"

Demon::Demon(Unit* warlock, const std::string& name, const std::string& type,const std::string& mutation, int health, int damage) : Unit(type, new DemonState(name, health, damage), new UnitAttack(), mutation) {
    this->master = warlock;
    this->getObserversList()->addObserver(this->master);
    std::cout << " creating Demon " << std::endl;
}

Demon::~Demon() {
    std::cout << " deleting Demon " << std::endl;
}

Unit* Demon::getMaster() const {
    return this->master;
}

void Demon::demonIsDestroyed() {
    this->master = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Demon& demon) {
    out << demon.getUnitType() << " [" << demon.getState() << "] ";
    if ( demon.getMaster() ) {
        out << "is mastered by " << demon.getMaster()->getUnitType() << " "<< demon.getMaster()->getState().getName() << '\n';
    } else {
        out << "is destroyed" << '\n';
    }
    return out;
}
