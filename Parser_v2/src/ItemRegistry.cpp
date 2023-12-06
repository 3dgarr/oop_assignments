#include <iostream>
#include <memory>
#include "ItemRegistry.hpp"


ItemRegistry::ItemRegistry()
{
	factoriesOfItems["rectangle"]	=	std::move(std::make_unique<RectangleFactory>());
	factoriesOfItems["elipse"]		=	std::move(std::make_unique<ElipseFactory>());
	factoriesOfItems["line"]		=	std::move(std::make_unique<LineFactory>());
	factoriesOfItems["trapezoid"]	=	std::move(std::make_unique<TrapezoidFactory>());
	factoriesOfItems["triangle"]	=	std::move(std::make_unique<TriangleFactory>());
	factoriesOfItems["circle"]		=	std::move(std::make_unique<CircleFactory>());
}

bool ItemRegistry::existsItem(const std::string &itemType)
{
	return (factoriesOfItems.find(itemType) != factoriesOfItems.end());
}

std::unique_ptr<Item> ItemRegistry::getNewItem(const std::string& itemType)
{
	return (factoriesOfItems[itemType]->getItem());
}
