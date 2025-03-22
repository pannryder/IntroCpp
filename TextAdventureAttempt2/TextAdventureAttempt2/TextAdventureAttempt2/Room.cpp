#include "Room.h"
#include <iostream>

using std::cout;

Room::Room(const string& desc, Item* item) 
    : description(desc), item(item), north(nullptr), south(nullptr), east(nullptr), west(nullptr)
{
}


Room::~Room() 
{
    delete item;
}

void Room::Description() const 
{
    cout << description << "\n";
    if (item) item->Description();
}

void Room::DefineExits(Room* n, Room* s, Room* e, Room* w) 
{
    north = n;
    south = s;
    east = e;
    west = w;
}

Room* Room::ReturnExit(const string& direction) 
{
    if (direction == "NORTH") 
    {
        return north;
    }
    if (direction == "SOUTH") 
    {
        return south;
    }
    if (direction == "EAST") 
    {
        return east;
    }
    if (direction == "WEST") 
    {
        return west;
    }
    return nullptr;
}

Item* Room::GetItem()
{
    return item;
}