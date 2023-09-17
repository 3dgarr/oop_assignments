#include "Parser.hpp"

void	Parser::run()
{
	while (commandInfo.notDone)
	{
		printMsg("Enter the expression:\n", YELLOW);
		try
		{
			clearContainers();
			getInput();
			Validator::tokenize(input, tokens);
			determineModeOfCommand(tokens);

			switch (commandInfo.mode)
			{
				case NORMAL:
					Validator::validateTokens(commandInfo, tokens,  registry);
					executor.execute(commandInfo, registry);
					break;
				case CREATE:
					Validator::validateTokens(commandInfo, tokens,  registry);
					executor.execute(commandInfo, registry);
					break;
				case RUN :
					Validator::validateSingleCommand(tokens);
					executor.execute(commandInfo, registry);
					break;
				case HELP :
					Validator::validateSingleCommand(tokens);
					executor.execute(commandInfo, registry);
					break;
				case EXIT :
					Validator::validateSingleCommand(tokens);
					executor.execute(commandInfo, registry);
				break;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() <<  DEFAULT << std::endl;
		}
	}
}

void Parser::determineModeOfCommand(StrVector& tokens)
{
	if (tokens.front() == Validator::_CREATE)
	{
		commandInfo.mode = COMMAND_MODE::CREATE;
	}
	else if (tokens.front() == Validator::_RUN)
	{
		commandInfo.mode = COMMAND_MODE::RUN;
	}
	else if (tokens.front() == Validator::_HELP)
	{
		commandInfo.mode = COMMAND_MODE::HELP;
	}
	else if (tokens.front() == Validator::_EXIT)
	{
		commandInfo.mode = COMMAND_MODE::EXIT;
	}
	else
	{
		commandInfo.mode = COMMAND_MODE::NORMAL;
		return ;
	}
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
}

void Parser::clearContainers()
{
	tokens.clear();
	commandInfo.operands.clear();

	tokens.shrink_to_fit();
	commandInfo.operands.shrink_to_fit();

	commandInfo.command.erase();
	commandInfo.mode = NORMAL;
}

void	Parser::getInput()
{
	printMsg("-> ", YELLOW);
	std::getline(std::cin, input);
	if (input.empty())
		throw	std::invalid_argument("Empty expression");
}

void	Parser::printMsg(const std::string& msg, const std::string& color = DEFAULT) const
{
	std::cout << color <<  msg << DEFAULT << std::flush;
}