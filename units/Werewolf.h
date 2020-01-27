#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Unit.h"
#include "../states/WerewolfState.h"
#include "../states/SoldierState.h"
#include "../attacks/WerewolfAttack.h"


class Werewolf : public Unit {
    public:
        Werewolf(const std::string& name, const std::string& type = TYPE::WEREWOLF, const std::string& mutation = TYPE::WEREWOLF, int health = static_cast<int>(HP::SOLDIER), int damage = static_cast<int>(DMG::SOLDIER), int alterHealth = static_cast<int>(HP::WEREWOLF), int alterDamage = static_cast<int>(DMG::WEREWOLF));
        virtual ~Werewolf();
};

// std::ostream& operator<<(std::ostream& out, const Werewolf& werewolf);

#endif // WEREWOLF_H
