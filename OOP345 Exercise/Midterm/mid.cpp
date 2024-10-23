#include <iostream>
#include <iomanip>

class Elements {
public:
	virtual void evoke(std::ostream& os) = 0;
	virtual ~Elements() = default;
};

class Fire :public Elements
{
	char* m_desc;
	double inten;
	static unsigned int cnt; // 클래스 밖에서 한번 더 선언

public:
	Fire() {};
	Fire(const char* desc, double data = 777.777)
	{
		m_desc = new char[strlen(desc) + 1];
		strcpy(m_desc, desc);

		inten = data;
	}

	void evoke(std::ostream& os)
	{
		if (m_desc == nullptr)
		{
			throw "Nondescrip Fire";
		}

		os << "Flames evoked: " << "[" << ++cnt << "]" << std::endl;
		os << "[" << m_desc << "] " << "[" << std::setprecision(3) << inten << "]" << std::endl;

	}

	Fire(const Fire& src)
	{
		*this = src;
	}

	Fire(Fire&& src) noexcept
	{
		*this = std::move(src);
	}

	Fire& operator=(const Fire& src)
	{
		if (this != &src)
		{
			delete[] m_desc;

			inten = src.inten;

			m_desc = new char[strlen(src.m_desc) + 1]; // null terminator

			strcpy(m_desc, src.m_desc);

		}

		return *this;
	}

	Fire& operator=(Fire&& src) noexcept
	{
		if (this != &src)
		{
			delete[] m_desc;

			m_desc = src.m_desc;
			inten = src.inten;

			src.m_desc = nullptr;
			src.inten = 0;
		}

		return *this;
	}

	~Fire()
	{
		delete[] m_desc;
	}
};

unsigned int Fire::cnt{ 0 };


namespace


//Fix: string& operator[](int idx);

 //  name = new char[strlen(nm) + 1]

 //초기 설정에는 const값 또는 고정된 값으로 해야한다.
 // const size_t maxSize = 5;