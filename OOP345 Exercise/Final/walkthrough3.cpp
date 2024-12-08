#include <iostream>
#include <functional>
using namespace std;

int main() {

    int val = 5;

    function<int(int, int)> fs[3]{
      [val](int i, int j) mutable -> double { val = i * j; return val; },
      [=](int i, int j) { return i - val - j; },
      [&val](int i, int j) { val = i + j + val; return val; }
    };

    for (auto& x : fs) {
        cout << x(1, 2) << endl;
        cout << val << endl;
    }
}