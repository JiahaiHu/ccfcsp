#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;

int matrix[MAX_N+1][MAX_N+1];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int j = m; j > 0; --j) {
        for (int i = 1; i <= n; ++i) {
            cout << matrix[i][j];
            if (i == n) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
    return 0;
}