#include "Cat.h"
#include <iostream>

using std::cout;

Cat::Cat() 
    : purring(false)
{
}

void Cat::Description() const 
{
    cout << "An adorable tuxedo cat, staring at you with it's green eyes.\n";
}
void Cat::Use() 
{
    purring = !purring;
    cout << (purring ? "The cat begins to purr, it's slight vibrations feel pleasant.\n" : "The begins to subside its purring, sadly.\n");
}