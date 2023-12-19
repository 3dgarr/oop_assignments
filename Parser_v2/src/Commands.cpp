#include "Commands.hpp"
#include <iterator>
#include <algorithm>
#include <typeinfo>
#include <iostream>

// --COMMAND
// -----------------------------------------------------------------

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

std::string Command::stringToLower(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), 
				[](unsigned char c)
				{
					return std::tolower(c); 
				});
	return s;
}

// --ADD
// -----------------------------------------------------------------

Add::Add()
{
	options = {"-x1", "-x2", "-y1", "-y2"};
};


std::unique_ptr<IAction> Add::process(std::vector<std::string> tokens, Document& document)
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
	auto addAction = std::make_unique<AddItemAction>(AddItemAction(document, std::move(item)));
	
	
	return addAction;
}

// void Add::execute(Document &document)
// {
// 	// std::cout <<__PRETTY_FUNCTION__ << std::endl;
// 	// std::cout << "ITEM IS -> " << item->getType() << std::endl;
// 	// std::cout << "SIZE IS -> " << document.size() << std::endl;
// 	// document.addItem(std::move(item));
// 	document.addToCurrentSlide(std::move(item));
// 	std::cout  << GREEN << "Item added succesfully" << DEFAULT << std::endl;
// }


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
	id = -1;
}


// void Remove::execute(Document &document)
// {
// 	size_t	index = id;
// 	if (index >= document.currentSlideSize())
// 	{
// 		throw std::invalid_argument("Out of range value: " + option_values["-id"]);
// 	}
// 	// document.removeItem(index);
// 	document.removeItemFromCurrentSlide(index);
// 	std::cout  << GREEN << "Item removed succesfully" << DEFAULT << std::endl;
// 	// std::cout <<__PRETTY_FUNCTION__ << std::endl;
// }

std::unique_ptr<IAction> Remove::process(std::vector<std::string> tokens, Document& document)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	
	if (tokens.empty())
	{
		throw std::invalid_argument("Not enough arguments for command");
	}
	getOptions(tokens);

	try
	{
		///TODO: need to empower this part, 12t is valid, t12 is not
		id = std::stoi(option_values["-id"]);
		if (id < 0)
			throw (std::exception{});
	}
	catch(const std::exception& e)
	{
		throw std::invalid_argument("Invalid value: " + option_values["-id"]);
	}
	 
	auto action = std::make_unique<RemoveItemAction>(RemoveItemAction(document, id));
	return action;

	// printOptValues();
};
// -----------------------------------------------------------------


// --DISPLAY
// -----------------------------------------------------------------

// void Display::execute(Document &document)
// {
// 	(void)document;
// 	std::cout <<__PRETTY_FUNCTION__ << std::endl;
// }

Display::Display()
{
	options = {"-id"};
}

std::unique_ptr<IAction> Display::process(std::vector<std::string> tokens, Document& document)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	
	if (tokens.empty())
	{
		throw std::invalid_argument("Not enough arguments for command");
	}
	getOptions(tokens);

	int id;

	try
	{
		///TODO: need to empower this part, 12t is valid, t12 is not
		id = std::stoi(option_values["-id"]);
		if (id < 0)
			throw (std::exception{});
	}
	catch(const std::exception& e)
	{
		throw std::invalid_argument("Invalid value: " + option_values["-id"]);
	}
	 
	auto action = std::make_unique<DisplayAction>(DisplayAction(document, id));
	return action;

};

// -----------------------------------------------------------------
// --CHANGE
// -----------------------------------------------------------------

std::unique_ptr<IAction> Change::process(std::vector<std::string> tokens, Document& document)
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

	auto action = std::make_unique<ChangeAction>(ChangeAction(document));
	return action;
};

// void Change::execute(Document &document)
// {
// 	(void)document;
// 	std::cout <<__PRETTY_FUNCTION__ << std::endl;
// }

Change::Change()
{
	options = {"-name", "-x1", "-x2", "-y1", "-y2", "-id"};
}

// -----------------------------------------------------------------


//---LIST
// -----------------------------------------------------------------
List::List()
{

};

std::unique_ptr<IAction> List::process(std::vector<std::string> tokens, Document& document)
{
	// option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	if (!tokens.empty())
	{
		throw std::invalid_argument("List has no any options!");
	}
	// getOptions(tokens);
	// printOptValues();

	auto action = std::make_unique<ListAction>(ListAction(document));
	return action;
}

// -----------------------------------------------------------------


//---EXIT--
// -----------------------------------------------------------------

std::unique_ptr<IAction> Exit::process(std::vector<std::string> tokens, Document& document)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
// 	getOptions(tokens);
// 	if (tokens.empty())
// 	{
// 		throw std::invalid_argument("Not enough arguments for command");
// 	}
	auto action = std::make_unique<ExitAction>(ExitAction(document));
	return action;

}
// void Exit::execute(Document &document)
// {
// 	(void)document;
// 	std::cout <<__PRETTY_FUNCTION__ << std::endl;

// };

// -----------------------------------------------------------------

//---SAVE--
// -----------------------------------------------------------------


Save::Save()
{
	options = {"-file"};
}

std::unique_ptr<IAction> Save::process(std::vector<std::string> tokens, Document& document)
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

	auto action = std::make_unique<SaveAction>(SaveAction(document));
	return action;

}
// void Save::execute(Document &document)
// {
// 	(void)document;
// 	std::cout <<__PRETTY_FUNCTION__ << std::endl;

// };
// -----------------------------------------------------------------

//---LOAD--

Load::Load()
{
	options = {"-file"};
}

std::unique_ptr<IAction> Load::process(std::vector<std::string> tokens, Document& document)
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

	auto action = std::make_unique<LoadAction>(LoadAction(document));
	return action;

}
// void Load::execute(Document &document)
// {
// 	(void)document;
// 	std::cout <<__PRETTY_FUNCTION__ << std::endl;

// };

// -----------------------------------------------------------------
