#ifndef HEALING_H
#define HEALING_H

#include <iostream>
#include "Spell.h"

class Healing : public Spell {
    public:
        Healing(int magicDamage = static_cast<int>(HEALING::STANDARD), int cost = static_cast<int>(HEALING::COST), const std::string& formula = castFormulas::HEALING);
        virtual void action(Unit* ally, Unit* healer, int magicDamage);
};

#endif // HEALING_H

