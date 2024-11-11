#include <iostream>
#include <algorithm>
#include "Collection.h"

namespace seneca
{
	Collection::Collection(const std::string& name)
		: m_name(name), m_observer(nullptr) {}

	Collection::~Collection()
	{
		for (auto item : m_item) {
			delete item;
		}
	}

	const std::string& Collection::name() const
	{
		return m_name;
	}

	size_t Collection::size() const
	{
		return m_item.size();
	}

	void Collection::setObserver(void(*observer)(const Collection&, const MediaItem&))
	{
		m_observer = observer;
	}

	Collection& Collection::operator+=(MediaItem* item)
	{
		bool already = std::any_of(m_item.begin(), m_item.end(), [item](const MediaItem* originItem)
			{
				return originItem->getTitle() == item->getTitle();
			});

		if (already)
		{
			delete item;
		}
		else
		{
			m_item.push_back(item);
			if (m_observer)
			{
				m_observer(*this, *item);
			}
		}

		return *this;
	}

	MediaItem* Collection::operator[](size_t idx) const
	{
		if (idx >= m_item.size())
		{
			throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_item.size()) + "] items.");
		}

		return m_item[idx];
	}

	MediaItem* Collection::operator[](const std::string& title) const
	{
		auto address = std::find_if(m_item.begin(), m_item.end(), [&title](const MediaItem* item)
			{
				return item->getTitle() == title;
			});

		return (address != m_item.end() ? *address : nullptr);
	}

	void Collection::removeQuotes()
	{

	}

	void Collection::sort(const std::string& field)
	{
	}




	std::ostream& operator<<(std::ostream& out, const Collection& collection)
	{
		return out;
		// TODO: insert return statement here
	}

}