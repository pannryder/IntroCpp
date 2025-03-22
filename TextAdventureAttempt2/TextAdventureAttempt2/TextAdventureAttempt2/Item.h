#pragma once


//Defualt Item class
class Item 
{
public:
    virtual ~Item();
    virtual void Description() const;
    virtual void Use();
};