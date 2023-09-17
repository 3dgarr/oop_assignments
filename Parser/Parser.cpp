#include "Parser.hpp"



void	Parser::run()
{
	while (true)
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
					break;
				case CREATE:
					Validator::validateTokens(commandInfo, tokens,  registry);
				case COMMAND_MODE::RUN :
					///TODO: LOGIC FOR RUN
					break;
			}

			std::cout << "COMMAND:\t" << commandInfo.command << std::endl;
			std::cout << "MODE:\t\t" << commandInfo.mode << std::endl;
			std::cout << "OPERANDS:\t" ;
			for (auto operand : commandInfo.operands)
			{
				std::cout << operand << " ";
			}
			std::cout << "\n";
			executor.execute(commandInfo, registry);

		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() <<  DEFAULT << std::endl;
		}
	}
}

void Parser::determineModeOfCommand(StrVector& tokens)
{
	if (tokens.front() == _CREATE)
	{
		commandInfo.mode = COMMAND_MODE::CREATE;
		tokens.erase(tokens.begin());
		tokens.shrink_to_fit();
	}
	else if (tokens.front() == _RUN)
	{
		commandInfo.mode = COMMAND_MODE::RUN;
		tokens.erase(tokens.begin());
		tokens.shrink_to_fit();
	}
	else
		commandInfo.mode = COMMAND_MODE::NORMAL;
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