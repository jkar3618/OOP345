#ifndef SENECA_SPAMFILTERPLUGIN_H
#define SENECA_SPAMFILTERPLUGIN_H

#include <string>
#include "plugin.h"

namespace seneca
{
	class SpamFilterPlugin : public Plugin
	{
		std::string m_spam[10];
		size_t m_cnt{ 0 };
		size_t m_spamCount{ 0 };

	public:
		SpamFilterPlugin(const char* filename);
		void operator()(Message& msg);
		void showStats() const;
	};

}
#endif

