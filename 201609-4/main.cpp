#include <bits/stdc++.h>
#define MAX_N 10000

using namespace std;

struct Edge {
    int v, cost;
};

vector<Edge> graph[MAX_N + 1];
int dis[MAX_N + 1];
bool vis[MAX_N + 1] = {0};
int prev_cost[MAX_N + 1];

int main() {
    int n, m;
    int sum = 0;

    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill(dis + 2, dis + n + 1, INT_MAX);
    fill(prev_cost + 2, prev_cost + n + 1, INT_MAX);

    for (int i = 0; i < n; ++i) {
        int u;
        int _min = INT_MAX;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && dis[j] < _min) {
                _min = dis[j];
                u = j;
            }
        }
        vis[u] = true;
        sum += prev_cost[u];
        // update
        for (int j = 0; j < graph[u].size(); ++j) {
            int v = graph[u][j].v;
            if (!vis[v] && dis[u] + graph[u][j].cost < dis[v]) {
                dis[v] = dis[u] + graph[u][j].cost;
                prev_cost[v] = graph[u][j].cost;
            } else if (!vis[v] && dis[u] + graph[u][j].cost == dis[v]) {
                if (graph[u][j].cost < prev_cost[v]) {
                    prev_cost[v] = graph[u][j].cost;
                }
            }
        }
    }
    cout << sum << endl;

    return 0;
}