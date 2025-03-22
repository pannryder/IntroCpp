#pragma once
#include <string>
#include <iostream>
#include "Item.h"

using std::string;
using std::cout;

class Room {
private:
	string description;
public:
	Item* item;
	Room();
	Room(string descript, Item* item);
	Room(string descript, Item* _item, bool battle, bool lock, int north, int east, int south, int west, int id);
	~Room();
	void Description() const;
	int RelativeN;
	int RelativeE;
	int RelativeS;
	int RelativeW;
	int RoomID;
	bool isBattle;
	bool isLocked;
};