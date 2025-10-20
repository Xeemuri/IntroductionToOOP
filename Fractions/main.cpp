#include <iostream>
using namespace std;

int GCD(int a, int b);
int LCM(int a, int b);

class Fraction
{
	int int_part;		//целая часть
	int numerator;		//числитель дроби
	int denominator;	//знаменатель дроби
public:
	int get_int_part()
	{
		return int_part;
	}
	int get_numerator()
	{
		return numerator;
	}
	int get_denominator()
	{
		return denominator;
	}
	void set_int_part(int number)
	{
		int_part = number;
	}
	void set_numerator(int number)
	{
		numerator = number;
	}
	void set_denominator(int number)
	{
		denominator = number;
	}

	Fraction(int numerator = 1, int denominator = 1, int int_part = 0)
	{
		while (denominator == 0)
		{
			cout << "Знаменатель дроби должен быть больше нуля, введите его : "; cin >> denominator;
		}
		this->int_part = int_part;
		this->numerator = numerator;
		this->denominator = denominator;
		this->check_negative();
	}
	
	Fraction& operator=(const Fraction& other)
	{
		this->int_part = other.int_part;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->check_negative();
		return *this;
	}

	void print() {
		if (int_part != 0) cout << int_part << " ";
		if(numerator!=0) cout << numerator << "/" << denominator << endl;
	}
	void simplify()
	{
		int gcd = GCD(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		if (numerator > denominator)
		{
			int_part += numerator / denominator;
			numerator = numerator % denominator;
		}
	}
	void check_negative()
	{
		if (denominator < 0 && numerator > 0)						//Например 1/-2 или 1 1/-2
		{
			if (int_part != 0)										// 1 1/-2
			{
				denominator = -denominator;
				int_part = -int_part;
			}
			else													// 1/-2
			{
				denominator = -denominator;
				numerator = -numerator;
			}
		}
		else if (denominator > 0 && numerator < 0 && int_part != 0)	// 1 -1/2
		{
			int_part = -int_part;
			numerator = -numerator;
		}
		else if (numerator < 0 && denominator < 0)					// 1 -1/-2 или -1/-2
		{
			numerator = -numerator;
			denominator = -denominator;
		}
	}
	void to_improper()
	{
		numerator = int_part * denominator + numerator;
	}

};

Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
int main()
{
	setlocale(LC_ALL, "");
	Fraction a(-1, -10);
	cout << "Дробь a = ";a.print();
	Fraction b(3, -10);
	cout << "Дробь b = "; b.print();
	Fraction c;
	c = a + b;
	cout << "a + b = "; c.simplify(); c.print();
	c = a - b;
	cout << "a - b = "; c.simplify(); c.print();
	c = a * b;
	cout << "a * b = "; c.simplify(); c.print();
	c = a / b;
	cout << "a / b = "; c.simplify(); c.print();
}


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

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction left_copy = left;
	Fraction right_copy = right;

	left_copy.to_improper();
	right_copy.to_improper();

	if (left_copy.get_denominator() != right_copy.get_denominator())
	{
		int lcm = LCM(left_copy.get_denominator(), right_copy.get_denominator());
		int left_multiplier = lcm / left_copy.get_denominator();
		int right_multiplier = lcm / right_copy.get_denominator();

		left_copy.set_numerator(left_copy.get_numerator() * left_multiplier);
		right_copy.set_numerator(right_copy.get_numerator() * right_multiplier);

		left_copy.set_denominator(left_copy.get_denominator() * left_multiplier);
		right_copy.set_denominator(right_copy.get_denominator() * right_multiplier);
	}

	Fraction result;
	result.set_numerator(left_copy.get_numerator() + right_copy.get_numerator());
	result.set_denominator(left_copy.get_denominator());
	result.check_negative();
	return result;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction left_copy = left;
	Fraction right_copy = right;

	left_copy.to_improper();
	right_copy.to_improper();

	if (left_copy.get_denominator() != right_copy.get_denominator())
	{
		int lcm = LCM(left_copy.get_denominator(), right_copy.get_denominator());
		int left_multiplier = lcm / left_copy.get_denominator();
		int right_multiplier = lcm / right_copy.get_denominator();

		left_copy.set_numerator(left_copy.get_numerator() * left_multiplier);
		right_copy.set_numerator(right_copy.get_numerator() * right_multiplier);

		left_copy.set_denominator(left_copy.get_denominator() * left_multiplier);
		right_copy.set_denominator(right_copy.get_denominator() * right_multiplier);
	}

	Fraction result;
	result.set_numerator(left_copy.get_numerator() - right_copy.get_numerator());
	result.set_denominator(left_copy.get_denominator());
	result.check_negative();
	return result;
}

Fraction operator*(const Fraction& left,const Fraction& right)
{
	Fraction left_copy = left;
	Fraction right_copy = right;
	Fraction result;
	result.set_numerator(left_copy.get_numerator() * right_copy.get_numerator());
	result.set_denominator(left_copy.get_denominator() * right_copy.get_denominator());
	result.check_negative();
	return result;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction left_copy = left;
	Fraction right_copy = right;
	Fraction result;

	//Переворачиваем дробь
	int buffer = right_copy.get_numerator();
	right_copy.set_numerator(right_copy.get_denominator());
	right_copy.set_denominator(buffer);

	result.set_numerator(left_copy.get_numerator() * right_copy.get_numerator());
	result.set_denominator(left_copy.get_denominator() * right_copy.get_denominator());
	result.check_negative();
	return result;
}