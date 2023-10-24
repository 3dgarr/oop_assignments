# ifndef COMMAND_HPP
# define COMMAND_HPP

#include <vector>
#include <string>
#include <iostream>
#include <map>


class Command
{
	public:
		Command() = default;
		
		virtual	void execute()  = 0;
		virtual	void process(std::vector<std::string> tokens)  = 0;
		virtual ~Command() = default;

	protected:
		std::vector<std::string>			options;
		std::map<std::string, std::string>	option_values;
};

class Add
	:	public	Command
{
	public:
		void execute(){};
		void process(std::vector<std::string> tokens);
		Add();
		~Add() = default;
	private:
		void getNameOfItem(std::vector<std::string>& tokens);
		void getOptions(std::vector<std::string>& tokens);

};

class Remove
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(){};
		Remove();
		~Remove() = default;
};

class Display
	: public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(){};
		Display(){};
		~Display() = default;
};

class ChangeId
	: public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(){};
		ChangeId();
		~ChangeId() = default;
};

class List
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(){};
		List(){};
		~List() = default;
};

class Exit
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(){};
		Exit(){};
		~Exit() = default;
};

class Save
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(){};
		Save();
		~Save() = default;
};

class Load
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(){};
		Load();
		~Load() = default;
};
# endif //COMMAND_HPP