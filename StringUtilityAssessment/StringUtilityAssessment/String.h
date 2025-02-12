#pragma once

class String
{
public:
	char text[255];
	size_t length;


	String();

	String(const char initialText[]);
	
	String(const char initialText[], size_t length);

	size_t Length() const;
	String& Append(const String& _str);

	String& ToUpper();
	String& ToLower();

	int FindCharacter(const char _chr) const;
	int Replace(const char _find, const char _replace);

	String& ReadFromConsole();
	String& WriteToConsole();

private:

};