# ifndef SLIDE_HPP
# define SLIDE_HPP

#include <iostream>
#include <memory>
#include <vector>


#include "Items.hpp"


class Slide
{
	public:
		using iterator			= typename std::vector<std::unique_ptr<Item>>::iterator;
		using const_iterator	= typename std::vector<std::unique_ptr<Item>>::const_iterator;
	
	public:
		iterator		begin();
		iterator		end();
		const_iterator	cbegin();
		const_iterator	cend();
		

	
	public:
		void	addItem(std::unique_ptr<Item>);
		void	removeItem(size_t);
		// Slide(const Slide&) = default;

		size_t	size() const;


		std::vector<std::unique_ptr<Item>>	items;
	private:
	
};


# endif// SLIDE_HPP