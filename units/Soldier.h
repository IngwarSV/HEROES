#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"
#include "../states/SoldierState.h"
#include "../Specifications.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, const std::string& type = TYPE::SOLDIER, const std::string& mutation = MUTATION::NONE, int health = static_cast<int>(HP::SOLDIER), int damage = static_cast<int>(DMG::SOLDIER));
        virtual ~Soldier();
};

// std::ostream& operator<<(std::ostream& out, const Soldier& soldier);

#endif // SOLDIER_H
