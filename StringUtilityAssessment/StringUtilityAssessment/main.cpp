#include "String.h"
#include <iostream>



int main()
{
	String Testing{};
	Testing.WriteToConsole();
	Testing.ToLower();
	std::cout << "\n";
	Testing.ToUpper();
	std::cout <<"\n" << Testing.Length() << "\n";
}