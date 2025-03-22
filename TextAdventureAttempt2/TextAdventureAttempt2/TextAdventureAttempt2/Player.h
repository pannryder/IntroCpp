#pragma once
#include <iostream>
#include <vector>

using std::vector;
using std::string;

//Defualt Player Class
class Player 
{
private:
    vector<string> spells;
    bool SearchSpell(const string& spell, int left, int right);
public:
    Player();
    ~Player();
    bool FindSpell(const string& spell);
};
