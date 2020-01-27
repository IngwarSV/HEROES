# rm:
# 	rm *.o

compile_all:
	g++ -std=c++11 spells/Spell.cpp -c
	g++ -std=c++11 spells/Fireball.cpp -c
	g++ -std=c++11 spells/Healing.cpp -c
	g++ -std=c++11 spells/Curse.cpp -c
	g++ -std=c++11 spells/demonSummon.cpp -c
	
	g++ -std=c++11 attacks/UnitAttack.cpp -c
	g++ -std=c++11 attacks/RogueAttack.cpp -c
	g++ -std=c++11 attacks/VampireAttack.cpp -c
	g++ -std=c++11 attacks/WerewolfAttack.cpp -c
	g++ -std=c++11 attacks/SpellCasterAttack.cpp -c
	g++ -std=c++11 attacks/WizardAttack.cpp -c
	g++ -std=c++11 attacks/HealerAttack.cpp -c
	g++ -std=c++11 attacks/PriestAttack.cpp -c
	g++ -std=c++11 attacks/WarlockAttack.cpp -c
	g++ -std=c++11 attacks/NecromancerAttack.cpp -c

	g++ -std=c++11 states/UnitState.cpp -c
	g++ -std=c++11 states/SoldierState.cpp -c
	g++ -std=c++11 states/DemonState.cpp -c
	g++ -std=c++11 states/RogueState.cpp -c
	g++ -std=c++11 states/BerserkerState.cpp -c
	g++ -std=c++11 states/VampireState.cpp -c
	g++ -std=c++11 states/WerewolfState.cpp -c
	g++ -std=c++11 states/SpellCasterState.cpp -c
	g++ -std=c++11 states/WizardState.cpp -c
	g++ -std=c++11 states/HealerState.cpp -c
	g++ -std=c++11 states/PriestState.cpp -c
	g++ -std=c++11 states/WarlockState.cpp -c
	g++ -std=c++11 states/NecromancerState.cpp -c
	g++ -std=c++11 states/Observable.cpp -c
	g++ -std=c++11 states/Observer.cpp -c
	

	g++ -std=c++11 units/Unit.cpp -c
	g++ -std=c++11 units/Soldier.cpp -c
	g++ -std=c++11 units/Demon.cpp -c
	g++ -std=c++11 units/Rogue.cpp -c
	g++ -std=c++11 units/Berserker.cpp -c
	g++ -std=c++11 units/Vampire.cpp -c
	g++ -std=c++11 units/Werewolf.cpp -c
	g++ -std=c++11 units/SpellCaster.cpp -c
	g++ -std=c++11 units/Wizard.cpp -c
	g++ -std=c++11 units/Healer.cpp -c
	g++ -std=c++11 units/Priest.cpp -c
	g++ -std=c++11 units/Warlock.cpp -c
	g++ -std=c++11 units/Necromancer.cpp -c


all: compile_all
	g++ -std=c++11 run.cpp *.o
	rm *.o

run: all
	a.exe






