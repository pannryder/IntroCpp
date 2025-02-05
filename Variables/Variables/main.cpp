#include <iostream>

int CheckInput()
{
	int TheValue;
	int counter;

	std::cout << "\033[4;32m[Please write either 1 or 2.]\033[0m\n\n";
	std::cin >> TheValue;
	//Checks if input is a numerical value, then allows for limited re-attempts
	for (counter = 1; !std::cin.good() && counter < 4; counter = counter + 1)
	{
		std::cout << "\n\033[4;31m[Wrong! Write a numerical value forehead. Do it again.]\n[You have " << 4 - counter << " attempts left.]\033[0m\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> TheValue;
	}
	return TheValue;
}

int main()
{


	int CheckOne = CheckInput();

	if (CheckOne == 0)
	{
		std::cout << "\n\033[4;31m[Don't piss me off...]\n[Goodbye.]\033[0m\n\n" << std::endl;
	}

	else if (CheckOne == 1)
	{
		std::cout << "\n\033[4;32m[You wrote " << CheckOne << ", thank YOU for complying <3.]\033[0m\n\n" << std::endl;
	}

	else if (CheckOne == 2)
	{
		std::cout << "\n\033[4;33m[You wrote " << CheckOne << ", that was certainly... a choice. Not what I would write but oh well.]\033[0m\n" << std::endl;
	}

	else
	{ 
		std::cout << "\n\033[4;31m[You wrote " << CheckOne << ". That's literally NOT what I asked for.]\n[There's something wrong with you. Goodbye.]\033[0m" << std::endl;
	}


	
}