#pragma once
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::transform;

class Player {

private:
	string name;
	vector<string> spells;
public:
	string description;
	int HP;
	int HPMax;
	int MP;
	int MPMax;
	Player(string _name, string _description, int _hp, int _mp, vector<string> spellList);
	~Player();
	const string Name();
	const string Description();
	bool FindSpell(string spell);
};

Player::Player(string _name, string _description, int _hp, int _mp, vector<string> spellList)
{
	name = _name;
	description = _description;
	HPMax = _hp;
	HP = _hp;
	MPMax = _mp;
	MP = _mp;
	spells = spellList;
}

Player::~Player()
{
}

const string Player::Name()
{
	return name;
}

const string Player::Description()
{
	return description;
}

bool Player::FindSpell(string spell) 
{
	string _search = spell;
	transform(_search.begin(), _search.end(), _search.begin(), ::toupper);
	if (std::binary_search(spells.begin(), spells.end(), _search) == true) {
		return true;
	}
	else {
		cout << name << " doesn't know what '" << spell << "' is.\n";
		return false;
	}
}

Player goblin("Goblin", "Green thing", 10, 5, { "IMPACT" });