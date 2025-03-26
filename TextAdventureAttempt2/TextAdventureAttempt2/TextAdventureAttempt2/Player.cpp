#include "Player.h"

Player::Player()
{
    spells = {"Desire","Encase","Humm","Strum","Torrent"};
}

Player::~Player()
{
}

//Binary search for spells
bool Player::SearchSpell(const std::string& spell, int left, int right)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (spells[mid] == spell) {
            return true;
        }
        else if (spells[mid] < spell) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

// Searches for spell
bool Player::FindSpell(const std::string& spell)
{
    return SearchSpell(spell, 0, spells.size() - 1);
}