#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include "Pair.h"

namespace seneca
{
	template <typename T, int CAP>
	class Collection
	{
		T arr[CAP]; // array of type T with the CAP of size
		size_t num{};

		static T dummy; // class variables aka static

	public:
		size_t size() const
		{
			return num;
		}
		std::ostream& display(std::ostream& os =std::cout) {
			
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;


			for (auto i = 0; i < num; ++i)
			{
				os << arr[i] << std::endl;
			}
		
			os << "----------------------" << std::endl;

			return os;
		}
		virtual bool add(const T& val)
		{
			if (num < CAP)
			{
				arr[num++] = val;
			}
			return false;
		}
		T& operator[](size_t index)
		{
			return index < num ? arr[index]: dummy;
		}
		virtual ~Collection() {}

	};

	template <class T, int CAP>
	T Collection<T, CAP>::dummy{};

	



	template <>
	Pair Collection<Pair, 100>::dummy{"No Key", "No Value"};

}


#endif // !SENECA_COLLECTION_H


