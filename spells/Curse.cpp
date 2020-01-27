#include "Curse.h"

Curse::Curse(int magicDamage, int cost, const std::string& formula): Spell(magicDamage, cost, formula) {}

void Curse::action(Unit* enemy, Unit* attacker, int magicDamage) {
    Necromancer* necromancer = dynamic_cast<Necromancer*>(attacker);
    if ( !necromancer ) { return; }
    
    std::cout << "Curse!" << std::endl;
    
    auto it = necromancer->getCurseBook()->getListOfVictims()->begin();
    
    for ( ; it != necromancer->getCurseBook()->getListOfVictims()->end(); ) {
        std::cout << (*it) << std::endl;
        std::cout << "Start!" << std::endl;
        Unit* temp = *it;
        ++it;
        temp->takeMagicDamage(magicDamage);
        std::cout << "Next!" << std::endl;
    }
}


