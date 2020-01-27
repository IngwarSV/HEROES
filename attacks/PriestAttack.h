#ifndef PRIESTATTACK_H
#define PRIESTATTACK_H

#include "SpellCasterAttack.h"
#include "../units/Priest.h"

class Priest;

class PriestAttack : public SpellCasterAttack {
    public:
        PriestAttack();
        virtual ~PriestAttack();
        
        virtual void attack(Unit& enemy, Unit& attacker) override;
        virtual void counterAttack(Unit& enemy, Unit& contrAttacker) override;
};

#endif // PRIESTATTACK_H
