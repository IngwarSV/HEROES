#include "Observer.h"

Observer::Observer(Necromancer* necromancer) {
    this->bookMaster = necromancer;
    this->listOfVictims = new std::set<Unit*>();
}

Observer::~Observer() {
    std::set<Unit*>::iterator it = this->listOfVictims->begin(); // auto
    for (; it != this->listOfVictims->end(); it++ ) {
        (*it)->getObserversList()->removeObserver(this->bookMaster);
    }
    delete(this->listOfVictims);
}

bool Observer::listIsEmpty() {
    return this->listOfVictims->empty();
}

std::set<Unit*>* Observer::getListOfVictims() const {
    return this->listOfVictims;
}

void Observer::addVictim(Unit* victim) {
    this->listOfVictims->insert(victim);
    victim->getObserversList()->addObserver(this->bookMaster);
}

void Observer::removeVictim(Unit* victim) {
    this->listOfVictims->erase(victim);
}

void Observer::receiveDeadNote(Unit* victim) {
            std::cout << "Necro receiving HP by curse - " << victim->Unit::getState().getMaxHp() / necromancerTribute << std::endl;
    this->bookMaster->takeTreatment(victim->Unit::getState().getMaxHp() / necromancerTribute);
    this->removeVictim(victim);
}

// void Observer::listVictims() {
//     auto it = this->listOfVictims->begin();
//     std::cout << "List of marked victims: " << std::endl;
    
//     for (; it != this->listOfVictims->end(); it++ ) {
//         std::cout << (*it)->getUnitType() << " " << (*it)->Unit::getState().getName() << std::endl;
//     }
// }

std::ostream& operator<<(std::ostream& out, const Observer& curseBook) {
    auto it = curseBook.getListOfVictims()->begin();
    
    for ( ; it != curseBook.getListOfVictims()->end(); it++ ) {
        out << "\t" << (*it)->getUnitType() << " ";
        out << (*it)->getState().getName() << std::endl;
    }
    return out;
}
