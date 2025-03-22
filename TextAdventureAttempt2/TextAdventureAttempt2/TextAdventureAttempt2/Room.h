#pragma once
#include <iostream>
#include "Item.h"

using std::string;

//Defualt Room Class
class Room 
{
private:
    string description;
    Item* item;
    Room* north;
    Room* south;
    Room* east;
    Room* west;
public:
    Room(const string& desc, Item* item);
    ~Room();
    void Description() const;
    void DefineExits(Room* n, Room* s, Room* e, Room* w);
    Room* ReturnExit(const string& direction);
    Item* GetItem();
};
