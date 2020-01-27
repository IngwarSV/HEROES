#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include <set>
#include <ctime>

#include "SpellCaster.h"
#include "../states/NecromancerState.h"
#include "../states/Observer.h"
#include "../attacks/NecromancerAttack.h"
#include "../Specifications.h"
#include "../spells/Fireball.h"
#include "../spells/Healing.h"
#include "../spells/Curse.h"

class NecromancerAttack;
class Observer;

class Necromancer : public SpellCaster {
    private:
        Observer* curseBook;
        void victimMarking(Unit& enemy);
    public:
        Necromancer(const std::string& name, const std::string& type = TYPE::NECROMANCER, int health = static_cast<int>(HP::NECROMANCER), int damage = static_cast<int>(DMG::NECROMANCER), int mana =  static_cast<int>(MANA::NECROMANCER), bool isUndead = true);
        virtual ~Necromancer();
        
        Observer* getCurseBook() const;
        // void addVictim(Unit* victim);
        // void removeVictim(Unit* victim);
        
        virtual void attack(Unit& enemy) override;
        virtual void castSpell(Unit* receiver = nullptr) override;
        
        virtual void notifyObservers(Unit* observable) override;
        // virtual void notifyObservable(Unit* observer) override;
        
        // void listMarkedVictims();
};

std::ostream& operator<<(std::ostream& out, const Necromancer& necromancer);

#endif // NECROMANCER_H
