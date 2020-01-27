#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <iostream>
#include <set>

#include "../units/Unit.h"

class Unit;

class Observable {
    private:
        Unit* target;
        std::set<Unit*>* listOfObservers;
    public:
        Observable(Unit* target);
        ~Observable();

        void listObservers();
        void notify();
        
        void addObserver(Unit* observer);
        void removeObserver(Unit* observer);
};

#endif // OBSERVABLE_H
