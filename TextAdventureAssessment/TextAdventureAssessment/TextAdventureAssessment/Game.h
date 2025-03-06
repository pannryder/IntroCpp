#pragma once
#include "Room.h"
#include "Player.h"

class Game {
private:
	Room rooms[3][3]{{r1,r2,r3},{r4,r5,r6},{r7,r8,r9}};
	Player* player;
public:
	Game();
	~Game();
	void Run();
};

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
}
