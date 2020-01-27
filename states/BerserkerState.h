#ifndef BERSERKERSTATE_H
#define BERSERKERSTATE_H

#include <iostream>
#include <string>
#include "../Specifications.h"
#include "UnitState.h"

class BerserkerState : public UnitState {
    public:
        BerserkerState(const std::string& name, int health = static_cast<int>(HP::BERSERKER), int damage = static_cast<int>(DMG::BERSERKER));
        virtual ~BerserkerState();
        
    virtual void takeMagicDamage(int dmg) override;
    virtual void takeTreatment(int hp) override;
};

#endif // BERSERKERSTATE_H
