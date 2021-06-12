﻿#include <iostream>
using namespace std;

/*
Реализовать класс Fraction, описывающий простую дробь.
В классе должны быть все обязательные методы, а так же методы :
-to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
-to_improper();		//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
-reduce();			//Сокращает дробь: 5/10 => 1/2;

+++++++++ 1. Арифметические операторы : +, -, *, / ;
2. Составные присваивания : +=, -=, *=, /=;
3. Increment / Decrement(++ / --);
4. Операторы сравнения : == , != , > , < , >= , <= ;
5. Операторы для работы с потоками : << , >>
*/




class Fraction
{
	int namerator;									// объявление переменной для числителя
	int denominator;								//объявление переменной для знаменателя


public:
	
	//GET methods
	int get_namerator()const						//GET метод для числителя
	{
		return namerator;
	}	
	
	int get_denominator()const						//GET метод для знаменателя
	{
		return denominator;
	}	
		
	//SET methods
	void set_namerator(int namerator)			//SET метод для числителя
	{
		this->namerator = namerator;
	}

	void set_denominator(int denominator)		//SET метод для знаменателя
	{
		this->denominator = denominator;
	}

	//Default constraction
	Fraction()
	{
		namerator = 0;
		denominator = 0;

		//cout << "Default Constraction" << endl;
	}
	
	Fraction(int namerator, int denominator)
	{
		this->namerator = namerator;
		this->denominator = denominator;

		//cout << namerator_one << "/" << denominator_one << endl;
		//cout << "Constructor:\t" << this << endl;
	}

	Fraction(const Fraction& other) //конструктор копирования 
	{
		this->namerator = other.namerator;
		this->denominator = other.denominator;
		//cout << "CopyConstructor: " << this << endl;
	}




	/*
	Fraction operator*=()
	{

	}	
	Fraction operator/=()
	{

	}

	Fraction operator++()
	{
	this->set_namerator_one(this->namerator_one += other.namerator_one);
	this->set_denominator_one(this->denominator_one);
	return *this;
	}
*/
	

	~Fraction()
	{
		//cout << "Destructor:\t" << this << endl;
	}
	
	void print()
	{
		cout << namerator << "/" << denominator << endl;
	}

	
	void operator=(const Fraction& other)	//Оператор присвоить
	{
		this->namerator = other.namerator;
		this->denominator = other.denominator;
		//cout << "CopyAssignment: \t\t " << this << endl;
	}


	//Составные присваивания (оператор +=)
	Fraction& operator+=(const Fraction& other)
	{
		if (this->denominator == other.denominator)
		{
			this->set_namerator(this->namerator + other.namerator);
			this->set_denominator(this->denominator);
		}
		else
		{
			this->set_namerator(this->namerator * other.denominator + other.namerator * this->denominator);
			this->set_denominator(this->denominator * other.denominator);
		}
		return *this;
	}

	Fraction& operator-=(const Fraction& other)
	{
		if (this->denominator == other.denominator)
		{
			this->set_namerator(this->namerator - other.namerator);
			this->set_denominator(this->denominator);
		}
		else
		{
			int nod;
			nod = this->denominator * other.denominator;
			this->set_namerator((this->namerator * (nod / other.denominator)) - (other.namerator * (nod / this->denominator)));
			this->set_denominator(nod);
		}
		return *this;
	}
private:

};

//Перегрузка оператора +
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	
	if (left.get_denominator() == 0 || right.get_denominator() == 0)
	{
		cout << "На ноль делить нельзя" << endl;
		return result;
	}


	if (left.get_denominator() == right.get_denominator())
	{
		result.set_namerator(left.get_namerator() + right.get_namerator());
		result.set_denominator(left.get_denominator());
	}
	else
	{
		int nod;
		nod = left.get_denominator() * right.get_denominator();
		result.set_namerator((left.get_namerator() * (nod/left.get_denominator())) + (right.get_namerator() * (nod/right.get_denominator())));				
		result.set_denominator(nod);
														//добавить функцию сокращения дроби
	}				
		
	return result;
}

//Перегрузка оператора -
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;

	if (left.get_denominator() == 0 || right.get_denominator() == 0)
	{
		cout << "На ноль делить нельзя" << endl;
		return result;
	}

	if (left.get_denominator() == right.get_denominator())
	{
		result.set_namerator(left.get_namerator() - right.get_namerator());
		result.set_denominator(left.get_denominator());
	}
	else
	{
		int nod;
		nod = left.get_denominator() * right.get_denominator();
		result.set_namerator((left.get_namerator() * (nod / left.get_denominator())) - (right.get_namerator() * (nod / right.get_denominator())));
		result.set_denominator(nod);
														//добавить функцию сокращения дроби
	}

	return result;
}

//Перегрузка оператора *
Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_namerator(left.get_namerator() * right.get_namerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
														//добавить функцию сокращения дроби
}

//Перегрузка оператора /
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_namerator(left.get_namerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_namerator());
	return result;
														//добавить функцию сокращения дроби
}



int main()
{
	setlocale(LC_ALL, "");
	
	int a;
	cout << "Введите значение числителя:\t" << endl;
	cin >> a;
	int b;
	cout << "Введите значение знаменателя:\t" << endl;
	cin >> b;
	cout << "Вывод первой дроби:\t" << endl;
	Fraction A(a,b);
	A.print();
	
	int c;
	cout << "Введите значение числителя второй дроби:\t" << endl;
	cin >> c;
	int d;
	cout << "Введите значение знаменателя второй дроби:\t" << endl;
	cin >> d;
	Fraction B(c, d);
	cout << "Вывод второй дроби:\t" << endl;
	B.print();

	Fraction C;
	cout << "Сложение дробей:\t" << endl;
	C = A + B;
	C.print();

	cout << "Вычитание дробей:\t" << endl;
	C = A - B;
	C.print();

	cout << "Умножение дробей:\t" << endl;
	C = A * B;
	C.print();

	cout << "Деление дробей:\t" << endl;
	C = A / B;
	C.print();

	cout << "Составные присваивания +=:\t" << endl;
	A += B;
	A.print();


	cout << "Составные присваивания -=:\t" << endl;
	(A -= B).print();
	





}
