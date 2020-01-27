#ifndef NECROMANCERATTACK_H
#define NECROMANCERATTACK_H

#include "SpellCasterAttack.h"
#include "../units/Necromancer.h"

class Necromancer;

class NecromancerAttack : public SpellCasterAttack {
    public:
        NecromancerAttack();
        virtual ~NecromancerAttack();
        
        // virtual void heal(Unit& ally, SpellCaster& healer);
};

#endif // NECROMANCERATTACK_H
