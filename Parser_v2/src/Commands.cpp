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

	item = itemReg.getNewItem(nameOfItem);

	printOptValues();
}

void Add::execute(Storage &storage)
{
	std::cout <<__PRETTY_FUNCTION__ << std::endl;
	std::cout << "ITEM IS -> " << item->getType() << std::endl;
	storage.addItem(std::move(item));
	std::cout << "SIZE IS -> " << storage.size() << std::endl;

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


// --REMOVE
// -----------------------------------------------------------------
Remove::Remove()
{
	options = {"-id"};
}


void Remove::execute(Storage &storage)
{
	(void)storage;
	std::cout <<__PRETTY_FUNCTION__ << std::endl;
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
// -----------------------------------------------------------------


// --DISPLAY
// -----------------------------------------------------------------

void Display::execute(Storage &storage)
{
	(void)storage;
	std::cout <<__PRETTY_FUNCTION__ << std::endl;
}

Display::Display()
{
	options = {"-id"};
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

// -----------------------------------------------------------------
// --CHANGE
// -----------------------------------------------------------------

void Change::process(std::vector<std::string> tokens)
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

void Change::execute(Storage &storage)
{
	(void)storage;
	std::cout <<__PRETTY_FUNCTION__ << std::endl;
}

Change::Change()
{
	options = {"-name", "-x1", "-x2", "-y1", "-y2", "-id"};
}

// -----------------------------------------------------------------


//---LIST
// -----------------------------------------------------------------

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

}
void List::execute(Storage &storage)
{
	(void)storage;
	std::cout <<__PRETTY_FUNCTION__ << std::endl;

};
// -----------------------------------------------------------------


//---EXIT--
// -----------------------------------------------------------------

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
}
void Exit::execute(Storage &storage)
{
	(void)storage;
	std::cout <<__PRETTY_FUNCTION__ << std::endl;

};

// -----------------------------------------------------------------

//---SAVE--
// -----------------------------------------------------------------


Save::Save()
{
	options = {"-file"};
}

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

}
void Save::execute(Storage &storage)
{
	(void)storage;
	std::cout <<__PRETTY_FUNCTION__ << std::endl;

};
// -----------------------------------------------------------------

//---LOAD--

Load::Load()
{
	options = {"-file"};
}

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

}
void Load::execute(Storage &storage)
{
	(void)storage;
	std::cout <<__PRETTY_FUNCTION__ << std::endl;

};

// -----------------------------------------------------------------
