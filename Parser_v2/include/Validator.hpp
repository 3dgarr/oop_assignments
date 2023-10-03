# ifndef VALIDATIOR_HPP
# define VALIDATIOR_HPP

# include <algorithm>
# include <exception>
# include <string>
# include <sstream>
# include <vector>
# include <iostream>

# include "CommandRegistry.hpp"
# include "Parser.hpp"


using Tokens = std::vector<std::string>;
struct CommandInfo;

class Validator
{
	public:
		static void	tokenize(const std::string& input, Tokens& tokens);
		static void validateTokens(Tokens& tokens, const CommandRegistry& registry);
		static void	validateCommand(const std::string& target, const CommandRegistry& registry, std::string& command);
		static void getOperandsFromTokens(Tokens& arguments, Tokens& operandVector);
		static void validateOperands(const Tokens& operandVector, std::vector<double>& doubleOperandVector);
};

# endif// VALIDATIOR_HPP