#ifndef WIZARDATTACK_H
#define WIZARDATTACK_H

#include "SpellCasterAttack.h"
#include "../units/Wizard.h"

class Wizard;

class WizardAttack : public SpellCasterAttack {
    public:
        WizardAttack();
        virtual ~WizardAttack();
        
        // virtual void heal(Unit& ally, SpellCaster& healer);
};

#endif // WIZARDATTACK_H
