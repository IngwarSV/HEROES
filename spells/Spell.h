#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include <string>

#include "../units/Unit.h"
#include "../Specifications.h"

class Spell {
    private:
        int magicDmg;
        int cost;
        std::string formula;
        
    public:
        Spell(int magicDamage, int cost, const std::string& formula);
        virtual ~Spell();
        
        int getMagicDmg() const;
        int getCost() const;
        const std::string& getFormula() const;
        
        virtual void action(Unit* receiver, Unit* attacker, int magicDamage) = 0;
};

#endif // SPELL_H
