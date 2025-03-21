#include "Spell.h"

Spell::Spell(string _name, int _damage, string _descript, int _cost, bool _healing)
{
	name = _name;
	damage = _damage;
	descript = _descript;
	cost = _cost;
	doesHeal = _healing;
}

bool Spell::Compare(Spell a, Spell b)
{
	if (a.damage > b.damage) {
		return true;
	}
	else {
		return false;
	}

}

Spell Inferno("Inferno", 15, "A spell that flings a ball of fire upon target.", 5, false);
Spell Impact("Impact", 10, "A spell that creates a rock to throw at target.", 2, false);
Spell Eruption("Eruption", 20, "A spell that causes a torrent of lava to burst from target's feet.", 8, false);
Spell Breathe("Breathe", 10, "A spell that restores and heals a brief part of its target's health.", 6, true);
Spell NullSpell("Null", 0, "Not a real spell.", 0, false);

Spell& referenceSpell(string _call) {
	if (_call == "INFERNO")
	{
		return Inferno;
	}
	else if (_call == "IMPACT")
	{
		return Impact;
	}
	else if (_call == "ERUPTION")
	{
		return Eruption;
	}
	else if (_call == "BREATHE")
	{
		return Breathe;
	}
	else
	{
		return NullSpell;
	}
}