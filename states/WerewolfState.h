#ifndef WEREWOLFSTATE_H
#define WEREWOLFSTATE_H

#include "../Specifications.h"
#include "UnitState.h"

class WerewolfState : public UnitState {
    public:
        WerewolfState(const std::string& name, int alterHealth = static_cast<int>(HP::WEREWOLF), int alterMaxHealth = static_cast<int>(HP::WEREWOLF), int alterDamage = static_cast<int>(DMG::WEREWOLF));
        virtual ~WerewolfState();
        
        virtual void takeMagicDamage(int dmg) override;
};

#endif // WEREWOLFSTATE_H
