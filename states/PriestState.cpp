#include <iostream>
#include "PriestState.h"

PriestState::PriestState(const std::string& name, int health, int damage, int mana) : SpellCasterState(name, health, damage, mana) {
    std::cout << " creating PriestState " << std::endl;
}

PriestState::~PriestState() {
    std::cout << " deleting PriestState " << std::endl;
}
