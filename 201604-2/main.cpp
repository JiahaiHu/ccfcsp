#include <bits/stdc++.h>

using namespace std;

int board[11][16];
int plate[4][4];
vector<pair<int, int> > cube;

int main() {
    for (int y = 15; y >= 1; --y) {
        for (int x = 1; x <= 10; ++x) {
            cin >> board[x][y];
        }
    }
    for (int y = 3; y >= 0; --y) {
        for (int x = 0; x <= 3; ++x) {
            cin >> plate[x][y];
        }
    }
    int col;
    cin >> col;
    for (int x = 0; x < 4; ++x) {
        for (int y = 0; y < 4; ++y) {
            if (plate[x][y] == 1) {
                cube.push_back({col + x, 16 + y});
            }
        }
    }
    int end = false;
    while (!end) {
        for (int i = 0; i < cube.size(); ++i) {
            if (cube[i].second - 1 > 15) {
                continue;
            }
            if (board[cube[i].first][cube[i].second - 1] == 1 || cube[i].second == 1) {
                end = true;
                break;
            }
        }
        if (!end) {
            for (int i = 0; i < cube.size(); ++i) {
                cube[i].second--;
            }
        }
    }
    for (int i = 0; i < cube.size(); ++i) {
        if (cube[i].second > 15) {
            continue;
        }
        board[cube[i].first][cube[i].second] = 1;
    }
    for (int y = 15; y >= 1; --y) {
        for (int x = 1; x <= 10; ++x) {
            cout << board[x][y];
            if (x == 10) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}