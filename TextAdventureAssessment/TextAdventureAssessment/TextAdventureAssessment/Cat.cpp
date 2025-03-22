#include "Cat.h"

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