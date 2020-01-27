#ifndef SPELLCASTERATTACK_H
#define SPELLCASTERATTACK_H

#include "UnitAttack.h"
#include "../units/SpellCaster.h"

class SpellCaster;

class SpellCasterAttack : public UnitAttack {
    public:
        SpellCasterAttack();
        virtual ~SpellCasterAttack();
        
        // virtual void magicAttack(Unit& enemy, SpellCaster& attacker);
        // virtual void heal(Unit& ally, SpellCaster& healer);
};

#endif // SPELLCASTERATTACK_H
