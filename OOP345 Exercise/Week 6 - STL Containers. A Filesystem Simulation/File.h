#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include <string>
#include "Flags.h"
#include "Resource.h"

namespace seneca
{
	class File : public Resource
	{
		std::string m_contents{};

	public:
		File(const std::string& fname, const std::string& content);
		~File() override = default;

		void update_parent_path(const std::string& parentPath) override;
		NodeType type() const override;
		std::string path() const override;
		std::string name() const override;
		int count() const override;
		size_t size() const override;


	};
}

#endif
