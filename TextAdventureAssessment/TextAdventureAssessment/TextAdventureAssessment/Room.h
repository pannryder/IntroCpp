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
	~Room();
	void Description() const;
};

Room::Room() {

}

Room::Room(string descript, Item* item)
	:item(NULL)
{
	description = descript;
}

Room::~Room()
{
}

void Room::Description() const
{
	cout << description;
}

Room r1 = { "The barracks, where you and the other pawns rest after a hard days work.",NULL };
Room r2 = { "The training room, this is where you can find pawns honing their magic, either with training dummies or sparring.",NULL };
Room r3 = { "The dark room. The room that is dark, crazy that. It is a good room.",NULL };
Room r4 = { "The common room, when not doing the Emperor's tasks or patrolling, pawns reside here to relax.",NULL };
Room r5 = { "Room",NULL };
Room r6 = { "Room",NULL };
Room r7 = { "Room",NULL };
Room r8 = { "Room",NULL };
Room r9 = { "Room",NULL };