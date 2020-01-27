#ifndef FIREBALL_H
#define FIREBALL_H

#include <iostream>
#include "Spell.h"

class Fireball : public Spell {
    public:
        Fireball(int magicDamage = static_cast<int>(FIREBALL::STANDARD), int cost = static_cast<int>(FIREBALL::COST), const std::string& formula = castFormulas::FIREBALL);
        virtual void action(Unit* enemy, Unit* attacker, int magicDamage);
};

#endif // FIREBALL_H
