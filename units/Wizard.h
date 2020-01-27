#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "SpellCaster.h"
#include "../states/WizardState.h"
#include "../attacks/WizardAttack.h"
#include "../Specifications.h"
#include "../spells/Fireball.h"
#include "../spells/Healing.h"

class WizardAttack;

class Wizard : public SpellCaster {
    public:
        Wizard(const std::string& name, const std::string& type = TYPE::WIZARD, int health = static_cast<int>(HP::WIZARD), int damage = static_cast<int>(DMG::WIZARD), int mana =  static_cast<int>(MANA::WIZARD));
        virtual ~Wizard();
};

// std::ostream& operator<<(std::ostream& out, const Wizard& Wizard);

#endif // WIZARD_H
