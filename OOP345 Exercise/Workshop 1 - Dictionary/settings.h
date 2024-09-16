#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

namespace seneca
{
	struct Settings
	{
		bool m_show_all{ false };
		bool m_verbose{ false };
		std::string m_time_units = "nanoseconds";
	};

	extern Settings g_settings;
}

#endif
