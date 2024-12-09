#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <thread>
#include <vector>
using namespace std;

struct Gem {
	string name;
	string colour;
	int shine;
	bool polished;
};

/*
 Create a Box class has the following properties:
?An STL container of Gems as a data member
?A += operator that adds Gems to the box
?A -= operator that removes Gems from the Box based on a given string (name) to search for.
  If the string is found then remove any Gems that match. If there isn’t a match at all then throw an
  exception of string type with a relevant error message
?A function called process that doesn’t receive any parameters nor returns any value.
  This function will iterate through the Gems in the Box and polish them if they aren’t yet polished.
  Polishing a Gem will cause its shine value to increase by 20. For this functionality incorporate the use of threads to divide the work.
?A display function that displays the contents of the box
?As an extra task, modify the Box class to instead have a container of Gem pointers and apply the use of smart pointers to the solution.
*/

class Box {
	vector<Gem*> gems{};
public:
	Box() = default;

	Box(const Box& src)
	{
		*this = src;
	}

	Box& operator=(const Box& src)
	{
		if (this != &src)
		{
			for(auto& i : gems)
			{
				delete i;
				i = nullptr;
			}
			gems.clear();

			for (auto& i : src.gems)
			{
				gems.push_back(new Gem(*i));
			}
		}
		return *this;
	}

	~Box()
	{
		for (auto& i : gems)
		{
			delete i;
			i = nullptr;
		}
	}

	Box& operator+=(const Gem& g)
	{
		gems.push_back(new Gem(g));
		return *this;
	}

	Box& operator-=(const string name)
	{
		auto remove = remove_if(gems.begin(), gems.end(), [name](Gem* g) {
			return g->name == name;
			});

		if (remove == gems.end())
		{
			throw string("None");
		}

		gems.erase(remove);
	}

	void process()
	{
		auto polish = [](vector<Gem>::iterator beg, vector<Gem>::iterator end) {
			for (auto i = beg; i != end; ++i)
			{
				if (!(*i).polished)
				{
					(*i).polished = true;
					(*i).shine += 20;
				}
			}
			};

		thread t1, t2;
		t1 = thread(polish, gems.begin(), gems.begin() + gems.size() / 2);
		t2 = thread(polish, gems.begin() + gems.size() / 2, gems.end());

		t1.join();
		t2.join();
	}

	void display() const
	{
		for (auto& x : gems) {
			cout << x->name <<
				"|" << x->polished << "|" << x->shine << endl;
		}
	}

};




class Box {
	vector<Gem*> gems{};
public:

	Box() = default;

	Box(const Box& src) {
		*this = src;
	}

	Box& operator=(const Box& src) {
		if (this != &src) {
			for (auto& x : gems) {
				delete x;
				x = nullptr;
			}
			gems.clear();

			// gems is vector of gem*
			// delete it just means every gem* is null / dealloc

			for (auto& x : src.gems) { // deep copy ??? what do???
				gems.push_back(new Gem(*x));
			}

		}
		return *this;
	}

	~Box() {
		for (auto& x : gems) {
			delete x;
		}
	}

	Box& operator+=(const Gem& g) {
		gems.push_back(new Gem(g)); // composition (alt: agg)
		return *this;
	}

	Box& operator-=(const std::string& s) {

		auto ret = remove_if(gems.begin(), gems.end(), [s](const Gem* g) {
			return g->name == s;
			});

		// 1 , 2, 3, end
		//ret = gems.end();

		if (ret == gems.end())
			throw std::string("None found");

		gems.erase(ret, gems.end());
	}

	void process() {

		/*for (auto i : gems) {
			if (!i.polished) {
				i.polished = true;
				i.shine += 20;
			}
		}*/

		auto polish = [](vector<Gem*>::iterator beg, vector<Gem*>::iterator end) {
			for (auto i = beg; i < end; ++i) {
				if (!(*i)->polished) {
					(*i)->polished = true;
					(*i)->shine += 20;
				}
			}
			};


		thread t1, t2;
		t1 = thread(polish, gems.begin(), gems.begin() + gems.size() / 2);
		t2 = thread(polish, gems.begin() + gems.size() / 2, gems.end());
		t1.join();
		t2.join();
	}

	void display() const {
		for (auto& x : gems) {
			cout << x->name <<
				"|" << x->polished << "|" << x->shine << endl;
		}
	}
};



int main() {
	Box b;

	cout << "\nAdding Gems" << endl;
	b += Gem{ "Emerald", "Green", 20, false };
	b += Gem{ "Ruby", "Red", 50, true };
	b += Gem{ "Sapphire", "Blue", 80, false };
	b += Gem{ "Onyx", "Black", 60, false };
	b += Gem{ "Opal", "White", 10, false };
	b.display();

	cout << "\nRemoving Gems" << endl;
	try {
		b -= "Ruby";
		b -= "Emerald";
		b -= "Diamond";
		b.display();
	}
	catch (string c) {
		cout << c << endl;
	}

	cout << "\nPolishing Gems" << endl;
	b.process();
	b.display();


	cout << "\nVector of Boxes" << endl;
	vector<Box*> boxes;
	boxes.push_back(new Box());
	boxes.push_back(new Box());
	boxes.push_back(new Box());

	for (auto x : boxes) {
		x->operator+=(Gem{ "Emerald", "Green", 20, false });
		x->operator+=(Gem{ "Ruby", "Red", 90, false });
		x->operator+=(Gem{ "Sapphire", "Blue", 40, false });
	}

	for (auto x : boxes) {
		delete x;
	}
}






//class Box {
//    vector<Gem*> m_gems{};
//
//public:
//    Box() = default;
//
//    Box(const Box& src)
//    {
//        *this = src;
//    }
//
//    Box& operator=(const Box& src)
//    {
//        if (this != &src)
//        {
//            for (auto& x : m_gems)
//            {
//                delete x;
//                x = nullptr;
//            }
//
//            m_gems.clear();
//
//            for (auto& i : src.m_gems)
//            {
//                m_gems.push_back(new Gem(*i));
//            }
//        }
//        return *this;
//    }
//
//    ~Box()
//    {
//        for (auto& x : m_gems)
//        {
//            delete x;
//            x = nullptr;
//        }
//    }
//
//    Box& operator+=(const Gem& g)
//    {
//        m_gems.push_back(new Gem(g));
//        return *this;
//    }
//
//    Box& operator-=(const string name)
//    {
//        auto remove = remove_if(m_gems.begin(), m_gems.end(), [name](Gem& g) {
//            return g.name == name;
//            });
//
//        if (remove == m_gems.end())
//        {
//            throw string("None");
//        }
//
//        m_gems.erase(remove, m_gems.end());
//    }
//
//    void process()
//    {
//        auto polish = [](vector<Gem>::iterator beg, vector<Gem>::iterator end) {
//            for (auto i = beg; i != end; ++i)
//            {
//                if ((*i).polished == false)
//                {
//                    (*i).polished = true;
//                    (*i).shine += 20;
//                }
//            }
//            };
//
//        thread t1, t2;
//        t1 = thread(polish, m_gems.begin(), m_gems.begin() + m_gems.size() / 2);
//        t2 = thread(polish, m_gems.begin() + m_gems.size() / 2, m_gems.end());
//
//        t1.join();
//        t2.join();
//    }
//
//};