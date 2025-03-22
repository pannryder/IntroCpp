#include "Room.h"

Room::Room()
{

}

Room::Room(string descript, Item* item)
	:item(nullptr)
{
	description = descript;
}

Room::Room(string descript, Item* _item, bool battle, bool lock, int north, int east, int south, int west, int id)
{
	description = descript;
	RelativeN = north;
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

Room r1 = { "You are in barracks, where you and the other pawns rest after a hard days work.\nAs the Pawn said, the door will lock behind you when you leave.\nFrom here you can only go DOWN.\n",nullptr, false, false, 0, 0, 4, 0, 1 };
Room r2 = { "You are in the training room, this is where you can find pawns honing their magic, either with training dummies or sparring.\nAlthough, the training dummy in here seems to be burnt to a crisp.\nFrom here you can DOWN or RIGHT.\n",nullptr, true, false, 0, 3, 5, 0, 2 };
Room r3 = { "You are a dark room. Although, you can make out where some things are despite the lack of light.\nFrom here you can only go LEFT.\n",nullptr, false, false, 0,0,0,2,3 };
Room r4 = { "You are in the common room. When not doing the Emperor's tasks or patrolling, pawns reside here to relax.\nFrom here you can go DOWN or RIGHT.\n",nullptr, false, false,0,5,7,0,4 };
Room r5 = { "Room\nFrom here you can go UP, DOWN or LEFT\n",nullptr, false, false,2,0,8,4,5 };
Room r6 = { "Room",nullptr, true, false, 0,0,9,0,6 };
Room r7 = { "You are in the corner hall, here's where the stray cat that found it's way into our base lives.\nWe named him 'Mittens'.\nFrom here you can go UP or RIGHT.\n",nullptr, false, false,4,8,0,0,7 };
Room r8 = { "Room\nFrom here you can go UP, RIGHT or LEFT.\n",nullptr, false, false,5,9,0,7,8 };
Room r9 = { "This is the halway that leads to the Pawn Base's exit. The door is sometimes locked.\nFrom here you can go UP or LEFT.\n",nullptr, false, true,6,0,0,8,9 };