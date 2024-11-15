#include <iostream>
#include <algorithm>
#include "collection.h"

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
		MediaItem* result = nullptr;

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

	void Collection::removeQuotes()
	{
		std::for_each(m_item.begin(), m_item.end(), [](MediaItem* item)
			{
				std::string title = item->getTitle();
				std::string summary = item->getSummary();


				if (!title.empty() && title.front() == '"')
				{
					title.erase(0, 1);
				}
				if (!title.empty() && title.back() == '"')
				{
					title.erase(title.size() - 1);
				}

				if (!summary.empty() && summary.front() == '"')
				{
					summary.erase(0, 1);
				}
				if (!summary.empty() && summary.back() == '"')
				{
					summary.erase(summary.size() - 1);
				}
				
				item->setTitle(title);
				item->setSummary(title);

			});

	}

	void Collection::sort(const std::string& field)
	{
		std::sort(m_item.begin(), m_item.end(), [field](const MediaItem* m1, const MediaItem* m2)
			{
				bool result = false;
				if (field == "Title")
				{
					result = m1->getTitle() < m2->getTitle();

				}
				else if (field == "Year")
				{
					result = m1->getYear() < m2->getYear();
				}
				return result;
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