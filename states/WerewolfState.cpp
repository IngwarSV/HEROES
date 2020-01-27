#include "WerewolfState.h"

WerewolfState::WerewolfState(const std::string& name, int alterHealth, int alterMaxHealth, int alterDamage) : UnitState(name + "_Wolf", alterHealth, alterMaxHealth, alterDamage) {
    std::cout << " creating WerewolfState " << std::endl;
}

WerewolfState::~WerewolfState() {
    std::cout << " deleting WerewolfState " << std::endl;
}

void WerewolfState::takeMagicDamage(int dmg) {
    this->hp -= dmg * 2;
    if ( this->hp < 1 ) {
        this->hp = 0;
    }
}
