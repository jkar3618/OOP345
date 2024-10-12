#ifndef SENECA_MAILSERVER_H
#define SENECA_MAILSERVER_H
#include <string>
#include "message.h"
#include "plugin.h"

namespace seneca
{
	using Observer_pfn = void(*)(const Message&);

	class MailServer
	{
		std::string m_userName;
		std::string m_userAddres;
		Message* m_inbox;
		size_t m_cnt;
		Observer_pfn onNewMailArrived;
		Plugin* m_plugins[2];

	public:
		MailServer(const char* name, const char* address);

		MailServer(const MailServer& src);
		MailServer& operator=(const MailServer& src);
		MailServer(MailServer&& src) noexcept;
		MailServer& operator=(MailServer&& src) noexcept;
		~MailServer();

		void receiveMail(Message msg);
		void addPlugin(Plugin* thePlugin);
		void setObserver(void(*observer)(const Message&));
		Message& operator[](size_t idx);
		size_t getInboxSize();
		void showInbox();
	};

}

#endif // !SENECA_MAILSERVER_H


