#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <set>

#include "../units/Necromancer.h"
#include "../Specifications.h"
// #include "Observable.h"


class Necromancer;

class Observer {
    private:
        Necromancer* bookMaster;
        std::set<Unit*>* listOfVictims;
    public:
        Observer(Necromancer* necromancer);
        ~Observer();

        bool listIsEmpty();

        std::set<Unit*>* getListOfVictims() const;

        void addVictim(Unit* victim);
        void removeVictim(Unit* victim);

        void receiveDeadNote(Unit* victim);
        void freeVictims(Unit* victim);

        // void listVictims();
};

std::ostream& operator<<(std::ostream& out, const Observer& curseBook);

#endif // OBSERVER_H
