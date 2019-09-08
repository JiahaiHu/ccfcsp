#include <bits/stdc++.h>
#define MAX_N 500

using namespace std;

int matrix[MAX_N+1][MAX_N+1];

void scan(int n, int k, int direction) {
    int i, j;
    if (k <= n) {
        i = 1;
        j = k;
        
    } else {
        i = 1 + k - n;
        j = n;
    }
    while (j > 0 && i <= n) {
        if (direction == 1) {
            cout << matrix[i][j] << " ";
        } else {
            cout << matrix[j][i] << " ";
        }
        ++i;
        --j;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> matrix[i][j];
        }
    }
    int d = 0;
    for (int i = 1; i <= 2 * n - 1; ++i) {
        scan(n, i, d);
        d = 1 - d;
    }
    return 0;
}