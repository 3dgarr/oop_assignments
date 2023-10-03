#include "CommandRegistry.hpp"
#include <iostream>
CommandRegistry::CommandRegistry()
{
	registry["Add"]			= std::make_shared<Add>();
	registry["Remove"]		= std::make_shared<Remove>();
	registry["Display"]		= std::make_shared<Display>();
	registry["ChangeId"]	= std::make_shared<ChangeId>();
	registry["List"]		= std::make_shared<List>();
	registry["Exit"]		= std::make_shared<Exit>();
	registry["Save"]		= std::make_shared<Save>();
	registry["Load"]		= std::make_shared<Load>();

}

CommandRegistry::~CommandRegistry()
{}

bool	CommandRegistry::existsCommand(const std::string& command) const
{
	auto	it = registry.find(command);

	return it != registry.cend();
}

 std::shared_ptr<Command>& CommandRegistry::operator[](const std::string& target) 
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
