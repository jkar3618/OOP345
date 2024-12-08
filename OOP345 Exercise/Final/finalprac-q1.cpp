#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

struct ComputerParts {
  string partType;
  string model;
  double price;
  double powerConsumption;
  bool used;
};

int main() {

  vector<ComputerParts> wishList;

  // Task 1
  // Add to the vector some number of desired Computer Parts
  // Eg. GPU, RTX 3080, 1000, 300, false
  wishList.push_back(ComputerParts{"CPU", "AMD 7950X3D", 800, 200, false});
  wishList.push_back(ComputerParts{"GPU", "NVIDIA 3070", 500, 250, false});
  wishList.push_back(ComputerParts{"RAM", "Ripjaws 32GB", 120, 50, true});
  wishList.push_back(ComputerParts{"PSU", "Corsair SFX750", 200, 750, true});
  wishList.push_back(ComputerParts{"MB", "ASRock B550i", 150, 100, false});

  auto display = [](vector<ComputerParts>& wl) {for (auto& x : wl) {
    cout << x.model << "|" << x.partType << endl;
    cout << x.price << "|" << x.powerConsumption << "|" << x.used << endl;
  }};
  display(wishList);
  cout << "*******************" << endl;

  // Task 2
  // Sort the wishList by price in ascending order
  sort(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
         return c1.price < c2.price;
      });
  display(wishList);
  cout << "*******************" << endl;

  // Task 3
  // Print to the screen the part in the wishList that has the most and least powerConsumption
  /*sort(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
      return c1.powerConsumption < c2.powerConsumption;
      });

  cout << "MOST: " << wishList.back().model << endl;
  cout << "LEAST: " << wishList.front().model << endl;*/

  auto max = max_element(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
      return c1.powerConsumption < c2.powerConsumption;
      });

  auto min = min_element(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
      return c1.powerConsumption < c2.powerConsumption;
      });

  cout << "MAX: " << max->model << endl;
  cout << "MIN: " << min->model << endl;

  cout << "*******************" << endl;

  // Task 4
  // Remove from the wishList all the parts that are 'used'
  auto itr = remove_if(wishList.begin(), wishList.end(), [](const ComputerParts& c) {
      return c.used;
      });

  if (itr != wishList.end())
      wishList.erase(itr, wishList.end());

  display(wishList);
  cout << "*******************" << endl;

  // Task 5
  // Find the average cost of all the parts in the wishList
  double sum = accumulate(wishList.begin(), wishList.end(), 0.0, [](double& s, const ComputerParts& c) {
      return s += c.price;
      });

  cout << "SUM: " << sum << endl;
  cout << "AVG: " << sum / wishList.size() << endl;

  cout << "*******************" << endl;

  // Task 6
  // Change all the items in the wishList to 'used' and reduce their price by 20% and save this result to a new vector
  vector<ComputerParts> usedList(wishList.size());

  transform(wishList.begin(), wishList.end(), (usedList.begin()), [](ComputerParts c) {
      if (!c.used) {
          c.used = true;
          //c.price -= c.price * 0.2;
          c.price *= 0.8;
      }
      return c;
      });

  display(usedList);
  cout << "*******************" << endl;
  display(wishList);
  cout << "*******************" << endl;

  // Task 7
  // Figure out how many of a given part type is in the wishList eg. how many GPUs and print to the screen
  string p_type{"GPU"};
  //cin >> p_type;
  int cnt = count_if(wishList.begin(), wishList.end(), [p_type](const ComputerParts& c) {
      return c.partType == p_type;
      });
  cout << "CNT: " << cnt << endl;
  cout << "*******************" << endl;

  // Task 8
  // Create new wishList of computer parts and combine it with the original one
  vector<ComputerParts> wishList2;
  wishList2.push_back(ComputerParts{"CPU", "AMD 7950X3D", 800, 200, false});
  wishList2.push_back(ComputerParts{"GPU", "NVIDIA 3070", 500, 250, false});
  wishList2.push_back(ComputerParts{"RAM", "Ripjaws 32GB", 120, 50, true});
  wishList2.push_back(ComputerParts{"PSU", "Corsair SFX750", 200, 750, true});
  wishList2.push_back(ComputerParts{"MB", "ASRock B550i", 150, 100, false});

  vector<ComputerParts> mergedList(wishList.size() + wishList2.size());

  // sort
  sort(wishList.begin(), wishList.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
  return c1.price < c2.price;
      });
  sort(wishList2.begin(), wishList2.end(), [](const ComputerParts& c1, const ComputerParts& c2) {
      return c1.price < c2.price;
      });
  // merge
  merge(wishList.begin(), wishList.end(), wishList2.begin(), wishList2.end(), 
      mergedList.begin(), [](const ComputerParts& c1, const ComputerParts& c2) {
          return c1.price < c2.price;
      });

  display(mergedList);
  cout << "*******************" << endl;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            