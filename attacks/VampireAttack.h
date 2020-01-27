#ifndef VAMPIREATTACK_H
#define VAMPIREATTACK_H

#include <ctime>

#include "UnitAttack.h"

class UnitAttack;

class VampireAttack : public UnitAttack {
    private:
        void mutationBite(Unit& enemy, Unit& attacker);
    public:
        VampireAttack();
        virtual ~VampireAttack();
        
        virtual void attack(Unit& enemy, Unit& attacker) override;
        virtual void counterAttack(Unit& enemy, Unit& contrAttacker) override;
};

#endif // VAMPIREATTACK_H
