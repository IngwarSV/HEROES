#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include "SpellCaster.h"
#include "../states/PriestState.h"
#include "../attacks/PriestAttack.h"
#include "../Specifications.h"
#include "../spells/Fireball.h"
#include "../spells/Healing.h"

class PriestAttack;

class Priest : public SpellCaster {
    public:
        Priest(const std::string& name, const std::string& type = TYPE::PRIEST, int health = static_cast<int>(HP::PRIEST), int damage = static_cast<int>(DMG::PRIEST), int mana =  static_cast<int>(MANA::PRIEST));
        virtual ~Priest();
        
        virtual void castSpell(Unit* receiver) override;
};

#endif // PRIEST_H


