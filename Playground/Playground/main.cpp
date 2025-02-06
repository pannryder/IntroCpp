#include <iostream>
#include <string>

//notes
// std::string , can be assigned variable and contain text
// example
// std::string myName = "My name here" //clearing string = "" OR myName.clear(); 
// std::getline(std::cinm myName) //for multiple words

int CheckInput()
{
	int TheValue;
	int counter;

	std::cout << "\033[4;32m[What do you chose to do?]\033[0m\n";
	std::cin >> TheValue;
	//Checks if input is a numerical value, then allows for limited re-attempts
	for (counter = 1; !std::cin.good() && counter < 4; counter = counter + 1)
	{
		std::cout << "\n\033[4;31m[That's not a numerical value.]\n[You have " << 4 - counter << " attempts left.]\033[0m\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> TheValue;
	}
	return TheValue;
}

void InputFail()
{
	std::cout << "\n\033[4;31m[That's literally NOT what I asked for.]\n[There's something wrong with you. Pathetic. Goodbye.]\033[0m";
	exit(0);
}

void ExitGame()
{
	std::cout << "\n\033[4;31m[Oh? Okay...]\n[Goodbye.]\033[0m\n\n";
	exit(0);
}

void Hallway1()
{
	std::cout << "As the door shuts hard behind you, causing a slight jump from the sound, the thump reverberates in the hallway presented to you.\n"
		"On the left at the end of the hall is a door, on the right the hall extends around the corner.";

	for (bool InRoom = true; InRoom == true;)
	{
		std::cout << "\n\033[0;36m[1 - Go left]\n"
			"[2 - Go right]\n"
			"[3 - Go back]\n"
			"\n[0 - Exit Game]\033[0m\n\n";
		int PlayerChoice = CheckInput();

		if (PlayerChoice == 0)
		{
			ExitGame();
		}

		else if (PlayerChoice == 1)
		{
			std::cout << "\n\033[4;33m[ACTION 1...]\033[0m\n"
				"Dummy text 1.\n";
		}

		else if (PlayerChoice == 2)
		{
			std::cout << "\n\033[4;33m[ACTION 2...]\033[0m\n"
				"Dummy text 2.\n";
		}

		else if (PlayerChoice == 3)
		{
			std::cout << "\n\033[4;33m[ACTION...]\033[0m\n"
				"You turn around and leave back to the hallway...\n";
			InRoom = false;
		}

		else
		{
			std::cout << "\n\033[4;31m[That's not an option]\n[Type one of the actual options.]\033[0m\n\n";
		}
	}

}

void Room1()
{

}

void Room2()
{
	std::cout << "As you enter the room, the unpleasent stench of rotting flesh violates your nostrils.\n"
		"You don't feel brave enough to search through any of the questionable bags that line the walls within.\n"
		"The room is dimly lit by a single, dying lightbulb. Walls are stained from something dripping down the walls.\n"
		"Among the bags is a single table with seemingly a lot of junk laid upon it.\n"; 

	for (bool InRoom = true; InRoom == true;)
	{
		std::cout << "\n\033[0;36m[1 - Inspect table]\n"
			"[2 - Touch bags]\n"
			"[3 - Leave]\n"
			"\n[0 - Exit Game]\033[0m\n\n";
		int PlayerChoice = CheckInput();

		if (PlayerChoice == 0)
		{
			ExitGame();
		}

		else if (PlayerChoice == 1)
		{
			std::cout << "\n\033[4;33m[You inspect the table...]\033[0m\n"
				"Approaching the table, laid upon it's worn, wooden planks is nothing but nonsenical gibberish scribbled upon parchment paper.\n"
				"Upon further inspection, there's nothing of import to gain amongst it's contents.\n";
		}

		else if (PlayerChoice == 2)
		{
			std::cout << "\n\033[4;33m[You attempt to touch the bags...]\033[0m\n"
				"Your hand extends slightly but you better judgement stops you.\n";
		}

		else if (PlayerChoice == 3)
		{
			std::cout << "\n\033[4;33m[You leave the room...]\033[0m\n"
				"You turn around and leave back to the hallway...\n";
			InRoom = false;
		}

		else
		{
			std::cout << "\n\033[4;31m[That's not an option]\n[Type one of the actual options.]\033[0m\n\n";
		}
	}

}

