#pragma once
#include "Player.h"
#include "Spell.h"

int Attack(Player& _attacker, Player& _target, Spell& _dmg);
int Heal(Player& _healer, Player& _target, Spell& _heal);
void CurrentHP(Player& _target);
int Movement();