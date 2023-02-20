#include <iostream>

int Num_global, const _N_const = 115, Array_Global[5]; // Объявление глобальных перемеенных инициализирует их 0
std::string _Gl_String;
double const _PI = 3.1416;
int Get_Int();
int Get_Dbl();

int Random_Number_Int(int Range_min, int Range_max) 
{
	//srand(time(NULL));
	return Range_min + rand() % (Range_max - Range_min + 1); 
}

void print_X()
{
	std::cout << "Global Num -> " << _N_const;
}

void Static_Variables()
{
	static int static_var=1;
	std::cout << "\nstatic_var -> " << static_var;
	static_var++;
	std::cout << "\nstatic_var++ -> " << static_var;
	if (static_var > 5) static_var = 1;
}

inline int Absolute(int num) //встраиваемая функция: не занимает места в памяти
{
	return ((num < 0) ? (-num) : num); // принято заключать return в скобки в встраиваемых функциях, чтобы точно быть уверенным насчет возращаемого значения/выражения
}

inline int Summ_A_B(int A, int B) //встраиваемая функция: не занимает места в памяти
{
	int Summ = 0;
	for (int i = A; i <= B; i++)
		Summ += i;
	return Summ;
}

int Power(int Num_1, int Num_2=2) //параметры по умолчанию
{
	int Res = 1;
	for (int i = 1; i <= Num_2; i++)
		Res *= Num_1;
		
	return Res;
}

//перегрузка функций - функция с одним именем но разными типом/кол-вом параметров
int Max_Search(int num1, int num2)
{
	std::cout << "\nINT_version";
	return ((num1 > num2) ? num1 : num2);
}
double Max_Search(double num1, double num2)
{
	std::cout << "\nDBL_version";
	return ((num1 > num2) ? num1 : num2);

}
int Max_Search(int num1, int num2, int num3)
{
	std::cout << "\nINT_version_3 arguments";
	
	return num1 > (num2 > num3 ? num2 : num3) ? num1 : (num2 > num3 ? num2 : num3);
}

template <typename T> T ABS_Number(T num) //шаблон функции ABS_Number - сможет использовать указанное тело функции с разными типами данных
{
	return num < 0 ? -num : num;
}

int main()
{
	std::cout << "\nABS_Number -5 ->" << ABS_Number(-5);
	std::cout << "\nABS_Number -5.7 ->" << ABS_Number(-5.7);

	//перегрузка функций
	std::cout << "\nMAX from 5 10 ->" << Max_Search(5,10);
	std::cout << "\nMAX from 5.7 10.6 ->" << Max_Search(5.7, 10.6);
	std::cout << "\nMAX from 5 10 25 ->" << Max_Search(5, 10, 25);

	
	
	//int My_Number = Get_Int();
	//int My_Number = -5;
	
	
	//Absolute(My_Number);
	
	//std::cout << "\nABS " << Absolute(My_Number);
	//std::cout << "\nSum [0..10] -> " << Summ_A_B(0, 10);

	//std::cout << "\n" <<Power(5, 3); 
	//std::cout << "\n" << Power(5);

	std::cout << "\n\n";
	system("pause");
	return 0;
}

int Get_Int()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "[Input error! Integer expected]\n";
		
	}
	return a;
}
int Get_Dbl()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "[Input error! Integer expected]\n";
		return a;
	}
	return a;
}