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
		// TODO: insert return statement here
	}
	
	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flag)
	{
		return nullptr;
	}
	
	void Directory::remove(const std::string& name, const std::vector<OpFlags>& flag)
	{
	}
	
	void Directory::display(std::ostream& os, const std::vector<FormatFlags>& flag) const
	{
	}
}