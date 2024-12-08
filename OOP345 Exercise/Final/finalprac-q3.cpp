// finalprac-q3.cpp
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
#include <future>
#include "finalprac-q3.h"
#include "finalprac-q3.h"
// #1 Compile Error:
// Desc: Double inclusion of the header
// without the use of header guards
// Fix: Add header guards

TreasureBox::TreasureBox(const std::string* names, unsigned* weights, unsigned size){
  for (unsigned x = 0; x < size; ++x) {
    gems.push_back(Gem{ names[x], weights[x] });
    weight += weights[x];
  }
}

TreasureBox& TreasureBox::operator+=(const Gem& g) {
  gems.push_back(g);
  weight += g.weight;
  return *this;
}

void TreasureBox::update(const std::string& name) {
  std::vector<Gem>::iterator itr;
  for (itr = gems.begin(); itr != gems.end(); ++itr) {
    if (itr->name == name) {
      unsigned sum = 0;
      sum = std::accumulate(name.begin(), name.end(), 0);
      itr->weight += sum;
    }
  }
}

std::ostream& TreasureBox::display() const {
  std::cout << "TreasureBox Contents" << std::endl;
  for (auto& g : gems) {
    std::cout << g.name << " : " << g.weight << std::endl;
  }
  return std::cout;
}

void task(std::promise<unsigned>& p) {
  Gem gems[]{ {"Red" , 10}, {"Green", 20}, {"Blue", 30} };

  auto idx = std::find_if(gems, gems + 2, [](const Gem& g) {
    return g.name == "Green";
  });

  // #6 Compile
  // Desc lacking a set_value call on the promise to 
  // deliver a value to the future expecting it
  // Fix: p.set_value(idx->weight);
}

int main() {

  std::string strs[]{ "Ruby", "Emerald", "Sapphire", "Opal" };
  unsigned nums[]{ 10, 20, 30, 40 };

  std::unique_ptr<TreasureBox> tbr(new TreasureBox());
  // #2 Compile
  // Desc: Lacking a def constr for the TreasureBox class
  // Fix: Add def constructor
  std::unique_ptr<TreasureBox> ptr(new TreasureBox(strs, nums, 4));
 
  std::string_view sv = "Ruby";
  std::string s = "Opal";
  ptr->update(sv); 
  //#3 Compile
  // Desc: string_views are not inherently convertable to std::string
  // Fix make sv a string
  ptr->update(s);
  ptr->display();

  *ptr += Gem{ "Diamond", 50 } += Gem{ "Amber", 60 }; 
  // #4 Compile
  // Desc: We don't have a gem += gem op defined
  // Fix: Define gem+=gem op, use brackets to have the ptr += gem occur
  (*ptr += Gem{ "Pearl", 70 }).display();

  std::promise<unsigned> pro;
  std::future<unsigned> fut = pro.get_future();

  std::thread t1;
  t1.join(); 
  // #5 Undef
  // Desc calling join on a unjoinable thread
  // Don't join before having a task assigned to a thread
  t1 = std::thread(task, std::ref(pro));
  std::cout << "Promised Future: " << fut.get() << std::endl; 
  t1.join();
}
