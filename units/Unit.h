#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>

#include "../states/UnitState.h"
#include "../states/Observable.h"
#include "../attacks/UnitAttack.h"

class UnitAttack;
class Observable;

class Unit {
    private:
        std::string unitType;
        std::string unitMutation;
        UnitState* uState;
        UnitAttack* uAttack;
        UnitState* alterEgo;
        UnitAttack* alterAttack;
        Observable* observersList;
        
    public:
        Unit(const std::string& type, UnitState* state, UnitAttack* attack, const std::string& mutation = MUTATION::NONE, UnitState* alEgo = nullptr, UnitAttack* alAttack = nullptr);
        virtual ~Unit();
        bool alterEgoOn;
        
        virtual UnitState& getState() const;
        virtual UnitState& getAlterState() const;
        UnitAttack& getAttack() const;
        const std::string& getUnitType() const;
        const std::string& getUnitMutation() const;
        Observable* getObserversList() const;
        
        virtual void attack(Unit& enemy);
        void counterAttack(Unit& enemy);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
        void takeTreatment(int hp);
        void creatureMutation(const std::string& mutation = MUTATION::NONE, UnitState* state = nullptr, UnitAttack* attack = nullptr, UnitState* alEgo = nullptr, UnitAttack* alAttack = nullptr);
        void transform();
        virtual void notifyObservers(Unit* observable);
        virtual void notifyObservable(Unit* observer);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);



#endif // UNIT_H
