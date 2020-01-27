#include <iostream>
#include "NecromancerState.h"

NecromancerState::NecromancerState(const std::string& name, int health, int damage, int mana, bool isUndead) : SpellCasterState(name, health, damage, mana, isUndead) {
    std::cout << " creating NecromancerState " << std::endl;
}

NecromancerState::~NecromancerState() {
    std::cout << " deleting NecromancerState " << std::endl;
}
