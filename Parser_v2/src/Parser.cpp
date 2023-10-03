#include "Parser.hpp"

void	Parser::run()
{
	while (true)
	{
		printMsg("Enter command:\n", YELLOW);
		try
		{
			getInput();
			Validator::tokenize(input, tokens);
			Validator::validateCommand(tokens.front(), registry, cmd);
			registry.printCommands();
			auto command = registry[cmd];
			command->process(tokens);			
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() <<  DEFAULT << std::endl;
		}
	}
}

void Parser::clearContainers()
{
	tokens.clear();
	tokens.shrink_to_fit();
	cmd.clear();
}

void	Parser::getInput()
{
	clearContainers();
	printMsg("-> ", YELLOW);
	std::getline(std::cin, input);
	if (input.empty())
		throw	std::invalid_argument("Empty expression");
}

void	Parser::printMsg(const std::string& msg, const std::string& color = DEFAULT) const
{
	std::cout << color <<  msg << DEFAULT << std::flush;
}