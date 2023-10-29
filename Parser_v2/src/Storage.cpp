#include "Storage.hpp"

void Storage::addItem(std::unique_ptr<Item> newItem)
{
	items.push_back(std::move(newItem));

}

size_t Storage::size() const
{
	return items.size();
}
