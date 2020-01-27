#ifndef DEMONSUMMON_H
#define DEMONSUMMON_H

#include <iostream>
#include "Spell.h"
#include "../units/Warlock.h"

class DemonSummon : public Spell {
    private:
        int demonNumber;
    public:
        DemonSummon(int magicDamage = static_cast<int>(DEMONSUMMON::STANDARD), int cost = static_cast<int>(DEMONSUMMON::COST), const std::string& formula = castFormulas::DEMONSUMMON);
        virtual void action(Unit* enemy, Unit* attacker, int magicDamage) override;
};

#endif // DEMONSUMMON_H
