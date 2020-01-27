#include "Healer.h"

Healer::Healer(const std::string& name, const std::string& type, int health, int damage, int mana) : SpellCaster(type, new HealerState(name, health, damage, mana), new HealerAttack(), new Fireball(static_cast<int>(FIREBALL::HEALER)), new Healing(static_cast<int>(HEALING::HEALER))) {
            std::cout << " creating Healer " << std::endl;
}

Healer::~Healer() {
            std::cout << " deleting Healer " << std::endl;
}
