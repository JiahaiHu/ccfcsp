#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

long long price[MAX_N+1], ans = 0;
vector<pair<int, int> > graph[MAX_N+1];
bool vis[MAX_N+1];

void dfs(int s, int t, long long p) {
	long long min_price;
	long long cost;
	if (s == t) {
		cout << ans << endl;
	} else {
		vis[s] = true;
		for (int i = 0; i < graph[s].size(); i++) {
			if (!vis[graph[s][i].first]) {
				min_price = min(p, price[s]);
				cost = graph[s][i].second * min_price;
				ans += cost;
				dfs(graph[s][i].first, t, min_price);
				ans -= cost;
			}
		}
	}
}

int main() {
    int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> price[i];
	}
	while (--n) {
		int u, v, e;
		cin >> u >> v >> e;
		graph[u].push_back({v, e});
		graph[v].push_back({u, e});
	}
	while (m--) {
		int s, t;
		cin >> s >> t;
		memset(vis, false, sizeof(vis));
		ans = 0;
		dfs(s, t, price[s]);
	}
	return 0;
}