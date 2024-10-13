#ifndef SENECA_VERIFYIDENTITYPLUGIN_H
#define SENECA_VERIFYIDENTITYPLUGIN_H
#include <string>
#include "plugin.h"
#include "message.h"


namespace seneca
{

	class VerifyIdentityPlugin : public Plugin
	{
		std::string m_trust[10];
		size_t m_cnt{ 0 };

	public:
		VerifyIdentityPlugin(const char* filename);
		void operator()(Message& msg);
		void showStats() const;
	};

}
#endif // !SENECA_VERIFYIDENTITYPLUGIN_H

