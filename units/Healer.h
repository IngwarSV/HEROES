#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "SpellCaster.h"
#include "../states/HealerState.h"
#include "../attacks/HealerAttack.h"
#include "../Specifications.h"
#include "../spells/Fireball.h"
#include "../spells/Healing.h"

class HealerAttack;

class Healer : public SpellCaster {
    public:
        Healer(const std::string& name, const std::string& type = TYPE::HEALER, int health = static_cast<int>(HP::HEALER), int damage = static_cast<int>(DMG::HEALER), int mana =  static_cast<int>(MANA::HEALER));
        virtual ~Healer();
};

#endif // HEALER_H

    // if ( this->uState->isUnDead ) {
    //     if ( attacker.getUnitType() == TYPE::PRIEST ) {
    //         this->uState->takeMagicDamage(dmg * 2);
    //     } else {
    //         this->uState->takeMagicDamage(dmg);
    //     }
    // } else {
    //     this->uState->takeMagicDamage(dmg);
    // }
