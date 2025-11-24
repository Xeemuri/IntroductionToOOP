#include <iostream>
#include <cstring>
using namespace std;

#define tab "\t"
#define delimeter "\n--------------------------------------------------------------\n"
//#define BASE_CHECK
#define OPERATORS_CHECK
class String
{
	int size;	//размер строки в байтах
	char* str;
public:
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size() const
	{
		return size;
	}

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor: \t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str)+1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor: \t" << this << endl;
	}
	String(const String& obj)
	{
		this->size = obj.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = obj.str[i];
		cout << "CopyConstructor: \t" << this << endl;
	}
	String(String&& other)
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
	~String()
	{
		delete[] str;
		cout << "Destructor: \t\t" << this << endl;
	}

	//		Methods:
	void print() const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}

	String& operator= (const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	char operator[](int i) const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
};

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
#endif // OPERATORS_CHECK

}