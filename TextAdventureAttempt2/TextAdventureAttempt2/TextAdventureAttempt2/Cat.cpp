#include "Cat.h"
#include <iostream>


Cat::Cat() 
    : purring(false)
{
}

void Cat::Description() const 
{
    std::cout << "An adorable tuxedo cat, staring at you with it's green eyes.\n";
}
void Cat::Use() 
{
    purring = !purring;
    std::cout << (purring ? "The cat begins to purr, it's slight vibrations feel pleasant.\n" : "The begins to subside its purring, sadly.\n");
}