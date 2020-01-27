#include "SpellCaster.h"

SpellCaster::SpellCaster(const std::string& type, SpellCasterState* state, SpellCasterAttack* attack, Spell* spell_1, Spell* spell_2, Spell* spell_3) : Unit(type, state, attack) {
    std::cout << " creating SpellCaster " << std::endl;
    this->activeSpell = nullptr;
    this->spellBook = new std::map<std::string, Spell*>();
        if ( spell_1 ) {
            this->activeSpell = spell_1;
            spellBook->insert(std::pair<std::string, Spell*>(spell_1->getFormula(), spell_1));
            if ( spell_2 ) {
                spellBook->insert(std::pair<std::string, Spell*>(spell_2->getFormula(), spell_2));
                if ( spell_3 ) {
                    spellBook->insert(std::pair<std::string, Spell*>(spell_3->getFormula(), spell_3));
                }
            }
        }
}

SpellCaster::~SpellCaster() { 
    std::cout << " deleting SpellCaster " << std::endl;
    delete(this->spellBook);
}

SpellCasterState& SpellCaster::getState() const {
    if ( alterEgoOn ) {
        return static_cast<SpellCasterState&>(this->Unit::getAlterState());
    } else {
        return static_cast<SpellCasterState&>(this->Unit::getState());
    }
}

Spell* SpellCaster::getActiveSpell() const {
    return this->activeSpell;
}

void SpellCaster::chooseSpell(std::string formula) {
    if ( formula == "none" ) {
        auto it = spellBook->upper_bound(this->activeSpell->getFormula());
        if ( it != spellBook->end() ) {
            this->activeSpell = it->second;
        } else {
            it = spellBook->begin();
            this->activeSpell = it->second;
        }
    } else if ( this->spellBook->find(formula) != this->spellBook->end() ) {
            this->activeSpell = spellBook->at(formula);
        } else {
            std::cout << "This " << this->getUnitType() << " hasn't this spell in his spellBook" << std::endl;
    }
}

void SpellCaster::castSpell(Unit* receiver) {
    if ( !alterEgoOn ) {
        if ( this->Unit::getState().outOfHp() ) { return; }
        if ( this->getState().getMana() >= this->activeSpell->getCost() ) {
            this->getState().useMana(this->activeSpell->getCost());
            this->activeSpell->action(receiver, this, this->activeSpell->getMagicDmg());
        } else {
            std::cout << "Not enough mana" << '\n';
        }
    }
}

void SpellCaster::addSpell(Spell* spell) {
    if ( spellBook->find(spell->getFormula()) == spellBook->end() ) {
        spellBook->insert(std::pair<std::string, Spell*>(spell->getFormula(), spell));
    }
}

void SpellCaster::refillMana(int mana) {
    if ( !alterEgoOn ) {
        if ( this->Unit::getState().outOfHp() ) { return; }
        this->getState().refillMana(mana);
    }
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster) {
    out << spellCaster.getUnitType() << " [";
    if ( spellCaster.alterEgoOn ) {
    out << spellCaster.Unit::getState()  << "] AlterEgo: [" << static_cast<SpellCasterState&>(spellCaster.Unit::getAlterState()) << ", active spell: " << spellCaster.getActiveSpell()->getFormula() << ']';
    } else {
        out << static_cast<SpellCasterState&>(spellCaster.Unit::getState()) << ", active spell: " << spellCaster.getActiveSpell()->getFormula() << ']';
        if ( &spellCaster.Unit::getAlterState() != nullptr ) {
            out << " AlterEgo: [" << spellCaster.Unit::getAlterState() << ']';
        }
    }
    out << " Mutation: [" << spellCaster.getUnitMutation()<< "]\n";
    
    return out;
}
