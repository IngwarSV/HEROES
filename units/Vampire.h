#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "Unit.h"
#include "../states/VampireState.h"
#include "../attacks/VampireAttack.h"

class Vampire : public Unit {
    public:
        Vampire(const std::string& name, const std::string& type = TYPE::VAMPIRE, const std::string& mutation = TYPE::VAMPIRE, int health = static_cast<int>(HP::VAMPIRE), int damage = static_cast<int>(DMG::VAMPIRE), bool isUndead = true);
        virtual ~Vampire();
};

// std::ostream& operator<<(std::ostream& out, const Vampire& vampire);

#endif // VAMPIRE_H
