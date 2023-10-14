#include "CommandRegistry.hpp"
#include <iostream>
CommandRegistry::CommandRegistry()
{
	registry["Add"]			= std::make_unique<Add>();
	registry["Remove"]		= std::make_unique<Remove>();
	registry["Display"]		= std::make_unique<Display>();
	registry["ChangeId"]	= std::make_unique<ChangeId>();
	registry["List"]		= std::make_unique<List>();
	registry["Exit"]		= std::make_unique<Exit>();
	registry["Save"]		= std::make_unique<Save>();
	registry["Load"]		= std::make_unique<Load>();

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
