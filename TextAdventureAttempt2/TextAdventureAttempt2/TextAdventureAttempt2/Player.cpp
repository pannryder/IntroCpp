#include "Player.h"
#include <algorithm>

using std::sort;

Player::Player()
{
    spells = {"Torrent","Encase","Humm","Strum","Desire"};
}

Player::~Player()
{
}

//Binary search for spells
bool Player::SearchSpell(const string& spell, int left, int right) 
{
    if (left > right)
    {
        return false;
    }
    int mid = left + (right - left) / 2;

    if (spells[mid] == spell)
    {
        return true;
    }
    if (spells[mid] > spell) 
    {
        return SearchSpell(spell, left, mid - 1);
    }
    return SearchSpell(spell, mid + 1, right);
}

// Ensure the list is sorted before searching
bool Player::FindSpell(const string& spell) 
{
    sort(spells.begin(), spells.end());
    return SearchSpell(spell, 0, spells.size() - 1);
}