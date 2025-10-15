#include <iostream>
using namespace std;
#define tab "\t"
#define delimeter "\n--------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
		//this - указатель на объект для которого вызывается метод
	}

	//		Constructors
	//Point()
	//{
	//	x = y = 0; //Записываем в переменные члены класса значения по умолчанию
	//	cout << "Default Constructor:\t" << this << endl;
	//}
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgConstructor:\t" << this << endl;
	//}
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//				Operators:
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return other;
	}

	//				Methods:
	double distance(const Point& other)const
	{
		/*other.x *= 100;
		other.y *= 100;
		this->x *= 100;
		this->y *= 100;*/
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance); //По теореме Пифагора
		return distance;
	}
	void print() const
	{
		cout << "X = " << x << ", \tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define FOR_COUNTER_LIFETIME
//#define CONSTRUCTORS_CHECK
#define ASSIGNMENT_CHECK
int main()
{
	setlocale(LC_ALL, "");   

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками А и B: " << distance(A, B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimeter << endl;
#endif // DISTANCE_CHECK
#ifdef FOR_COUNTER_LIFETIME
	for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	//Если бы переменная 'i' была объектом, то по завершении всех итераций для нее был бы вызван деструктор
	//по скольку время жизни переменной 'i' завершается по оканчании всех итераций цикла 'for'.
	cout << endl;
#endif // FOR_COUNTER_LIFETIME
#ifdef STRUCT_POINT
	cout << "Hello OOP!" << endl;
	Point A;	//Объявление переменной А типа Point
	//Объявление объекта А структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A; //Объявляем указатель на объект "A"
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A;		//Default constructor
	A.print();

	Point B(12);	// Single-argument constructor (Конструктор с одним ппараметром)
	B.print();

	Point C(2, 3);	//Конструктор с параметрами
	C.print();

	Point D = C;	//Конструктор копирования
	D.print();

	Point E;
	E = D;			//CopyAssignment
	E.print();
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK
	return 0;
}
