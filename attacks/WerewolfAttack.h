#ifndef WEREWOLFATTACK_H
#define WEREWOLFATTACK_H

#include <ctime>

#include "UnitAttack.h"
#include "../states/WerewolfState.h"

class UnitAttack;

class WerewolfAttack : public UnitAttack {
    private:
        void mutationBite(Unit& enemy, Unit& attacker);
    public:
        WerewolfAttack();
        virtual ~WerewolfAttack();
        
        virtual void attack(Unit& enemy, Unit& attacker) override;
        virtual void counterAttack(Unit& enemy, Unit& contrAttacker) override;
};

#endif // WEREWOLFATTACK_H
