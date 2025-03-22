#include "Actions.h"
#include "Item.h"
#include "Game.h"
#include <algorithm>

using std::transform;
using std::string;

void Action(Player& _player, Room& _room)
{
	cout << "What action would you like to preform?\nMOVE | SEARCH\n";
	string Action;
	cin >> Action;
	Action = toUpper(Action);
	for (;;)
	{
		if (Action == "MOVE")
		{
			return;
		}
		else if (Action == "SEARCH")
		{
			if (_room.item == mittens) {
				cout << "You found something!\n";
				Mittens.Description();
				cout << "Would you like to pet Mittens? \n"
					<< "YES | NO\n";
				string itemChoice;
				cin >> itemChoice;
				itemChoice = toUpper(itemChoice);
				if (itemChoice == "YES") {
					Mittens.Use();
					return;
				}
				else {
					return;
				}
			}

			else if (_room.item == lantern) {
				cout << "You found something!\n";
				Lantern.Description();
				cout << "Would you like use the lantern? \n"
					<< "YES | NO\n";
				string itemChoice;
				cin >> itemChoice;
				itemChoice = toUpper(itemChoice);
				if (itemChoice == "YES") {
					Lantern.Use();
					r9.isLocked = false;
					return;
				}
				else {
					return;
				}
			}
			else if (_room.item == donuts) {
				cout << "You found something!\n";
				EmpDonuts.Description();
				cout << "Would you like to eat one ? \n"
					<< "YES | NO\n";
				string itemChoice;
				cin >> itemChoice;
				itemChoice = toUpper(itemChoice);
				if (itemChoice == "YES") {
					EmpDonuts.UseDonut(_player);
					return;
				}
				else {
					return;
				}
			}
			else {
				cout << "There's nothing really of note within this room.\n";
				return;
			}
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
			if (_room.isLocked != true)
			{
				return _room.RelativeN;
			}
			else
				cout << "This room seems to be locked...\nYou remember hearing somewhere that the lock is connected to the light power of another room.\nWhat an odd mechanisim to have...\n";
			return _room.RoomID;
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
					_attacker.MP = _attacker.MP - _spell.cost;
					return _target.HP = _target.HPMax;
				}
				else {
					_attacker.MP = _attacker.MP - _spell.cost;
					return _target.HP = _target.HP + _spell.damage;
				}
			}
			else
			{
				if (_target.HP - _spell.damage <= 0)
				{
					_attacker.MP = _attacker.MP - _spell.cost;
					cout << _attacker.Name() << " attacks with " << _spell.name << ", dealing " << _spell.damage << " damage!\n";
					return _target.HP = 0;
				}
				else {
					_attacker.MP = _attacker.MP - _spell.cost;
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
	cout << "BATTLE START!\n"
		<< "Target : " << _npc.Name() << "\n"
		<< _npc.Description() << "\n\n";

	for (int turns = 1; _player.HP != 0; turns++)
	{

		if (isPlayerTurn == true) {
			if (_player.HP <= 0)
			{
				break;
			}
			cout << "[[[  Round " << round << "  ]]]\n"
				<< _player.Name() << "\n";
			CurrentHP(_player);
			CurrentMP(_player);
			playerTurn(_player, _npc);
			isPlayerTurn = false;
		}
		else
		{
			if (_npc.HP <= 0) {
				cout << _npc.Name() << " has been knocked out!\n";
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
			Spell& beingCasted = getSpell(spell);
			if (_player.MP >= beingCasted.cost) {
				Attack(_player, _target, beingCasted);
			}
			else {
				cout << _player.Name() << " doesn't have enough MP to cast that!\n";
			}
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

void CurrentMP(Player& _target)
{
	cout << _target.Name() << " is at " << _target.MP << "/" << _target.MPMax << "MP.\n";
}

Room& roomChange(int _newRoom) {
	if (_newRoom == 1) {
		return r1;
	}
	else if (_newRoom == 2) {
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