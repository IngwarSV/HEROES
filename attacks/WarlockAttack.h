#ifndef WARLOCKATTACK_H
#define WARLOCKATTACK_H

#include "SpellCasterAttack.h"
#include "../units/Warlock.h"

class Warlock;

class WarlockAttack : public SpellCasterAttack {
    public:
        WarlockAttack();
        virtual ~WarlockAttack();
        
        // virtual void heal(Unit& ally, SpellCaster& healer);
};

#endif // WARLOCKATTACK_H
