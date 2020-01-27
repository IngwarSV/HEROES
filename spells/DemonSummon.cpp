#include "DemonSummon.h"

DemonSummon::DemonSummon(int magicDamage, int cost, const std::string& formula): Spell(magicDamage, cost, formula) {
    this->demonNumber = 1;
}

void DemonSummon::action(Unit* enemy, Unit* attacker, int magicDamage) {
    Warlock* warlock = dynamic_cast<Warlock*>(attacker);
    if ( !warlock ) { return; }
    
    warlock->addDemon(new Demon(warlock, warlock->getState().getName() + "_Demon_" + std::to_string(this->demonNumber)));
    this->demonNumber += 1;
    std::cout << "Demon is waiting!" << std::endl;
}


