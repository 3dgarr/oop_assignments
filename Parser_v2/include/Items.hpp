# ifndef ITEMS_HPP
# define ITEMS_HPP

#include <iostream>
#include <memory>
class Item
{
	public:
		virtual std::string	getType() const = 0;
		virtual std::unique_ptr<Item> clone() const = 0;
		virtual ~Item() = default;
};


class Rectangle
	:	public Item
{
	public:
		std::string	getType() const override;
		virtual ~Rectangle() = default;
		std::unique_ptr<Item> clone() const override 
		{
        	return std::make_unique<Rectangle>(*this);
    	}
};

class Elipse
	:	public Item
{
	public:
		std::string	getType() const override;
		virtual ~Elipse() = default;
		std::unique_ptr<Item> clone() const override 
		{
        	return std::make_unique<Elipse>(*this);
    	}
};


class Line
	:	public Item
{
	public:
		std::string	getType() const override;
		virtual ~Line() = default;
		std::unique_ptr<Item> clone() const override 
		{
        	return std::make_unique<Line>(*this);
    	}
};


class Trapezoid
	:	public Item
{
	public:
		std::string	getType() const override;
		virtual ~Trapezoid() = default;
		std::unique_ptr<Item> clone() const override 
		{
        	return std::make_unique<Trapezoid>(*this);
    	}
};

class Triangle
	:	public Item
{
	public:
		std::string	getType() const override;
		virtual ~Triangle() = default;
		std::unique_ptr<Item> clone() const override 
		{
        	return std::make_unique<Triangle>(*this);
    	}
};

class Circle
	:	public Item
{
	public:
		std::string	getType() const override;
		virtual ~Circle() = default;
		std::unique_ptr<Item> clone() const override 
		{
        	return std::make_unique<Circle>(*this);
    	}
};






# endif// ITEMS_HPP