# ifndef COMMAND_HPP
# define COMMAND_HPP

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "ItemRegistry.hpp"
#include "Slide.hpp"
#include "Utils.hpp"
#include "Document.hpp"
#include "Actions.hpp"


class Command
{
	public:
		Command() = default;
		virtual ~Command() = default;
		
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document) = 0;


		virtual	void getOptions(std::vector<std::string>& tokens);
		virtual	void printOptValues() const;
		virtual	std::string stringToLower(std::string s);
		

	protected:
		std::vector<std::string>			options;
		std::map<std::string, std::string>	option_values;
		ItemRegistry						itemReg;
};

class Add
	:	public	Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);

		Add();

	private:
		void getNameOfItem(std::vector<std::string>& tokens);

		std::string				nameOfItem;
		std::unique_ptr<Item>	item;
};

class Remove
	:	public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);

		Remove();
	
	private:
		int	id;
};

class Display
	: public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);
		Display();
};

class Change
	: public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);

		Change();
};

class List
	:	public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);
		List();

};

class Exit
	:	public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);
		Exit(){};
};

class Save
	:	public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);
		
		Save();
		~Save() = default;
};

class Load
	:	public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);
		Load();
};

class Undo
	:	public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);
		Undo(){};
		~Undo() = default;
};

class Redo
	:	public Command
{
	public:
		virtual	std::unique_ptr<IAction> process(std::vector<std::string> tokens, std::shared_ptr<Document> document);
		Redo(){};
		~Redo() = default;
};
# endif //COMMAND_HPP