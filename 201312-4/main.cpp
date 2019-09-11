#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX_N 1000

using namespace std;

// dp[k][0]: the number of k-digit numbers consist of 2
// dp[k][1]: the number of k-digit numbers consist of 2, 0
// dp[k][2]: the number of k-digit numbers consist of 2, 3
// dp[k][3]: the number of k-digit numbers consist of 2, 0, 1
// dp[k][4]: the number of k-digit numbers consist of 2, 0, 3
// dp[k][5]: the number of k-digit numbers consist of 2, 0, 1, 3
long long dp[MAX_N+1][6];

int main() {
	int n;
	cin >> n;
	int i;
	memset(dp, 0, sizeof(dp));
	dp[1][0] = 1;
	for (i = 2; i <= n; ++i) {
		dp[i][0] = 1;
		dp[i][1] = (dp[i - 1][1] * 2 + dp[i - 1][0]) % MOD;
		dp[i][2] = (dp[i - 1][2] + dp[i - 1][0]) % MOD;
		dp[i][3] = (dp[i - 1][3] * 2 + dp[i - 1][1]) % MOD;
		dp[i][4] = (dp[i - 1][4] * 2 + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][5] = (dp[i - 1][5] * 2 + dp[i - 1][3] + dp[i - 1][4]) % MOD;
	}
	cout << dp[n][5] << endl;
	return 0;
}