void RoomTemp()
{
	std::cout << "Room description.\n";

	for (bool InRoom = true; InRoom == true;)
	{
		std::cout << "\n\033[0;36m[1 - ACTION 1]\n"
			"[2 - ACTION 2]\n"
			"[3 - Leave]\n"
			"\n[0 - Exit Game]\033[0m\n\n";
		int PlayerChoice = CheckInput();

		if (PlayerChoice == 0)
		{
			ExitGame();
		}

		else if (PlayerChoice == 1)
		{
			std::cout << "\n\033[4;33m[ACTION 1...]\033[0m\n"
				"Dummy text 1.\n";
		}

		else if (PlayerChoice == 2)
		{
			std::cout << "\n\033[4;33m[ACTION 2...]\033[0m\n"
				"Dummy text 2.\n";
		}

		else if (PlayerChoice == 3)
		{
			std::cout << "\n\033[4;33m[ACTION...]\033[0m\n"
				"You turn around and leave back to the hallway...\n";
			InRoom = false;
		}

		else
		{
			std::cout << "\n\033[4;31m[That's not an option]\n[Type one of the actual options.]\033[0m\n\n";
		}
	}

}

void TravelTesting()
{
	
}

int main()
{
	bool ScisorsNearby = true;
	int NarativeCheck{};
	TravelTesting();
	std::cout << "You awaken within a darkly lit room, your face pressed against the cold and old wooden floor.\n"
		"From this angle, you see a dangling lamp cable, a pair of muddy worn boots and the glisten of silver scissors laid upon the ground.\n"
		"Despite the fatigue that plagues your body, you feel something binding your hands, causing them to ache.\nAlthough, your legs are free.\n"
		"Your limited options are laid bare, but try not to overexert yourself...\n"
		"\n\033[0;36m[1 - Kick the lamp]\n"
		"[2 - Kick the boots]\n"
		"[3 - Kick the scissors]\n"
		"[4 - Scream]\n"
		"\n[0 - Exit Game]\033[0m\n\n";

	int PlayerChoice = CheckInput();

	if (PlayerChoice == 0)
	{
		ExitGame();
	}

	else if (PlayerChoice == 1)
	{
		NarativeCheck = 1;
		std::cout << "\n\033[4;33m[You kick the lamp...]\033[0m\n"
			"As you extend your leg, the cord coils around your ankle.\n"
			"Although you feel weak, you're able to give it a strong tug, causing it to fall off the table it was rest on.\n"
			"With the shatter of the bulb, the flash of a flame is seen.\n"
			"The boots begin to move on their own in erratic nature, not long before they're fallen to he ground, followed with a large thud and the stench of burnt meat.\n";
	}

	else if (PlayerChoice == 2)
	{
		NarativeCheck = 2;
		std::cout << "\n\033[4;33m[You kick the boots...]\033[0m\n"
			"Kicking your leg weakly, you attempt to knock over the leather boots within your reach.\n"
			"They don't budge from your impact, but they do move.\n"
			"Turning to your direction, stepping on their own.\n";
	}

	else if (PlayerChoice == 3)
	{
		NarativeCheck = 2;
		ScisorsNearby = false;
		std::cout << "\n\033[4;33m[You kick the scissors...]\033[0m\n";
			"With the stretch of your leg, extending your foot, you attempt to reach the scissors.\n"
			"Alas, they're slightly out of reach. In feeble effort, you try reaching out with your being.\n"
			"Each kick getting you closer, and closer... except you push a bit too hard and kick them out of reach.\n";
	}

	else if (PlayerChoice == 4)
	{
		NarativeCheck = 3;
		std::cout << "\n\033[4;33m[You scream out your lungs...]\033[0m\n"
			"The limited energy that your body has uses itself to scream out for help.\n"
			"Muffled by the sounds of your pleas, the heavy stomps of the dirty boots get closer.\n"
			"Sadly, you can't move your head up to check who's approached you.\n"
			"But you can hear the words the utter.\n\n"
			"[???] : Damn. Shut up.\n\n"
			"Not long before that single line, you feel a blunt pain against the back of your head.\n";

	}

	else
	{
		InputFail();
	}

	if (NarativeCheck == 1)
	{
		std::cout << "\nWell. That's a burnt corpse.\n"
			"As the result of your actions begin to permiate the air, you continue to lay on the floor.\n"
			"With each breath, your mindfog begins to clear. Which is great! Yet, you're still bound and stuck on the floor.\n"
			"You feel you have enough energy to attempt another action. But once again, try not to overexert yourself.\n"
			"\n\033[0;36m[1 - Stand up]\n"
			"[2 - Sit up]\n"
			"[3 - Lay there]\n"
			"\n[0 - Exit Game]\033[0m\n\n";
		PlayerChoice = CheckInput();

		if (PlayerChoice == 0)
		{
			ExitGame();
		}

		else if (PlayerChoice == 1)
		{
			NarativeCheck = 1;
			std::cout << "\n\033[4;33m[You try to stand up...]\033[0m\n"
				"In attempt to stand up with your limited energy, you rise.\n"
				"Yet, you feel unstable, uneasy. Your balance wavers.\n"
				"Black spots begin to fill your vision, your head feels light.\n"
				"Despite no windflow, you begin to slowly topple.\n"
				"With a not-so-graceful decent, the corner of the a nearby bench flashes in your vision.\n"
				"A great white flicker, then dardkness.\n"
				"\n\033[4;31m[You have died. Try again.]\033[0m";
			return(0);
		}

		else if (PlayerChoice == 2)
		{
			NarativeCheck = 2;
			std::cout << "\n\033[4;33m[You try to sit up...]\033[0m\n"
				"Dummy text.\n";
		}

		else if (PlayerChoice == 3)
		{
			NarativeCheck = 3;
			std::cout << "\n\033[4;33m[You just lay there...]\033[0m\n"
				"You just... lay there. Okay. Sure. Rot for all I care.\n"
				"\n\033[4;31m[You have died. Try again.]\033[0m";
			return(0);
		}

		else
		{
			InputFail();
		}

	}

	else if (NarativeCheck == 2)
	{
		std::cout << "From above you hear a low, gutteral voice.\n"
			"\n[???] : Finally awake, eh?\n"
			"A large hand grabs your collar, forcing you to sit up and face the owner."
			"Standing before you is a widesit man, his eyes are yellow, hidden with the deep, tired sockets that hide below a torn hat.\n"
			"His jaw lined with a unkempt brown beard, sitting above with a rotten smirk, surrounded by mismanaged stubble."
			"\n[???] : Didn't expect you to still be kicking after such a struggle.\n\n"
			"Your memory is blurred. Nothing flowing back within your mind, yet the aches in your bones ring his statement true.\n"
			"\n[???] : Such a waste too. A fighter like yourself would've been great to turn into the living dead.\n"
			"[???] : Oh well. I hope you like drills in your skull. Ha! What am I saying, of course you don't.\n\n"
			"He turns his back to you, presumably on his way to grab the 'skull drilling' tool."
			"If you want to live, you have to act fast.";

			if (ScisorsNearby == true)
			{
				std::cout << "\n\033[0;36m[1 - Speak]\n"
					"[2 - Charge]\n"
					"[3 - Grab scissors]\n"
					"\n[0 - Exit Game]\033[0m\n\n";
				PlayerChoice = CheckInput();
			}

			else 
			{
				std::cout << "\n\033[0;36m[1 - Speak]\n"
					"[2 - Charge]\n"
					"\n[0 - Exit Game]\033[0m\n\n";
				PlayerChoice = CheckInput();
			}

			if (PlayerChoice == 0)
			{
				ExitGame();
			}

			else if (PlayerChoice == 1)
			{
				NarativeCheck = 1;
				std::cout << "\n\033[4;33m[You speak up...]\033[0m\n"
					"Dummy text.\n";
			}

			else if (PlayerChoice == 2)
			{
				NarativeCheck = 2;
				std::cout << "\n\033[4;33m[You try to charge at the man...]\033[0m\n"
					"Dummy text.\n";
			}

			else if (PlayerChoice == 3 && ScisorsNearby == true)
			{
				NarativeCheck = 3;
				ScisorsNearby = false;
				std::cout << "\n\033[4;33m[You grab the scissors from underneath you...]\033[0m\n"
					"You just... lay there. Okay. Sure.\n";
				return(0);
			}

			else
			{
				InputFail();
			}
	}

	else
	{
		std::cout << "\n\033[4;31m[You have died. Try again.]\033[0m";
		return(0);
	}
}