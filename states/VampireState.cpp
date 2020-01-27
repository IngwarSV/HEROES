#include "VampireState.h"

VampireState::VampireState(const std::string& name, int health, int damage, bool isUndead) : UnitState (name, health, health, damage, isUndead) {
    std::cout << " creating VampireState " << std::endl;
}

VampireState::~VampireState() {
    std::cout << " deleting VampireState " << std::endl;
}
