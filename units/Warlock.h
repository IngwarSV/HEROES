#ifndef WARLOCK_H
#define WARLOCK_H

#include <iostream>
#include <set>

#include "SpellCaster.h"
#include "Demon.h"
#include "../states/WarlockState.h"
#include "../states/Observer.h"
#include "../attacks/WarlockAttack.h"
#include "../Specifications.h"
#include "../spells/Fireball.h"
#include "../spells/Healing.h"
#include "../spells/demonSummon.h"

class WarlockAttack;

class Warlock : public SpellCaster {
    private:
        std::set<Demon*>* demonBook;
        Demon* lastDemon;
        // bool hasDemon;
        
    public:
        Warlock(const std::string& name, const std::string& type = TYPE::WARLOCK, int health = static_cast<int>(HP::WARLOCK), int damage = static_cast<int>(DMG::WARLOCK), int mana =  static_cast<int>(MANA::WARLOCK));
        virtual ~Warlock();
        
        std::set<Demon*>* getDemonBook() const;
        virtual void castSpell(Unit* receiver = nullptr) override;
        void addDemon(Demon* demon);
        Demon* summonDemon();
        
        virtual void notifyObservers(Unit* observable) override;
        virtual void notifyObservable(Unit* observer) override;
};

std::ostream& operator<<(std::ostream& out, const Warlock& warlock);

#endif // WARLOCK_H
