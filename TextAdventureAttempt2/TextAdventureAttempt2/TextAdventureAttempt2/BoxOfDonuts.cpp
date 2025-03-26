#include"BoxOfDonuts.h"
#include <iostream>

BoxOfDonuts::BoxOfDonuts(int initialCount) 
    : count(initialCount) 
{
}

void BoxOfDonuts::Description() const 
{
    if (count > 0) 
    {
        std::cout << "A box of assorted donuts of many flavors, with " << count << " left.\n";
    }
    else 
    {
        std::cout << "An empty box that HAD donuts...\n";
    }
}

void BoxOfDonuts::Use() 
{
    if (count > 0) 
    {
        count--;
        std::cout << "You consume a donut, each bite tingling your senses. The amount of donuts remaining is : " << count << ".\n";
    }
    else 
    {
        std::cout << "All donuts are gone. How sad...\n";
    }
}