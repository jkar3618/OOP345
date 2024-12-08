#include <iostream>
using namespace std;

int main() {

    const int row = 2, col = 2;
    int arr[row][col]{};

    auto lam = [&arr](int num) {
        for (auto i = 0; i < row; ++i)
            for (auto j = 0; j < col; ++j)
                arr[i][j] = num * i + j;
    };

    auto disp = [&arr](int r, int c) {
        cout << arr[r][c] << endl;
    };

    lam(4);
    disp(0, 1);
    disp(1, 0);
    disp(0, 0);
    disp(1, 1);
    lam(2);
    disp(1, 0);
    disp(1, 1);
    disp(0, 1);
    disp(0, 0);
}