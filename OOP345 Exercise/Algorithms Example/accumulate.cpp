///*
//1: std::accumulate
//  1. 합계.
//  2. 평균값.
//  3. 곱.
//*/
//
//#include <iostream>
//#include <vector>
//#include <numeric>
//
//int main() {
//    std::vector<int> data = { 3, 7, 2, 5, 8, 6, 4, 9, 1 };
//
//    int sum;
//    sum = std::accumulate(data.begin(), data.end(), 0); 
//    std::cout << "sum: " << sum << std::endl;
//
//
//    double average;
//    average = sum / data.size();
//    std::cout << "average: " << average << std::endl;
//
//    int product;
//    product = std::accumulate(data.begin(), data.end(), 1, [](int total, int current) {
//        return total * current;
//        });
//    std::cout << "product: " << product << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//    std::vector<std::string> fruits = { "apple", "banana", "cherry", "date" };
//
//    std::sort(fruits.begin(), fruits.end(), [](string start, string current) {
//        return start.size() > current.size();
//        // return start.length() > current.length();
//        }
//
//    return 0;
//}

/*
3: std::for_each
- 문자열 벡터가 있습니다: {"apple", "banana", "cherry", "date", "fig"}.
- `"5:apple", "6:banana" 변환

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> fruits = { "apple", "banana", "cherry", "date", "fig" };

    // Modify each string to include its length at the beginning
    
    std::for_each(fruits.begin(), fruits.end(), [](std::string& current) {
        current = std::to_string(current.length()) + current;
        });

    std::cout << "Modified strings:" << std::endl;
    for (const auto& fruit : fruits) {
        std::cout << fruit << std::endl;
    }

    return 0;
}



