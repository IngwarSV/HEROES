#ifndef UNITSTATE_H
#define UNITSTATE_H

#include <iostream>
#include <string>

class UnitState {
    private:
        std::string name;
        int maxHp;
        int dmg;

    protected:
        int hp;

    public:
        UnitState(const std::string& name, int health, int maxHealth, int damage, bool isUndead = false);
        virtual ~UnitState();
        bool outOfHp() const;
        bool isUnDead;
        const std::string& getName() const;
        int getHp() const;
        int getMaxHp() const;
        int getDmg() const;
        void setName(const std::string& name);
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);
        virtual void takeTreatment(int hp);
};

std::ostream& operator<<(std::ostream& out, const UnitState& state);

#endif // UNITSTATE_H
