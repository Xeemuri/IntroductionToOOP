#pragma once
#include <iostream>
#include <cstring>
using namespace std;

#define tab "\t"
#define delimeter "\n--------------------------------------------------------------\n"


//////////////////////////////////////////////////////////////////////////////////////
//////////////				Class declaration							//////////////

class String
{
	int size;	//размер строки в байтах
	char* str;
public:
	int get_size() const;
	const char* get_str() const;
	char* get_str();

	explicit String(int size = 80);
	String(const char str[]);
	String(const String& obj);
	String(String&& other);
	~String();

	//		Methods:
	void print() const;

	String& operator= (const String& other);
	char operator[](int i) const;
	char& operator[](int i);
};
//////////////				Class declaration end						//////////////
//////////////////////////////////////////////////////////////////////////////////////

