#include <bits/stdc++.h>
#define MAX_N 5000
using namespace std;

int x[MAX_N + 1];
int y[MAX_N + 1];

short x_sum[MAX_N + 1][MAX_N + 1];
short y_sum[MAX_N + 1][MAX_N + 1];

int main () {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    memset(x_sum, 0, sizeof(x_sum));
    memset(y_sum, 0, sizeof(y_sum));
    for (int i = 1; i <= n; ++i) {
        x_sum[x[i]][y[i]] = y_sum[x[i]][y[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++){
            x_sum[i][j] += x_sum[i][j-1];
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            y_sum[i][j] += y_sum[i-1][j];
        }
    }
        
    int best = 0, best_cnt;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int level = min(x_sum[i][j-1] - 0, x_sum[i][n] - x_sum[i][j]);
            int tmp = min(y_sum[i-1][j] - 0, y_sum[n][j] - y_sum[i][j]);
            level = min(level, tmp);
            if (level > best) {
                best = level;
                best_cnt = 1;
            } else if (level == best) {
                best_cnt++;
            }
        }
    }
        
    if (q == 1) {
        cout << best << endl;
    }
    else {
        cout << best_cnt << endl;
    }
    return 0;
}