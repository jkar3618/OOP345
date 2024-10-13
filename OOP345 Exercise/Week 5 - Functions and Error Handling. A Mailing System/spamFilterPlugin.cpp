#include <iostream>
#include <fstream>
#include <string>

#include "spamFilterPlugin.h"
#include "message.h"

using namespace std;

namespace seneca
{
	SpamFilterPlugin::SpamFilterPlugin(const char* filename)
	{
		ifstream file(filename);
		
		if (!file)
		{
			throw "Error";
		}

		while (getline(file, m_spam[m_cnt++]));
		file.close();
	}

	void SpamFilterPlugin::operator()(Message& msg)
	{
		bool found = false;
		for (size_t i = 0; i < m_cnt && !found; i++)
		{
			if (msg.m_subject.find(m_spam[i]))
			{
				found = true;
				msg.m_subject = "[SPAM] " + msg.m_subject;
				m_spamCount++;
			}
		}
	}

	void SpamFilterPlugin::showStats() const
	{
		cout << "[Spam Filter Plugin] Identified " << m_spamCount << "spam messages." << endl;
	}

}