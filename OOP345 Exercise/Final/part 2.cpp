#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>

using namespace std;

struct Gem {
	string name;
	string colour;
	int shine;
	bool polished;
};

class Box {
	std::vector<Gem> m_gems;

public:
	Box& operator+=(const Gem& gem)
	{
		m_gems.push_back(gem);
		return *this;
	}

	Box& operator-=(std::string& name)
	{
		auto it = std::find_if(m_gems.begin(), m_gems.end(), [name](const Gem& g) {
			return g.name == name;
			});

		if (it != m_gems.end())
		{
			m_gems.erase(it);
		}
		else
		{
			throw string("Error");
		}
	}

	void process() {
		std::vector<thread> ths;

		auto polish = [](Gem& g) {
			
				if (!g.polished)
				{
					g.shine += 20;
					g.polished = true;
				}
		};

		for (Gem& g : m_gems)
		{
			ths.push_back(thread(polish, g));
		}

		for (auto& t : ths)
		{
			t.join();
		}

		std::thread t1(polish, m_gems);
		t1.join();
		
	}

	void display() const
	{
		for (const auto& g : m_gems)
		{
			std::cout << g.name << g.colour << g.polished << g.shine;
		}
	}


};