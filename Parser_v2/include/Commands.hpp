# ifndef COMMAND_HPP
# define COMMAND_HPP

#include <vector>
#include <string>
#include <iostream>


class Command
{
	public:
		Command(){};
		
		virtual	void execute()  = 0;
		virtual	void process(std::vector<std::string> tokens)  = 0;
		virtual ~Command(){};
};

class Add
	:	public	Command
{
	public:
		void execute(){};
		void process(std::vector<std::string> tokens);
		Add(){};
		~Add(){};
};

class Remove
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(){};
		Remove(){};
		~Remove(){};
};

class Display
	: public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(){};
		Display(){};
		~Display(){};
};

class ChangeId
	: public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(){};
		ChangeId(){};
		~ChangeId(){};
};

class List
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(){};
		List(){};
		~List(){};
};

class Exit
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(){};
		Exit(){};
		~Exit(){};
};

class Save
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(){};
		Save(){};
		~Save(){};
};

class Load
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(){};
		Load(){};
		~Load(){};
};
# endif //COMMAND_HPP