#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "Item.h"

using std::string;
using std::vector;
using std::transform;
using std::cout;

class Player {

private:
	string name;
	vector<string> spells;
public:
	string description;
	int HP, HPMax;
	int MP, MPMax;
	Player();
	Player(string _name, string _description, int _hp, int _mp, vector<string> spellList);
	~Player();
	const string Name();
	const string Description();
	bool FindSpell(string spell);
};

