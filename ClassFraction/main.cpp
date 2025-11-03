#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define tab "\t"
#define delimeter "\n--------------------------------------------\n"
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPOUND_ASSIGNMENTS
//#define INCREMENT_DECREMENT
// STREAMS_CHECK_1
// STREAMS_CHECK_2
//#define TYPE_CONVERSIONS_BASICS
class Fraction;
Fraction operator+ (Fraction left, Fraction right);
Fraction operator- (Fraction left, Fraction right);
Fraction operator* (Fraction left, Fraction right);
Fraction operator/ (const Fraction& left, const Fraction& right);


class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator )
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	 explicit Fraction(int integer)
	{
		this->integer = integer;
		numerator = 0;
		denominator = 1;
		cout << "SingleArgConstrucor: \t" << this << endl;
	}
	
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t"  << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor: \t\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor: \t\t" << this << endl;
	}


	Fraction& operator= (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	//	Операторы составного присваивания:
	Fraction& operator+=(const Fraction& right)
	{
		return *this = *this + right;
	}
	Fraction& operator-=(const Fraction& right)
	{
		return *this = *this - right;
	}
	Fraction& operator*=(const Fraction& right)
	{
		return *this = *this * right;
	}
	Fraction& operator/=(const Fraction& right)
	{
		return *this = *this / right;
	}
	//		Инкременты:
	Fraction& operator++()		//префиксный
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int)	//постфиксный
	{
		Fraction old = *this;
		this->integer++;
		return old;
	}
	//		Декременты:
	Fraction& operator--()		//префиксный
	{
		this->integer--;
		return *this;
	}
	Fraction operator--(int)	//постфиксный
	{
		Fraction old = *this;
		this->integer--;
		return old;
	}
	//		Методы класса:
	Fraction& reduce()
	{
		int more, less, rest = 0;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted() const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

};

int GCD(int a, int b)	//Greatest Common Divisor (Наибольший общий делитель)
{
	int greater, lesser;
	if (a == b) return a;
	else if (a > b)
	{
		greater = abs(a);
		lesser = abs(b);
	}
	else
	{
		greater = abs(b);
		lesser = abs(a);
	}
	int remainder;
	do
	{
		remainder = greater % lesser;
		if (remainder == 0) return lesser;
		greater = lesser;
		lesser = remainder;
	} while (remainder != 0);
}

int LCM(int a, int b) //Least Common Multiple (Наименьшее Общее Кратное)
{
	return a * b / GCD(a, b);
}

//			Арифметические операторы:
Fraction operator+(Fraction left, Fraction right)
{

	left.to_improper();
	right.to_improper();

	if (left.get_denominator() != right.get_denominator())
	{
		int lcm = LCM(left.get_denominator(), right.get_denominator());
		int left_multiplier = lcm / left.get_denominator();
		int right_multiplier = lcm / right.get_denominator();

		left.set_numerator(left.get_numerator() * left_multiplier);
		right.set_numerator(right.get_numerator() * right_multiplier);

		left.set_denominator(left.get_denominator() * left_multiplier);
		right.set_denominator(right.get_denominator() * right_multiplier);
	}

	Fraction result;
	result.set_numerator(left.get_numerator() + right.get_numerator());
	result.set_denominator(left.get_denominator());
	return result;
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	if (left.get_denominator() != right.get_denominator())
	{
		int lcm = LCM(left.get_denominator(), right.get_denominator());
		int left_multiplier = lcm / left.get_denominator();
		int right_multiplier = lcm / right.get_denominator();

		left.set_numerator(left.get_numerator() * left_multiplier);
		right.set_numerator(right.get_numerator() * right_multiplier);

		left.set_denominator(left.get_denominator() * left_multiplier);
		right.set_denominator(right.get_denominator() * right_multiplier);
	}

	Fraction result;
	result.set_numerator(left.get_numerator() - right.get_numerator());
	result.set_denominator(left.get_denominator());
	return result;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}


//			Операторы сравнения: 
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator != (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator < (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator <= (const Fraction& left, const Fraction& right)
{
	return !(left > right);
}
bool operator >= (const Fraction& left,const Fraction& right)
{
	return !(left < right);
}

//	Операторы перенаправления в поток:
 ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
 std::istream& operator>>(std::istream& is, Fraction& obj)
 {
	 const int SIZE = 32;
	 char buffer[SIZE] = {};
	 is >> buffer;
	 /*is.getline(buffer, SIZE);*/
	 cout << buffer << endl;
	 int numbers[3] = {};
	 const char delimiters[] = "+()/";
	 int n = 0;
	 for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	 {
		 numbers[n++] = atoi(pch);	//atoi - ANSI/ASCII to Int;
		 cout << pch << "\t";
	 }
	 cout << endl;
	 switch (n)
	 {
	 case 1: obj = Fraction(numbers[0]); break;
	 case 2: obj = Fraction(numbers[0],numbers[1]); break;
	 case 3: obj = Fraction(numbers[0],numbers[1],numbers[2]); break;
	 }
	 return is;
 }


void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A / B;
	C.print();
#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef COMPOUND_ASSIGNMENTS
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	A *= B;
	A.print();
	A /= B;
	A.print();
#endif // COMPOUND_ASSIGNMENTS

#ifdef INCREMENT_DECREMENT
	for (Fraction i(1, 2); i.get_integer() < 10; ++i)
	{
		i.print();
	}
#endif // INCREMENT_DECREMENT

#ifdef STREAMS_CHECK_1
	//cout << (Fraction(1, 2) != Fraction(5, 10)) << endl;

/*Fraction B = 0;*/
/*cout << ++B << endl;
cout << B++ << endl;*/

	Fraction A;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif // STREAMS_CHECK_1
	Fraction A, B, C;
	cout << "Введите 3 простых дроби: ";
	cin >> A >> B >> C;
	cout << A << tab << B << tab <<  C << endl;

#ifdef TYPE_CONVERSION_BASICS
	int a = 2;
	double b = a;
	int c = b;
	int d = 3.14;
#endif // TYPE_CONVERSION_BASICS
	/*Fraction A = (Fraction)5;
	cout << A << endl;

	Fraction B;
	B = Fraction(8);
	cout << B << endl;*/

}