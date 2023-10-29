#include "Commands.hpp"
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <iostream>


void Command::getOptions(std::vector<std::string>& tokens)
{
	auto optionIt = options.begin(); 
	while (optionIt != options.end())
	{
		auto it = std::find(tokens.begin(), tokens.end(), *optionIt); 
		if (it == tokens.end())
		{
			++optionIt;
			continue;
		}
		if (std::next(it) == tokens.end())
		{
			throw std::invalid_argument("Option " + *optionIt + " has no value" );
		}
		option_values[*it] = *std::next(it);
		tokens.erase(std::next(it));
		tokens.erase(it);
		tokens.shrink_to_fit();
		++optionIt;
	}
	if (!tokens.empty())
	{
		throw std::invalid_argument("Invalid token: " + *tokens.begin() + ":" );
	}
}

void Command::printOptValues() const
{
	std::cout <<"OPTION --- VALUE" << std::endl;
	for (auto element : option_values)
	{
		std::cout << "|" << element.first << " --- " << element.second << "|\n";
	}
	std::cout << std::endl;
}


Add::Add()
{
	options = {"-x1", "-x2", "-y1", "-y2"};
};

void Add::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	if (tokens.empty())
	{
		throw std::invalid_argument("Not enough arguments for command");
	}
	getNameOfItem(tokens);
	if (!itemReg.existsItem(nameOfItem))
	{
		throw std::invalid_argument("Unknown item to add");
	}
	getOptions(tokens);

	
	std::unique_ptr<Item> item = itemReg.getNewItem(nameOfItem);

	std::cout << "ITEM IS -> " << item->getType() << std::endl;
	itemStorage.addItem(std::move(item));

	// std::cout << "SIZE IS -> " << itemStorage.size() << std::endl;





	printOptValues();
}

void Add::getNameOfItem(std::vector<std::string>& tokens)
{
	auto	it = tokens.begin();
	if (*it != "-name")
	{
		throw	std::invalid_argument("Undefined option: " + *it);
	}
	if (std::next(it) == tokens.end())
	{
		throw	std::invalid_argument("Option -name has no value");
	}
	nameOfItem =  *std::next(it);
	option_values[*it] = *std::next(it);
	tokens.erase(it, std::next(it, 2));
	tokens.shrink_to_fit();
}

Remove::Remove()
{
	options = {"-id"};
}

void Remove::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	if (tokens.empty())
	{
		throw std::invalid_argument("Not enough arguments for command");
	}

	getOptions(tokens);

	printOptValues();
};

Save::Save()
{
	options = {"-file"};
}

Load::Load()
{
	options = {"-file"};
}

Display::Display()
{
	options = {"-id"};
}


ChangeId::ChangeId()
{
	options = {"-name", "-x1", "-x2", "-y1", "-y2", "-id"};
}


void Display::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	if (tokens.empty())
	{
		throw std::invalid_argument("Not enough arguments for command");
	}
	getOptions(tokens);
	printOptValues();
};

void ChangeId::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	if (tokens.empty())
	{
		throw std::invalid_argument("Not enough arguments for command");
	}
	getOptions(tokens);
	printOptValues();


};

void List::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	// if (tokens.empty())
	// {
	// 	throw std::invalid_argument("Not enough arguments for command");
	// }
	getOptions(tokens);
	printOptValues();

};

void Exit::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
// 	getOptions(tokens);
// 	if (tokens.empty())
// 	{
// 		throw std::invalid_argument("Not enough arguments for command");
// 	}
};

void Save::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	if (tokens.empty())
	{
		throw std::invalid_argument("Not enough arguments for command");
	}
	getOptions(tokens);
	printOptValues();

};

void Load::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	if (tokens.empty())
	{
		throw std::invalid_argument("Not enough arguments for command");
	}
	getOptions(tokens);
	printOptValues();

};
