# ifndef ITEMS_HPP
# define ITEMS_HPP

class Item
{
	public:
		Item() = default;
		virtual ~Item() = default;
};


class Rectangle
	:	public Item
{
	public:
		Rectangle() = default;
		virtual ~Rectangle() = default;
};

class Elipse
	:	public Item
{
	public:
		Elipse() = default;
		virtual ~Elipse() = default;
};


class Line
	:	public Item
{
	public:
		Line() = default;
		virtual ~Line() = default;
};


class Trapezoid
	:	public Item
{
	public:
		Trapezoid() = default;
		virtual ~Trapezoid() = default;
};

class Triangle
	:	public Item
{
	public:
		Triangle() = default;
		virtual ~Triangle() = default;
};

class Circle
	:	public Item
{
	public:
		Circle() = default;
		virtual ~Circle() = default;
};





# endif// ITEMS_HPP