#pragma once

#include "String.h"
#include <iostream>
#include <string>

String::String()
	:text{}, length{}
{
	
}

String::String(const char* _str)
{
	strcpy_s(text, _str);
}

String::String(const char initialText[], size_t length)
{
}

String::~String()
{
}

size_t String::Length() const
{
	return(std::strlen(text));
}

String& String::Append(const String& _str)
{
	if (sizeof(text) < length + _str.length + 1)
	{
		return *this;
	}

	strcat_s(text, _str.text);
	length += _str.length;
	return *this;
}

String& String::ToLower()
{
	for (int i = 0; i < strlen(text); i++)
		putchar(tolower(text[i]));
	return *this;
}

String& String::ToUpper()
{
	for (int i=0; i<strlen(text); i++)
		putchar(toupper(text[i]));
	return *this;
}

int String::FindCharacter(const char _chr) const
{
	char searchTarget;
	std::cin >> searchTarget;
	//finish this on friday

}

//int String::Replace(const char _find, const char _replace)
//{
//	
//}

String& String::ReadFromConsole() 
{
	std::string readBuffer;
	std::getline(std::cin, readBuffer);

	Append(readBuffer.c_str());

	return *this;
}

String& String::WriteToConsole()
{
	std::cout << text << std::endl;
		return *this;
}