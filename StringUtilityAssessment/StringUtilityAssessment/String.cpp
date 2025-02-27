#include "String.h"
#include <iostream>
#include <string>

String::String()
	: length()
{
	text = new char[1];
	text[0] = '\0';
}

String::String(const char initialText[])
	: length()
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
	: length()
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

String::~String()
{
	delete[] text;
}

size_t String::Length() const 
{
	return(length);
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

String& String::Copy(const String& _str)
{
	operator=(_str);
	return *this;
}

String& String::ToLower() 
{
	for (int i = 0; i < length; i++)
		text[i] = (tolower(text[i]));
	return *this;
}

String& String::ToUpper() 
{
	for (int i  =0; i < length; i++)
		text[i] = (toupper(text[i]));
	return *this;
}

int String::FindCharacter(const char _chr) const 
{
	int loc = -1;
	for (int i = 0; i < length; i++) {
		if (text[i] == _chr) {
			loc = i;
			break;
		}
	}
	return loc;
}

int String::Replace(const char _find, const char _replace)
{
	const char* Finder = std::strchr(text, _find);
	if (Finder != NULL)
	{
		for (int i = 1;;i++) {
			text[Finder - text] = _replace;
			Finder = std::strchr(Finder + 1, _find);
			if (Finder == NULL) {
				return i;
			}
		}
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
	std::cout << text;
		return *this;
}

bool String::operator==(const String& other) const 
{
	return std::strcmp(text, other.text);
}

bool String::operator<(const String& other) const 
{
	return std::strcmp(text, other.text) < 0;
}

String& String::operator=(const String& other)
{
	std::size_t newLength = other.length;
	char* newText = new char[newLength + 1] {};

	if (text != nullptr && length > 0)
	{
		strcpy(newText, other.text);
	}
	else
	{
		newText[0] = '\0';
	}

	length = newLength;

	delete[] text;
	text = newText;

	return *this;
}

char& String::operator[](size_t _index)
{
	if (_index > 0 && _index < length)
	{
		return text[_index];
	}
	else
	{
		return text[length];
	}
}

const char& String::operator[](size_t _index) const
{
	if (_index > 0 && _index < length)
	{
		return text[_index];
	}
	else
	{
		return text[length];
	}
}
