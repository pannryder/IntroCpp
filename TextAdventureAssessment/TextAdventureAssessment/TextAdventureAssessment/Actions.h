#pragma once
#include "Player.h"
#include "Spell.h"
#include "Item.h"
#include "Room.h"
#include "Game.h"
#include <algorithm>

using std::transform;
using std::string;

void Action(Room& _room);
int Attack(Player& _attacker, Player& _target, Spell& _spell);
void CurrentHP(Player& _target);
int Movement(Room& _room);
string toUpper(string _input);
void Battle(Player& _player, Player& _npc);
void playerTurn(Player& _player, Player& _target);
Spell& getSpell(string _spell);
void enemyTurn(Player& _enemy, Player& _target);
Room& roomChange(int _newRoom);

void Action(Room& _room)
{
	cout << "What action would you like to preform?\nMOVE | SEARCH\n";
	string Action;
	cin >> Action;
	Action = toUpper(Action);
	for (;;)
	{
		if (Action == "MOVE")
		{
			Movement(_room);
			return;
		}
		else if (Action == "SEARCH")
		{
			return;
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

int Movement(Room& _room)
{
	cout << "Which direction would you like to go?\n";
	string MoveDirection;
	cin >> MoveDirection;
	MoveDirection = toUpper(MoveDirection);
	for (;;)
	{
		if (MoveDirection == "LEFT" && _room.RelativeW != 0 || MoveDirection == "WEST" && _room.RelativeW != 0)
		{
			return _room.RelativeW;
		}
		else if (MoveDirection == "RIGHT" && _room.RelativeE != 0 || MoveDirection == "EAST" && _room.RelativeE != 0)
		{
			return _room.RelativeE;
		}
		else if (MoveDirection == "UP" && _room.RelativeN != 0 || MoveDirection == "NORTH" && _room.RelativeN != 0)
		{
			return _room.RelativeN;
		}
		else if (MoveDirection == "DOWN" && _room.RelativeS != 0 || MoveDirection == "SOUTH" && _room.RelativeS != 0)
		{
			return _room.RelativeS;
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

int Attack(Player& _attacker, Player& _target, Spell& _spell)
{
	if (_spell.name != "Null")
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
	else
	{
		cout << _attacker.Name() << " tries to do something, but fails.\n";
		return 0;
	}
}

void Battle(Player& _player, Player& _npc) {
	bool isPlayerTurn = true;
	int round = 1;
	for (int turns = 1; _player.HP != 0; turns++) 
	{

		if (isPlayerTurn == true) {
			if (_player.HP <= 0)
			{
				cout << "you dead.\n";
				break;
			}
			cout << "Round " << round << ".\n";
			playerTurn(_player, _npc);
			isPlayerTurn = false;
		}
		else
		{
			if (_npc.HP <= 0) {
				cout << _npc.Name() << " dead.\n";
				break;
			}
			enemyTurn(_npc, _player);
			CurrentHP(_player);
			++round;
			isPlayerTurn = true;
		}

	}

}

Spell& getSpell(string _spell) {
	string input = toUpper(_spell);
	return referenceSpell(input);
}

void playerTurn(Player& _player, Player& _target) {
	cout << "What action would you like to preform?\nCAST | INFO\n";
	string Action;
	cin >> Action;
	Action = toUpper(Action);
	for (;;)
	{
		if (Action == "INFO") {
			cout << "(" << Inferno.name << ") : " << Inferno.descript << "\n Costs : " << Inferno.cost << "MP\n Does : " << Inferno.damage << "DMG\n";
			cout << "(" << Eruption.name << ") : " << Eruption.descript << "\n Costs : " << Eruption.cost << "MP\n Does : " << Eruption.damage << "DMG\n";
			cout << "(" << Breathe.name << ") : " << Breathe.descript << "\n Costs : " << Breathe.cost << "MP\n Restores : " << Breathe.damage << "HP\n";
			break;
		}
		else if (Action == "CAST")
		{
			string spell;
			cout << "What spell would you like to use?\n";
			cin >> spell;
			Attack(_player, _target, getSpell(spell));
			break;
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

void enemyTurn(Player& _enemy, Player& _target) {
	std::srand(time({}));
	int spellChoice = rand() % 2;
	if (spellChoice == 0) {
		Attack(_enemy, _target, Inferno);
	}
	else {
		Attack(_enemy, _target, Impact);
	}
}

void CurrentHP(Player& _target)
{
	cout << _target.Name() << " is at " << _target.HP << "/" << _target.HPMax << "HP.\n";
}

Room& roomChange(int _newRoom) {
	if (_newRoom == 1) {
		return r1;
	}
	else if (_newRoom == 2){
		return r2;
	}
	else if (_newRoom == 3) {
		return r3;
	}
	else if (_newRoom == 4) {
		return r4;
	}
	else if (_newRoom == 5) {
		return r5;
	}
	else if (_newRoom == 6) {
		return r6;
	}
	else if (_newRoom == 7) {
		return r7;
	}
	else if (_newRoom == 8) {
		return r8;
	}
	else if (_newRoom == 9) {
		return r9;
	}
}