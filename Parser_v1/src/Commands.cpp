#include "Commands.hpp"
#include <functional>
#include <numeric>

double	Add::execute(Operands operands)
{
	double result = operands.front();
	operands.erase(operands.begin());
	operands.shrink_to_fit();
	for(auto operand : operands)
	{
		result += operand;
	}
	return result;
}

double	Sub::execute(Operands operands)
{
	double result = operands.front();
	operands.erase(operands.begin());
	operands.shrink_to_fit();
	for(auto operand : operands)
	{
		result -= operand;
	}
	return result;
}

double	Mul::execute(Operands operands)
{
	double result = operands.front();
	operands.erase(operands.begin());
	operands.shrink_to_fit();
	for(auto operand : operands)
	{
		result *= operand;
	}
	return result;
}

double	Div::execute(Operands operands)
{
	double result = operands.front();
	operands.erase(operands.begin());
	operands.shrink_to_fit();
	
	for(auto operand : operands)
	{
		result /= operand;
	}
	return result;
}

double	Help::execute(Operands operands)
{
	(void) operands;
	double res = 0;
	return res;
}
