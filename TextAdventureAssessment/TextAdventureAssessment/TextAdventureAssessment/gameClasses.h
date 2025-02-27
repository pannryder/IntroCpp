#pragma once
#include <string>


class Room {
private:
	std::string description;
public:
	Item* item;
};

class Item {
public:
	const void Description();
	void Use();
};

class Player {

private:
	//list <std::string> spells;
public:
	Player();
	~Player();
	int Health;
	bool FindSpell(std::string spell);
};

class Spell {

public:
	std::string name;
	int damage;
	Spell(std::string name, int damage);
	void Cast();
};

class Game {
private:
	Room rooms;
	Player* player;

public:
	Game();
	~Game();
	void Run();

};

class Attacks {

};