#include "UnitState.h"

UnitState::UnitState(const std::string& name, int health, int maxHealth, int damage, bool isUndead) {
            std::cout << "\tcreating UnitState" << std::endl;
    this->name = name;
    this->hp = health;
    this->maxHp = maxHealth;
    this->dmg = damage;
    this->isUnDead = isUndead;
}

UnitState::~UnitState() {
            std::cout << "\tdeleting UnitState" << std::endl;
}

bool UnitState::outOfHp() const {
    return this->hp == 0;
}

const std::string& UnitState::getName() const {
    return this->name;
}

int UnitState::getHp() const {
    return this->hp;
}

int UnitState::getMaxHp() const {
    return this->maxHp;
}

int UnitState::getDmg() const {
    return this->dmg;
}

void UnitState::setName(const std::string& name) {
    this->name = name;
}

void UnitState::takeDamage(int dmg) {
    this->hp -= dmg;
    if ( this->hp < 1 ) {
        this->hp = 0;
    }
}

void UnitState::takeMagicDamage(int dmg) {
    this->hp -= dmg;
    if ( this->hp < 1 ) {
        this->hp = 0;
    }
}

void UnitState::takeTreatment(int hp) {
    this->hp += hp;
    if ( this->hp > maxHp ) {
        this->hp = maxHp;
    }
}

std::ostream& operator<<(std::ostream& out, const UnitState& state) {
    out << state.getName() << ", ";
    out << state.getMaxHp() << ":" << state.getHp() << ", ";
    out << state.getDmg();
    return out;
}
