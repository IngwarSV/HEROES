#ifndef HEALERSTATE_H
#define HEALERSTATE_H

#include <iostream>
#include <string>
#include "SpellCasterState.h"
#include "../Specifications.h"


class HealerState : public SpellCasterState {
    public:
        HealerState(const std::string& name, int health = static_cast<int>(HP::HEALER), int damage = static_cast<int>(DMG::HEALER), int mana =  static_cast<int>(MANA::HEALER));
        virtual ~HealerState();
};

#endif // HEALERSTATE_H
