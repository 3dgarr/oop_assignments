# ifndef VALIDATIOR_HPP
# define VALIDATIOR_HPP

# include <algorithm>
# include <exception>
# include <string>
# include <sstream>
# include <vector>

# include "CommandRegistry.hpp"
# include "Parser.hpp"


using StrVector = std::vector<std::string>;
struct CommandInfo;

class Validator
{
	public:
		static const char*	_OP ;
		static const char*	_CREATE ;
		static const char*	_RUN ;
		static const char*	_HELP ;
		static const char*	_EXIT ;
	public:
		static void validateTokens(CommandInfo&	CommandInfo, StrVector& tokens, const CommandRegistry& registry);
		static void	tokenize(const std::string& input, StrVector& tokens);
		static void	checkIdxOfCmd(const std::string& commnad);
		static void	validateCommand(const std::string& target, const CommandRegistry& registry, std::string& command);
		static void getOperandsFromTokens(StrVector& arguments, StrVector& operandVector);
		static void validateOperands(const StrVector& operandVector, std::vector<double>& doubleOperandVector);
		static void	validateSingleCommand(const StrVector& tokens);
	private:
};

# endif// VALIDATIOR_HPP