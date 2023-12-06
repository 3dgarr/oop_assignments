#include "CommandRegistry.hpp"
#include <iostream>

CommandRegistry::CommandRegistry()
{
	registry["add"]		= std::make_unique<Add>();
	registry["remove"]	= std::make_unique<Remove>();
	registry["display"]	= std::make_unique<Display>();
	registry["change"]	= std::make_unique<Change>();
	registry["list"]	= std::make_unique<List>();
	registry["exit"]	= std::make_unique<Exit>();
	registry["save"]	= std::make_unique<Save>();
	registry["load"]	= std::make_unique<Load>();

}

CommandRegistry::~CommandRegistry()
{}

bool	CommandRegistry::existsCommand(const std::string& command) const
{
	auto	it = registry.find(command);

	return it != registry.cend();
}

std::unique_ptr<Command>& CommandRegistry::operator[](const std::string& target) 
{
	return	registry[target];
}

void CommandRegistry::printCommands()
{

	for(auto	it = registry.begin(); it != registry.end(); ++it)
	{
		std::cout << "|"<< it->first  << "| " << std::flush;
	}
	std::cout << "\n";
}
