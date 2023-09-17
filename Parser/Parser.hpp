# ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <exception>
# include <vector>

# include "CommandRegistry.hpp"
# include "Executor.hpp"
# include "Validator.hpp"
# include "Utils.hpp"

class Executor;

class Parser
{
	public:
		void run();
	
	public:
		Parser(){};
		~Parser(){};
	
	private:
		void getInput();
		void printMsg(const std::string& msg, const std::string& color) const;
		void clearContainers();
		void determineModeOfCommand(StrVector&);


	private:
		CommandInfo					commandInfo;
		std::string					input;
		std::vector<std::string>	tokens;
		Executor					executor;
		CommandRegistry				registry;
};


# endif// PARSER_HPP