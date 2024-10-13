#include <iostream>
#include <iomanip>
#include "mailServer.h"


using namespace std;

namespace seneca
{

	MailServer::MailServer(const char* name, const char* address) : m_userName(name), m_userAddres(address), m_inbox(nullptr), m_cnt(0), onNewMailArrived(nullptr)
	{
		m_plugins[0] = nullptr;
		m_plugins[1] = nullptr;
	}

	MailServer::MailServer(const MailServer& src)
	{
		*this = src;

	}

	MailServer& MailServer::operator=(const MailServer& src)
	{
		if (this != &src)
		{
			delete[] m_inbox;

			m_userName = src.m_userName;
			m_userAddres = src.m_userAddres;
			m_cnt = src.m_cnt;
			onNewMailArrived = src.onNewMailArrived;
			m_plugins[0] = src.m_plugins[0];
			m_plugins[1] = src.m_plugins[1];

			m_inbox = new Message[m_cnt];

			for (size_t i = 0; i < m_cnt; i++)
			{
				m_inbox[i] = src.m_inbox[i];
			}
		}

		return *this;
	}

	MailServer::MailServer(MailServer&& src) noexcept
	{
		*this = std::move(src);
	}

	MailServer& MailServer::operator=(MailServer&& src) noexcept
	{
		if (this != &src)
		{
			m_userName = src.m_userName;
			m_userAddres = src.m_userAddres;
			m_cnt = src.m_cnt;
			onNewMailArrived = src.onNewMailArrived;
			m_plugins[0] = src.m_plugins[0];
			m_plugins[1] = src.m_plugins[1];
			m_inbox = src.m_inbox;

			src.m_userName = "";
			src.m_userAddres = "";
			src.m_cnt = 0;
			src.onNewMailArrived = nullptr;
			src.m_plugins[0] = nullptr;
			src.m_plugins[1] = nullptr;
			src.m_inbox = nullptr;

		}

		return *this;
	}

	MailServer::~MailServer()
	{
		delete[] m_inbox;
	}

	void MailServer::receiveMail(Message msg)
	{
		if (m_userAddres != msg.m_toAddress)
		{
			throw msg.m_toAddress;
		}

		for (size_t i = 0; i < m_cnt; i++)
		{
			(*m_plugins[i])(msg); // functor
		}

		Message* temp = new Message[m_cnt + 1];

		for (size_t i = 0; i < m_cnt; i++)
		{
			temp[i] = m_inbox[i];
		}

		temp[m_cnt] = msg;

		delete[] m_inbox;
		m_inbox = temp;
		m_cnt++;

		if (onNewMailArrived)
		{
			onNewMailArrived(msg);
		}
	}

	void MailServer::addPlugin(Plugin* thePlugin)
	{
		for (size_t i = 0; i < m_cnt; i++)
		{
			if (m_plugins[i] == nullptr)
			{
				m_plugins[i] = thePlugin;
			}
		}

	}

	void MailServer::setObserver(Observer_pfn ptr)
	{
		onNewMailArrived = ptr;
	}

	Message& MailServer::operator[](size_t idx)
	{
		if (m_cnt > idx)
		{
			throw std::out_of_range("Index IDX is out of bounds");
		}

		return m_inbox[idx];
	}

	size_t MailServer::getInboxSize()
	{
		return m_cnt;
	}

	void MailServer::showInbox()
	{

		for (size_t i = 0; i < m_cnt; i++)
		{

			cout << m_inbox[i].m_fromName << " " << m_inbox[i].m_fromAddress << " " << m_inbox[i].m_date << m_inbox[i].m_subject << endl;
		}
	}

}