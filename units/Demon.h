#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include "Unit.h"
#include "../states/DemonState.h"
#include "../Specifications.h"

class Demon : public Unit {
    private:
        Unit* master;
    public:
        Demon(Unit* warlock, const std::string& name = "Bubble", const std::string& type = TYPE::DEMON, const std::string& mutation = MUTATION::MAGICCREATURE, int health = static_cast<int>(HP::DEMON), int damage = static_cast<int>(DMG::DEMON));
        virtual ~Demon();
        
        Unit* getMaster() const;
        
        void demonIsDestroyed();
};

std::ostream& operator<<(std::ostream& out, const Demon& demon);

#endif // DEMON_H
