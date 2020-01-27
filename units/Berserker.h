#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "Unit.h"
#include "../states/BerserkerState.h"
#include "../Specifications.h"

class Berserker : public Unit {
    public:
        Berserker(const std::string& name, const std::string& type = TYPE::BERSERKER, int health = static_cast<int>(HP::BERSERKER), int damage = static_cast<int>(DMG::BERSERKER));
        virtual ~Berserker();
};

// std::ostream& operator<<(std::ostream& out, const Berserker& berserker);

#endif // BERSERKER_H
