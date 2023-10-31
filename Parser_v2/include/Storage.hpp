# ifndef STORAGE_HPP
# define STORAGE_HPP

#include <iostream>
#include <memory>
#include <vector>

#include "Items.hpp"



class Storage
{
	public:
		using iterator			= typename std::vector<std::unique_ptr<Item>>::iterator;
		using const_iterator	= typename std::vector<std::unique_ptr<Item>>::const_iterator;
	
	public:
		iterator		begin();
		iterator		end();
		const_iterator	cbegin();
		const_iterator	cend();
		// std::unique_ptr<Item>	operator[](int);
		

	
	public:
		void	addItem(std::unique_ptr<Item>);
		void	removeItem(size_t);

		size_t	size() const;

		Storage()	= default;
		~Storage()	= default;


	private:
		std::vector<std::unique_ptr<Item>>	items;
	
};


# endif// STORAGE_HPP