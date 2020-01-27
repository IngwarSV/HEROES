#include <iostream>
#include "SpellCasterState.h"

SpellCasterState::SpellCasterState(const std::string& name, int health, int damage, int mana, bool isUndead) : UnitState(name, health, health, damage, isUndead) {
    std::cout << " creating SpellCasterState " << std::endl;
    this->mana = mana;
    this->maxMana = mana;
    // this->magicDmg = magicDamage;
    // this->treatment = treatment;
}

SpellCasterState::~SpellCasterState() { std::cout << " deleting SpellCasterState " << std::endl; }

void SpellCasterState::useMana(int mana) {
    this->mana -= mana;
}

void SpellCasterState::refillMana(int mana) {
            std::cout << " refilling mana " << std::endl;
    this->mana += mana;
    if ( this->mana > this->maxMana ) {
        this->mana = this->maxMana;
    }
}

int SpellCasterState::getMana() const {
    return this->mana;
}

int SpellCasterState::getMaxMana() const {
    return this->maxMana;
}


// int SpellCasterState::getMagicDmg() const {
//     return this->magicDmg;
// }

// int SpellCasterState::getTreatment() const {
//     return this->treatment;
// }

std::ostream& operator<<(std::ostream& out, const SpellCasterState& state) {
    out << state.getName() << ", ";
    out << state.getMaxHp() << ":" << state.getHp() << ", ";
    out << state.getDmg() << ", ";
    out << state.getMaxMana() << ":" << state.getMana();
    // out << state.getMagicDmg();
    return out;
}
