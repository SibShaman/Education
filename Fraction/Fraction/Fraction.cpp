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
	int namerator_one;									// объявление переменной для числителя
	int denominator_one;								//объявление переменной для знаменателя



public:
	
	//GET methods
	int get_namerator_one()const						//GET метод для числителя
	{
		return namerator_one;
	}	
	
	int get_denominator_one()const						//GET метод для знаменателя
	{
		return denominator_one;
	}	

	
	//SET methods
	void set_namerator_one(int namerator_one)			//SET метод для числителя
	{
		this->namerator_one = namerator_one;
	}

	void set_denominator_one(int denominator_one)		//SET метод для знаменателя
	{
		this->denominator_one = denominator_one;
	}

	//Default constraction
	Fraction()
	{
		namerator_one = 0;
		denominator_one = 0;

		cout << "Default Constraction" << endl;
	}
	
	Fraction(int namerator_one, int denominator_one)
	{
		this->namerator_one = namerator_one;
		this->denominator_one = denominator_one;

		//cout << namerator_one << "/" << denominator_one << endl;
		cout << "Constructor:\t" << this << endl;
	}



	/*
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
*/
	void print()
	{
		cout << namerator_one << "/" << denominator_one << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}


private:

};

//Перегрузка оператора +
Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	
	if (left.get_denominator_one() == 0 || right.get_denominator_one() == 0)
	{
		cout << "На ноль делить нельзя" << endl;
		return result;
	}


	if (left.get_denominator_one() == right.get_denominator_one())
	{
		result.set_namerator_one(left.get_namerator_one() + right.get_namerator_one());
		result.set_denominator_one(left.get_denominator_one());
	}
	else
	{
		int nok;
		nok = left.get_denominator_one() * right.get_denominator_one();
		result.set_namerator_one((left.get_namerator_one() * (nok/left.get_denominator_one())) + (right.get_namerator_one() * (nok/right.get_denominator_one())));				
		result.set_denominator_one(nok);
														//добавить функцию сокращения дроби
	}				
		
	return result;
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;

	if (left.get_denominator_one() == 0 || right.get_denominator_one() == 0)
	{
		cout << "На ноль делить нельзя" << endl;
		return result;
	}


	if (left.get_denominator_one() == right.get_denominator_one())
	{
		result.set_namerator_one(left.get_namerator_one() - right.get_namerator_one());
		result.set_denominator_one(left.get_denominator_one());
	}
	else
	{
		int nok;
		nok = left.get_denominator_one() * right.get_denominator_one();
		result.set_namerator_one((left.get_namerator_one() * (nok / left.get_denominator_one())) - (right.get_namerator_one() * (nok / right.get_denominator_one())));
		result.set_denominator_one(nok);
		//добавить функцию сокращения дроби
	}

	return result;
}





int main()
{
	setlocale(LC_ALL, "");
	


	cout << "Вывод простой дроби:\t" << endl;
	Fraction A(1,3);
	A.print();
	
	cout << "Сложение дробей:\t" << endl;
	Fraction B(1, 6);
	Fraction C = A + B;
		C.print();

	cout << "Вычитание дробей:\t" << endl;
	C = A - B;
	C.print();

	
}
