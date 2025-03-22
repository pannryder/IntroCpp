#pragma once
#include "Item.h"

class Cat : public Item {
	bool purring;
public:
	Cat();
	const void Description();
	void Use();
};