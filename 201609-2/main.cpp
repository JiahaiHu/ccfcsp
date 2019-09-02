#include <bits/stdc++.h>

using namespace std;

bool sold[20+1][5+1] = {0};

int main() {
    int n;
    cin >> n;
    while (n--) {
        bool flag = false;
        int p;
        cin >> p;
        for (int row = 1; row <= 20; ++row) {
            if (flag) {
                break;
            }
            for (int col = 1; col <= 6 - p; ++col) {
                if (!sold[row][col]) {
                    for (int j = 0; j < p; ++j) {
                        sold[row][col + j] = true;
                        cout << (row - 1) * 5 + col + j;
                        if (j == p - 1) {
                            cout << endl;
                        } else {
                            cout << " ";
                        }
                    }
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            for (int i = 1; i <= 100 && p > 0; ++i) {
                int row = 1 + i / 5;
                int col = i % 5;
                if (!sold[row][col]) {
                    sold[row][col] = true;
                    --p;
                }
            }
        }
    }
    return 0;
}