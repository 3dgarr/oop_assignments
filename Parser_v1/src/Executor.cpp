#include "Executor.hpp"

void Executor::execute(CommandInfo& commandInfo,   CommandRegistry& registry)
{
	double result(0);
	switch (commandInfo.mode)
	{
		case NORMAL:
			result = registry[commandInfo.command]->execute(commandInfo.operands);
			results.push(result);
			printResult();
			results.pop();
			break;
		case CREATE:
			result = registry[commandInfo.command]->execute(commandInfo.operands);
			results.push(result);
			break;
		case RUN:
			printResult();
			if (results.size())
				results.pop();
			break;
		case HELP:
			printHelpMessage();
			break;
		case EXIT :
			commandInfo.notDone = false;
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
void Executor::printHelpMessage() const
{

}


Executor::Executor()
{
}

Executor::~Executor()
{
}
