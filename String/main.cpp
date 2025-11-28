#include"String.h"
//#define BASE_CHECK
#define OPERATORS_CHECK
int main()
{
#ifdef BASE_CHECK
	setlocale(LC_ALL, "");
	String str(12);
	cout << str << endl;

	String str1 = "Hello";
	//str1.print();
	cout << str1 << endl;

	String str2 = str1;
	cout << str2 << endl;
	return 0;
#endif // BASE_CHECK
#ifdef OPERATORS_CHECK
	String str1 = "Hello";
	String str2 = "World";

	cout << delimeter << endl;
	String str3 = str1 + str2;
	cout << delimeter << endl;
	cout << str3 << endl;
	String str4 = str3;
	str4.print();
#endif // OPERATORS_CHECK

}