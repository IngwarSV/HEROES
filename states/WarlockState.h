#ifndef WARLOCKSTATE_H
#define WARLOCKSTATE_H

#include <iostream>
#include <string>
#include "SpellCasterState.h"
#include "../Specifications.h"


class WarlockState : public SpellCasterState {
    public:
        WarlockState(const std::string& name, int health = static_cast<int>(HP::WARLOCK), int damage = static_cast<int>(DMG::WARLOCK), int mana =  static_cast<int>(MANA::WARLOCK));
        virtual ~WarlockState();
        
        
};

#endif // WARLOCKSTATE_H
