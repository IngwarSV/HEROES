#ifndef DEMONSTATE_H
#define DEMONSTATE_H

#include <iostream>
#include <string>
#include "../Specifications.h"
#include "UnitState.h"

class DemonState : public UnitState {
    public:
        DemonState(const std::string& name, int health = static_cast<int>(HP::DEMON), int damage = static_cast<int>(DMG::DEMON));
        virtual ~DemonState();
        
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
        virtual void takeTreatment(int hp);
};

#endif // DEMONSTATE_H
