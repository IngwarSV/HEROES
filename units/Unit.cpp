#include "Unit.h"

Unit::Unit(const std::string& type, UnitState* state, UnitAttack* attack, const std::string& mutation, UnitState* alEgo, UnitAttack* alAttack) {
            std::cout << "\tcreating Unit " << std::endl;
    this->unitType = type;
    this->unitMutation = mutation;
    this->uState = state;
    this->uAttack = attack;
    this->alterEgo = alEgo;
    this->alterAttack = alAttack;
    this->alterEgoOn = false;
    this->observersList = new Observable(this);
}

Unit::~Unit() {
            std::cout << "\tdeleting Unit " << std::endl;
    delete(this->uState);
    delete(this->uAttack);
    delete(this->alterEgo);
    delete(this->alterAttack);
    delete(this->observersList);
            std::cout << "\tUnit is deleted" << std::endl;
}

UnitState& Unit::getState() const {
    return *this->uState;
}

UnitState& Unit::getAlterState() const {
    return *this->alterEgo;
}

UnitAttack& Unit::getAttack() const {
    return *this->uAttack;
}

const std::string& Unit::getUnitType() const {
    return this->unitType;
}

const std::string& Unit::getUnitMutation() const {
    return this->unitMutation;
}

Observable* Unit::getObserversList() const {
    return this->observersList;
}

void Unit::attack(Unit& enemy) {
    if ( this->uState->outOfHp() ) { return; }
    this->uAttack->attack(enemy, *this);
}

void Unit::counterAttack(Unit& enemy) {
    if ( this->uState->outOfHp() ) { return; }
    this->uAttack->counterAttack(enemy, *this);
}

void Unit::takeDamage(int dmg) {
    if ( this->uState->outOfHp() ) { return; }
    this->uState->takeDamage(dmg);
    
    if ( this->alterEgo != nullptr ) {
        double hpFactor = static_cast<double>(this->alterEgo->getMaxHp()) / this->uState->getMaxHp();
        dmg = this->alterEgo->getHp() - this->uState->getHp() * hpFactor;
        this->alterEgo->UnitState::takeDamage(dmg);
    }
    
    if ( this->uState->outOfHp() ) {
        this->observersList->notify();
        this->notifyObservable(this);
    }
}

void Unit::takeMagicDamage(int dmg) {
    if ( this->uState->outOfHp() ) { return; }
    
    this->uState->takeMagicDamage(dmg);
    
    if ( this->alterEgo != nullptr ) {
        double hpFactor = static_cast<double>(this->alterEgo->getMaxHp()) / this->uState->getMaxHp();
        dmg = this->alterEgo->getHp() - this->uState->getHp() * hpFactor;
        this->alterEgo->UnitState::takeDamage(dmg);
    }
    
    if ( this->uState->outOfHp() ) {
        this->observersList->notify();
        this->notifyObservable(this);
    }
}

void Unit::takeTreatment(int hp) {
    if ( this->uState->outOfHp() ) { return; }
    this->uState->takeTreatment(hp);
    
    if ( this->alterEgo != nullptr ) {
        double hpFactor = static_cast<double>(this->alterEgo->getMaxHp()) / this->uState->getMaxHp();
        hp = this->uState->getHp() * hpFactor - this->alterEgo->getHp();
        this->alterEgo->UnitState::takeTreatment(hp);
    }
}

void Unit::creatureMutation(const std::string& mutation, UnitState* state, UnitAttack* attack, UnitState* alEgo, UnitAttack* alAttack) {
            std::cout << "\tReceiving mutationBite " << std::endl;
    if ( mutation != MUTATION::NONE ) {
        this->unitMutation = mutation;
    }
    if ( state != nullptr ) {
        delete(this->uState);
        this->uState = state;
    }
    if ( attack != nullptr ) {
        delete(this->uAttack);
        this->uAttack = attack;
    }
    if ( alEgo != nullptr ) {
        delete(this->alterEgo);
        this->alterEgo = alEgo;
        if ( this->uState->isUnDead ) {
            this->alterEgo->isUnDead = true;
        }
    }
    if ( alAttack != nullptr ) {
        delete(this->alterAttack);
        this->alterAttack = alAttack;
    }
}

void Unit::transform() {
    if ( this->uState->outOfHp() || this->alterEgo == nullptr || this->alterAttack == nullptr ) { return; }
            std::cout << "\ttransforming" << std::endl;
    UnitState* tmp1 = this->uState;
    UnitAttack* tmp2 = this->uAttack;
    this->uState = this->alterEgo;
    this->uAttack = this->alterAttack;
    this->alterEgo = tmp1;
    this->alterAttack = tmp2;
    this->alterEgoOn = !(this->alterEgoOn);
}

void Unit::notifyObservers(Unit* observable) {}

void Unit::notifyObservable(Unit* observer) {}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getUnitType() << " [" << unit.getState()  << ']';
    if ( &unit.getAlterState() != nullptr ) {
        out << " AlterEgo: [" << unit.getAlterState()  << ']';
    }
    out << " Mutation: [" << unit.getUnitMutation()<< "]\n";
    
    return out;
}
