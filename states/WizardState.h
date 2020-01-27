#ifndef WIZARDSTATE_H
#define WIZARDSTATE_H

#include <iostream>
#include <string>
#include "SpellCasterState.h"
#include "../Specifications.h"


class WizardState : public SpellCasterState {
    public:
        WizardState(const std::string& name, int health = static_cast<int>(HP::WIZARD), int damage = static_cast<int>(DMG::WIZARD), int mana =  static_cast<int>(MANA::WIZARD));
        virtual ~WizardState();
};

#endif // WIZARDSTATE_H
