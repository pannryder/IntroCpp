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
	Room(string descript, Item* item, int north, int east, int south, int west, int id, int x, int y);
	~Room();
	void Description() const;
	int RelativeN;
	int RelativeE;
	int RelativeS;
	int RelativeW;
	int RoomID;
	int RoomX;
	int RoomY;
};

Room::Room()
{

}

Room::Room(string descript, Item* item)
	:item(NULL)
{
	description = descript;
}

Room::Room(string descript, Item* item, int north, int east, int south, int west, int id, int x, int y) 
	:item(NULL)
{
	description = descript;
	RelativeN =  north;
	RelativeE = east;
	RelativeS = south;
	RelativeW = west;
	RoomID = id;
	RoomX = x;
	RoomY = y;
}

Room::~Room()
{
}

void Room::Description() const
{
	cout << description << "\n";
}

Room r1 = { "The barracks, where you and the other pawns rest after a hard days work.",NULL, 0, 0, 4, 0, 1, 0,0 };
Room r2 = { "The training room, this is where you can find pawns honing their magic, either with training dummies or sparring.\nAlthough, the training dummy in here seems to be burnt to a crisp.",NULL, 0, 3, 5, 0, 2,0,1 };
Room r3 = { "The dark room. The room that is dark, crazy that. It is a good room.",lantern, 0,0,0,2,3,0,2 };
Room r4 = { "The common room, when not doing the Emperor's tasks or patrolling, pawns reside here to relax.",NULL,1,5,7,0,4,1,0 };
Room r5 = { "Room",donuts,2,0,8,4,5,1,1 };
Room r6 = { "Room",NULL,0,0,9,0,6,1,2 };
Room r7 = { "Room",mittens,4,8,0,0,7,2,0 };
Room r8 = { "Room",NULL,5,9,0,7,8,2,1 };
Room r9 = { "Room",NULL,6,0,0,8,9,2,2 };