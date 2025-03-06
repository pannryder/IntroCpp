#include "gameClasses.cpp"
#include "gameClasses.h"
#include "Item.h"
#include "Player.h"
#include "Spell.h"
#include "Actions.h"
#include "Room.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using std::cin;
using std::cout;
using std::transform;

int main()
{
	string playerName;
	cin >> playerName;
	Player playerCharacter(playerName, "Wears yellow robes", 25, 10,{ "BREATHE","ERRUPTION","IMPACT","INFERNO" });
	cout << playerCharacter.Name() << ".\n" << playerCharacter.Description() << ".\n";
	CurrentHP(playerCharacter);
	Attack(goblin, playerCharacter, Inferno);
	CurrentHP(playerCharacter);
	Attack(playerCharacter, playerCharacter, Breathe);
	Attack(playerCharacter, playerCharacter, Breathe);
	Attack(playerCharacter, playerCharacter, Breathe);
	CurrentHP(playerCharacter);
	return (0);
}

