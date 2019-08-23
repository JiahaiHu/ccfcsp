#include <bits/stdc++.h>
#define INF 0x7F7F7F7F
#define MAX_N 1000

using namespace std;
 
int t[MAX_N + 1];
int sum[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];
 
int solve(int l, int r) {
    if (dp[l][r] == INF) {
        for (int i = l; i < r; i++) {
            dp[l][r] = min(dp[l][r], solve(l, i) + solve(i + 1, r) + sum[r] - sum[l - 1]);
        }
    }
    return dp[l][r];
}
 
int main() {
    int n;
 
    memset(dp, 0x7f, sizeof(dp));
    cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        sum[i] = sum[i - 1] + t[i];
        dp[i][i] = 0;
    }
    solve(1, n);
    cout << dp[1][n] << endl;
 
    return 0;
}