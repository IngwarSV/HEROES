#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Unit.h"
#include "../states/RogueState.h"
#include "../attacks/RogueAttack.h"
#include "../Specifications.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& name, const std::string& type = TYPE::ROGUE, int health = static_cast<int>(HP::ROGUE), int damage = static_cast<int>(DMG::ROGUE));
        virtual ~Rogue();
};

#endif // ROGUE_H
