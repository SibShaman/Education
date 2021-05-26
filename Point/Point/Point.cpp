#include<iostream>
using namespace std;

//			1. В классе Point реализовать МЕТОД ? ? ? distance(? ? ? ), который возвращает расстояние до указанной точки; 	
//			2. Реализовать ФУНКЦИЮ ? ? ? distance(? ? ? ), которая возвращает расстояние между двумя точками;

class Point;
void func_distance(Point A);


class Point
{
	double point_x;    //Объявление переменной для одной из координат (по оси Х)
	double point_y;	//Объявление переменной для одной из координат (по оси Y)	

public:
	//GET methods
	double get_X()const
	{
		return point_x;
	}
	double get_Y()const
	{
		return point_y;
	}

	//SET methods
	void set_x(double point_x)
	{
		this->point_x = point_x;
	}
	void set_y(double point_y)
	{
		this->point_y = point_y;
	}

	//Default constructor
	Point()
	{
		point_x = 0;
		point_y = 0;
		//cout << "Default constructor" << this << endl;
	}

	//Constructor with two parametres
	Point(double point_X, double point_Y)
	{
		this->point_x = point_X;
		this->point_y = point_Y;
		//cout << "Constructor:\t" << this << endl;
	}

	void point()
	{
		cout << "Введите координаты точки Х: " << endl;
		cin >> point_x;
		cout << "Введите координаты точки Y: " << endl;
		cin >> point_y;
	}

	//Method distance - считает расстояние до точки введенной с клавиатуры
	double distance()  //double point_x, double point_y
	{
		return sqrt(pow(point_x, 2) + pow(point_y, 2));
	}

	//Destructor
	//~Point()
	//{
	//	cout << "Destructor" << this << endl;
	//}
};

void main()
{
	setlocale(LC_ALL, "");

	Point A;
	func_distance(A);
}

void func_distance(Point A)
{
	double distance_in_func;
	double point_Z;
	double point_F;
	double result;

	cout << "Введите координаты точки класса Point:" << endl;
	A.point();

	cout << "Введите координаты точки функции:" << endl;
	cout << "Введите координаты точки Z: " << endl;
	cin >> point_Z;

	cout << "Введите координаты точки F: " << endl;
	cin >> point_F;

	distance_in_func = sqrt(pow(point_Z, 2) + pow(point_F, 2));


	cout << "Расстояние до точки А (в классе): \t" << A.distance() << endl;
	cout << "Расстояние до точки В(в функции):\t" << distance_in_func << endl;

	result = abs(distance_in_func - A.distance());

	cout << "Расстояние между точкой А (в классе) и точкой В (в функции): \t" << result << endl;
}


