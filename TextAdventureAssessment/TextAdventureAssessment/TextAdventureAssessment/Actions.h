#pragma once
#include "Player.h"
#include "Spell.h"
#include <algorithm>

using std::transform;
using std::string;

int Action();
int Attack(Player& _attacker, Player& _target, Spell& _spell);
void CurrentHP(Player& _target);
int Movement();
string toUpper(string _input);
int Battle(Player& _player, Player& _npc);

int Action()
{
	cout << "What action would you like to preform?\nMOVE | ITEM | ATTACK\n";
	string Action;
	cin >> Action;
	Action = toUpper(Action);
	for (;;)
	{
		if (Action == "MOVE")
		{
			return (1);
		}
		else if (Action == "ITEM" || Action == "USE ITEM")
		{
			return (2);
		}
		else if (Action == "ATTACK")
		{
			return (3);
		}
		else
		{
			cout << "Please write a valid action.\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> Action;
			Action = toUpper(Action);
		}

	}
}

string toUpper(string _input)
{
	transform(_input.begin(), _input.end(), _input.begin(), ::toupper);
	return _input;
}

int Movement()
{
	cout << "Which direction would you like to go?\n";
	string MoveDirection;
	cin >> MoveDirection;
	MoveDirection = toUpper(MoveDirection);
	for (;;)
	{
		if (MoveDirection == "LEFT" || MoveDirection == "WEST")
		{
			return (1);
		}
		else if (MoveDirection == "RIGHT" || MoveDirection == "EAST")
		{
			return (2);
		}
		else if (MoveDirection == "FORWARD" || MoveDirection == "UP" || MoveDirection == "NORTH")
		{
			return (3);
		}
		else if (MoveDirection == "BACK" || MoveDirection == "DOWN" || MoveDirection == "SOUTH")
		{
			return (4);
		}
		else
		{
			cout << "Please write a valid direction.\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> MoveDirection;
			MoveDirection = toUpper(MoveDirection);
		}

	}
}



//int UseItem()
//{
//	;
//}
//

int Attack(Player& _attacker, Player& _target, Spell& _spell)
{
	bool check = _attacker.FindSpell(_spell.name);
	if (check == true) {

		if (_spell.doesHeal == true) {
			cout << _attacker.Name() << " heals with " << _spell.name << ", restoring " << _spell.damage << "HP!\n";
			if (_target.HP + _spell.damage > _target.HPMax)
			{
				return _target.HP = _target.HPMax;
			}
			else {
				return _target.HP = _target.HP + _spell.damage;
			}
		}
		else
		{
			if (_target.HP - _spell.damage <= 0)
			{
				cout << _attacker.Name() << " attacks with " << _spell.name << ", dealing " << _spell.damage << " damage!\n";
				return _target.HP = 0;
			}
			else {
				cout << _attacker.Name() << " attacks with " << _spell.name << ", dealing " << _spell.damage << " damage!\n";
				return _target.HP = _target.HP - _spell.damage;
			}
		}
	}
	else
	{
		cout << _attacker.Name() << " tries to do something, but fails.\n";
		return 0;
	}
}

//int Battle(Player& _player, Player& _npc) {
//	while (_player.HP != 0) {
//
//	}
//
//}

void CurrentHP(Player& _target)
{
	cout << _target.Name() << " is at " << _target.HP << "/" << _target.HPMax << "HP.\n";
}