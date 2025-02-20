#pragma once

class String
{
public:
	char text[100];
	size_t length;


	String();

	String(const char initialText[]);
	
	String(const char initialText[], size_t length);

	~String();

	//Gets the length of a string and returns the length
	size_t Length() const;

	//Joins two strings together
	String& Append(const String& _str);

	//Converts the characters in a string to lowercase characters
	String& ToUpper();

	//Converts the characters in a string to uppercase characters
	String& ToLower();

	//Searchs for the first instance of a character within a string
	int FindCharacter(const char _chr) const;


	int Replace(const char _find, const char _replace);

	//Reads input from the console
	String& ReadFromConsole();

	//Outputs text to the console
	String& WriteToConsole();

	//Checks if the strings are equal
	int operator==(const String& other) const;

	//Checks which string comes first alphabetically
	bool operator<(const String& other) const;

	//Replaces characters in the inital string with characters from the comparative string.
	int operator=(const String& other);

	char operatorss(int n);
private:

};