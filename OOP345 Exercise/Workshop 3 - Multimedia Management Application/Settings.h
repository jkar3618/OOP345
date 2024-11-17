//*****************************************************************************
//<assessment name : Workshop - #3>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************

#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

namespace seneca
{
	struct Settings
	{
		int m_maxSummaryWidth{ 80 };
		bool m_tableView{ false };
	};

	extern Settings g_settings;
}

#endif

