#pragma once
#include <cstddef>

class String
{
private:
	char* text;
	size_t length;

public:

	String();

	String(const char* _str);
	
	String(const String& _other);

	~String();



	//Gets the length of a string and returns the length
	size_t Length() const;

	//Joins two strings together
	String& Append(const String& _str);

	//Converts the characters in a string to lowercase characters
	String& ToUpper();

	//Converts the characters in a string to uppercase characters
	String& ToLower();

	//Copies and replaces one string to another
	String& Copy(const String& _str);

	//Searchs for the first instance of a character within a string
	int FindCharacter(const char _chr) const;

	//Searches and replaces any instances of inputted character with another
	int Replace(const char _find, const char _replace);

	//Reads input from the console
	String& ReadFromConsole();

	//Outputs text to the console
	String& WriteToConsole();

	//Checks if the strings are equal
	bool operator==(const String& other) const;

	//Checks which string comes first alphabetically
	bool operator<(const String& other) const;

	//Replaces characters in the inital string with characters from the comparative string.
	String& operator=(const String& other);

	char& operator[](size_t _index);

	const char& operator[](size_t _index) const;

	char& Print();
private:

};