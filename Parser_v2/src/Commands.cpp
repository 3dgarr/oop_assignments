#include "Commands.hpp"
#include <functional>
#include <numeric>


void Add::process(std::vector<std::string> tokens)
{
	for(auto token : tokens)
	{
		std::cout << "|" << token << "| ";
	}
	std::cout << std::endl;
	// std::cout << __PRETTY_FUNCTION__ << std::endl;
};
	
void Remove::process(std::vector<std::string> tokens)
{
	for(auto token : tokens)
	{
		std::cout << "|" << token << "| ";
	}
	std::cout << std::endl;
	// std::cout << __PRETTY_FUNCTION__ << std::endl;
};

void Display::process(std::vector<std::string> tokens)
{
	for(auto token : tokens)
	{
		std::cout << "|" << token << "| ";
	}
	std::cout << std::endl;
	// std::cout << __PRETTY_FUNCTION__ << std::endl;
};

void ChangeId::process(std::vector<std::string> tokens)
{
	for(auto token : tokens)
	{
		std::cout << "|" << token << "| ";
	}
	std::cout << std::endl;
	// std::cout << __PRETTY_FUNCTION__ << std::endl;
};

void List::process(std::vector<std::string> tokens)
{
	for(auto token : tokens)
	{
		std::cout << "|" << token << "| ";
	}
	std::cout << std::endl;
	// std::cout << __PRETTY_FUNCTION__ << std::endl;
};

void Exit::process(std::vector<std::string> tokens)
{
	for(auto token : tokens)
	{
		std::cout << "|" << token << "| ";
	}
	std::cout << std::endl;
	// std::cout << __PRETTY_FUNCTION__ << std::endl;
};

void Save::process(std::vector<std::string> tokens)
{
	for(auto token : tokens)
	{
		std::cout << "|" << token << "| ";
	}
	std::cout << std::endl;
	// std::cout << __PRETTY_FUNCTION__ << std::endl;
};

void Load::process(std::vector<std::string> tokens)
{
	for(auto token : tokens)
	{
		std::cout << "|" << token << "| ";
	}
	std::cout << std::endl;
// 
	std::cout << __PRETTY_FUNCTION__ << std::endl;
};
