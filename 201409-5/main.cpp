#include <bits/stdc++.h>
#define MAX_M 7
#define MOD 1000000007
#define COVER(i) (1<<(i))

using namespace std;

// state transition matrix;
// matrix[i][j]: 
int matrix[1<<MAX_M][1<<MAX_M];
int temp[1<<MAX_M][1<<MAX_M];
int res[1<<MAX_M][1<<MAX_M];
int m;

void display(int matrix[1<<MAX_M][1<<MAX_M]) {
    for (int i = 0; i < 1<<m; ++i) {
        for (int j = 0; j < 1<<m; ++j) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void multi_matrix(int A[1<<MAX_M][1<<MAX_M], int B[1<<MAX_M][1<<MAX_M], int res[1<<MAX_M][1<<MAX_M]) {
    memset(res, 0, sizeof(int)*(1<<MAX_M)*(1<<MAX_M));
    for (int i = 0; i < 1<<m; ++i) {
        for (int j = 0; j < 1<<m; ++j) {
            for (int k = 0; k < 1<<m; ++k) {
                res[i][j] = (res[i][j] + 1ll * A[i][k] * B[k][j]) % MOD;
            }
        }
    }
}

bool covered(int s, int i) {
    return s & COVER(i);
}

void dfs(int s_init, int s, int s_next) {
    // cout << s_init << s << s_next << endl;
    if (s == (1 << m) - 1) {
        // cout << "ok" << endl;
        matrix[s_init][s_next]++;
        return;
    }
    for (int i = 0; i < m; ++i) {
        if (!covered(s, i)) {
            //      i  i+1
            //  j   *   *
            // j+1      *
            if (i + 1 < m && !covered(s, i+1) && !covered(s_next, i+1)) {
                int new_s = s | COVER(i) | COVER(i+1);
                int new_s_next = s_next | COVER(i+1);
                dfs(s_init, new_s, new_s_next);
            }
            //      i  i+1
            //  j   *   *
            // j+1  *
            if (i + 1 < m && !covered(s, i+1) && !covered(s_next, i)) {
                int new_s = s | COVER(i) | COVER(i+1);
                int new_s_next = s_next | COVER(i);
                dfs(s_init, new_s, new_s_next);
            }
            //     i-1  i
            //  j       *
            // j+1  *   *
            if (i != 0 && !covered(s_next, i-1) && !covered(s_next, i)) {
                int new_s = s | COVER(i);
                int new_s_next = s_next | COVER(i-1) | COVER(i);
                dfs(s_init, new_s, new_s_next);
            }
            //      i  i+1
            //  j   *
            // j+1  *   *
            if (i + 1 < m && !covered(s_next, i) && !covered(s_next, i+1)) {
                int new_s = s | COVER(i);
                int new_s_next = s_next | COVER(i) | COVER(i+1);
                dfs(s_init, new_s, new_s_next);
            }
            break;
        }
    }
}

int main() {
    long long n;
    cin >> n >> m;
    int M = 1 << m;

    // generate state transition matrix
    for (int s = 0; s < M; ++s) {
        dfs(s, s, 0);
    }

    for (int i = 0; i < M; ++i) {
        res[i][i] = 1;
    }
    
    long long pow = n - 1;
    while (pow) {
        if (pow & 1) {    // odd
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < M; ++j) {
                    temp[i][j] = res[i][j];
                }
            }
            multi_matrix(matrix, temp, res);
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                temp[i][j] = matrix[i][j];
            }
        }
        multi_matrix(temp, temp, matrix); // square
        pow >>= 1;
    }

    cout << res[0][M-1] << endl;

    return 0;
}