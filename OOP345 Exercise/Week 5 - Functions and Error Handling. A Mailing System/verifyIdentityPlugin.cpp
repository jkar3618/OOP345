#include <iostream>
#include <fstream>
#include "verifyIdentityPlugin.h"

using namespace std;

namespace seneca
{
	VerifyIdentityPlugin::VerifyIdentityPlugin(const char* filename)
	{
		ifstream file(filename);

		if (!file)
		{
			throw "Error";
		}

		while (getline(file, m_trust[m_cnt++]));
	}

	void VerifyIdentityPlugin::operator()(Message& msg)
	{
		bool found = false;

		for (size_t i = 0; i < m_cnt && !found; i++)
		{
			if (msg.m_fromAddress == m_trust[i])
			{
				found = true;
				msg.m_subject = "[TRUSTED] " + msg.m_subject;
			}
		}
	}

	void VerifyIdentityPlugin::showStats() const
	{
		cout << "[Identity Checker Plugin] can validate identity for ";

		for (size_t i = 0; i < m_cnt; i++)
		{
			cout << m_trust[i];
			if (i != m_cnt)
			{
				cout << ", ";
			}
		}

		cout << endl;
	}

}