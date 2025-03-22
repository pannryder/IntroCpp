#pragma once
#include "Item.h"

class BoxOfDonuts : public Item {
	int count;
	int restorePoints;
public:
	BoxOfDonuts();
	const void Description();
	void Use();
	void UseDonut(Player& _user);
};