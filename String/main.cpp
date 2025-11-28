#include <iostream>
#include <cstring>
using namespace std;

#define tab "\t"
#define delimeter "\n--------------------------------------------------------------\n"
//#define BASE_CHECK
#define OPERATORS_CHECK

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

//////////////////////////////////////////////////////////////////////////////////////
//////////////				Class definition							//////////////
int String::get_size() const
{
	return size;
}
const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}

String::String(int size) :
	str(new char[size] {}),
	size(size)
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefConstructor: \t" << this << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	/*this->size = strlen(str)+1;
	this->str = new char[size] {};*/
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor: \t\t" << this << endl;
}
String::String(const String& obj) : String(obj.str)
{
	/*this->size = obj.size;
	this->str = new char[size] {};*/
	//for (int i = 0; i < size; i++) this->str[i] = obj.str[i];
	cout << "CopyConstructor: \t" << this << endl;
}
String::String(String&& other)
{
	//String&& other - r-value reference
	//Shallow copy - поверхностное копирование
	this->size = other.size;
	this->str = other.str;

	//Обязательно нужно обнулить копируемый объектЖ
	other.size = 0;
	other.str = nullptr;
	//это предотвращает удаление динамической памяти деструктором
	cout << "MoveConstructor: \t" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor: \t\t" << this << endl;
}

//		Methods:
void String::print() const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String& String::operator= (const String& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size];
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyAssignment: " << this << endl;
	return *this;
}
char String::operator[](int i) const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

String operator+ (const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		result[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		result[i + left.get_size()-1] = right[i];
	}
	return result;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
//////////////				Class definition end						//////////////
//////////////////////////////////////////////////////////////////////////////////////
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