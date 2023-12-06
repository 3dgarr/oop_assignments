# ifndef DOCUMENT_HPP
# define DOCUMENT_HPP

# include <vector>
# include <memory>

class Slide;
class Item;


class Document
{
	public:

		using iterator			= typename std::vector<std::unique_ptr<Slide>>::iterator;
		using const_iterator	= typename std::vector<std::unique_ptr<Slide>>::const_iterator;
	
	public:
		iterator		begin();
		iterator		end();
		const_iterator	cbegin();
		const_iterator	cend();
		size_t	currentSlideSize() const;

	public:
		void addToCurrentSlide(std::unique_ptr<Item>);
		void removeItemFromCurrentSlide(size_t);
		iterator& getCurrentSlide();
		void listCurrentSlide() const;



	public:
		Document();

	private:
		std::vector<std::unique_ptr<Slide>> slides;
		iterator current_slide;
};





# endif// DOCUMENT_HPP