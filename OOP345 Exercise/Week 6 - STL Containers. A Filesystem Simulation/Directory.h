#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H
#include <vector>
#include <string>
#include "Resource.h"
#include "Flags.h"

namespace seneca
{
	class Directory : public Resource
	{
		std::vector<Resource*> m_contents{};

	public:
		Directory(std::string& name);
		void update_parent_path(const std::string& parentPath) override;
		NodeType type() const override;
		std::string path() const override;
		std::string name() const override;
		int count() const override;
		size_t size() const override;
		
		Directory& operator+=(Resource* resource);
		Resource* find(const std::string& name, const std::vector<OpFlags>& flag = {});
		void remove(const std::string& name, const std::vector<OpFlags>& flag = {});
		void display(std::ostream& os, const std::vector<FormatFlags>& flag = {}) const;

		Directory(const Directory&) = delete;
		Directory& operator=(const Directory&) = delete;
		Directory(Directory&&) = delete;
		Directory& operator=(Directory&&) = delete;

		~Directory() override = default;


	};

}

#endif

