#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

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
	Player(string _name, string _description, int _hp, int _mp);
	~Player();
	const string Name();
	const string Description();
	//bool FindSpell(string spell);
};