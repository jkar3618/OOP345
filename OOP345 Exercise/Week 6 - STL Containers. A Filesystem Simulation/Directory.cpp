#include <iostream>
#include "Directory.h"

using namespace std;

namespace seneca
{
	Directory::Directory(std::string& name)
	{
		m_name = name;
	}
	
	void Directory::update_parent_path(const std::string& parentPath)
	{
		m_parent_path = parentPath;
		
		for (auto& resource : m_contents)
		{
			resource->update_parent_path(path());
		}
	}
	
	NodeType Directory::type() const
	{
		return NodeType::DIR;
	}
	
	std::string Directory::path() const
	{
		return m_parent_path + "/" + m_name;
	}
	
	std::string Directory::name() const
	{
		return m_name;
	}
	
	int Directory::count() const
	{
		return static_cast<int>(m_contents.size());
	}
	
	size_t Directory::size() const
	{
		size_t size = 0;
		
		for (auto& resource : m_contents)
		{
			size += resource->size();
		}

		return size;
	}
	
	Directory& Directory::operator+=(Resource* resource)
	{
		bool flag = false;
		for (auto it = m_contents.begin(); it != m_contents.end(); it++)
		{
			if ((*it)->name() == resource->name())
			{
				flag = true;
			}
		}
		
		if (flag)
		{
			throw "find";
		}

		m_contents.push_back(resource);
		
		resource->update_parent_path(path());

		return *this;
	}
	
	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flag)
	{
		Resource* add = nullptr;
		bool rec = false;

		for (auto itr = flag.begin(); itr != flag.end(); itr++)
		{
			if (*itr == OpFlags::RECURSIVE) 
			{
				rec = true;
			}
		}

		for (size_t i = 0; i < m_contents.size(); i++)
		{
			if (m_contents[i]->name() == name)
			{
				add = m_contents[i];
			}
		}

		if (add == nullptr && rec)
		{
			for (auto itr = m_contents.begin(); itr != m_contents.end(); itr++)
			{
				if ((*itr)->type() == NodeType::DIR)
				{
					Directory* dir = dynamic_cast<Directory*>(*itr);
					Resource* source = dir->find(name, flag);
					if (source != nullptr)
					{
						add = source;
					}
				}
			}
		}

		return add;
	}
	
	void Directory::remove(const std::string& name, const std::vector<OpFlags>& flag)
	{
		Resource* source = nullptr;
		bool found = false;
		std::vector<Resource*>::iterator itr;

		for (itr = m_contents.begin(); itr != m_contents.end() && !found; itr++)
		{
			if ((*itr)->name() == name)
			{
				found = true;
				source = *itr;
			}
		}

	
		if (found)
		{
			if (source->type() == NodeType::DIR)
			{
				bool rec = false;
				for (auto it = flag.begin(); it != flag.end(); it++)
				{
					if (*it == OpFlags::RECURSIVE) {
					
						rec = true;
					}
				}

				if (!rec)
				{
					throw std::invalid_argument(name + "is a directory.Pass the recursive flag to delete directories.");
				}
				
			}
			m_contents.erase(itr);

			delete source;
		}
		else
		{
			throw std::string(name + "does not exist in " + this->name());
		}

	}
	
	void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flag) const
	{
	}
}