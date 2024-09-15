//FoodOrder.h
#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

extern double g_taxrate, g_dailydiscount;

namespace seneca
{
	class FoodOrder
	{
		char f_name[16]{};
		char f_desc[26]{};
		double f_price{};
		bool f_special{};

	public:
		FoodOrder();
		FoodOrder(const FoodOrder& src);
		~FoodOrder();
		FoodOrder& operator=(const FoodOrder& src);

		std::istream& read(std::istream& is);
		void display() const;
		explicit operator bool() const;

	};

	std::istream& operator>>(std::istream& is, FoodOrder& order);
	void operator>>(const FoodOrder& order1, FoodOrder& order2);
}

#endif // !SENECA_FOODORDER_H
