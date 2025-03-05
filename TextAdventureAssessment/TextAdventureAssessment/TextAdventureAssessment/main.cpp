#include "gameClasses.cpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using std::cin;
using std::cout;
using std::transform;

void main()
{
	Player goblin("Goblin", "Green thing", 10, 5);
	Cat Mittens;
	Mittens.Description();
	Mittens.Use();
	Mittens.Use();
	Mittens.Use();
	Mittens.Use();
	string playerName;
	cin >> playerName;
	Player playerCharacter(playerName, "Wears yellow robes", 25, 10);
	Spell RedBlast("Red Blast", 20);
	Spell WhiteBlast("White Blast", 10);
	cout << playerCharacter.Name() << ".\n" << playerCharacter.Description() << ".\n";
	CurrentHP(playerCharacter);
	Attack(goblin,playerCharacter,RedBlast);
	CurrentHP(playerCharacter);
	Heal(playerCharacter,playerCharacter,WhiteBlast);
	CurrentHP(playerCharacter);
	return;
}

