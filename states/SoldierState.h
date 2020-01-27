#ifndef SOLDIERSTATE_H
#define SOLDIERSTATE_H

#include <iostream>
#include <string>
#include "../Specifications.h"
#include "UnitState.h"

class SoldierState : public UnitState {
    public:
        SoldierState(const std::string& name, int health = static_cast<int>(HP::SOLDIER), int damage = static_cast<int>(DMG::SOLDIER));
        virtual ~SoldierState();
};

#endif // SOLDIERSTATE_H
