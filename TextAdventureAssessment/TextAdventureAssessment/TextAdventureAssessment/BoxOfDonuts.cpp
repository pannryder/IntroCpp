#include "BoxOfDonuts.h"

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