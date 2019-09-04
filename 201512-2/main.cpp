#include <bits/stdc++.h>
#define MAX_N 30

using namespace std;

int b[MAX_N][MAX_N];
vector<pair<int, int> > clear;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    // clear row
    for (int i = 0; i < n; ++i) {
        int cur = b[i][0];
        int num = 1;
        for (int j = 1; j < m; ++j) {
            if (b[i][j] == cur) {
                ++num;
            }
            else {
                cur = b[i][j];
                num = 1;
            }
            if (num == 3) {
                clear.push_back({i, j});
                clear.push_back({i, j - 1});
                clear.push_back({i, j - 2});
            } else if (num > 3) {
                clear.push_back({i, j});
            }
        }
    }
    // clear column
    for (int j = 0; j < m; ++j) {
        int cur = b[0][j];
        int num = 1;
        for (int i = 1; i < n; ++i) {
            if (b[i][j] == cur) {
                ++num;
            }
            else {
                cur = b[i][j];
                num = 1;
            }
            if (num == 3) {
                clear.push_back({i, j});
                clear.push_back({i - 1, j});
                clear.push_back({i - 2, j});
            } else if (num > 3) {
                clear.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < clear.size(); ++i) {
		b[clear[i].first][clear[i].second] = 0;
    }
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
            cout << b[i][j];
            if (j == m - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
	}

    return 0;
}