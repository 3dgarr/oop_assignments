# ifndef COMMAND_HPP
# define COMMAND_HPP

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "ItemRegistry.hpp"
#include "Storage.hpp"


class Command
{
	public:
		Command() = default;
		virtual ~Command() = default;
		
		virtual	void execute(Storage& storage)  = 0;
		virtual	void process(std::vector<std::string> tokens) = 0;


		virtual	void getOptions(std::vector<std::string>& tokens);
		virtual	void printOptValues() const;
		virtual	std::string stringToLower(std::string s);
		// {
		// 	std::transform(s.begin(), s.end(), s.begin(), 
		// 				// static_cast<int(*)(int)>(std::tolower)         // wrong
		// 				// [](int c){ return std::tolower(c); }           // wrong
		// 				// [](char c){ return std::tolower(c); }          // wrong
		// 				[](unsigned char c){ return std::tolower(c); } // correct
		// 				);
		// 	return s;
		// }
		

	protected:
		std::vector<std::string>			options;
		std::map<std::string, std::string>	option_values;
		ItemRegistry						itemReg;
};

class Add
	:	public	Command
{
	public:
		void execute(Storage& storage);
		void process(std::vector<std::string> tokens);

		Add();
		~Add() = default;

	private:
		void getNameOfItem(std::vector<std::string>& tokens);

		std::string				nameOfItem;
		std::unique_ptr<Item>	item;
};

class Remove
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(Storage& storage);
		Remove();
		~Remove() = default;
};

class Display
	: public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(Storage& storage);
		Display();
		~Display() = default;
};

class Change
	: public Command
{
	public:
		void process(std::vector<std::string> tokens);

		void execute(Storage& storage);
		Change();
		~Change() = default;
};

class List
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(Storage& storage);
		List(){};
		~List() = default;
};

class Exit
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(Storage& storage);
		Exit(){};
		~Exit() = default;
};

class Save
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(Storage& storage);
		Save();
		~Save() = default;
};

class Load
	:	public Command
{
	public:
		void process(std::vector<std::string> tokens);
		void execute(Storage& storage);
		Load();
		~Load() = default;
};
# endif //COMMAND_HPP