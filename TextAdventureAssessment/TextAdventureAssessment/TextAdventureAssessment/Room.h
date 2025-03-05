#pragma once
#include <string>
#include "Item.h"

using std::string;

class Room {
private:
	string description;
public:
	Item* item;
	Room(string descript, Item* item);
	~Room();
	void Description() const;
};