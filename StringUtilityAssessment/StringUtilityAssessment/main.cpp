#include "String.h"
#include <iostream>

int ActionCheck()
{
	std::cout << "\nPlease choose a utility function.\n>>1. Lengths of inputs\n>>2. Append inital input to comparative input\n>>3. Inputs to lowercase\n>>4. Inputs to uppercase\n>>5. Seach for comparative input within inital input\n>>6.\n>>7.\n>>8. Compare inputs alphabetically.\n";
	int Choice = 0;
	std::cin >> Choice;
	for (;;)
	{
		if (Choice <= 8 && Choice >= 1)
		{
			return (Choice);
		}
		else
		{
			std::cout << "Please write a valid input.\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin >> Choice;
		}

	}
;
}


int main()
{

	String InputOne{};
	String InputTwo{};
	std::cout << "Please write your inital input.\n";
	InputOne.ReadFromConsole();
	std::cout << "\nPlease write your comparative input.\n";
	InputTwo.ReadFromConsole();
	std::cout << "\nINITIAL INPUT : ";
	InputOne.WriteToConsole();
	std::cout << "COMPARATIVE INPUT : ";
	InputTwo.WriteToConsole();
	int Action;
	Action = ActionCheck();

	if (Action == 1)
	{
		std::cout << ">>The length of your inital input '" << InputOne.text << "' is '" << InputOne.Length() << "'.\n";
		std::cout << ">>The length of your comparative input '" << InputTwo.text << "' is '" << InputTwo.Length() << "'.\n";
	}
	else if (Action == 2)
	{
		std::cout << "\n>> Appending '" << InputTwo.text << "' to '" << InputOne.text << "'.\n";
		InputOne.Append(InputTwo.text);
		std::cout << InputOne.text << "\n";
	}
	else if (Action == 3)
	{
		std::cout << "\n>> Converted " << InputOne.text << " and " << InputTwo.text << " to lowercase.\n";
		InputOne.ToLower();
		std::cout << "\n";
		InputTwo.ToLower();
	}
	else if (Action == 4)
	{
		std::cout << "\n>> Converted " << InputOne.text << " and " << InputTwo.text << " to uppercase.\n";
		InputOne.ToUpper();
		std::cout << "\n";
		InputTwo.ToUpper();
	}
	else if (Action == 5)
	{
		std::cout << "Please insert a character to search for.\n"
		char Searching;
		std::cin >> Searching;
		InputOne.FindCharacter(Searching);
		std::cout << "\n'" << Searching << "' found at position '""' in '" << InputOne.text << "' and '";
	}
	else if (Action == 6)
	{
		std::cout << "Function 6.\n";
	}
	else if (Action == 7)
	{
		std::cout << "Function 7.\n";
	}
	else if (Action == 8)
	{
		bool IsLessThan = InputOne.operator<(InputTwo.text);
		if (IsLessThan == true)
		{
			std::cout << "'" << InputOne.text << "' comes before '" << InputTwo.text << "' alphabetically.\n" ;
		}
		else
		{
			std::cout << "'" << InputOne.text << "' comes after '" << InputTwo.text << "' alphabetically.\n";
		}
	}
	else
	{
		return(0);
	}


	//String Testing{};
	//Testing.WriteToConsole();
	//Testing.ToLower();
	//std::cout << "\n";
	//Testing.ToUpper();
	//std::cout <<"\n" << Testing.Length() << "\n";
}