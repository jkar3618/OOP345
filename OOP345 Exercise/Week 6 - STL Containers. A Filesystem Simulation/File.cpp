#include <iostream>
#include <string>
#include "File.h"
#include "Resource.h"
#include "Flags.h"

using namespace std;

namespace seneca
{
	File::File(const std::string& fname, const std::string& content = "") : m_contents(content)
	{
		m_name = fname;
	}

	
	void File::update_parent_path(const std::string& parentPath)
	{
		m_parent_path = parentPath;
	}

	NodeType File::type() const
	{
		return NodeType::FILE;
	}
	
	std::string File::path() const
	{
		return m_parent_path + "/" + m_name;
	}
	
	std::string File::name() const
	{
		return m_name;
	}
	
	int File::count() const
	{
		return -1;
	}
	
	size_t File::size() const
	{
		return m_contents.size();
	}
}