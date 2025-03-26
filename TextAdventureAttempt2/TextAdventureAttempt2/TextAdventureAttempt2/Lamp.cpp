#include "Lamp.h"
#include <iostream>

Lamp::Lamp() 
    : turnedOn(false)
{
}

void Lamp::Description() const 
{
    std::cout << "A rusty, but somehow still endreading lantern.\n";
}
void Lamp::Use() 
{
    turnedOn = !turnedOn;
    std::cout << (turnedOn ? "The lantern's flame flickers on, illumnating the area.\n" : "The lanterns flame dies, bringing back the darkness.\n");
}