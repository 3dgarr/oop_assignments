# ifndef	ITEM_REGISTRY_HPP
# define	ITEM_REGISTRY_HPP

#include "ItemFactory.hpp"
#include <unordered_map>
#include <memory>


class ItemRegistry
{
	public:
		ItemRegistry();
		bool existsItem(const std::string& itemType);
		std::unique_ptr<Item>	getNewItem(std::string itemType);

		~ItemRegistry() = default;

	private:
		std::unordered_map<std::string, std::unique_ptr<ItemFactory> >	factoriesOfItems;
};


# endif//	ITEM_REGISTRY_HPP