#pragma once
#include "Item.h"

class Lamp : public Item {
	bool turnedOn;
public:
	Lamp();
	const void Description();
	void Use();
};