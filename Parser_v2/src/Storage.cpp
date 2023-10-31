#include "Storage.hpp"

void Storage::addItem(std::unique_ptr<Item> newItem)
{
	items.push_back(std::move(newItem));

}

size_t Storage::size() const
{
	return items.size();
}

auto	Storage::begin() -> iterator
{
	return	items.begin();
}

auto	Storage::end() -> iterator
{
	return	items.end();
}

auto	Storage::cbegin() -> const_iterator
{
	return	items.cbegin();
}

auto	Storage::cend()-> const_iterator
{
	return	items.cend();
}
