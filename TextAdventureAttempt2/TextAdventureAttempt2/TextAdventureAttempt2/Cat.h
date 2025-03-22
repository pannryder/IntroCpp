#pragma once
#include "Item.h"

//Cat class, derived from Item
class Cat : public Item 
{
private:
    bool purring;
public:
    Cat();
    void Description() const;
    void Use();
};

