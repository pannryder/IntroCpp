#include "gameClasses.h"
#include "Item.h"
#include "Player.h"
#include "Spell.h"
#include "Actions.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::transform;

////--- Game
//Game::Game()
//{
//	;
//}
//
//Game::~Game()
//{
//	;
//}
//
//void Game::Run()
//{
//	;
//}
//



//--- Item

const void Item::Description() 
{
}

void Item::Use() 
{
}

//--- Room

Room::Room(string descript, Item* item)
{
	description = descript;
}

Room::~Room()
{
}

void Room::Description() const
{
	cout << description;
}

//--- Player
Player::Player(string _name, string _description, int _hp, int _mp)
{
	name = _name;
	description = _description;
	HPMax = _hp;
	HP = _hp;
	MPMax = _mp;
	MP = _mp;
}

Player::~Player() 
{
}

const string Player::Name() 
{
	return name;
}

const string Player::Description()
{
	return description;
}

//bool Player::FindSpell(string spell) 
//{
//	;
//}

//--- Spell
Spell::Spell(string _name, int _damage) 
{
	name = _name;
	damage = _damage;
}

void Spell::Cast() 
{
}

//bool Spell::Compare(Spell a, Spell b) 
//{
//	;
//}

BoxOfDonuts::BoxOfDonuts()
	: count(6)
{
}

const void BoxOfDonuts::Description()
{
	cout << "A wooden box containg donuts, the Emperor's favorite snack. ";
	if (count > 0) {
		cout << "There's currently " << count << " in the box.\n";
	}
	else {
		cout << "There's no donuts left.\n";
	}
}

void BoxOfDonuts::Use()
{
	if (count > 0)
		count = count - 1;
}

string toUpper(string _input)
{
	transform(_input.begin(), _input.end(), _input.begin(), ::toupper);
	return _input;
}

Cat::Cat() 
	: purring(false)
{
}

const void Cat::Description() 
{
	cout << "A black cat with piercing green eyes.\n";
}

void Cat::Use() 
{
	if (purring == false) {
		purring = true;
		cout << "The cat begins to purr as you pet it gently.\n";
	}
	else {
		cout << "The cat continues to purr with your repeated petting.\n";
	}
}



Lamp::Lamp()
	: turnedOn(false)
{
}

const void Lamp::Description()
{
	cout << "A ornate black gas lamp. ";
	if (turnedOn == true) {
		cout << "The green flame it produces flickers in the castle's slight draft.\n";
	}
	else{
		cout << "It's currently turned off.\n";
	}
}

void Lamp::Use()
{
	turnedOn = !turnedOn;
}

EmptyHand::EmptyHand()
{

}
void EmptyHand::Use() {

}
const void EmptyHand::Description() {
	cout << "Your hand is empty.";
}

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

int Attack(Player& _attacker, Player& _target , Spell& _dmg)
{
	cout << _attacker.Name() << " attacks with "<< _dmg.name <<" dealing " << _dmg.damage << " damage!\n";
	return _target.HP = _target.HP - _dmg.damage;
}

int Heal(Player& _healer, Player& _target, Spell& _dmg)
{
	cout << _healer.Name() << " heals " << _dmg.damage << "HP!\n";
	if (_target.HP + _dmg.damage > _target.HPMax)
	{
		return _target.HPMax;
	}
	else {
		return _target.HP = _target.HP + _dmg.damage;
	}

}



void CurrentHP(Player& _target)
{
	cout << _target.Name() << " is at " << _target.HP << "/" << _target.HPMax << "HP.\n";
}