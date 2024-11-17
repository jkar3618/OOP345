//*****************************************************************************
//<assessment name : Workshop - #3>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************

#include <iostream>
#include <algorithm>
#include "collection.h"

namespace seneca
{
	// Constructor
	Collection::Collection(const std::string& name)
		: m_name(name), m_observer(nullptr) {}

	// Destructor
	Collection::~Collection()
	{
		for (auto item : m_item) {
			delete item;
		}
	}

	// Return name
	const std::string& Collection::name() const
	{
		return m_name;
	}

	// Return Size of item
	size_t Collection::size() const
	{
		return m_item.size();
	}

	// Set observer
	void Collection::setObserver(void(*observer)(const Collection&, const MediaItem&))
	{
		m_observer = observer;
	}

	// Add MediaItem to the collection
	Collection& Collection::operator+=(MediaItem* item)
	{
		// Check if an item with the same title already exists
		bool already = std::any_of(m_item.begin(), m_item.end(), [item](const MediaItem* originItem)
			{
				return originItem->getTitle() == item->getTitle();
			});

		// If the item exists, delete the new item
		if (already)
		{
			delete item;
		}
		else
		{
			// Add the item to the collection
			m_item.push_back(item);

			if (m_observer)
			{
				m_observer(*this, *item);
			}
		}

		return *this;
	}

	// Return specific index of item, throw exception if out of range
	MediaItem* Collection::operator[](size_t idx) const
	{
		if (idx >= m_item.size())
		{
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_item.size()) + "] items.");
		}

		return m_item[idx];
	}

	// Return specific title of item
	MediaItem* Collection::operator[](const std::string& title) const
	{
		MediaItem* result = nullptr;

		// Find item withe matching title
		auto address = std::find_if(m_item.begin(), m_item.end(), [title](const MediaItem* item)
			{
				return item->getTitle() == title;
			});

		if (address != m_item.end())
		{
			result = *address;
		}

		return result;
	}

	// Remove quotes from title and summary of items
	void Collection::removeQuotes()
	{
		std::for_each(m_item.begin(), m_item.end(), [](MediaItem* item)
			{
				std::string title = item->getTitle();
				std::string summary = item->getSummary();

				// remove quotes from the beginning and end of title
				if (!title.empty() && title.front() == '"')
				{
					title.erase(0, 1);
				}
				if (!title.empty() && title.back() == '"')
				{
					title.erase(title.size() - 1);
				}

				// remove quotes from the beginning and end of summary
				if (!summary.empty() && summary.front() == '"')
				{
					summary.erase(0, 1);
				}
				if (!summary.empty() && summary.back() == '"')
				{
					summary.erase(summary.size() - 1);
				}
				
				// update title and summary
				item->setTitle(title);
				item->setSummary(summary);

			});

	}

	// Sort the collection based on the Title or Year
	void Collection::sort(const std::string& field) {
		// Sort using std::sort and a lambda expression
		std::sort(m_item.begin(), m_item.end(),
			[field](const MediaItem* a, const MediaItem* b) {
				if (field == "title") {
					return a->getTitle() < b->getTitle();
				}
				else if (field == "year") {
					return a->getYear() < b->getYear();
				}
				return false; // Default: no sorting if field is invalid
			});
	}


	std::ostream& operator<<(std::ostream& out, const Collection& collection)
	{

		for (const auto& result : collection.m_item)
		{
			result->display(out);
		}
		return out;
		// TODO: insert return statement here
	}

}