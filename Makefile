# make -f Makefile-1 - вказання шляху до мейкфайлу

CC = g++
CFLAGS= -c
C++11 = -std=c++11

compile_all:
	$(CC) -std=c++11 spells/Spell.cpp $(CFLAGS)
	$(CC) -std=c++11 spells/Fireball.cpp $(CFLAGS)
	$(CC) -std=c++11 spells/Healing.cpp $(CFLAGS)
	$(CC) -std=c++11 spells/Curse.cpp $(CFLAGS)
	$(CC) -std=c++11 spells/demonSummon.cpp $(CFLAGS)
	
	$(CC) -std=c++11 attacks/UnitAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/RogueAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/VampireAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/WerewolfAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/SpellCasterAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/WizardAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/HealerAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/PriestAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/WarlockAttack.cpp $(CFLAGS)
	$(CC) -std=c++11 attacks/NecromancerAttack.cpp $(CFLAGS)

	$(CC) -std=c++11 states/UnitState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/SoldierState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/DemonState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/RogueState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/BerserkerState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/VampireState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/WerewolfState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/SpellCasterState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/WizardState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/HealerState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/PriestState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/WarlockState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/NecromancerState.cpp $(CFLAGS)
	$(CC) -std=c++11 states/Observable.cpp $(CFLAGS)
	$(CC) -std=c++11 states/Observer.cpp $(CFLAGS)
	

	$(CC) -std=c++11 units/Unit.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Soldier.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Demon.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Rogue.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Berserker.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Vampire.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Werewolf.cpp $(CFLAGS)
	$(CC) -std=c++11 units/SpellCaster.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Wizard.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Healer.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Priest.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Warlock.cpp $(CFLAGS)
	$(CC) -std=c++11 units/Necromancer.cpp $(CFLAGS)


all: compile_all
	$(CC) -std=c++11 run.cpp *.o
	rm *.o

run: all
	a.exe






