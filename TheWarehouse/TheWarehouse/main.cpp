#include <iostream>
#include <string>

int CheckInput()
{
	int TheValue;
	int counter;

	std::cout << "\033[4;32m[What do you chose to do?]\033[0m\n";
	std::cin >> TheValue;
	//Checks if input is a numerical value, then allows for limited re-attempts
	for (counter = 1; !std::cin.good() && counter < 4; counter = counter + 1)
	{
		std::cout << "\n[Try Again.]\n[You have " << 4 - counter << " attempts left.]\033[0m\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> TheValue;
	}
	return TheValue;
}

class Room
{


public:
	int RoomNum; //Room Number
	std::string RoomName; //Room Name
	std::string Description; //Description dialouge for room
	int MoveLeft;
	int MoveRight;
	int MoveForward;
	int MoveBack;

};

class Invt {
public:
	bool Scissors;
	bool Key;
};

int Movement()
{
	std::string MoveDirection;

	std::cin >> MoveDirection;
	for (;;)
	{
		if (MoveDirection == "Left" || MoveDirection == "left" || MoveDirection == "LEFT")
		{
			return (1);
		}
		else if (MoveDirection == "Right" || MoveDirection == "right" || MoveDirection == "RIGHT")
		{
			return (2);
		}
		else if (MoveDirection == "Forward" || MoveDirection == "forward" || MoveDirection == "FORWARD")
		{
			return (3);
		}
		else if (MoveDirection == "Back" || MoveDirection == "back" || MoveDirection == "BACK")
		{
			return (4);
		}
		else
		{
			std::cout << "Please write a valid direction.\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin >> MoveDirection;
		}

	}
}

int RoomChecker(Room* CurrentRoom)
{
	int CanMoveLeft = CurrentRoom->MoveLeft;
	int CanMoveRight = CurrentRoom->MoveRight;
	int CanMoveForward = CurrentRoom->MoveForward;
	int CanMoveBack = CurrentRoom->MoveBack;

	std::cout << "You are currently in " << CurrentRoom->RoomName << ".\n" << CurrentRoom->Description << "\n";
	std::cout << "Which way are you going?\n";

	int CurrentMovement = Movement();
	for (;;) {
		if (CurrentMovement == 1 && CanMoveLeft != 0)
		{
			return(CanMoveLeft);
			break;
		}
		else if (CurrentMovement == 2 && CanMoveRight != 0)
		{
			return(CanMoveRight);
			break;
		}
		else if (CurrentMovement == 3 && CanMoveForward != 0)
		{
			return(CanMoveForward);
			break;
		}
		else if (CurrentMovement == 4 && CanMoveBack != 0)
		{
			return(CanMoveBack);
			break;
		}
		else
		{
			std::cout << "You can't go that way.\n";
			CurrentMovement = Movement();
		}
	}
}


int main()
{

	int RoomSelected;
	bool ValidAnswer = false;
	bool WinState = false;

	Invt Collection = { false, false };
	Room Room0 = { 0, "Invalid Room", "you're not supposed to be here GET OUT GET OUT GET OUT.", 0, 0, 0, 0 }; //failsafe room
	Room Room1 = { 1, "the first room", "This is the room you woke up in initally. There's a door in front of you and another to your right.",0 , 9, 2, 0 }; //room ref 1
	Room Room2 = { 2, "a hallway", "This hallway has a door to its left and the hallway extends around the corner to the right.", 3, 4, 0, 1 }; //room ref 2
	Room Room3 = { 3, "a room with a macabre energy.", "A room filled questionable bags and dark stains.", 0, 0, 0, 2, }; //room ref 3
	Room Room4 = { 4, "a hallway", "This hallway continues forward. Additionally, theres a door to the left.", 5, 0, 9, 2 }; //room ref 4
	Room Room5 = { 5, "an office", "A room that seemed to once be an office. Both behind you and in front on the other side of the room.", 0, 0, 6, 4 }; //room ref 5
	Room Room6 = { 6, "a hallway", "This hallway feels tight. It extends both to the right and left. Behind you is the door to the office.", 7, 8, 0, 5, }; //room ref 6
	Room Room7 = { 7, "a janitor storage room", "A room filled with very dirty cleaning tools.", 0, 0, 0, 6 }; //room ref 7
	Room Room8 = { 8, "a room with dirty sheets", "This room contains a single futon with many dirty sheets.", 0, 0, 0, 6 }; //room ref 8
	Room Room9 = { 9, "a hallway", "At the end of the hall is a door and to your right is a door.", 0, 1, 10, 4, }; //room ref 9
	Room Room10 = { 10, "a cold room filled with boxes", "This room feels very cold.", 0, 0, 0, 9 }; //room ref 10
	Room* CurrentRoom; //Current Room reference
	CurrentRoom = &Room1;

	for (;;) {
		if (WinState == true)
		{
			std::cout << "You win!";
			return(0);
		}
		else
		{
			int JumpRoom = RoomChecker(CurrentRoom);
			if (JumpRoom == 1) 
			{
				CurrentRoom = &Room1;
			}
			else if (JumpRoom == 2) 
			{
				CurrentRoom = &Room2;
			}
			else if (JumpRoom == 3)
			{
				CurrentRoom = &Room3;
			}
			else if (JumpRoom == 4)
			{
				CurrentRoom = &Room4;
			}
			else if (JumpRoom == 5)
			{
				CurrentRoom = &Room5;
			}
			else if (JumpRoom == 6)
			{
				CurrentRoom = &Room6;
			}
			else if (JumpRoom == 7)
			{
				CurrentRoom = &Room7;
			}
			else if (JumpRoom == 8)
			{
				CurrentRoom = &Room8;
			}
			else if (JumpRoom == 9)
			{
				CurrentRoom = &Room9;
			}
			else if (JumpRoom == 10)
			{
				CurrentRoom = &Room10;
			}
		}
	}

	//std::cout << "You are currently in the " << CurrentRoom->RoomName << ".\n" << CurrentRoom->Description << "\n";
	
}