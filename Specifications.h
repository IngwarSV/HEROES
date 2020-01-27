#ifndef SPECIFICATIONS_H
#define SPECIFICATIONS_H

#include <string>

enum class HP {
    SOLDIER = 100,
    DEMON = 100,
    ROGUE = 85,
    BERSERKER = 120,
    VAMPIRE = 110,
    WEREWOLF = 200,
    WIZARD = 80,
    HEALER = 50,
    PRIEST = 60,
    WARLOCK = 105,
    NECROMANCER = 90
};

enum class DMG {
    SOLDIER = 20,
    DEMON = 20,
    ROGUE = 25,
    BERSERKER = 35,
    VAMPIRE = 30,
    WEREWOLF = 30,
    WIZARD = 15,
    HEALER = 10,
    PRIEST = 10,
    WARLOCK = 15,
    NECROMANCER = 15
};

enum class MANA {
    WIZARD = 50,
    HEALER = 40,
    PRIEST = 40,
    WARLOCK = 60,
    NECROMANCER = 60
};

enum class FIREBALL {
    STANDARD = 10,
    HEALER = 20,
    PRIEST = 20,
    WIZARD = 40,
    WARLOCK = 40,
    NECROMANCER = 40,
    COST = 10
};

enum class HEALING {
    STANDARD = 10,
    HEALER = 40,
    PRIEST = 40,
    WIZARD = 20,
    WARLOCK = 20,
    NECROMANCER = 20,
    COST = 10
};

enum class CURSE {
    STANDARD = 10,
    NECROMANCER = 20,
    COST = 10
};

enum class DEMONSUMMON {
    STANDARD = 0,
    COST = 20
};

namespace castFormulas {
        const std::string FIREBALL = "fb";
        const std::string HEALING = "heal";
        const std::string CURSE = "curse";
        const std::string DEMONSUMMON = "ds";
};

const int vampireCreationProbability = 100; //Probability 100%
const int werewolfCreationProbability = 100; //Probability 100%
const int vampireBleedingDamage = 20; //20-th part of enemy's current Hp
const int necromancerTribute = 10; //10-th part of enemy's maxHp
const int necromancerMarkingProbability = 100; //Probability 100%
const int warlockMaxDemons = 10;


namespace TYPE {
    const std::string UNIT = "Unit";
    const std::string SOLDIER = "Soldier";
    const std::string DEMON = "Demon";
    const std::string ROGUE = "Rogue";
    const std::string BERSERKER = "Berserker";
    const std::string VAMPIRE = "Vampire";
    const std::string WEREWOLF = "Werewolf";
    const std::string WIZARD = "Wizard";
    const std::string HEALER = "Healer";
    const std::string PRIEST = "Priest";
    const std::string WARLOCK = "Warlock";
    const std::string NECROMANCER = "Necromancer";
}

namespace MUTATION {
    const std::string NONE = "none";
    const std::string VAMPIRE = "Vampire";
    const std::string WEREWOLF = "Werewolf";
    const std::string MAGICCREATURE = "MagicCreature";
}
#endif // SPECIFICATIONS_H
