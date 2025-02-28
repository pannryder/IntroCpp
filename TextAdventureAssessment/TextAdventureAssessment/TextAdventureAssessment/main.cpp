#include "gameClasses.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>

using std::cin;
using std::cout;
using std::transform;

void main()
{
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
	cout << playerCharacter.Name() << ".\n" << playerCharacter.Description() << ".\n";
	cout << playerCharacter.Name() << " is at " << playerCharacter.HP << ".\n";
	cout << "Enemy casts " << RedBlast.name << ", causing " << RedBlast.damage << " damage!\n";
	Attack(playerCharacter,RedBlast);
	cout << playerCharacter.Name() << " is now at " << playerCharacter.HP << ".\n";
	return;
}

