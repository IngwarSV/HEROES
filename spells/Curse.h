#ifndef CURSE_H
#define CURSE_H

#include <iostream>
#include "Spell.h"
#include "../units/Necromancer.h"

class Curse : public Spell {
    public:
        Curse(int magicDamage = static_cast<int>(CURSE::STANDARD), int cost = static_cast<int>(CURSE::COST), const std::string& formula = castFormulas::CURSE);
        virtual void action(Unit* enemy, Unit* attacker, int magicDamage) override;
};

#endif // CURSE_H
