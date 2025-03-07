#pragma once
#include <string>
#include <iostream>
#include "Player.h"

using std::string;
using std::cin;
using std::cout;

class Item {
public:
	const void Description();
	void Use();
};

class BoxOfDonuts : public Item {
	int count;
	int restorePoints;
public:
	BoxOfDonuts();
	const void Description();
	void Use();
	void UseDonut(Player& _user);
};

class Lamp : public Item {
	bool turnedOn;
public:
	Lamp();
	const void Description();
	void Use();
};

class Cat : public Item {
	bool purring;
public:
	Cat();
	const void Description();
	void Use();
};

const void Item::Description()
{
}

void Item::Use()
{
}

BoxOfDonuts::BoxOfDonuts()
	: count(6), restorePoints(10)
{
}

const void BoxOfDonuts::Description()
{
	cout << "A wooden box containg donuts, the Emperor's favorite snack. They're known to restore magic power if needed.\n";
	if (count > 0) {
		cout << "There's currently " << count << " in the box.\n";
	}
	else {
		cout << "There's no donuts left.\n";
	}
}

void BoxOfDonuts::Use()
{
}

void BoxOfDonuts::UseDonut(Player& _user) {
	if (count > 0)
	{
		if (_user.MP + restorePoints > _user.MPMax)
		{
			_user.MP = _user.MPMax;
		}
		else {
			_user.MP = _user.MP + restorePoints;
		}
		count = count - 1;
		cout << "You ate a donut, with " << count << " remaining.\n";
		cout << _user.Name() << " is at " << _user.MP << "/" << _user.MPMax << "MP.\n";
		
	}
	else
	{
		cout << "There's no donuts in the box.\n";
	}
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
	else {
		cout << "It's currently turned off.\n";
	}
}

void Lamp::Use()
{
	turnedOn = !turnedOn;
}

Cat Mittens;
Item* mittens = &Mittens;
Lamp Lantern;
Item* lantern = &Lantern;
BoxOfDonuts EmpDonuts;
Item* donuts = &EmpDonuts;
Item* emptyHand;