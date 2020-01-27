#ifndef SPELLCASTERSTATE_H
#define SPELLCASTERSTATE_H

#include <iostream>
#include <string>
#include "UnitState.h"


class SpellCasterState : public UnitState {
    private:
        int mana;
        int maxMana;
        // int magicDmg;
        // int treatment;
        
    public:
        SpellCasterState(const std::string& name, int health, int damage, int mana, bool isUndead = false);
        virtual ~SpellCasterState();
        
        void useMana(int mana);
        void refillMana(int mana);
        
        int getMana() const;
        int getMaxMana() const;
        int getMagicDmg() const;
        int getTreatment() const;

};

std::ostream& operator<<(std::ostream& out, const SpellCasterState& state);

#endif // SPELLCASTERSTATE_H
