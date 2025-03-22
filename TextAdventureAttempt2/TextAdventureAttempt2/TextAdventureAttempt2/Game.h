#pragma once
#include "Player.h"
#include "Room.h"

//Default Game Class
class Game
{
private:
    Room* rooms[2][2];
    Room* currentRoom;
    Player* player;
public:
    Game();
    ~Game();
    void Run();
    void Action(const string& command);
};