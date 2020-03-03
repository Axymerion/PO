#pragma once

class Calculator 
{
private:
	double result;

public:
	Calculator();

	enum Error { SUCCESS, DIVIDE_BY_ZERO, NO_ROOTS, SINGLE_ROOT, INVALID_PARAMETER };

	void Add(const double x, const double y);

	void Subtract(const double x, const double y);
	
	void Multiply(const double x, const double y);
	
	Error Divide(const double x, const double y);

	double GetResult();

	Error Roots(const double a, const double b, const double c, double& x1, double& x2);
};