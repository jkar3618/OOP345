#ifndef SENECA_SET_H
#define SENECA_SET_H
#include "Collection.h"

namespace seneca
{
	template<typename T>
	class Set : public Collection<T, 100>
	{
	public:
		bool add(const T& val);
	};
	
	template<typename T>
	bool Set<T>::add(const T& val)
	{
		bool flag = false;
		bool res = false;

		for (size_t i = 0; i < Collection<T, 100>::size() && !flag; i++)
		{
			if ((*this)[i] == val)
			{
				flag = true;
			}
		}

		if (!flag)
		{
			res = Collection<T, 100>::add(val);

		}
	return res;
	}

	template<>
	bool Set<double>::add(const double& val)
	{
		double gap = 0.01;
		bool flag = false;
		bool res = false;

		for (size_t i = 0; i < Collection<double, 100>::size(); i++)
		{
			if (fabs((*this)[i] - val) <= gap)
			{
				flag = true;
			}
		}

		if (!flag)
		{
			res = Collection<double, 100>::add(val);
		}
		return res;

	}

}


#endif // !SENECA_COLLECTION_H


