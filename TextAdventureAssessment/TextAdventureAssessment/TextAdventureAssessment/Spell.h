#pragma once
#include <string>
#include <iostream>
#include "Player.h"

using std::string;
using std::cout;

class Spell {
public:
	string name;
	int damage;
	string descript;
	int cost;
	bool doesHeal;
	Spell(string _name, int _damage, string _descript, int _cost, bool _healing);
	static bool Compare(Spell a, Spell b);
};
Spell& referenceSpell(string _call);