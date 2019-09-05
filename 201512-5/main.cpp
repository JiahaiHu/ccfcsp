#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;

int n, m;
int A[MAX_N+1][MAX_N+1], temp[MAX_N+1][MAX_N+1], base[MAX_N+1][MAX_N+1], res[MAX_N+1][MAX_N+1];
int b[MAX_N+1], ans[MAX_N+1];

void display(int matrix[MAX_N+1][MAX_N+1]) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void multi_matrix(int A[MAX_N+1][MAX_N+1], int B[MAX_N+1][MAX_N+1], int res[MAX_N+1][MAX_N+1]) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            res[i][j] = (A[i][1] & B[1][j]);
            for (int k = 2; k <= n; ++k) {
                res[i][j] ^= (A[i][k] & B[k][j]);
            }
        }
    }
}

void multi(int A[MAX_N+1][MAX_N+1], int b[MAX_N+1], int res[MAX_N+1]) {
    for (int i = 1; i <= n; ++i) {
        res[i] = A[i][1] & b[1];
        for (int j = 2; j <= n; ++j) {
            res[i] ^= A[i][j] & b[j];
        }
    }
}

int main() {
    string s;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            A[i][j] = s[j - 1];  // matrix A
        }
    }
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        b[i] = s[i - 1];
    }
    cin >> m;
    while (m--) {
        int k;
        cin >> k;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                base[i][j] = A[i][j];
            }
        }
        memset(res, 0, sizeof(res));
        for (int i = 1; i <= n; ++i) {
            res[i][i] = 1;
        }
        while (k) {
            if (k & 1) {    // odd
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        temp[i][j] = res[i][j];
                    }
                }
                multi_matrix(base, temp, res);
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    temp[i][j] = base[i][j];
                }
            }
            multi_matrix(temp, temp, base); // square
            k >>= 1;
        }
        multi(res, b, ans);
        for (int i = 1; i <= n; ++i) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}