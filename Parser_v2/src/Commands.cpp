#include "Commands.hpp"
#include <iterator>
#include <algorithm>


void Add::process(std::vector<std::string> tokens)
{
	option_values.clear();
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	getNameOfItem(tokens);
	getOptions(tokens);

	for (auto element : option_values)
	{
		std::cout << "|" << element.first << " --- " << element.second << "|\n";
	}
	// std::cout << std::endl;
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
	option_values[*it] = *std::next(it);
	tokens.erase(it, std::next(it, 2));
	tokens.shrink_to_fit();
	// it = tokens.begin()
}
void Add::getOptions(std::vector<std::string>& tokens)
{
	auto optionIt = std::next(options.begin()); 
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
		tokens.erase(it, std::next(it, 2));
		tokens.shrink_to_fit();
		++optionIt;
	}
	if (!tokens.empty())
	{
		throw std::invalid_argument("Invalid token: " + *tokens.begin() + ":" );
	}
}

Add::Add()
{
	options.push_back("-x1");
	options.push_back("-x2");
	options.push_back("-y1");
	options.push_back("-y2");
};

Remove::Remove()
{
	options.push_back("-id");
}

Save::Save()
{
	options.push_back("-file");
}

Load::Load()
{
	options.push_back("-file");
}

ChangeId::ChangeId()
{
	options.push_back("-name");
	options.push_back("-x1");
	options.push_back("-x2");
	options.push_back("-y1");
	options.push_back("-y2");
	options.push_back("-id");
}


void Remove::process(std::vector<std::string> tokens)
{

};

void Display::process(std::vector<std::string> tokens)
{

};

void ChangeId::process(std::vector<std::string> tokens)
{

};

void List::process(std::vector<std::string> tokens)
{
};

void Exit::process(std::vector<std::string> tokens)
{
};

void Save::process(std::vector<std::string> tokens)
{
};

void Load::process(std::vector<std::string> tokens)
{
};
