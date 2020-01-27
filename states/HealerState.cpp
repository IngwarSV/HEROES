#include <iostream>
#include "HealerState.h"

HealerState::HealerState(const std::string& name, int health, int damage, int mana) : SpellCasterState(name, health, damage, mana) {
    std::cout << " creating HealerState " << std::endl;
}

HealerState::~HealerState() {
    std::cout << " deleting HealerState " << std::endl;
}
