#pragma once
#include "Room.h"
#include "Player.h"
#include "Actions.h"
#include "Item.h"
#include "Spell.h"

class Game {
private:
	Room rooms[3][3];
	Player* player;
	bool playerAlive;
	bool winState;
	int round;
	bool isPlayerTurn;
public:
	Game();
	~Game();
	void Run();
	void nextRound() { round++; }
	bool isGameOver() const { return !playerAlive || winState; }
	void setWinState(bool state) { winState = state; }
	void setPlayerAlive(bool state) { playerAlive = state; }
};


