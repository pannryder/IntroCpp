#pragma once

#include "String.h"
#include <iostream>
#include <string>

// -To be implimented-
// Subscript Operator

// -Implimented-
// Length
// Append
// ToLower
// ToUpper
// FindCharacter
// ReadFromConsole
// WriteToConsole
// LessThan Operator
// Equality Operator
// Replace
// Assignment Operator

String::String()
	:text{}, length{}
{
	
}

String::String(const char initialText[])
	:text{}, length{}
{
	strcpy_s(text, initialText);
}

String::String(const char initialText[], size_t length)
	:text{}, length{}
{
	strcpy_s(text, initialText);
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
	//if (sizeof(text) < length + _str.length + 1)
	//{
	//	return *this;
	//}

	if (_str.length == 0)
	{
		return *this;
	}
	std::size_t newLength = length + _str.length;
	char* newText = new char[newLength + 1]{};

	if (length < 0)
	{
		std::strcpy(newText, text);
	}
	strcat(newText, _str.text);
	length += _str.length;

	delete[] text;
	text = newText;

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
	const char* result = std::strchr(text, _chr);
	if (result != NULL)
	{
		while (result != NULL) {
			std::cout << "Found '" << _chr << "' at '" << result - text + 1 << "' in '" << text << "'.\n";
			result = std::strchr(result + 1, _chr);
		}
		return 1;
	}
	else
	{
		return -1;
	}
}

int String::Replace(const char _find, const char _replace)
{
	const char* Finder = std::strchr(text, _find);
	if (Finder != NULL)
	{
		while (Finder != NULL) {
			text[Finder - text] = _replace;
			Finder = std::strchr(Finder + 1, _find);
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

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

int String::operator==(const String& other) const 
{
	return std::strcmp(text, other.text);
}

bool String::operator<(const String& other) const 
{
	return std::strcmp(text, other.text) < 0;
}

int String::operator=(const String& other)
{
	strcpy_s(text, other.text);
	return 1;
}

char String::operatorss(int n)
{
	char output = text[n];
	if (output != NULL)
	{
		return output;
	}
	else 
	{
		return 0;
	}
}