#include "CommandRegistry.hpp"

CommandRegistry::CommandRegistry()
{
	cRegistry["ADD"] = new Add();
	cRegistry["SUB"] = new Sub();
	cRegistry["MUL"] = new Mul();
	cRegistry["DIV"] = new Div();
	cRegistry["HELP"] = new Help();
}

CommandRegistry::~CommandRegistry()
{
	for (auto command : cRegistry)
	{
		delete command.second;
	}
}

bool	CommandRegistry::existsCommand(const std::string& command) const
{
	auto	it = cRegistry.find(command);

	return it != cRegistry.cend();
}

 Command* CommandRegistry::operator[](const std::string& target) 
{
	return	cRegistry[target];
}