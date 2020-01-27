#include "SoldierState.h"

SoldierState::SoldierState(const std::string& name, int health, int damage) : UnitState (name, health, health, damage) {
    std::cout << " creating SoldierState " << std::endl;
}

SoldierState::~SoldierState() {
    std::cout << " deleting SoldierState " << std::endl;
}

