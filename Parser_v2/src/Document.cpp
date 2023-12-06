#include "Document.hpp"
#include "Slide.hpp"

auto	Document::begin() -> iterator
{
	return	slides.begin();
}

auto	Document::end() -> iterator
{
	return	slides.end();
}

auto	Document::cbegin() -> const_iterator
{
	return	slides.cbegin();
}

auto	Document::cend()-> const_iterator
{
	return	slides.cend();
}

void Document::addToCurrentSlide(std::unique_ptr<Item> item)
{
	current_slide->get()->addItem(std::move(item));	
}

void Document::removeItemFromCurrentSlide(size_t index)
{
	current_slide->get()->removeItem(index);	
}

size_t	Document::currentSlideSize() const
{
	return (current_slide->get()->size());
}

auto Document::getCurrentSlide() -> iterator&
{
	return current_slide;
}

void Document::listCurrentSlide() const
{
	auto start = current_slide->get()->begin();
	auto end = current_slide->get()->end();

	if (std::distance(start, end) == 0)
	{
		std::cout << "Empty document" << std::endl;
		return;
	}
	int index = 0;
	for (Slide::iterator it = start; it != end; ++it)
	{
		std::cout << index++ << ": " << it->get()->getType() << std::endl;
		
	}
	
}





Document::Document()
{
	// CHGITEEEEM
	std::unique_ptr<Slide> slide = std::move(std::make_unique<Slide>(Slide()));
	slides.push_back(std::move(slide));
	current_slide = slides.begin();
	
}


