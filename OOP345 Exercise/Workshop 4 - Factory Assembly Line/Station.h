//*****************************************************************************
//<assessment name : Workshop - #4>
//  Full Name : Taehwa Hong
//  Student ID# : 132546227
//	Email : thong14@myseneca.ca
//	Section : OOP345 NDD
//	Authenticity Declaration :
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider.This submitted
//piece of work is entirely of my own creation.
//* ****************************************************************************
#ifndef SENECA_STATION_H
#define SENECA_STATION_H
#include <string>

namespace seneca
{
	class Station
	{
		int m_id{};
		std::string m_name{};
		std::string m_desc{};
		unsigned int m_serial{};
		size_t m_stock{};

		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station();
		Station(const std::string& record);
		virtual ~Station();

		// returns the name of the current Station object
		const std::string& getItemName() const;

		// returns the next serial number to be used on the assembly line and increments m_serialNumber
		size_t getNextSerialNumber();

		// returns the remaining quantity of items in the Station object
		size_t getQuantity() const;

		// subtracts 1 from the available quantity; should not drop below 0.
		void updateQuantity();

		// inserts information about the current object into stream os.
		void display(std::ostream& os, bool full) const;


	};


}

#endif


