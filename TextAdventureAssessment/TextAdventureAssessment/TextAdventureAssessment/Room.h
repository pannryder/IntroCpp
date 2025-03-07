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

Room::Room()
{

}

Room::Room(string descript, Item* item)
	:item(NULL)
{
	description = descript;
}

Room::Room(string descript, Item* _item, bool battle, bool lock, int north, int east, int south, int west, int id)
{
	description = descript;
	RelativeN =  north;
	RelativeE = east;
	RelativeS = south;
	RelativeW = west;
	RoomID = id;
	isBattle = battle;
	isLocked = lock;
	item = _item;
}

Room::~Room()
{
}

void Room::Description() const
{
	cout << description << "\n";
}

Room r1 = { "You are in barracks, where you and the other pawns rest after a hard days work.\nAs the Pawn said, the door will lock behind you when you leave.\nFrom here you can only go DOWN.\n",NULL, false, false, 0, 0, 4, 0, 1 };
Room r2 = { "You are in the training room, this is where you can find pawns honing their magic, either with training dummies or sparring.\nAlthough, the training dummy in here seems to be burnt to a crisp.\nFrom here you can DOWN or RIGHT.\n",NULL, true, false, 0, 3, 5, 0, 2 };
Room r3 = { "You are a dark room. Although, you can make out where some things are despite the lack of light.\nFrom here you can only go LEFT.\n",lantern, false, false, 0,0,0,2,3 };
Room r4 = { "You are in the common room. When not doing the Emperor's tasks or patrolling, pawns reside here to relax.\nFrom here you can go DOWN or RIGHT.\n",NULL, false, false,0,5,7,0,4 };
Room r5 = { "Room\nFrom here you can go UP, DOWN or LEFT\n",donuts, false, false,2,0,8,4,5 };
Room r6 = { "Room",NULL, true, false, 0,0,9,0,6 };
Room r7 = { "You are in the corner hall, here's where the stray cat that found it's way into our base lives.\nWe named him 'Mittens'.\nFrom here you can go UP or RIGHT.\n",mittens, false, false,4,8,0,0,7 };
Room r8 = { "Room\nFrom here you can go UP, RIGHT or LEFT.\n",NULL, false, false,5,9,0,7,8 };
Room r9 = { "This is the halway that leads to the Pawn Base's exit. The door is sometimes locked.\nFrom here you can go UP or LEFT.\n",NULL, false, true,6,0,0,8,9 };