#pragma once
#include <string>

using std::string;

class Spell {

public:
	string name;
	int damage;
	Spell(string _name, int _damage);
	void Cast();
	//static bool Compare(Spell a, Spell b);
};