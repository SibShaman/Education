﻿#include <iostream>
using namespace std;

/*
Реализовать класс Fraction, описывающий простую дробь.
В классе должны быть все обязательные методы, а так же методы :
-to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
-to_improper();		//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
-reduce();			//Сокращает дробь: 5/10 => 1/2;
1. Арифметические операторы : +, -, *, / ;
2. Составные присваивания : +=, -=, *=, /=;
3. Increment / Decrement(++ / --);
4. Операторы сравнения : == , != , > , < , >= , <= ;
5. Операторы для работы с потоками : << , >>
*/


class Fraction
{
	double namerator_one;
	double denominator_one;
	double namerator_two;
	double denominator_two;


public:
	Fraction();


	~Fraction();

private:

};

Fraction::Fraction()
{
}

Fraction::~Fraction()
{
}


int main()
{
	setlocale(LC_ALL, "");

	cout << "Test";
}
