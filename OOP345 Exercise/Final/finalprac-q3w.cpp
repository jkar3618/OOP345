#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;

struct Headphone {
  string description;
  double price{};
  bool wireless;
  bool noise_cancelling;
  bool used;
};

Headphone shopping(std::vector<Headphone> phones) {
  /*
  {"Denon D5000"      , 350.99  , false , false , true},
  {"Air Pods"         , 200.24  , true  , false , true},
  {"Sony 1000XM3"     , 300.25  , true  , true  , true},
  {"Senhesier HD 650" , 500     , false , false , false},
  {"Sony 1000XM4"     , 400.50  , true  , true  , false},
  {"Shure SE215"      , 99.99   , true  , true  , true}});
  */
  // Task 1
  {
    sort(phones.begin(), phones.end(), [](const Headphone& h1, const Headphone& h2) 
    { return h1.price > h2.price; });
    cout << phones.front().description << endl; // Output 1 - Senn, 500
    cout << phones.back().description << endl; // Output 2 - Shure SE215 - 99.99
  }

  // Task 2
  // Senn, Xm4, Denon, Xm3, Air, Shure
  {
    for_each(phones.begin() + 1, phones.end() - 1, [](const Headphone& phone) {
      if (phone.wireless && phone.noise_cancelling) {
        cout << phone.price << endl; // Output 3 - 400.50, 300.25
      }
    });
  }

  vector<Headphone> phones2;

  // Task 3
  {
    auto num = count_if(phones.begin(), phones.end() - 2, [](const Headphone& phone) { return phone.wireless; }); // 2 
    phones2.resize(num);
    copy_if(phones.begin(), phones.end() - 2, phones2.begin(), [](const Headphone& phone) { return phone.wireless; });
    cout << "Num: " << num << endl; // Output 4
    cout << phones2.front().description << endl; // Output 5
  }

  // Task 4
  {
    transform(phones2.begin(), phones2.end(), phones2.begin(), [](Headphone& phone) {
      if (phone.used) {
        phone.price -= phone.price * 0.2;
      }
    return phone;
    });
    cout << phones2.back().price << endl; // Output 6
  }

  Headphone ret;

  // Task 5
  {
    auto itr = find_if(phones2.begin(), phones2.end(), 
      [](const Headphone& phone) { return phone.noise_cancelling && phone.used; });
    ret = *itr;
    if (itr != phones2.end()) // Output 7
      cout << itr->description << endl;
    else
      cout << "Nothing found" << endl;
  }

  return ret;
}

int main() {

  std::vector<Headphone> phones({
  {"Denon D5000"      , 350.99  , false , false , true},
  {"Air Pods"         , 200.24  , true  , false , true},
  {"Sony 1000XM3"     , 300.25  , true  , true  , true},
  {"Senhesier HD 650" , 500     , false , false , false},
  {"Sony 1000XM4"     , 400.50  , true  , true  , false},
  {"Shure SE215"      , 99.99   , true  , true  , true}
    });
  auto phone = shopping(phones);
}

/*
Output 1: 
Output 2: 
...
Output 10:
*/
