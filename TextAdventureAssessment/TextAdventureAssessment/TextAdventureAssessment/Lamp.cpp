#include "Lamp.h"

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