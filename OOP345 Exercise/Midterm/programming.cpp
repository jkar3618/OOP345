#include <iostream>

using namespace std;

enum class StateType
{
	boolean,
	character,
	number
};

typedef struct
{
	char name[20];
	StateType sType;
	union
	{
		bool stateAsBool;
		char stateAsChar;
		int stateAsNum;
	} sState;
} Switch;

class HomeStereo
{
	Switch* arr{};
	size_t sz{};

public:
	HomeStereo() {}
	HomeStereo(const Switch* a, size_t s)
	{
		if (a && s > 0)
		{
			arr = new Switch[s];
			for (auto i = 0; i < s; i++)
			{
				arr[i] = a[i];
				sz = s;
			}
		}
	}

	//Channel Name: xxxxxx - State [on/off]< endl >
	ostream& displayOutputState(ostream& os) const
	{
		for (auto i = 0; i < sz; i++)
		{
			os << "Channel Name: " << arr[i].name << " - State [";
			switch (arr[i].sType)
			{
			case StateType::boolean:
				if (arr[i].sState.stateAsBool == true)
					os << "on";
				else
					os << "off";
			case StateType::character:
				if (arr[i].sState.stateAsChar == 'O')
					os << "on";
				else
					os << "off";
			case StateType::number:
				if (arr[i].sState.stateAsNum == 1)
					os << "on";
				else
					os << "off";
			default:
				break;
			}
			os << "]" << endl;
		}

		return os;
	}

	~HomeStereo() { delete[] arr; }

	HomeStereo(const HomeStereo& src)
	{
		*this = src;
	}

	HomeStereo(HomeStereo&& src) noexcept
	{
		*this = std::move(src);
	}

	HomeStereo operator=(const HomeStereo& src)
	{
		if (this != &src)
		{
			sz = src.sz;
			delete[] arr;
			arr = nullptr;

			// deepcopy
			if (src.arr)
			{
				arr = new Switch[sz];
				for (auto i = 0; i < sz; i++)
				{
					arr[i] = src.arr[i];
				}
			}
		}

		return *this;
	}

	HomeStereo operator=(HomeStereo&& src) noexcept
	{
		if (this != &src)
		{
			sz = src.sz;
			delete[] arr;
			arr = nullptr;

			arr = src.arr;

			src.arr = nullptr;
			src.sz = 0;
		}

		return *this;

	}
};