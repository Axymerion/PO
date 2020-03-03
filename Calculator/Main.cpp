#include "Calculator.h"
#include <iostream>

using namespace std;

int main()
{
	Calculator calc;

	calc.Add(5, 6);
	cout << calc.GetResult() << endl;

	calc.Subtract(10, 12);
	cout << calc.GetResult() << endl;

	calc.Multiply(21, 37);
	cout << calc.GetResult() << endl;

	if (calc.Divide(12, 3) == Calculator::Error::SUCCESS)
	{
		cout << calc.GetResult() << endl;
	}

	if(calc.Divide(12, 0) == Calculator::Error::SUCCESS)
	{
		cout << calc.GetResult() << endl;
	}

	double x1, x2;

	if (calc.Roots(1, 4, 3, x1, x2) == Calculator::Error::SUCCESS)
	{
		cout << x1 << '\t' << x2 << endl;
	}
}