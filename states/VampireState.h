#ifndef VAMPIRESTATE_H
#define VAMPIRESTATE_H

#include "../Specifications.h"
#include "UnitState.h"

class VampireState : public UnitState {
    public:
        VampireState(const std::string& name, int health = static_cast<int>(HP::VAMPIRE), int damage = static_cast<int>(DMG::VAMPIRE), bool isUndead = true);
        virtual ~VampireState();
        
};

#endif // VAMPIRESTATE_H
