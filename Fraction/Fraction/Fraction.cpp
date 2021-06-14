#include <iostream>
using namespace std;

/*
Реализовать класс Fraction, описывающий простую дробь.
В классе должны быть все обязательные методы, а так же методы :
-to_proper();		//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
-to_improper();		//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
-reduce();			//Сокращает дробь: 5/10 => 1/2;

+++++++++ 1. Арифметические операторы : +, -, *, / ;
+++++++++ 2. Составные присваивания : +=, -=, *=, /=;
+++++++++ 3. Increment / Decrement(++ / --);
+++++++++ 4. Операторы сравнения : == , != , > , < , >= , <= ;
+++++++++ 5. Операторы для работы с потоками : << , >>
*/

class Fraction
{
	int namerator;									// объявление переменной для числителя
	int denominator;								//объявление переменной для знаменателя
	int integer;

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
	int get_integer()const						//GET метод для целого
	{
		return integer;
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
	void set_integer(int integer)		//SET метод для знаменателя
	{
		this->integer = integer;
	}

	//Default constraction
	Fraction()
	{
		namerator = 0;
		denominator = 0;
	}
	
	Fraction(int namerator, int denominator)
	{
		this->namerator = namerator;
		this->denominator = denominator;
	}

	Fraction(const Fraction& other) //конструктор копирования 
	{
		this->namerator = other.namerator;
		this->denominator = other.denominator;
	}
	
	~Fraction()
	{
		//cout << "Destructor:\t" << this << endl;
	}
	
	void print()
	{
		if (namerator > denominator)
		{
			to_proper();
		}
		else
		{
			cout << namerator << "/" << denominator << endl;
		}
		
		
	}
	//Оператор присваивания (=)
	Fraction& operator=(const Fraction& other)	//Оператор присвоить
	{
		this->namerator = other.namerator;
		this->denominator = other.denominator;
		return *this;
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
	//Составные присваивания (оператор -=)
	Fraction& operator-=(const Fraction& other)
	{
		if (this->denominator == other.denominator)
		{
			this->set_namerator(this->namerator - other.namerator);
			this->set_denominator(this->denominator);
		}
		else
		{
			this->set_namerator(this->namerator * other.denominator - other.namerator * this->denominator);
			this->set_denominator(this->denominator * other.denominator);
		}		
		return *this;
	}
	//Составные присваивания (оператор *=)
	Fraction& operator*=(const Fraction& other)
	{
		this->set_namerator(this->namerator * other.namerator);
		this->set_denominator(this->denominator * other.denominator);
		return *this;
	}
	//Составные присваивания (оператор /=)
	Fraction& operator/=(const Fraction& other)
	{
		this->set_namerator(this->namerator * other.denominator);
		this->set_denominator(this->denominator * other.namerator);
		return *this;
	}
	//Prefix increment
	Fraction& operator++()					
	{
		this->namerator++;
		this->denominator;
		return *this;
	}
	//Postfix increment
	Fraction& operator++(int)  
	{
		Fraction old = *this;
		++* this;			
		return old;
	}
	//Prefix decrement
	Fraction& operator--()
	{
		this->namerator--;
		this->denominator;
		return *this;
	}
	//Postfix decrement
	Fraction& operator--(int)
	{
		Fraction old = *this;
		--* this;
		return old;
	}
	
	//Неправильную дробь переводит в правильную: 11/4 => 2(3/4)
	void to_proper()
	{
			integer = namerator / denominator;
			this->namerator = namerator % denominator;
			cout << integer << "(" << namerator << "/" << denominator << ")" << endl;	
	}


	/*
	
	-to_improper();		//Переводит правильную дробь в неправильную: 2(3/4) => 11/4
	-reduce();			//Сокращает дробь: 5/10 => 1/2;
	*/

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

}
//Перегрузка оператора /
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_namerator(left.get_namerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_namerator());
	return result;
}

//оператор ==
bool operator==(const Fraction& left, const Fraction& right)
{	
	int nod = left.get_denominator() * right.get_denominator();
	return((left.get_namerator() * (nod / left.get_denominator())) == (right.get_namerator() * (nod / right.get_denominator())));
}
//оператор !=
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
//оператор >
bool operator>(const Fraction& left, const Fraction& right)
{
	int nod = left.get_denominator() * right.get_denominator();
	return ((left.get_namerator() * (nod / left.get_denominator())) > (right.get_namerator() * (nod / right.get_denominator())));
}
//оператор <
bool operator<(const Fraction& left, const Fraction& right)
{
	return (right > left);
}

//перегрузка оператора <<
ostream& operator<<(ostream& os, const Fraction& obj)      //используем ostream& чтобы не перегружать endl   
{
	os << " X= " << obj.get_namerator() << "\t" << "Y = " << obj.get_denominator();
	return os;
}
//перегрузка оператора >>
istream& operator>>(istream& is, Fraction& obj)      //используем istream& чтобы не перегружать endl   
{
	double x, y;
	is >> x >> y;
	obj.set_namerator(x);
	obj.set_denominator(y);
	return is;
}




int main()
{
	setlocale(LC_ALL, "");
	
	int a;
	cout << "Введите значение числителя:\t" << endl; 	cin >> a;
	int b;
	cout << "Введите значение знаменателя:\t" << endl; 	cin >> b;
	cout << "Вывод первой дроби:\t" << endl;
	Fraction A(a,b);
	A.print();
	
	int c;
	cout << "Введите значение числителя второй дроби:\t" << endl; 	cin >> c;
	int d;
	cout << "Введите значение знаменателя второй дроби:\t" << endl; cin >> d;
	Fraction B(c, d);
	cout << "Вывод второй дроби:\t" << endl;
	B.print();

	Fraction C;
	cout << "Сложение дробей:\t" << endl; 	C = A + B;
	C.print();

	cout << "Вычитание дробей:\t" << endl; 	C = A - B;
	C.print();

	cout << "Умножение дробей:\t" << endl; 	C = A * B;
	C.print();

	cout << "Деление дробей:\t" << endl; 	C = A / B;
	C.print();

	cout << "Составные присваивания +=:\t" << endl; (A += B).print();

	Fraction D(a, b);
	cout << "Составные присваивания -=:\t" << endl; (D -= B).print();
	
	Fraction E(a, b);
	cout << "Составные присваивания *=:\t" << endl; (E *= B).print();
	
	Fraction F(a, b);
	cout << "Составные присваивания /=:\t" << endl; (F /= B).print();
	
	Fraction G(a, b);
	cout << "Оператор префиксного инкремента: \t" << endl;	(++G).print();
	//cout << "Оператор постфиксного инкремента: \t" << endl;	(G++).print();

	cout << "Проверка операторов сравнения (==):\t" << endl; 
	if (A == B) { cout << "дроби равны" << endl; }
	else { cout << "дроби разные" << endl; }
	cout << (A == B) << endl;;
	
	cout << "Проверка операторов сравнения (!=):\t" << endl; 
	if (A != B) { cout << "дроби разные" << endl; }
	else { cout << "дроби равны" << endl; }
	cout << (A != B) << endl;;
	
	cout << "Проверка операторов сравнения (>):\t" << endl; 
	if (A > B) { cout << "дробь А больше B" << endl; }
	else { cout << "дробь B больше A" << endl; }
	cout << (A > B) << endl;;
	
	cout << "Проверка операторов сравнения (<):\t" << endl; 
	if (A == B) { cout << "дробь А меньше B" << endl; }
	else { cout << "дробь B меньше A" << endl; }
	cout << (A < B) << endl;;
	



	
}
