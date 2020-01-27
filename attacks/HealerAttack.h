#ifndef HEALERATTACK_H
#define HEALERATTACK_H

#include "SpellCasterAttack.h"
#include "../units/Healer.h"

class Healer;

class HealerAttack : public SpellCasterAttack {
    public:
        HealerAttack();
        virtual ~HealerAttack();
};

#endif // HEALERATTACK_H
