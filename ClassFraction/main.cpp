#include <iostream>
using namespace std;

#define tab "\t"
#define delimeter "\n--------------------------------------------\n"
//#define CONSTRUCTORS_CHECK
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
	Fraction(int integer)
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

	Fraction to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
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

int LCM(int a, int b)//Least Common Multiple (Наименьшее Общее Кратное)
{
	return a * b / GCD(a, b);
}

Fraction operator*(Fraction left, Fraction right)
{

	left.to_improper();
	right.to_improper();

	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);*/
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*result.to_proper();*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator*=(Fraction& left, const Fraction& right)
{
	return left = left * right;
}
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
Fraction operator+=(Fraction& left, const Fraction& right)
{
	return left = left + right;
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
Fraction operator-=(Fraction& left, const Fraction& right)
{
	return left = left - right;
}
Fraction operator/(Fraction left, Fraction right)
{
	Fraction result;

	left.to_improper();
	right.to_improper();

	//Переворачиваем дробь
	int buffer = right.get_numerator();
	right.set_numerator(right.get_denominator());
	right.set_denominator(buffer);

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/=(Fraction& left, const Fraction& right)
{
	return left = left / right;
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

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();
}