#pragma once
#include "Player.h"
#include "Spell.h"
#include "Room.h"
#include <algorithm>

using std::transform;
using std::string;

void Action(Player& _player, Room& _room);
int Attack(Player& _attacker, Player& _target, Spell& _spell);
void CurrentHP(Player& _target);
void CurrentMP(Player& _target);
int Movement(Room& _room);
string toUpper(string _input);
void Battle(Player& _player, Player& _npc);
void playerTurn(Player& _player, Player& _target);
Spell& getSpell(string _spell);
void enemyTurn(Player& _enemy, Player& _target);
Room& roomChange(int _newRoom);