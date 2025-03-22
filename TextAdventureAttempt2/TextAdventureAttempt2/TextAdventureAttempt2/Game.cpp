#include "Game.h"
#include "Room.h"
#include "Item.h"
#include "Cat.h"
#include "Lamp.h"
#include "BoxOfDonuts.h"
#include "Player.h"

using std::cin;

Game::Game() 
{
    player = new Player();

    rooms[0][0] = new Room("This room has a sweet scent...", new BoxOfDonuts(6));
    rooms[0][1] = new Room("This room is rather dim...", new Lamp());
    rooms[1][0] = new Room("This room has a couch with a creature...", new Cat());
    rooms[1][1] = new Room("This room seems barren...", nullptr);

    rooms[0][0]->DefineExits(nullptr, rooms[1][0], rooms[0][1], nullptr);
    rooms[0][1]->DefineExits(nullptr, rooms[1][1], nullptr, rooms[0][0]);
    rooms[1][0]->DefineExits(rooms[0][0], nullptr, rooms[1][1], nullptr);
    rooms[1][1]->DefineExits(rooms[0][1], nullptr, nullptr, rooms[1][0]);

    currentRoom = rooms[0][0];
}

Game::~Game() 
{
    delete player;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            delete rooms[i][j];
        }
    }
}

void Game::Run() 
{
    string command;
    while (true) {
        currentRoom->Description();
        std::cout << "Which direction would you like to go? Or would you like to check a spell? Or perhaps the room has an item...\n [ NORTH | SOUTH | EAST | WEST | SPELL | ITEM]\n";
        cin >> command;
        Action(command);
    }
}

void Game::Action(const string& command) 
{
    if (command == "NORTH" || command == "SOUTH" || command == "EAST" || command == "WEST") 
    {
        Room* nextRoom = currentRoom->ReturnExit(command);
        if (nextRoom) {
            currentRoom = nextRoom;
        }
        else {
            std::cout << "Can't move in that direction...\n";
        }
    }
    else if (command == "SPELL") 
    {
        std::cout << "Which spell are we checking?\n";
        string spell;
        cin >> spell;
        if (player->FindSpell(spell)) 
        {
            std::cout << "Ah! " << spell << "! You know that one!\n";
        }
        else 
        {
            std::cout << spell << "? That's not familiar...\n";
        }
    }
    else if (command == "ITEM") 
    {
        Item* item = currentRoom->GetItem();
        if (item) {
            item->Description();
            item->Use();
        }
        else {
            std::cout << "There's nothing of interest here...\n";
        }
    }
    else 
    {
        std::cout << "That's not an action you can do...\n";
    }
}