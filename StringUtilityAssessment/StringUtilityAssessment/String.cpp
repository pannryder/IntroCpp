#include "String.h"
#include <iostream>
#include <string>

String::String()
	:text{}, length{ 0 }
{

}

size_t String::Length() const
{

}

String& String::Append(const String& _str)
{

}

String& String::ToLower()
{

}

String& String::ToUpper()
{
	char text = std::toupper(text);
}

int String::FindCharacter(const char _chr) const
{

}

int String::Replace(const char _find, const char _replace)
{

}

String& String::ReadFromConsole() 
{

}

String& String::WriteToConsole()
{

}