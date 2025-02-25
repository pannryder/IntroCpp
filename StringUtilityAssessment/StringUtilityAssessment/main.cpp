#include "String.h"
#include <iostream>

int ActionCheck()
{
	std::cout << "\nPlease choose a utility function.\n>>1. Lengths of inputted strings\n>>2. Append inital string to comparative string\n>>3. Convert input string to lowercase\n>>4. Convert input string to uppercase\n>>5. Search within inital string\n>>6. Replace all instances of a character within the inital string with another\n>>7. Compare if strings are equal\n>>8. Compare strings alphabetically\n>>9. Replace inital string with comparative string\n>>10. Call character from location in inital string\n";
	int Choice = 0;
	std::cin >> Choice;
	for (;;)
	{
		if (Choice <= 10 && Choice >= 1)
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
	std::cout << "\nINITIAL STRING : ";
	InputOne.WriteToConsole();
	std::cout << "COMPARATIVE STRING : ";
	InputTwo.WriteToConsole();
	int Action;
	Action = ActionCheck();
	while (Action != 11) {
		if (Action == 1)
		{
			std::cout << ">>The length of your inital string '" << InputOne.text << "' is '" << InputOne.Length() << "'.\n";
			std::cout << ">>The length of your comparative string '" << InputTwo.text << "' is '" << InputTwo.Length() << "'.\n";
		}
		else if (Action == 2)
		{
			std::cout << "\n>> Appending '" << InputTwo.text << "' to '" << InputOne.text << "'.\n";
			InputOne.Append(InputTwo.text);
			std::cout << InputOne.text << "\n";
		}
		else if (Action == 3)
		{
			InputOne.ToLower();
			std::cout << "\n>> Converted '" << InputOne.text << "' to lowercase.\n";
		}
		else if (Action == 4)
		{
			InputOne.ToUpper();
			std::cout << "\n>> Converted '" << InputOne.text << "' to uppercase.\n";
		}
		else if (Action == 5)
		{
			char SearchInput;
			std::cout << "Please input a character to search for in the inital string :\n";
			std::cin >> SearchInput;
			int SearchResult = InputOne.FindCharacter(SearchInput);
			if (SearchResult != -1)
			{
				std::cout << "Search Complete!\n";
			}
			else
			{
				std::cout << "'" << SearchInput << "' could not be found in '" << InputOne.text << "'.\n";
			}
		}
		else if (Action == 6)
		{
			char SearchInput;
			char ReplaceInput;
			std::cout << "Please input a character to search and replace in the inital string :\n";
			std::cin >> SearchInput;
			std::cout << "Please input replacement character :\n";
			std::cin >> ReplaceInput;
			InputOne.Replace(SearchInput, ReplaceInput);
			std::cout << InputOne.text << "\n";
		}
		else if (Action == 7)
		{
			int IsEquals = InputOne.operator==(InputTwo.text);
			if (IsEquals == 0)
			{
				std::cout << "'" << InputOne.text << "' and '" << InputTwo.text << "' are equal.\n";
			}
			else
			{
				std::cout << "'" << InputOne.text << "' and '" << InputTwo.text << "' are NOT equal.\n";
			}
		}
		else if (Action == 8)
		{
			bool IsLessThan = InputOne.operator<(InputTwo.text);
			if (IsLessThan == true)
			{
				std::cout << "'" << InputOne.text << "' comes before '" << InputTwo.text << "' alphabetically.\n";
			}
			else
			{
				std::cout << "'" << InputOne.text << "' comes after '" << InputTwo.text << "' alphabetically.\n";
			}
		}
		else if (Action == 9)
		{
			InputOne.operator=(InputTwo);
			std::cout << "The inital string is now '" << InputOne.text << "'.\n";
		}
		else if (Action == 10)
		{
			int SSinput;
			std::cout << "Please input a location to find within the inital string :\n";
			std::cin >> SSinput;
			char SSoutput = InputOne.operatorss(SSinput);
			if (SSoutput != 0)
			{
				std::cout << "'" << SSoutput << "' can be found at '" << SSinput << "'.\n";
			}
			else
			{
				std::cout << "Nothing can be found at '" << SSinput << "'!\n";
			}
		}
		else
		{
			return 0;
		}
		Action = ActionCheck();
	}
}