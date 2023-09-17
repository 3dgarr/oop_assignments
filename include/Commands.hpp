# ifndef COMMAND_HPP
# define COMMAND_HPP

#include <vector>
#include <string>

using Operands = std::vector<double>;

class Command
{
	public:
		Command(){};
		
		virtual	double execute(Operands operands)  = 0;
		virtual ~Command(){};
};

class Add
	:	public	Command
{
	public:
		double execute(Operands operands);
		Add(){};
		~Add(){};
};

class Sub
	:	public Command
{
	public:
		double execute(Operands operands);
		Sub(){};
		~Sub(){};
};

class Mul
	: public Command
{
	public:
		double execute(Operands operands);
		Mul(){};
		~Mul(){};
};

class Div
	: public Command
{
	public:
		double execute(Operands operands);
		Div(){};
		~Div(){};
};

class Help
	:	public Command
{
	public:
		double execute(Operands operands);
		Help(){};
		~Help(){};
};

# endif //COMMAND_HPP