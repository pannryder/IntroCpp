#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

//class Game {
//private:
//	Room[][] rooms;
//	Player* player;
//
//public:
//	Game();
//	~Game();
//	void Run();
//
//};

class Room {
private:
	string description;
public:
	Item* item;
	Room(string description, Item* item);
	~Room();
	const void Description();
};

class Item {
public:
	const void Description();
	void Use();
};

class Player {

private:
	string name;
	vector<string> spells;
public:
	string description;
	int HP;
	int MP;
	Player(string _name, string _description, int _hp, int _mp);
	~Player();
	const string Name();
	const string Description();
	//bool FindSpell(string spell);
};

class Spell {

public:
	string name;
	int damage;
	Spell(string _name, int _damage);
	void Cast();
	//static bool Compare(Spell a, Spell b);
};

class BoxOfDonuts : public Item {
	int count;
public:
	BoxOfDonuts();
	const void Description();
	void Use();
};

class Lamp : public Item {
	bool turnedOn;
public:
	Lamp();
	const void Description();
	void Use();
};

class Cat : public Item {
	bool purring;
public :
	Cat();
	const void Description();
	void Use();
};

int Attack(Player& _target, Spell& _dmg);