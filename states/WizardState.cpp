#include <iostream>
#include "WizardState.h"

WizardState::WizardState(const std::string& name, int health, int damage, int mana) : SpellCasterState(name, health, damage, mana) {
    std::cout << " creating WizardState " << std::endl;
}

WizardState::~WizardState() {
    std::cout << " deleting WizardState " << std::endl;
}
