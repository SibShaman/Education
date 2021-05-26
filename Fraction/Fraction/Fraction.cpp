#include <iostream>
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
	int namerator_one;
	int denominator_one;
	int namerator_two;
	int denominator_two;


public:
	
	//GET methods
	int get_namerator_one()const
	{
		return namerator_one;
	}	
	int get_namerator_two()const
	{
		return namerator_two;
	}	
	int get_denominator_one()const
	{
		return denominator_one;
	}	
	int get_denominator_two()const
	{
		return denominator_two;
	}
	
	//SET methods
	void set_namerator_one(int namerator_one)
	{
		this->namerator_one = namerator_one;
	}
	void set_namerator_two(int namerator_two)
	{
		this->namerator_two = namerator_two;
	}
	void set_denominator_one(int denominator_one)
	{
		this->denominator_one = denominator_one;
	}
	void set_denominator_two(int denominator_two)
	{
		this->denominator_two = denominator_two;
	}
	


	Fraction operator+()
	{

	}

	Fraction operator-()
	{

	}

	Fraction operator*()
	{

	}
	Fraction operator/()
	{

	}	
	Fraction operator+=()
	{

	}	
	Fraction operator-=()
	{

	}	
	Fraction operator*=()
	{

	}	
	Fraction operator/=()
	{

	}





	//Default constraction
	Fraction()
	{
		namerator_one = 0;
		denominator_one = 0;
		namerator_two = 0;
		denominator_two = 0;
		//cout << "Default Constraction" << endl;
	}


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
