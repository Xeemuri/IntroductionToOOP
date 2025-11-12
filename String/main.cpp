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
bool is_palindrome(const char* str);
char* RemoveSymbol(char str[], char symbol = ' ');
bool is_int_number(char* str);
int to_int_number(char* str);
bool is_bin_number(char* str);
int bin_to_dec(char* str);
bool is_hex_number(char* str);
int hex_to_dec(char* str);
bool isIPaddress(char* str);
bool isMACaddress(char* str);

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

	const int SIZE = 50;
	char str[SIZE] = {"00-50-B6-5B-CA-6A"};
	//cout << "Введите строку: ";
	SetConsoleCP(1251);
	//cin.getline(str,SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << StringLength(str) << endl;
	cout << strlen(str) << endl;
	cout << ToUpper(str) << endl;
	cout << ToLower(str) << endl;
	shrink(str);
	cout << str << endl;
	cout << "Строка" << ((is_palindrome(str)) ? " - палиндром" : " не палиндром") << endl;
	cout << "Строка" << ((is_int_number(str)) ? " - целое число" : " нецелое число") << endl;
	cout << to_int_number(str) << endl;
	cout << endl;
	cout << "Строка" << ((is_bin_number(str)) ? " - двоичное число" : " не двоичное число") << endl;
	cout << bin_to_dec(str) << endl;
	cout << endl;
	cout << "Строка" << ((is_hex_number(str)) ? " - шестнадцатеричное число" : " не шестнадцатеричное число") << endl;
	cout << hex_to_dec(str) << endl;
	cout << "Строка" << ((isIPaddress(str)) ? " - IP адрес" : " не IP адрес") << endl;
	cout << "Строка" << ((isMACaddress(str)) ? " - " : " не ") << "MAC адрес" << endl;
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

bool is_palindrome(const char* str)
{
	/*toLower(str);*/
	int size = strlen(str);
	char* buffer = new char[size + 1] {};
	strcpy(buffer, str);
	//strcpy(dst,src) //Эта функция копирует содержимое строки 'src' (Source) в строку 'dst' (Destination)
	ToLower(buffer);
	RemoveSymbol(buffer);
	size = strlen(buffer);
	for (int i = 0; i < size/2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

char* RemoveSymbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
bool is_int_number(char* str)
{
	for (int i = 0; str[i]; i++)
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
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ') return false;
	}
	return true;
}
int bin_to_dec(char* str)
{
	/*if (is_bin_number(str) == false)return 0;

	int result = 0, pow_of_two = 0;
	for (int i = strlen(str)-1; i>=0; i--)
	{
		result += int(str[i] - '0') * pow(2, pow_of_two++);
	}
	return result;*/

	int decimal = 0;
	int weight = 1;		//Весовой коэффициент разряда
	int length = strlen(str);
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] == ' ')continue;
		decimal += (str[i] - '0') * weight;
		weight *= 2;
	}
	return decimal;
}

bool is_hex_number(char* str)
{
	/*ToUpper(str);
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < 'A' || str[i] >'F') && (str[i] < '0' || str[i] >'9')) return false;
	}
	return true;*/

	bool prefix = false;
	if (str[0] == '0' && str[1] == 'x')prefix = true;
	for (int i = prefix ? 2 : 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			!(str[i] >= 'a' && str[i] <= 'f')
			) return false;
	}
	return true;
}
int hex_to_dec(char* str)
{
	/*if(!is_hex_number(str)) return 0;
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
	return result;*/
	int decimal = 0;
	int weight = 1;
	int length = strlen(str);
	bool prefix = false;
	if (str[0] == '0' && str[1] == 'x')prefix = true;
	for (int i = length - 1; i >= (prefix ? 2 : 0); i--)
	{
		int digit = 0;
		if (str[i] >= '0' && str[i] <= '9')digit += str[i] - 48;
		if (str[i] >= 'A' && str[i] <= 'F')digit += str[i] - 55;
		if (str[i] >= 'a' && str[i] <= 'f')digit += str[i] - 87;
		decimal += digit * weight;
		weight *= 16;
	}
	return decimal;
}
bool isIPaddress(char* str)
{
	char* num;
	int index = 0;
	int number;
	int size = 0;
	int j = 0;
	for (int i = 0; i < 4; i++)	//цикл по числам
	{
		for (index; str[index] != '.'&& size < 4;index++) //передача числа в массив
		{
			size++;
		}
		num = new char[size+1];
		for (index -= size, j = 0; j < size; index++, j++)
		{
			num[j] = str[index];
		}
		num[size] = '\0';
		if (!is_int_number(num)) return false;
		number = atoi(num);
		if (number > 255) return false;
		if (str[index++] != '.' && i < 3) return false;
		delete[] num;
		size = 0;
	}
	if (str[index]) return false;
	return true;
}
bool isMACaddress(char* str)
{
	if(str[17]) return false;
	char* num;
	int index = 0;
	int number;
	int size = 2;
	for (int i = 0; i < 6; i++)	//цикл по числам
	{
		num = new char[size + 1];
		for (int j = 0; j < size; index++, j++)
		{
			num[j] = str[index];
		}
		num[size] = '\0';
		if (!is_hex_number(num)) return false;
		if (str[index++] != '-' && i < 5) return false;
		delete[] num;
	}
	if (str[index]) return false;
	return true;
}