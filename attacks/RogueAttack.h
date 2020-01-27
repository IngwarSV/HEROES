#ifndef ROGUEATTACK_H
#define ROGUEATTACK_H

// #include "../units/Rogue.h"
#include "UnitAttack.h"

class Rogue;

class RogueAttack : public UnitAttack {
    public:
        RogueAttack();
        virtual ~RogueAttack();
        
        virtual void attack(Unit& enemy, Unit& attacker);
        virtual void counterAttack(Unit& enemy, Unit& contrAttacker);
};

#endif // ROGUEATTACK_H
