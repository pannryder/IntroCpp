#include"BoxOfDonuts.h"
#include <iostream>

using std::cout;

BoxOfDonuts::BoxOfDonuts(int initialCount) 
    : count(initialCount) 
{
}

void BoxOfDonuts::Description() const 
{
    if (count > 0) 
    {
        cout << "A box of assorted donuts of many flavors, with " << count << " left.\n";
    }
    else 
    {
        cout << "An empty box that HAD donuts...\n";
    }
}

void BoxOfDonuts::Use() 
{
    if (count > 0) 
    {
        count--;
        cout << "You consume a donut, each bite tingling your senses. The amount of donuts remaining is : " << count << ".\n";
    }
    else 
    {
        cout << "All donuts are gone. How sad...\n";
    }
}