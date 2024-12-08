#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <thread>

using namespace std;

struct Toy
{
	string name;
	string type;
	int funLevel;
	bool isBroken;

	Toy(const string& n, const string& t, int f, bool b)
		: name(n), type(t), funLevel(f), isBroken(b) {}


};

/*
### **ToyBox Class Requirements**

1. **Add Toys**
   - Implement the `+=` operator to add a **Toy** to the **ToyBox**.

2. **Remove Toys**
   - Implement the `-=` operator to remove all **Toy** objects with a matching **name** from the **ToyBox**.
   - If no matching Toy is found, throw an exception of **string** type with a relevant error message.

3. **Fix Broken Toys**
   - Implement the `fixAll` function that "fixes" all broken toys.
   - Fixing a Toy increases its **funLevel** by **10 points** and sets **isBroken** to `false`.
   - Use **one thread** to perform the work on the collection of toys.

4. **View ToyBox**
   - Implement the `display` function that displays the list of toys currently in the **ToyBox**.

5. **Access Toys by Index**
   - Implement the `[]` operator to access a **Toy** at the given index in the **ToyBox**.
   - If the index is out of range, throw an exception of **string** type with an appropriate error message.

*/

class ToyBox {
	//std::vector<Toy*> m_toys;
	std::vector<unique_ptr<Toy>> m_toys;

	ToyBox() = default;


	ToyBox& operator+=(unique_ptr<Toy>& newToy) {
		m_toys.push_back(std::move(newToy));
	}

	ToyBox& operator-=(std::string name) {
		auto itr = std::remove_if(m_toys.begin(), m_toys.end(), [name](unique_ptr<Toy>& newToy) {
			return newToy->name == name;
			});

		m_toys.erase(itr);

		if (itr == m_toys.end())
		{
			throw std::string("None");
		}

	}

	void fixAll()
	{
		auto fix = [](std::vector<unique_ptr<Toy>>& toys) {

			for (auto& i : toys)
			{
				i->funLevel += 10;
				i->isBroken = false;
			}

		};

		auto process = [](std::vector<unique_ptr<Toy>>::iterator beg, std::vector<unique_ptr<Toy>>::iterator end) {

			for (auto i = beg; i != end; ++i)
			{
				(*i)->funLevel += 10;
				(*i)->isBroken = false;
			}

		};

		std::thread t1, t2;

		t1 = thread(process, m_toys.begin(), m_toys.begin() + m_toys.size() / 2);
		t2 = thread(process, m_toys.begin() + m_toys.size() / 2, m_toys.end());
		t1.join();
		t2.join();


		//std::thread t1 = std::thread(fix, m_toys);
		//t1.join();
	}

	Toy& operator[](size_t index) {
		if (index > m_toys.size())
		{
			throw std::string("Error");
		}	

		return *m_toys[index];
	}


};