#include <iostream>
using namespace std;

class Point1
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
	double distance()
	{
		double distance = sqrt(x * x + y * y); //По теореме Пифагора
		return distance;
	}
};

class Point2
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
	}
	double distance()
	{
		return sqrt(x * x + y * y);
	}
};


double distance(double x1, double y1, double x2, double y2)
{
	 return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");
	Point1 A;
	Point2 B;
	A.set_x(4);
	A.set_y(3);
	B.set_x(3);
	B.set_y(4);
	cout <<"Point A: "<< A.get_x() << "\t" << A.get_y() << endl;
	cout << "Point B: " << B.get_x() << "\t" << B.get_y() << endl;
	cout << "Distance to point A: " << A.distance()<<endl;
	cout << "Distance to point B: " << B.distance()<<endl;

	cout << "Distance between point A and point B: " << distance(A.get_x(), A.get_y(), B.get_x(), B.get_y());
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

}
