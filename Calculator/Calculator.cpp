#include "Calculator.h"
#include <cmath>

Calculator::Calculator() 
{
	this->result = 0;
}

void Calculator::Add(const double x, const double y) 
{
	this->result = x + y;
}

void Calculator::Subtract(const double x, const double y)
{
	this->result = x - y;
}

void Calculator::Multiply(const double x, const double y)
{
	this->result = x * y;
}

Calculator::Error Calculator::Divide(const double x, const double y)
{
	if (y == 0)
	{
		return DIVIDE_BY_ZERO;
		this->result = 0;
	}

	this->result = x / y;
	return SUCCESS;
}

double Calculator::GetResult()
{
	return this->result;
}

Calculator::Error Calculator::Roots(const double a, const double b, const double c, double& x1, double& x2)
{
	if (a == 0)
	{
		return INVALID_PARAMETER;
	}

	double delta = (b * b) - (4 * a * c);

	if (delta < 0)
	{
		return NO_ROOTS;
	}

	x1 = (-1 * b - sqrt(delta)) / (2 * a);
	x2 = (-1 * b + sqrt(delta)) / (2 * a);

	if (delta > 0)
	{
		return SUCCESS;
	}
	else
	{
		return SINGLE_ROOT;
	}
}