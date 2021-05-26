#include<iostream>
using namespace std;

//			1. � ������ Point ����������� ����� ? ? ? distance(? ? ? ), ������� ���������� ���������� �� ��������� �����; 	
//			2. ����������� ������� ? ? ? distance(? ? ? ), ������� ���������� ���������� ����� ����� �������;

class Point;
void func_distance(Point A);


class Point
{
	double point_x;    //���������� ���������� ��� ����� �� ��������� (�� ��� �)
	double point_y;	//���������� ���������� ��� ����� �� ��������� (�� ��� Y)	

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
		cout << "������� ���������� ����� �: " << endl;
		cin >> point_x;
		cout << "������� ���������� ����� Y: " << endl;
		cin >> point_y;
	}

	//Method distance - ������� ���������� �� ����� ��������� � ����������
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

	cout << "������� ���������� ����� ������ Point:" << endl;
	A.point();

	cout << "������� ���������� ����� �������:" << endl;
	cout << "������� ���������� ����� Z: " << endl;
	cin >> point_Z;

	cout << "������� ���������� ����� F: " << endl;
	cin >> point_F;

	distance_in_func = sqrt(pow(point_Z, 2) + pow(point_F, 2));


	cout << "���������� �� ����� � (� ������): \t" << A.distance() << endl;
	cout << "���������� �� ����� �(� �������):\t" << distance_in_func << endl;

	result = abs(distance_in_func - A.distance());

	cout << "���������� ����� ������ � (� ������) � ������ � (� �������): \t" << result << endl;
}


