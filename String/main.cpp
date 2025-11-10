#include <Windows.h>
#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;


int StringLength(const char str[]);
char* ToUpper(char str[]);
char* ToLower(char str[]);
void shrink(char str[]); 
bool is_palindrome(char* str);
bool is_int_number(char* str);
int to_int_number(char* str);
bool is_bin_number(char* str);
int bin_to_dec(char* str);
bool is_hex_number(char* str);
int hex_to_dec(char* str);

//#define LINES_BASICS_1

int main()
{
	setlocale(LC_ALL, "");
#ifdef LINES_BASICS_1
	/*char str[] = { 'H','e','l','l','o',' ', 0 };*/
	char str[] = "Hello";
	cout << str << endl;
	return 0;
#endif // LINES_BASICS_1

	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str,SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << StringLength(str) << endl;
	cout << strlen(str) << endl;
	cout << ToUpper(str) << endl;
	cout << ToLower(str) << endl;
	shrink(str);
	cout << str << endl;
	cout << ((is_palindrome(str) == true) ? "Строка - палиндром" : "Строка не палиндром") << endl;
	cout << is_int_number(str) << endl;
	cout << to_int_number(str) << endl;
	cout << endl;
	cout << is_bin_number(str)<<endl;
	cout << bin_to_dec(str) << endl;
	cout << endl;
	cout << is_hex_number(str)<<endl;
	cout << hex_to_dec(str) << endl;
}


int StringLength(const char str[])
{
	int i = 0;

	while (str[i] != '\0') i++;
	return i;
}
char* ToUpper(char str[])
{
	for (int i = 0; str[i]; i++) str[i] = toupper(str[i]);
	/*for (int i = 0;str[i]; i++)
	{
		if ('a' <= (int)str[i] and (int)str[i] <= 'z') str[i] -= 32;
		if ('а' <= (int)str[i] and (int)str[i] <= 'я') str[i] -= 32;
		if (str[i] == 'ё')str[i] -= 16;
	}*/
	return str;
}
char* ToLower(char str[])
{
	for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
	/*for (int i = 0; str[i]; i++)
	{
		if ('A' <= (int)str[i] and (int)str[i] <= 'Z') str[i] += 32;
		if ('А' <= (int)str[i] and (int)str[i] <= 'Я') str[i] += 32;
		if (str[i] == 'Ё')str[i] += 16;
	}*/
	return str;
}
void shrink(char str[])
{
	char previous = '\0';
	int j = 0;
	for (int i = 0; str[i]; i++)
	{
		if (previous != ' ' || str[i] != ' ')
		{
			str[j++] = str[i];
		}
			previous = str[i];
	}
	str[j] = '\0';
}

bool is_palindrome(char* str)
{
	
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i]) return false;
	}
	return true;
}

bool is_int_number(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if ((int)str[i] < '0' || (int)str[i] > '9') return false;
	}
	return true;
}
int to_int_number(char* str)
{
	if (is_int_number(str) == false) return 0;
	else return atoi(str);
}
bool is_bin_number(char* str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1') return false;
	}
	return true;
}
int bin_to_dec(char* str)
{
	if (is_bin_number(str) == false)return 0;


	int result = 0, pow_of_two = 0;
	for (int i = strlen(str)-1; i>=0; i--)
	{
		result += int(str[i] - '0') * pow(2, pow_of_two++);
	}
	return result;
}

bool is_hex_number(char* str)
{
	ToUpper(str);
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < 'A' || str[i] >'F') && (str[i] < '0' || str[i] >'9')) return false;
	}
	return true;
}
int hex_to_dec(char* str)
{
	int result = 0, power = 0;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] - '0' < 10)
		{
			result += int(str[i] - '0') * pow(16, power++);
		}
		else
		{
			switch (str[i])
			{
			case 'A': result += 10 * pow(16, power++);break;
			case 'B': result += 11 * pow(16, power++);break;
			case 'C': result += 12 * pow(16, power++);break;
			case 'D': result += 13 * pow(16, power++);break;
			case 'E': result += 14 * pow(16, power++);break;
			case 'F': result += 15 * pow(16, power++);break;
			}
		}
		
	}
	return result;
}
