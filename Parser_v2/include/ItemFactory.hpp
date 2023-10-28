# ifndef	ITEM_FACTORY_HPP
# define	ITEM_FACTORY_HPP

# include "Items.hpp"
# include <memory>
# include <map>

class ItemFactory
{
	public:
		virtual std::unique_ptr<Item>	getItem() const = 0;
		virtual ~ItemFactory() = default;
};

class RectangleFactory
	:public ItemFactory
{
	public:
		std::unique_ptr<Item>	getItem() const;
};

class ElipseFactory
	:public ItemFactory
{
	public:
		std::unique_ptr<Item>	getItem() const;
};

class LineFactory
	:public ItemFactory
{
	public:
		std::unique_ptr<Item>	getItem() const;
};

class TrapezoidFactory
	:public ItemFactory
{
	public:
		std::unique_ptr<Item>	getItem() const;
};

class TriangleFactory
	:public ItemFactory
{
	public:
		std::unique_ptr<Item>	getItem() const;
};

class CircleFactory
	:public ItemFactory
{
	public:
		std::unique_ptr<Item>	getItem() const;
};



# endif//	ITEM_FACTORY_HPP