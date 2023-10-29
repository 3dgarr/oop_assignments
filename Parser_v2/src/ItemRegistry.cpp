#include <iostream>
#include <memory>
#include "ItemRegistry.hpp"


ItemRegistry::ItemRegistry()
{
	factoriesOfItems["Rectangle"]	=	std::move(std::make_unique<RectangleFactory>());
	factoriesOfItems["Elipse"]		=	std::move(std::make_unique<ElipseFactory>());
	factoriesOfItems["Line"]		=	std::move(std::make_unique<LineFactory>());
	factoriesOfItems["Trapezoid"]	=	std::move(std::make_unique<TrapezoidFactory>());
	factoriesOfItems["Triangle"]	=	std::move(std::make_unique<TriangleFactory>());
	factoriesOfItems["Circle"]		=	std::move(std::make_unique<CircleFactory>());
}

bool ItemRegistry::existsItem(const std::string &itemType)
{
	return (factoriesOfItems.find(itemType) != factoriesOfItems.end());
}

std::unique_ptr<Item> ItemRegistry::getNewItem(std::string itemType)
{
	return (factoriesOfItems[itemType]->getItem());
}
