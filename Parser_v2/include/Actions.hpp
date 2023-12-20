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
		AddItemAction(std::shared_ptr<Document> doc, std::unique_ptr<Item> it);
		void execute() override;
	
	private:
		std::shared_ptr<Document> document;
		std::unique_ptr<Item> item;
};

class RemoveItemAction
	:	public IAction
{
		public:
			RemoveItemAction(std::shared_ptr<Document> doc, size_t id);
			void execute() override;
		
		private:
			std::shared_ptr<Document> document;
			size_t item_id;
};


class ListAction
	:	public IAction
{
		public:
			ListAction(std::shared_ptr<Document> doc);
			void execute() override;

		private:
			std::shared_ptr<Document> document;
};

class DisplayAction
	:	public IAction
{
		public:
			DisplayAction(std::shared_ptr<Document> doc, size_t id);

			void execute() override;
		
		private:
			std::shared_ptr<Document> document;
			size_t item_id;
};

class ChangeAction
	:	public IAction
{
		public:
			ChangeAction(std::shared_ptr<Document> doc);

			void execute() override;
		
		private:
			std::shared_ptr<Document> document;
};

class SaveAction
	:	public IAction
{
		public:
			SaveAction(std::shared_ptr<Document> doc);

			void execute() override;

		private:
			std::shared_ptr<Document> document;
};

class LoadAction
	:	public IAction
{
		public:
			LoadAction(std::shared_ptr<Document> doc);

			void execute() override;

		private:
			std::shared_ptr<Document> document;
};

class ExitAction
	:	public IAction
{
		public:
			ExitAction(std::shared_ptr<Document> doc);

			void execute() override;

		private:
			std::shared_ptr<Document> document;
};

class RedoAction
	:	public IAction
{
		public:
			RedoAction(std::shared_ptr<Document> doc);

			void execute() override;

		private:
			std::shared_ptr<Document> document;
};


class UndoAction
	:	public IAction
{
		public:
			UndoAction(std::shared_ptr<Document> doc);

			void execute() override;

		private:
			std::shared_ptr<Document> document;
};

class AddSlideAction
	:	public IAction
{
		public:
			AddSlideAction(std::shared_ptr<Document> doc);

			void execute() override;

		private:
			std::shared_ptr<Document> document;
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