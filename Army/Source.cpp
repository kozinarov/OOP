#include <iostream>
using namespace std;

#include "Soldier.h"
#include "Sergeant.h"
#include "Spell.h"
#include "SpellBook.h"
#include "Wizard.h"
#include "Commander.h"

int main()
{
	Soldier a("aaa", 32, 100, 3000);
	Soldier b;
	b = a;

	Soldier* soldiers = new Soldier[5];
	soldiers[0] = Soldier("aaa", 30, 100, 3000);
	soldiers[1] = Soldier("bbb", 31, 101, 3001);
	soldiers[2] = Soldier("ccc", 32, 102, 3002);
	soldiers[3] = Soldier("ddd", 33, 103, 3003);
	soldiers[4] = Soldier("eee", 34, 104, 3004);

	Sergeant sergeant("Tosho", 40, 400, 5000, "squad1", soldiers, 5);

	Spell spell1("lighting", "kill", 10);
	Spell spell2("ghj", "attack", 200);
	Spell spell3("oij", "harm", 5);
	Spell spell4("sdx", "heal", 30);
	Spell spell5("poiy", "kill", 32);

	SpellBook spellBook;
	spellBook.add(spell1);
	spellBook.add(spell2);
	spellBook.add(spell3);
	spellBook.add(spell4);
	spellBook.add(spell5);

	//for now the sergeants have the same soldiers
	Sergeant* sergeants = new Sergeant[5];
	
	sergeants[0] = Sergeant("Tosho", 40, 400, 5000, "squad1", soldiers, 5);
	sergeants[1] = Sergeant("Gosho", 41, 401, 5001, "squad2", soldiers, 5);
	sergeants[2] = Sergeant("Pesho", 42, 402, 5002, "squad3", soldiers, 5);
	sergeants[3] = Sergeant("Toncho", 43, 403, 5003, "squad4", soldiers, 5);
	sergeants[4] = Sergeant("Petkan", 44, 404, 5004, "squad5", soldiers, 5);
	
	Wizard wizard("Voldemort", 70, 700, 7000, "wizard1", sergeants, 5, 100, spellBook);

	//for now the wizards have the same spellbook and the same sergeants whit the same soldiers
	Wizard* wizards = new Wizard[5];
	wizards[0] = Wizard("Voldemort", 70, 700, 7000, "wizard1", sergeants, 5, 100, spellBook);
	wizards[1] = Wizard("Potter", 71, 701, 7001, "wizard2", sergeants, 5, 120, spellBook);
	wizards[2] = Wizard("Kelesha", 72, 702, 7002, "wizard3", sergeants, 5, 130, spellBook);
	wizards[3] = Wizard("Shibanqka", 73, 703, 7003, "wizard4", sergeants, 5, 140, spellBook);
	wizards[4] = Wizard("Pederasa", 74, 704, 7004, "wizard5", sergeants, 5, 150, spellBook);
	
	Commander commander("Shefa", 80, 1000, 10000, "army", wizards, 5);

	cout << "Sum Strenght: " << commander.sumStrenght() << endl;
	cout << "Average Strenght: " << commander.averageStrenght() << endl;
	cout << "Sum Mana: " << commander.sumMana() << endl;
	cout << "Average Mana: " << commander.averageMana() << endl;
	cout << "Sum paychecks: " << commander.sumSalary() << endl;
	cout << "Sum Max Spells: " << commander.sumMaxSpells() << endl;
	return 0;
}