# ifndef VALIDATIOR_HPP
# define VALIDATIOR_HPP

# include <algorithm>
# include <exception>
# include <string>
# include <sstream>
# include <vector>
# include <iostream>

# include "CommandRegistry.hpp"
# include "Application.hpp"


using Tokens = std::vector<std::string>;

class Validator
{
	public:
		static void	tokenize(const std::string& input, Tokens& tokens);
		static void	validateCommand(const std::string& target, const CommandRegistry& registry, std::string& command);
		static bool isAllWhiteSpaces(const std::string& input);
};

# endif// VALIDATIOR_HPP