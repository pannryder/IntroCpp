#pragma once
#include "Room.h"
#include "Player.h"
#include "Actions.h"
#include "Item.h"
#include "Spell.h"

class Game {
private:
	Room rooms[3][3]{
		{r1,r2,r3},
		{r4,r5,r6},
		{r7,r8,r9}};
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
	bool playerAlive = true;
	while(playerAlive = true)
	{
		Room& CurrentRoom = r1;
		r1.Description();
		CurrentRoom = roomChange(Movement(CurrentRoom));
	}
}

Game Maze;

