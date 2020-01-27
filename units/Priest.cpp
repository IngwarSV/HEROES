#include "Priest.h"

Priest::Priest(const std::string& name, const std::string& type, int health, int damage, int mana) : SpellCaster(type, new PriestState(name, health, damage, mana), new PriestAttack(), new Fireball(static_cast<int>(FIREBALL::PRIEST)), new Healing(static_cast<int>(HEALING::PRIEST))) {
            std::cout << " creating Priest " << std::endl;
}

Priest::~Priest() {
            std::cout << " deleting Priest " << std::endl;
}

void Priest::castSpell(Unit* receiver) {
    if ( !alterEgoOn ) {
        if ( this->Unit::getState().outOfHp() ) { return; }
        if ( this->getState().getMana() >= this->getActiveSpell()->getCost() ) {
            this->getState().useMana(this->getActiveSpell()->getCost());
            if ( receiver->getState().isUnDead && this->getActiveSpell()->getFormula() != "heal" ) {
                this->getActiveSpell()->action(receiver, this, this->getActiveSpell()->getMagicDmg() * 2);
            } else {
                this->getActiveSpell()->action(receiver, this, this->getActiveSpell()->getMagicDmg());
            }
        } else {
            std::cout << "Not enough mana" << '\n';
        }
    }
}
