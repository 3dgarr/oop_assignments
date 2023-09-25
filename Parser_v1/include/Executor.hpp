# ifndef	EXECUTOR_HPP
# define	EXECUTOR_HPP

// #include "Parser.hpp"
#include "Utils.hpp"
#include "CommandRegistry.hpp"
#include <queue>
#include <iostream>

struct CommandInfo;

class Executor
{
	public:
		void execute(CommandInfo& commandInfo,  CommandRegistry& registry);
		void printResult() const;
		void printHelpMessage() const;
	
	private:

	public:
		Executor();
		~Executor();
	private:
		std::queue<double>	results;
};




# endif//	EXECUTOR_HPP