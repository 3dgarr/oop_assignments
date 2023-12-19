#include "Actions.hpp"
#include <iostream>
#include "Utils.hpp"

AddItemAction::AddItemAction(Document &doc, std::unique_ptr<Item> it)
	: document(doc),
	  item(std::move(it))
{}

void AddItemAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	document.addToCurrentSlide(std::move(item));
	// document.addToCurrentSlide(std::move(item));
	std::cout  << GREEN << "Item added succesfully" << DEFAULT << std::endl;
}

RemoveItemAction::RemoveItemAction(Document &doc, size_t id)
	: document(doc),
	  item_id(id)
{}

void RemoveItemAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (item_id >= document.currentSlideSize())
	{
		throw std::invalid_argument("Out of range value: " + std::to_string(item_id));
	}
	document.removeItemFromCurrentSlide(item_id);
	std::cout  << GREEN << "Item removed succesfully" << DEFAULT << std::endl;
}


DisplayAction::DisplayAction(Document &doc, size_t id)
	: document(doc),
	  item_id(id)
{}

void DisplayAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ListAction::ListAction(Document &doc)
	:	document(doc)
{}

void ListAction::execute()
{
	document.listCurrentSlide();
}

ChangeAction::ChangeAction(Document &doc)
	:	document(doc)
{}

void ChangeAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

SaveAction::SaveAction(Document &doc)
	:	document(doc)
{}

void SaveAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}


LoadAction::LoadAction(Document &doc)
	:	document(doc)
{}

void LoadAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}


ExitAction::ExitAction(Document &doc)
	:	document(doc)
{}

void ExitAction::execute()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
