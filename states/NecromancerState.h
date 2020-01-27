#ifndef NECROMANCERSTATE_H
#define NECROMANCERSTATE_H

#include <iostream>
#include <string>
#include "SpellCasterState.h"
#include "../Specifications.h"


class NecromancerState : public SpellCasterState {
    public:
        NecromancerState(const std::string& name, int health = static_cast<int>(HP::NECROMANCER), int damage = static_cast<int>(DMG::NECROMANCER), int mana =  static_cast<int>(MANA::NECROMANCER), bool isUndead = true);
        virtual ~NecromancerState();
        
        
};

#endif // NECROMANCERSTATE_H
