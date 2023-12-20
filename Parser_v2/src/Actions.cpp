#include "Actions.hpp"
#include <iostream>
#include "Utils.hpp"

AddItemAction::AddItemAction(std::shared_ptr<Document> doc, std::unique_ptr<Item> it)
	: document(doc),
	  item(std::move(it))
{}

void AddItemAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	document->addToCurrentSlide(std::move(item));
	// document.addToCurrentSlide(std::move(item));
	std::cout  << GREEN << "Item added succesfully" << DEFAULT << std::endl;
}

RemoveItemAction::RemoveItemAction(std::shared_ptr<Document> doc, size_t id)
	: document(doc),
	  item_id(id)
{}

void RemoveItemAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (item_id >= document->currentSlideSize())
	{
		throw std::invalid_argument("Out of range value: " + std::to_string(item_id));
	}
	document->removeItemFromCurrentSlide(item_id);
	std::cout  << GREEN << "Item removed succesfully" << DEFAULT << std::endl;
}


DisplayAction::DisplayAction(std::shared_ptr<Document> doc, size_t id)
	: document(doc),
	  item_id(id)
{}

void DisplayAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ListAction::ListAction(std::shared_ptr<Document> doc)
	:	document(doc)
{}

void ListAction::execute()
{
	document->listCurrentSlide();
}

ChangeAction::ChangeAction(std::shared_ptr<Document> doc)
	:	document(doc)
{}

void ChangeAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SaveAction::SaveAction(std::shared_ptr<Document> doc)
	:	document(doc)
{}

void SaveAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}


LoadAction::LoadAction(std::shared_ptr<Document> doc)
	:	document(doc)
{}

void LoadAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}


ExitAction::ExitAction(std::shared_ptr<Document> doc)
	:	document(doc)
{}

void ExitAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

UndoAction::UndoAction(std::shared_ptr<Document> doc)
	:	document(doc)
{}

void UndoAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}


RedoAction::RedoAction(std::shared_ptr<Document> doc)
	:	document(doc)
{}

void RedoAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

AddSlideAction::AddSlideAction(std::shared_ptr<Document> doc)
	:	document(doc)
{}

void AddSlideAction::execute()
{
	document->addNewSlide();

	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "COUNT OF SLIDES " << document->slidesCount() << std::endl;
}



