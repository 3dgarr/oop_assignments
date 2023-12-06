#include "Slide.hpp"

void Slide::addItem(std::unique_ptr<Item> newItem)
{
	items.push_back(std::move(newItem));

}

void Slide::removeItem(size_t index)
{
	items.erase(std::next(items.begin(), index));
	items.shrink_to_fit();
}

size_t Slide::size() const
{
	return items.size();
}

auto	Slide::begin() -> iterator
{
	return	items.begin();
}

auto	Slide::end() -> iterator
{
	return	items.end();
}

auto	Slide::cbegin() -> const_iterator
{
	return	items.cbegin();
}

auto	Slide::cend()-> const_iterator
{
	return	items.cend();
}
