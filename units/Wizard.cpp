#include "Wizard.h"

Wizard::Wizard(const std::string& name, const std::string& type, int health, int damage, int mana) : SpellCaster(type, new WizardState(name, health, damage, mana), new WizardAttack(), new Fireball(static_cast<int>(FIREBALL::WIZARD)), new Healing(static_cast<int>(HEALING::WIZARD))) {
            std::cout << " creating Wizard " << std::endl;
}

Wizard::~Wizard() {
            std::cout << " deleting Wizard " << std::endl;
}

// std::ostream& operator<<(std::ostream& out, const Wizard& Wizard) {
//     out << "Wizard [" << Wizard.getState() << ']';
//     return out;
// }
