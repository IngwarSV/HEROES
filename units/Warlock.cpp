#include "Warlock.h"

Warlock::Warlock(const std::string& name, const std::string& type, int health, int damage, int mana) : SpellCaster(type, new WarlockState(name, health, damage, mana), new WarlockAttack(), new Fireball(static_cast<int>(FIREBALL::WARLOCK)), new Healing(static_cast<int>(HEALING::WARLOCK)), new DemonSummon()) {
            std::cout << " creating Warlock " << std::endl;
    this->demonBook = new std::set<Demon*>();
        // this->demonBook->reserve(warlockMaxDemons);
    this->lastDemon = nullptr;
    // this->hasDemon = false;
}

Warlock::~Warlock() {
            std::cout << " deleting Warlock " << std::endl;
            // deleting Demons?
    delete(this->demonBook);
            std::cout << " deleted Warlock " << std::endl;
}

std::set<Demon*>* Warlock::getDemonBook() const { //const?
    return this->demonBook;
}
void Warlock::castSpell(Unit* receiver) {
    if ( !alterEgoOn ) {
        if ( this->Unit::getState().outOfHp() ) { return; }
        if ( this->getState().getMana() >= this->getActiveSpell()->getCost() ) {
            if ( this->getActiveSpell()->getFormula() == "ds" ) {
                if ( this->lastDemon ) {
                    std::cout << "You already have a Demon, summon it!" << std::endl;
                    return;
                }
                if ( this->demonBook->size() == warlockMaxDemons ) {
                    std::cout << "You already have max amount of demons!" << std::endl;
                    return;
                }
            }
            this->getState().useMana(this->getActiveSpell()->getCost());
            this->getActiveSpell()->action(receiver, this, this->getActiveSpell()->getMagicDmg());
        } else {
            std::cout << "Not enough mana" << '\n';
        }
    }
}

void Warlock::addDemon(Demon* demon) {
    this->demonBook->insert(demon);
    this->lastDemon = demon;
    
    // this->lastDemon = true;
}

Demon* Warlock::summonDemon() {
    if ( !this->lastDemon ) {
        std::cout << "You have to cast Demon before summon it" << std::endl;
        Demon* bubbleDemon = new Demon(this);
        this->demonBook->insert(bubbleDemon);
        bubbleDemon->takeDamage(bubbleDemon->getState().getMaxHp() * 2);
        return bubbleDemon;
    }
    Demon* demon = this->lastDemon;
    this->lastDemon = nullptr;
    return demon;
}

void Warlock::notifyObservers(Unit* observable) {
    Demon* demon = dynamic_cast<Demon*>(observable);
    if ( !demon ) { return; }
    demon->demonIsDestroyed();
    this->demonBook->erase(demon);
}

void Warlock::notifyObservable(Unit* observer) {
    for ( std::set<Demon*>::iterator it = this->demonBook->begin(); it != this->demonBook->end(); ) {
        Demon* demon = (*it);
        ++it;
            std::cout << "kiling Demon" << demon->getState().getName() << std::endl;
        demon->takeDamage(demon->getState().getMaxHp() * 2);
    }
}

std::ostream& operator<<(std::ostream& out, const Warlock& warlock) {
    out << warlock.getUnitType() << " [";
    if ( warlock.alterEgoOn ) {
    out << warlock.Unit::getState()  << "] AlterEgo: [" << static_cast<WarlockState&>(warlock.Unit::getAlterState()) << ", active spell: " << warlock.getActiveSpell()->getFormula() << ']';
    } else {
        out << static_cast<WarlockState&>(warlock.Unit::getState()) << ", active spell: " << warlock.getActiveSpell()->getFormula() << ']';
        if ( &warlock.Unit::getAlterState() != nullptr ) {
            out << " AlterEgo: [" << warlock.Unit::getAlterState() << ']';
        }
    }
    
    out << " Mutation: [" << warlock.getUnitMutation() << "]\n";
    
    out << "List of demons: ";
    if ( warlock.getDemonBook()->empty() ) {
        out << " is empty." << "\n";
    } else {
        out << "\n";
        for ( Demon* demon : *warlock.getDemonBook() ) {
            out << demon->getState().getName() << "\n";
        }
    }
    return out;
}
