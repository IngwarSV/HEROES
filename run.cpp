#include <iostream>

#include "units/Soldier.h"
#include "units/Demon.h"
#include "units/Rogue.h"
#include "units/Berserker.h"
#include "units/Vampire.h"
#include "units/Werewolf.h"
#include "units/Wizard.h"
#include "units/Healer.h"
#include "units/Priest.h"
#include "units/Warlock.h"
#include "units/Necromancer.h"

int main() {

    Soldier* s1 = new Soldier("S1");
    Rogue* r1 = new Rogue("R1");
    Berserker* b1 = new Berserker("B1");
    Vampire* v1 = new Vampire("Vamp1");
    Werewolf* wer1 = new Werewolf("Wer1");
    Wizard* wiz1 = new Wizard("Wiz1");
    Healer* hel1 = new Healer("Hel1");
    Priest* pr1 = new Priest("Pr1");
    Necromancer* nec1 = new Necromancer("Nec1");
    Warlock* war1 = new Warlock("War1");
    
    war1->chooseSpell("ds");
    war1->castSpell();
    Demon* d1 = war1->summonDemon();
    
    std::cout << *s1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << *b1 << std::endl;
    std::cout << *v1 << std::endl;
    std::cout << *wer1 << std::endl;
    std::cout << *wiz1 << std::endl;
    std::cout << *hel1 << std::endl;
    std::cout << *pr1 << std::endl;
    std::cout << *nec1 << std::endl;
    std::cout << *war1 << std::endl;
    std::cout << *d1 << std::endl;
    wer1->transform();
    std::cout << "------------------" << std::endl;
    v1->attack(*wer1);
    wer1->attack(*v1);
    v1->attack(*s1);
    s1->attack(*r1);
    wer1->attack(*pr1);
    nec1->castSpell(b1);
    pr1->castSpell(nec1);
    nec1->castSpell(d1);
    nec1->castSpell(d1);
    wer1->attack(*pr1);
    pr1->castSpell(wer1);
    // pr1->castSpell(wer1);
    // v1->attack(*s1);
    
    std::cout << "------------------" << std::endl;
    std::cout << *s1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << *v1 << std::endl;
    std::cout << *b1 << std::endl;
    std::cout << *wer1 << std::endl;
    std::cout << *pr1 << std::endl;
    std::cout << *nec1 << std::endl;
    std::cout << *d1 << std::endl;
    std::cout << "------------------" << std::endl;
    delete(s1);
    delete(r1);
    delete(b1);
    delete(v1);
    delete(wer1);
    delete(wiz1);
    delete(hel1);
    delete(pr1);
    delete(nec1);
    delete(war1);
    delete(d1);
    
    return 0;
}
