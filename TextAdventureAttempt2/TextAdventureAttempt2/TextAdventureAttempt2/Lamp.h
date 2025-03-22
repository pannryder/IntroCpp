#pragma once
#include "Item.h"

//Lamp class, derived from Item
class Lamp : public Item 
{
private:
    bool turnedOn;
public:
    Lamp();
    void Description() const;
    void Use();
};
