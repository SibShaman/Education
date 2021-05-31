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
	
	//Default constraction
	Fraction()
	{
		namerator_one = 0;
		denominator_one = 0;
		namerator_two = 0;
		denominator_two = 0;
		//cout << "Default Constraction" << endl;
	}

	/*
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
*/





/*
	-to_improper();		//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
	-reduce();			//Сокращает дробь: 5/10 => 1/2;
*/




	void input_values()
	{
		cout << "Введите значение числителя первой дроби \n";
		cin >> namerator_one;
		cout << "Введите значение знаменателя первой дроби\n";
		cin >> denominator_one;

		cout << "Введите значение числителя второй дроби\n";
		cin >> namerator_two;
		cout << "Введите значение знаменателя второй дроби\n";
		cin >> denominator_two;
	}




	//~Fraction();

private:

};


/*
Fraction::Fraction()
{
}

Fraction::~Fraction()
{
}
*/

void to_proper(const Fraction& obj)		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
{
	if (obj.get_namerator_one() > obj.get_denominator_one())
	{
		int res1, res2;
		res1 = obj.get_namerator_one()/ obj.get_denominator_one();
		res2 = obj.get_namerator_one() % obj.get_denominator_one();
		
		if (res2 == 0)
			cout << res1 << endl;
		else
			cout << res1 << "(" << res2 << "/" << obj.get_denominator_one() <<")"<< endl;
	}else 
		cout << obj.get_namerator_one() << "/" << obj.get_denominator_one() << endl;
	
	if (obj.get_namerator_two() > obj.get_denominator_two())
	{
		int res1, res2;
		res1 = obj.get_namerator_two()/ obj.get_denominator_two();
		res2 = obj.get_namerator_two() % obj.get_denominator_two();
		
		if (res2 == 0)
			cout << res1 << endl;
		else
			cout << res1 << "(" << res2 << "/" << obj.get_denominator_two() << ")" << endl;
	}else 
		cout << obj.get_namerator_two() << "/" << obj.get_denominator_two() << endl;
}

void to_improper()		//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
{


}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	//для сложения дробей надо найти общий знаменатель
	//после этого просто сложить числители(полученные) и сократить дробь


	Fraction result;
	
	/*
	result.set_namerator_one(left.get_namerator_one() + right.get_namerator_one());	
	result.set_namerator_two(left.get_namerator_two() + right.get_namerator_two());	
	result.set_denominator_one(left.get_denominator_one() + right.get_denominator_one());	
	result.set_denominator_two(left.get_denominator_two() + right.get_denominator_two());
	*/
	
	return result;
}




int main()
{
	setlocale(LC_ALL, "");
	Fraction A;
		A.input_values();

	cout << "Выберите действие которое хотите проверить\n";

	int choice;
	do 
	{
		cout << "1. Арифметические операторы\n";
		cout << "2. Составные присваивания\n";
		cout << "3. Инкремент/Декремент\n";
		cout << "4. Операторы сравнения\n";
		cout << "5. Операторы для работы с потоками\n";
		cout << "0. Выход\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int arithmetic_operators;
			do 
			{
				cout << "1. Сложение дробей\n";
				cout << "2. Вычитание дробей\n";
				cout << "3. Умножение дробей\n";
				cout << "4. Деление дробей\n";
				cout << "0. Назад\n";
				cin >> arithmetic_operators;

				switch (arithmetic_operators)
				{
				case 1:
				{
					to_proper(A);



				}
				break;
				case 2:
				{

				}
				break;
				case 3:
				{

				}
				break;
				case 4:
				{

				}
				break;

				default:
					break;
				}
			
			} while (arithmetic_operators);
		}
		break;

		case 2:
		{
			int compound_assignments;
			do 
			{
				cout << "1. Оператор +=\n";
				cout << "2. Оператор -=\n";
				cout << "3. Оператор *=\n";
				cout << "4. Оператор /=\n";
				cout << "0. Назад\n";
				cin >> compound_assignments;

				switch (compound_assignments)
				{
				case 1:
				{

				}
				break;
				case 2:
				{

				}
				break;
				case 3:
				{

				}
				break;
				case 4:
				{

				}
				break;
				default:
					break;
				}


			} while (compound_assignments);
		}
		break;

		case 3:
		{
			int unary_operators;
			do
			{
				cout << "1. Префиксный инкремент (++x)\n";
				cout << "2. Префиксный декремент (--x)\n";
				cout << "3. Постфиксный инкремент (x++)\n";
				cout << "4. Постфиксный декремент (x--)\n";
				cout << "0. Назад\n";
				cin >> unary_operators;
				switch (unary_operators)
				{
				case 1:
				{

				}
				break;
				case 2:
				{

				}
				break;
				case 3:
				{

				}
				break;
				case 4:
				{

				}
				break;
				default:
					break;
				}
			} while (unary_operators);
		}
		break;

		case 4:
		{
			int comparison_operators;
			do
			{
				cout << "1. Оператор ==\n";
				cout << "2. Оператор !=\n";
				cout << "3. Оператор >\n";
				cout << "4. Оператор <\n";
				cout << "5. Оператор >=\n";
				cout << "6. Оператор <=\n";
				cout << "0. Назад\n";

				cin>> comparison_operators;
				switch (comparison_operators)
				{
				case 1:
				{

				}
				break;
				case 2:
				{

				}
				break;
				case 3:
				{

				}
				break;
				case 4:
				{

				}
				break;
				case 5:
				{

				}
				break;
				case 6:
				{

				}
				break;
				default:
					break;
				}
			} while (comparison_operators);
		}
		break;

		case 5:
		{
			int stream_operators;
			do
			{
				cout << "1. Оператор <<\n";
				cout << "1. Оператор >>\n";
				cin >> stream_operators;

				switch (stream_operators)
				{
				case 1:
				{

				}
				break;
				case 2:
				{

				}
				break;
				default:
					break;
				}



			} while (stream_operators);
		}
		break;

		default:
			break;
		}


	} while (choice);
}
