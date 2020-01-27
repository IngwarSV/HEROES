#include "DemonState.h"

DemonState::DemonState(const std::string& name, int health, int damage) : UnitState (name, health, health, damage) {
    std::cout << " creating DemonState " << std::endl;
}

DemonState::~DemonState() {
    std::cout << " deleting DemonState " << std::endl;
}

void DemonState::takeDamage(int dmg) {
    this->hp -= dmg / 2;
    if ( this->hp < 1 ) {
        this->hp = 0;
    }
}

void DemonState::takeMagicDamage(int dmg) {
    this->hp -= dmg * 2;
    if ( this->hp < 1 ) {
        this->hp = 0;
    }
}

void DemonState::takeTreatment(int hp) {}
