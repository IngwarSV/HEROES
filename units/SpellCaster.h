#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <map>

#include "Unit.h"
#include "../states/SpellCasterState.h"
#include "../attacks/SpellCasterAttack.h"
#include "../spells/Spell.h"

class SpellCasterAttack;

class SpellCaster : public Unit {
    private:
        Spell* activeSpell;
        std::map<std::string, Spell*>* spellBook;
    public:
        SpellCaster(const std::string& type, SpellCasterState* state, SpellCasterAttack* attack, Spell* spell_1 = nullptr, Spell* spell_2 = nullptr, Spell* spell_3 = nullptr);
        virtual ~SpellCaster();
        virtual SpellCasterState& getState() const override;
        Spell* getActiveSpell() const;
        void chooseSpell(std::string formula = "none");
        virtual void castSpell(Unit* receiver = nullptr);
        void addSpell(Spell* spell);
        void refillMana(int mana);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster);

#endif // SPELLCASTER_H
