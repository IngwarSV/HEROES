#ifndef UNITATTACK_H
#define UNITATTACK_H

#include "../Specifications.h"
#include "../units/Unit.h"

class Unit;

class UnitAttack {
    public:
        UnitAttack();
        virtual ~UnitAttack();
        
        virtual void attack(Unit& enemy, Unit& attacker);
        virtual void counterAttack(Unit& enemy, Unit& contrAttacker);
};

#endif // UNITATTACK_H
