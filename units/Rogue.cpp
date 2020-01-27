#include "Rogue.h"

Rogue::Rogue(const std::string& name, const std::string& type, int health, int damage) : Unit(type, new RogueState(name, health, damage), new RogueAttack()) {}

Rogue::~Rogue() {}
