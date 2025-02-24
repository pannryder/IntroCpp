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
	: length(0)
{
	text = new char[1];
	text[0] = '\0';
}

String::String(const char initialText[])
{
	if (initialText)
	{
		length = std::strlen(initialText);
		text = new char[length + 1];
		std::strcpy(text, initialText);
	}
	else
	{
		length = 0;
		text = new char[1];
		text[0] = '\0';
	}
}

String::String(const char initialText[], size_t length)
	:text{}, length{}
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

	if (text != nullptr && length > 0)
	{
		strcpy(newText, text);
	}
	else
	{
		newText[0] = '\0';
	}
	strcat(newText, _str.text);

	length = newLength;

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
	//std::istream::sentry inputBuffer(std::cin);
	//if (!inputBuffer)
	//{
	//	return *this;
	//}

	int nextChar = std::cin.rdbuf()->sgetc();
	for (;;nextChar = std::cin.rdbuf()->snextc())
	{
		if (nextChar == -1)
		{
			break;
		}
		if (nextChar == '\n')
		{
			std::cin.rdbuf()->sbumpc();
			break;
		}

		char temp[2] = { static_cast<char>(nextChar), '\0' };
		Append(String(temp));
	}

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
	strcpy(text, other.text);
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