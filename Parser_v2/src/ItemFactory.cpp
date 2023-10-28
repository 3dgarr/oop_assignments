# include "ItemFactory.hpp"
# include <memory>

std::unique_ptr<Item> RectangleFactory::getItem() const
{
	return std::make_unique<Rectangle>();
}

std::unique_ptr<Item> ElipseFactory::getItem() const
{
	return std::make_unique<Elipse>();
}

std::unique_ptr<Item> LineFactory::getItem() const
{
	return std::make_unique<Line>();
}

std::unique_ptr<Item> TrapezoidFactory::getItem() const
{
	return std::make_unique<Trapezoid>();
}

std::unique_ptr<Item> TriangleFactory::getItem() const
{
	return std::make_unique<Triangle>();
}

std::unique_ptr<Item> CircleFactory::getItem() const
{
	return std::make_unique<Circle>();
}