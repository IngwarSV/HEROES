#ifndef PRIESTSTATE_H
#define PRIESTSTATE_H

#include <iostream>
#include <string>
#include "SpellCasterState.h"
#include "../Specifications.h"


class PriestState : public SpellCasterState {
    public:
        PriestState(const std::string& name, int health = static_cast<int>(HP::PRIEST), int damage = static_cast<int>(DMG::PRIEST), int mana =  static_cast<int>(MANA::PRIEST));
        virtual ~PriestState();
};

#endif // PRIESTSTATE_H
