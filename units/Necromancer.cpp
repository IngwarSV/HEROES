#include "Necromancer.h"

Necromancer::Necromancer(const std::string& name, const std::string& type, int health, int damage, int mana, bool isUndead) : SpellCaster(type, new NecromancerState(name, health, damage, mana, isUndead), new NecromancerAttack(), new Fireball(static_cast<int>(FIREBALL::NECROMANCER)), new Healing(static_cast<int>(HEALING::NECROMANCER)), new Curse(static_cast<int>(CURSE::NECROMANCER))) {
            std::cout << " creating Necromancer " << std::endl;
    this->curseBook = new Observer(this);
}

Necromancer::~Necromancer() {
            std::cout << " deleting Necromancer " << std::endl;
    delete(this->curseBook);
            std::cout << " deleted Necromancer " << std::endl;
}

Observer* Necromancer::getCurseBook() const {
    return this->curseBook;
}

void Necromancer::victimMarking(Unit& enemy) {
    if ( enemy.getUnitMutation() == MUTATION::MAGICCREATURE ) { return; }
    srand(time(NULL) + enemy.getState().getHp());
    int marking = rand()%100;
    if ( marking < necromancerMarkingProbability && !enemy.getState().outOfHp()) {
        this->curseBook->addVictim(&enemy);
                std::cout << "\tNecro is marking: " << marking << std::endl;
    }
}

void Necromancer::attack(Unit& enemy) {
    if ( !alterEgoOn ) {
        if ( this->Unit::getState().outOfHp() ) { return; }
        this->victimMarking(enemy);
        this->getAttack().attack(enemy, *this);
    } else {
        this->getAttack().attack(enemy, *this);
    }
}

void Necromancer::castSpell(Unit* receiver) {
    if ( !alterEgoOn ) {
        if ( this->Unit::getState().outOfHp() ) { return; }
        if ( this->getState().getMana() >= this->getActiveSpell()->getCost() ) {
            this->getState().useMana(this->getActiveSpell()->getCost());
            if ( receiver ) {
                this->victimMarking(*receiver);
            }
            this->getActiveSpell()->action(receiver, this, this->getActiveSpell()->getMagicDmg());
        } else {
            std::cout << "Not enough mana" << '\n';
        }
    } else {
        std::cout << "Can't cast in alterEgo state" << '\n';
    }
}

void Necromancer::notifyObservers(Unit* observable) {
    this->curseBook->receiveDeadNote(observable);
}

// void Necromancer::listMarkedVictims() {
//     this->curseBook->listVictims();
// }

// void Warlock::notifyObservable(Unit* observer) {
//     for ( std::set<Demon*>::iterator it = this->demonBook->begin(); it != this->demonBook->end(); ) {
//         Demon* demon = (*it);
//         ++it;
//             std::cout << "kiling Demon" << demon->getState().getName() << std::endl;
//         demon->takeDamage(demon->getState().getMaxHp() * 2);
//     }
// }

std::ostream& operator<<(std::ostream& out, const Necromancer& necromancer) {
    out << necromancer.getUnitType() << " [";
    if ( necromancer.alterEgoOn ) {
    out << necromancer.Unit::getState()  << "] AlterEgo: [" << static_cast<NecromancerState&>(necromancer.Unit::getAlterState()) << ", active spell: " << necromancer.getActiveSpell()->getFormula() << ']';
    } else {
        out << static_cast<NecromancerState&>(necromancer.Unit::getState()) << ", active spell: " << necromancer.getActiveSpell()->getFormula() << ']';
        if ( &necromancer.Unit::getAlterState() != nullptr ) {
            out << " AlterEgo: [" << necromancer.Unit::getAlterState() << ']';
        }
    }
    
    out << " Mutation: [" << necromancer.getUnitMutation() << "]\n";
    
    out << "List of marked victims: ";
    if ( necromancer.getCurseBook()->listIsEmpty() ) {
        out << " is empty." << "\n";
    } else {
        out << "\n" << *necromancer.getCurseBook();
    }
    return out;
}
