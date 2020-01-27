#include "Spell.h"

Spell::Spell(int magicDamage, int cost, const std::string& formula) : magicDmg(magicDamage), cost(cost), formula(formula) {}

Spell::~Spell() {}

int Spell::getMagicDmg() const {
    return this->magicDmg;
}

int Spell::getCost() const {
    return this->cost;
}

const std::string& Spell::getFormula() const {
    return this->formula;
}
