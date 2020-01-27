#include <iostream>
#include "WarlockState.h"

WarlockState::WarlockState(const std::string& name, int health, int damage, int mana) : SpellCasterState(name, health, damage, mana) {
    std::cout << " creating WarlockState " << std::endl;
}

WarlockState::~WarlockState() {
    std::cout << " deleting WarlockState " << std::endl;
}
