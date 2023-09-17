#include "Executor.hpp"

void Executor::execute(CommandInfo commandInfo,   CommandRegistry& registry)
{
	double result = registry[commandInfo.command]->execute(commandInfo.operands);
	results.push(result);

	switch (commandInfo.mode)
	{
		case NORMAL:
			printResult();
			results.pop();
			break;
		case CREATE:
					;
			break;
		case RUN:
			printResult();
			results.pop();
			break;
	}
}

void Executor::printResult() const
{
	if (!results.empty())
	{
		std::cout << GREEN << "Result: " << results.front() << DEFAULT << std::endl;
	}
	else
		std::cout << RED << "Empty results queue: " << DEFAULT << std::endl;
		
}


Executor::Executor()
{
}

Executor::~Executor()
{
}
