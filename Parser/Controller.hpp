# ifndef CONTROLLER_HPP
# define CONTROLLER_HPP

# include <iostream>
# include <exception>
# include <vector>

#include "Validator.hpp"

enum ECommand 
{ 
	ADD, 
	SUB, 
	MUL, 
	DIV, 
	HELP, 
}; //EnumCommand

class Controller
{
	public:
		void run();
	
	public:
		Controller();
		~Controller();
	
	private:
		void getInput();
		void printMsg() const;
	

	private:
		std::vector<std::string>	strArguments;
		std::vector<double>			dArguments;
		std::string input;
		std::string output;
		Validator	validator;
};


# endif// CONTROLLER_HPP