#include "RogueState.h"

RogueState::RogueState(const std::string& name, int health, int damage) : UnitState (name, health, health, damage) {}

RogueState::~RogueState() {}

