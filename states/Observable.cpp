#include "Observable.h"

Observable::Observable(Unit* target) {
    this->target = target;
    this->listOfObservers = new std::set<Unit*>();
}

Observable::~Observable() {
    // std::set<Unit*>::iterator it = this->listOfObservers->begin();

    // for ( ; it != this->listOfObservers->end(); it++ ) {
    //     (*it)->removetarget(this);
    // }
    this->notify();
    delete(this->listOfObservers);
}

void Observable::listObservers() {
    std::set<Unit*>::iterator it = this->listOfObservers->begin();
    
    std::cout << this->target->getState().getName() << " listOfObservers:" << std::endl;
    for ( ; it != this->listOfObservers->end(); it++ ) {
        std::cout << (*it)->getUnitType() << " " << (*it)->Unit::getState().getName() << std::endl;
    }
}

void Observable::notify() {
    std::set<Unit*>::iterator it = this->listOfObservers->begin();

    for (; it != this->listOfObservers->end(); it++ ) {
        (*it)->notifyObservers(this->target);
    }
    this->listOfObservers->clear();
}

void Observable::addObserver(Unit* observer) {
    this->listOfObservers->insert(observer);
}

void Observable::removeObserver(Unit* observer) {
    this->listOfObservers->erase(observer);
}
