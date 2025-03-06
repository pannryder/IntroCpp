#pragma once
#include <string>
#include <iostream>

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
public:
	BoxOfDonuts();
	const void Description();
	void Use();
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

class EmptyHand : public Item {
public:
	EmptyHand();
	const void Description();
	void Use();
};

BoxOfDonuts::BoxOfDonuts()
	: count(6)
{
}

const void Item::Description()
{
}

void Item::Use()
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

EmptyHand::EmptyHand()
{

}
void EmptyHand::Use() {

}
const void EmptyHand::Description() {
	cout << "Your hand is empty.";
}

Cat Mittens;