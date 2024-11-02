#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H
#include "Directory.h"
#include "File.h"

namespace seneca
{
	class Filesystem
	{
		Directory* m_root;
		Directory* m_current;

	public:
		Filesystem(const std::string& name, const std::string& rootName = "");






		
	};

}
#endif

