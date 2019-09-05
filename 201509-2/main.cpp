#include <bits/stdc++.h>

using namespace std;

int days[12] = {
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
};

int bonus[12] = {0};

int main() {
    int y, d;
    cin >> y >> d;
    if (y % 100 == 0) {
        if (y % 400 == 0) {
            bonus[1] = 1;
        }
    } else if (y % 4 == 0) {
        bonus[1] = 1;
    }
    int month;
    for (int i = 0; i < 12; ++i) {
        if (d > days[i] + bonus[i]) {
            d -= days[i] + bonus[i];
        } else {
            month = i + 1;
            break;
        }
    }
    cout << month << endl;
    cout << d << endl;
    return 0;
}