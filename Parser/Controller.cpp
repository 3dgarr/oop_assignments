#include "Controller.hpp"



void	Controller::run()
{
	while (true)
	{
		printMsg();
		try
		{
			getInput();
			validator.tokenize(input, strArguments);
			validator.checkIdxOfCmd(strArguments.front());

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	

}

void	Controller::getInput()
{
	std::getline(std::cin, input);
	if (input.empty())
		throw	std::invalid_argument("Empty expression");
		
}

void	Controller::printMsg() const
{
	std::cout << "Enter the expression: " << std::endl;
}