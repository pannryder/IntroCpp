#pragma once
#include "Item.h"

//BoxOfDonuts class, derived from Item
class BoxOfDonuts : public Item 
{
private:
    int count;
public:
    BoxOfDonuts(int initialCount);
    void Description() const;
    void Use();
};
