#include <string>
#include <vector>
#include <algorithm>
#include "Player.h"

Player::Player()
	:HP(0), HPMax(0), MP(0), MPMax(0)
{
}

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

Player HotHeadPawn("Hot-Headed Pawn", "A Pawn like yourself, but seems to have a lust for combat training.\n", 50, 50, { "IMPACT","INFERNO" });
Player Bishop("Bishop", "A soldier who outranks you, but something seems off about him...\n", 70, 80, { "IMPACT","INFERNO" });