#define _CRT_SECURE_NO_WARNINGS
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
bool isIPaddress(const char str[]);
bool isMACaddress(const char str[]);
bool isIPaddressTok(const char str[]);

//#define LINES_BASICS_1
//#define NUMERICS

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
	char str[SIZE] = { "1.2.3.4" };
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
#ifdef NUMERICS
	cout << "Строка" << ((is_palindrome(str)) ? " - палиндром" : " не палиндром") << endl;
	cout << "Строка" << ((is_int_number(str)) ? " - целое число" : " нецелое число") << endl;
	cout << to_int_number(str) << endl;
	cout << endl;
	cout << "Строка" << ((is_bin_number(str)) ? " - двоичное число" : " не двоичное число") << endl;
	cout << bin_to_dec(str) << endl;
	cout << endl;
	cout << "Строка" << ((is_hex_number(str)) ? " - шестнадцатеричное число" : " не шестнадцатеричное число") << endl;
	cout << hex_to_dec(str) << endl;
#endif // NUMERICS
	cout << "Строка" << ((isIPaddress(str)) ? " - IP адрес" : " не IP адрес") << endl;
	cout << "Строка" << ((isMACaddress(str)) ? " - " : " не ") << "MAC адрес" << endl;
	cout << "Строка" << ((isIPaddressTok(str)) ? " - IP адрес" : " не IP адрес") << endl;
	cout << str;
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
	for (int i = 0; i < size / 2; i++)
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
	/*if (!is_int_number(str)) return 0;
	else return atoi(str);*/
	if (!is_int_number(str)) return INT_MIN;
	int integer = 0;
	for (int i = 0; str[i]; i++)
	{
		integer *= 10;
		integer += str[i] - '0';
	}
	return integer;
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
bool isIPaddress(const char str[])
{
	//char* num;
	//int index = 0;
	//int number;
	//int size = 0;
	//int j = 0;
	//for (int i = 0; i < 4; i++)	//цикл по числам
	//{
	//	for (index; str[index] != '.' && size < 4; index++) //передача числа в массив
	//	{
	//		size++;
	//	}
	//	num = new char[size + 1];
	//	for (index -= size, j = 0; j < size; index++, j++)
	//	{
	//		num[j] = str[index];
	//	}
	//	num[size] = '\0';
	//	if (!is_int_number(num)) return false;
	//	number = atoi(num);
	//	if (number > 255) return false;
	//	if (str[index++] != '.' && i < 3) return false;
	//	delete[] num;
	//	size = 0;
	//}
	//if (str[index]) return false;
	//return true;
	if (strlen(str) < 7 || strlen(str) > 15)return false;
	int start = 0;
	int points_count = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '.')
		{
			if (i - start > 3)return false;
			char sz_byte[4] = {};	//sz_ - string zero (NTL)
			unsigned int i_byte = 0;			//i_ - int
			int k = 0;
			for (int j = start; j < i; j++)
			{
				sz_byte[k++] = str[j];
			}
			i_byte = to_int_number(sz_byte);
			if (i_byte > 255) return false;
			start = i+1;
			points_count++;
		}
	}
	return points_count == 3 ? true : false;
}

bool isIPaddressTok(const char str[])
{
	/*if (strlen(str) < 7 || strlen(str) > 15)return false;
	char* buffer = new char[strlen(str)+1];
	strcpy(buffer, str);

	int cnt = 0;
	int number;
	char* pch = strtok(buffer, ".");
	for (int i = 0; pch!= NULL; i++)
	{
		if (i > 3) break;
		if (strlen(pch) > 3) break;
		if (!is_int_number(pch)) break;
		number = std::atoi(pch);
		if (number > 255 || number < 0) break;
		pch = strtok(NULL, ".");
		cnt++;
	}
	delete[] buffer;
	if (cnt != 4) return false;
	else return true;*/

	int size = strlen(str);
	if (size < 7 || size > 15) return false;
	char* buffer = new char[size + 1];
	strcpy(buffer, str);
	int n = 0;
	unsigned int bytes[4] = {};
	for (char* pch = strtok(buffer, "."); pch; pch = strtok(NULL, "."))
		bytes[n++] = std::atoi(pch);
	if (n < 4)return false;
	for (int i = 0; i < n; i++)
	{
		if (bytes[i] > 255)return false;
	}
	return true;
}
bool isMACaddress(const char str[])
{
	//if (strlen(str) != 17 || str[17]) return false;
	//char* num;
	//int index = 0;
	//int number;
	//int size = 2;
	//for (int i = 0; i < 6; i++)	//цикл по числам
	//{
	//	num = new char[size + 1];
	//	for (int j = 0; j < size; index++, j++)
	//	{
	//		num[j] = str[index];
	//	}
	//	num[size] = '\0';
	//	if (!is_hex_number(num)) return false;
	//	if (str[index++] != '-' && i < 5) return false;
	//	delete[] num;
	//}
	//if (str[index]) return false;
	//return true;

	if (strlen(str) != 17) return false;
	for (int i = 0; str[i]; i++)
	{
		if ((i + 1) % 3 == 0 && (str[i] == '-' || str[i] == ':')) continue;
		else if ((i + 1) % 3 == 0) return false;
		/*if(
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			!(str[i] >= 'A' && str[i] <= 'F')
			)return false;*/
		if (!isxdigit(str[i]))return false;
	}
	return true;
}