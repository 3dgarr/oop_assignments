#include "Director.hpp"
#include <Actions.hpp>
#include <Document.hpp>
#include <iostream>
#include <memory>


Director::Director()  
{
	redoStack = std::stack<std::shared_ptr<Document>>();
	undoStack = std::stack<std::shared_ptr<Document>>();

	currentDocument = std::make_shared<Document>(Document());
	undoStack.push(currentDocument);
}

void Director::runAction(std::unique_ptr<IAction> action)
{
 	UndoAction* undoActPtr = dynamic_cast<UndoAction*>(action.get());
    RedoAction* redoActPtr = dynamic_cast<RedoAction*>(action.get());

	if (undoActPtr)
		undo();
	else if (redoActPtr)
		redo();
	else
	{
		action->execute();
		///TODO:Need to recheck this part
    	AddItemAction* isAddActPtr = dynamic_cast<AddItemAction*>(action.get());
    	RemoveItemAction* isRemoveActPtr = dynamic_cast<RemoveItemAction*>(action.get());
		if (isAddActPtr || isRemoveActPtr)
		{
			///HERE_SHOULD_BE_CLONE_OF_DOCUMENT:
			undoStack.push(currentDocument);
			redoStack = std::stack<std::shared_ptr<Document>>();
			currentDocument = undoStack.top();
			// currentDocument = std::make_shared<Document>(currentDocument);
		}
		std::cout << "SIZEOF UNDO STACK " << undoStack.size() << std::endl;

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
		redoStack.push(undoStack.top());
		undoStack.pop();
		currentDocument = undoStack.top();
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
		undoStack.push(redoStack.top());
		redoStack.pop();
		currentDocument = undoStack.top();
		std::cout << "Redo successful." << std::endl;
	}
	else
	{
		std::cout << "Cannot redo. No changes available." << std::endl;
	}
}
