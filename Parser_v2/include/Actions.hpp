# ifndef ACTIONST_HPP
# define ACTIONST_HPP

#include "Document.hpp"
#include "Items.hpp"

class Item;

class IAction
{
	public:
		virtual void execute() = 0;
};

class AddItemAction
	:	public IAction
{

	public:
		AddItemAction(Document& doc, std::unique_ptr<Item> it);
		void execute() override;
	
	private:
		Document& document;
		std::unique_ptr<Item> item;
};

class RemoveItemAction
	:	public IAction
{
		public:
			RemoveItemAction(Document& doc, size_t id);
			void execute() override;
		
		private:
			Document& document;
			size_t item_id;
};


class ListAction
	:	public IAction
{
		public:
			ListAction(Document& doc);
			void execute() override;

		private:
			Document& document;
};

class DisplayAction
	:	public IAction
{
		public:
			DisplayAction(Document& doc, size_t id);

			void execute() override;
		
		private:
			Document& document;
			size_t item_id;
};

class ChangeAction
	:	public IAction
{
		public:
			ChangeAction(Document& doc);

			void execute() override;
		
		private:
			Document& document;
};

class SaveAction
	:	public IAction
{
		public:
			SaveAction(Document& doc);

			void execute() override;

		private:
			Document& document;
};

class LoadAction
	:	public IAction
{
		public:
			LoadAction(Document& doc);

			void execute() override;

		private:
			Document& document;
};

class ExitAction
	:	public IAction
{
		public:
			ExitAction(Document& doc);

			void execute() override;

		private:
			Document& document;
};
# endif// ACTIONST_HPP

// "add"
// "remove"
// "display"
// "change"
// "list"
// "exit"
// "save"
// "load"