#pragma once
#include <iostream>
#include <string>
#include "Item.h"

//Defualt Room Class
class Room 
{
private:
    std::string description;
    Room* north;
    Room* south;
    Room* east;
    Room* west;
public:
    Room();
    Room(const std::string& desc, Item* item);
    ~Room();
    Item* item;
    void Description() const;
    void SetRoom(const std::string& desc, Item* item);
    void DefineExits(Room* n, Room* s, Room* e, Room* w);
    Room* ReturnExit(const std::string& direction);
    Item* GetItem();
};
