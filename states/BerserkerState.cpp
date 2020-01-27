#include "BerserkerState.h"

BerserkerState::BerserkerState(const std::string& name, int health, int damage) : UnitState (name, health, health, damage) {
    std::cout << " creating BerserkerState " << std::endl;
}

BerserkerState::~BerserkerState() {
    std::cout << " deleting BerserkerState " << std::endl;
}

void BerserkerState::takeMagicDamage(int dmg) {}

void BerserkerState::takeTreatment(int hp) {}
