#include	"Validator.hpp"

const char* Validator::_OP = "-op" ;
const char* Validator::_CREATE = "CREATE" ;
const char* Validator::_RUN = "RUN" ;
const char* Validator::_HELP = "HELP" ;
const char* Validator::_EXIT = "EXIT" ;

void Validator::tokenize(const std::string& input, StrVector& tokens)
{
	std::stringstream	ss(input);
	if (ss.fail())
		throw	std::invalid_argument("SStream failed");
	
	std::string	tmp;
	while (std::getline(ss, tmp, ' '))
	{
		if (tmp.empty())
			continue;
		tokens.push_back(tmp);
	}	


}

void	Validator::checkIdxOfCmd(const std::string& commnad)
{
	(void)commnad;
}

void Validator::validateCommand(const std::string& target, const CommandRegistry& registry, std::string& command)
{
	if (!registry.existsCommand(target))
		throw	std::invalid_argument("Wrong Command !");
	command = target;
}

void	Validator::getOperandsFromTokens(StrVector& tokens, StrVector& operandVector)
{
	tokens.erase(tokens.begin());
	tokens.shrink_to_fit();
	auto	begin = tokens.cbegin();
	auto	end = tokens.cend();
	while (true)
	{
		auto it = std::find(begin, end,_OP);
		if (it == tokens.end())
		{
			break ;
		}
		if (std::next(it) == tokens.end())
		{
			throw	std::invalid_argument("Invalid place for option " + std::string(_OP));
		}
		operandVector.push_back(std::string(*std::next(it)));
		tokens.erase(std::next(it));
		tokens.erase(it);
		tokens.shrink_to_fit();
		begin = tokens.cbegin();
		end = tokens.cend();
	}
	if (!tokens.empty())
		throw	std::invalid_argument("Unknown token " + tokens.front());


}

void	Validator::validateOperands(const StrVector& operandVector, std::vector<double>& doubleOperandVector)
{
	double	temp = 0;
	if (operandVector.size() < 2)
		throw	std::invalid_argument("Not enough operands ");
	for (auto element : operandVector)
	{
		try
		{
			temp = std::stod(element);
		}
		catch(const std::exception& e)
		{
			throw	std::invalid_argument("Invalid argument : " + element);
		}
		doubleOperandVector.push_back(temp);		
	}
	
}

void Validator::validateTokens(CommandInfo&	CommandInfo, StrVector& tokens, const CommandRegistry& registry)
{
	StrVector	operandVector;
	if (tokens.size() < 3)
		throw	std::invalid_argument("Not enough arguments");
	validateCommand(tokens.front(), registry, CommandInfo.command);
	getOperandsFromTokens(tokens, operandVector);
	validateOperands(operandVector, CommandInfo.operands);
}

void	Validator::validateSingleCommand(const StrVector& tokens)
{
	if (!tokens.empty())
	{
		throw	std::invalid_argument("Single command error!");
	}
}

