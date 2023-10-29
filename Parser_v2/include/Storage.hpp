# ifndef STORAGE_HPP
# define STORAGE_HPP


#include <memory>
#include <vector>

#include "Items.hpp"

class Storage
{
	public:
		void	addItem(std::unique_ptr<Item>);
		size_t	size() const;

		Storage()	= default;
		~Storage()	= default;


	private:
		std::vector<std::unique_ptr<Item>>	items;
	
};


# endif// STORAGE_HPP