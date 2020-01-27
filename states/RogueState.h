#ifndef ROGUESTATE_H
#define ROGUESTATE_H

#include <iostream>
#include <string>
#include "../Specifications.h"
#include "UnitState.h"

class RogueState : public UnitState {
    public:
        RogueState(const std::string& name, int health = static_cast<int>(HP::ROGUE), int damage = static_cast<int>(DMG::ROGUE));
        virtual ~RogueState();
};

#endif // ROGUESTATE_H
