# ifndef DIRECTOR_HPP
# define DIRECTOR_HPP

// #include "Document.hpp"
#include <stack>
#include <memory>

class Document;



class IAction;

class Director
{
	public:
		Director();

		void						runAction(std::unique_ptr<IAction> action);
		std::shared_ptr<Document>	getCurrentDocument();

		void undo();
		void redo();

	private:
		std::shared_ptr<Document>				currentDocument;

		std::stack<std::shared_ptr<Document>>	undoStack;
		std::stack<std::shared_ptr<Document>>	redoStack;
};

# endif// DIRECTOR_HPP