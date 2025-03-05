#pragma once
#include <string>

using std::string;

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

