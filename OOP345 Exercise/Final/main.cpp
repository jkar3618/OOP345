// main.cpp
#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<algorithm>
#include<numeric>
#include<future>
#include<thread>
#include"sample.h"
#include"sample.h" // only one needed

int main() {

	std::string strs[]{ "Ruby","Emerald","Sapphire","Opal" };
	unsigned nums[]{ 10,20,30,40 };

	std::unique_ptr<TreasureBox> tbr(new TreasureBox()); // no default constructor
	std::unique_ptr<TreasureBox> ptr(new TreasureBox(strs, nums, 4));

	std::string_view sv = "Ruby";
	std::string s = "Opal";
	ptr->update(sv);
	ptr->update(s);
	ptr->display();

	*ptr += Gem{ "Diamond",50 } += Gem{ "Amber",60 };
	(*ptr += Gem{ "Pearl",70 }).display();

	std::promise<unsigned> pro;
	std::future<unsigned> fut = pro.get_future();

	std::thread t1;
	t1.join(); // should be after thread
	t1 = std::thread(task, std::ref(pro));
	std::cout << "Promised Future: " << fut.get() << std::endl;
	t1.join();

}