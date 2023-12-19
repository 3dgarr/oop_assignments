#include "Director.hpp"
#include <Actions.hpp>
#include <Document.hpp>
#include <iostream>
#include <typeinfo>


Director::Director()  
{
	currentDocument = std::make_shared<Document>(Document());
}

void Director::runAction(std::unique_ptr<IAction> action)
{
	///PTINAYVIESPAHY:
	if (typeid(action) == typeid(std::unique_ptr<UndoAction>()))
		undo();
	else if (typeid(action) == typeid(std::unique_ptr<RedoAction>()))
		redo();
	else
	{
		action->execute();
		///TODO:Need to recheck this part

		// undoStack.push(currentDocument);
		// redoStack = std::stack<std::shared_ptr<Document>>();
		// currentDocument = std::make_shared<Document>(*currentDocument); 
	}
}



std::shared_ptr<Document> Director::getCurrentDocument()
{
	return currentDocument;
}

void Director::undo()
{
	if (!undoStack.empty())
	{
		redoStack.push(currentDocument);
		currentDocument = undoStack.top();
		undoStack.pop();
		std::cout << "Undo successful." << std::endl;
	}
	else
	{
		std::cout << "Cannot undo. No changes available." << std::endl;
	}
}

void Director::redo()
{
	if (!redoStack.empty())
	{
		undoStack.push(currentDocument);
		currentDocument = redoStack.top();
		redoStack.pop();
		std::cout << "Redo successful." << std::endl;
	}
	else
	{
		std::cout << "Cannot redo. No changes available." << std::endl;
	}
}
