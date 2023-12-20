#include "Document.hpp"
#include "Slide.hpp"
#include <algorithm>

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

std::unique_ptr<Document> Document::clone() const
{
	 auto clonedDocument = std::make_unique<Document>();
    
    // Deep copy each slide
    clonedDocument->slides.reserve(slides.size());
    std::transform(slides.begin(), slides.end(), std::back_inserter(clonedDocument->slides),
                   [](const auto &slide) {
						auto clonedSlide = std::make_unique<Slide>();
						
						// Deep copy each item in the slide
						clonedSlide->items.reserve(slide->items.size());
						std::transform(slide->items.begin(), slide->items.end(), std::back_inserter(clonedSlide->items),
										[](const auto &item) {
											// Assuming Item has a virtual clone method
											return item->clone();
										});
						
                       return clonedSlide;
                   });

    // Copy the iterator (if it makes sense for your design)
    // clonedDocument->current_slide = std::next(clonedDocument->slides.cbegin(), std::distance(slides.begin(), current_slide));


    return clonedDocument;

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

void Document::addNewSlide()
{
	slides.push_back(std::make_unique<Slide>(Slide()));
	current_slide = std::next(current_slide);

}

size_t Document::slidesCount() const
{
	return slides.size();
}

Document::Document()
{
	// std::unique_ptr<Slide> slide = std::make_unique<Slide>();
	slides.push_back(std::make_unique<Slide>(Slide()));
	current_slide = slides.begin();
}


