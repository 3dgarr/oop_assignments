# ifndef ITEMS_HPP
# define ITEMS_HPP

#include <iostream>
class Item
{
	public:
		virtual std::string	getType() const = 0;
		Item() = default;
		virtual ~Item() = default;
};


class Rectangle
	:	public Item
{
	public:
		std::string	getType() const override;
		Rectangle() = default;
		virtual ~Rectangle() = default;
};

class Elipse
	:	public Item
{
	public:
		std::string	getType() const override;
		Elipse() = default;
		virtual ~Elipse() = default;
};


class Line
	:	public Item
{
	public:
		std::string	getType() const override;
		Line() = default;
		virtual ~Line() = default;
};


class Trapezoid
	:	public Item
{
	public:
		std::string	getType() const override;
		Trapezoid() = default;
		virtual ~Trapezoid() = default;
};

class Triangle
	:	public Item
{
	public:
		std::string	getType() const override;
		Triangle() = default;
		virtual ~Triangle() = default;
};

class Circle
	:	public Item
{
	public:
		std::string	getType() const override;
		Circle() = default;
		virtual ~Circle() = default;
};






# endif// ITEMS_HPP