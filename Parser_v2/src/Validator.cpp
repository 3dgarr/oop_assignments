#include	"Validator.hpp"

void Validator::tokenize(const std::string& input, Tokens& tokens)
{
	if (isAllWhiteSpaces(input))
		throw	std::invalid_argument("All space");


	std::stringstream	ss(input);
	if (ss.fail())
		throw	std::runtime_error("SStream failed");
	
	std::string	tmp;
	while (std::getline(ss, tmp, ' '))
	{
		if (tmp.empty() || isAllWhiteSpaces(tmp))
			continue;
		tokens.push_back(tmp);
	}	
}

void Validator::validateCommand(const std::string& target, const CommandRegistry& registry, std::string& command)
{
	std::string tempCmd = target;
	std::transform(tempCmd.begin(), tempCmd.end(), tempCmd.begin(), 
				[](unsigned char c)
				{ 
					return std::tolower(c); 
				});
	if (!registry.existsCommand(tempCmd))
		throw	std::invalid_argument("Wrong Command !");
	command = tempCmd;
}

bool Validator::isAllWhiteSpaces(const std::string& input)
{
	for (auto	element : input)
	{
		if (!std::isspace(element))
			return false;
	}
	return true;
}

// void	Validator::getOperandsFromTokens(Tokens& tokens, Tokens& operandVector)
// {

	// (void) tokens;
	// (void) operandVector;
	// tokens.erase(tokens.begin());
	// tokens.shrink_to_fit();
	// auto	begin = tokens.cbegin();
	// auto	end = tokens.cend();
	// while (true)
	// {
	// 	auto it = std::find(begin, end,_OP);
	// 	if (it == tokens.end())
	// 	{
	// 		break ;
	// 	}
	// 	if (std::next(it) == tokens.end())
	// 	{
	// 		throw	std::invalid_argument("Invalid place for option " + std::string(_OP));
	// 	}
	// 	operandVector.push_back(std::string(*std::next(it)));
	// 	tokens.erase(std::next(it));
	// 	tokens.erase(it);
	// 	tokens.shrink_to_fit();
	// 	begin = tokens.cbegin();
	// 	end = tokens.cend();
	// }
	// if (!tokens.empty())
	// 	throw	std::invalid_argument("Unknown token " + tokens.front());
// }

// void	Validator::validateOperands(const Tokens& operandVector, std::vector<double>& doubleOperandVector)
// {
// 	double	temp = 0;
// 	if (operandVector.size() < 2)
// 		throw	std::invalid_argument("Not enough operands ");
// 	for (auto element : operandVector)
// 	{
// 		try
// 		{
// 			temp = std::stod(element);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			throw	std::invalid_argument("Invalid argument : " + element);
// 		}
// 		doubleOperandVector.push_back(temp);		
// 	}
// }

