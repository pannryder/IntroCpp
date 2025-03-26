#pragma once
#include <iostream>
#include <vector>
#include <string>

//Defualt Player Class
class Player 
{
private:
    std::vector<std::string> spells;
    bool SearchSpell(const std::string& spell, int left, int right);
public:
    Player();
    ~Player();
    bool FindSpell(const std::string& spell);
};
