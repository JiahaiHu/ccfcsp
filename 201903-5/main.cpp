#include <bits/stdc++.h>
#define MAX_N 10000

using namespace std;

vector<pair<int, int> > path[MAX_N + 1]; // second: length of path
int dis[MAX_N + 1][MAX_N + 1];  // distance
 
int min_connected_with[MAX_N + 1];  // min node connected with

int update_min(int x) {
    int min_with_x = min_connected_with[x];
    if (min_with_x == x) return x;
    if (min_with_x > min_connected_with[min_with_x]) {  // min changed
        min_connected_with[x] = update_min(min_with_x);
    }
    return min_connected_with[x];
}
 
void connect(int n, int m) {
    int a = update_min(n);
    int b = update_min(m);
    if (a == b) return;
    min_connected_with[a] = min(a, b);
    min_connected_with[b] = min(a, b);
}
 
bool is_connected(int a,int b) {
    return update_min(a) == update_min(b);
}
 
int main() {
    int n, m, k;
    vector<int> engine;

    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int is_engine[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> is_engine[i];
        if (is_engine[i]) {
            engine.push_back(i);
        }
    }

    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }

    for (int i = 1; i <= MAX_N; i++) {
        min_connected_with[i] = i;
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        connect(a, b);
        path[a].push_back({b, c});
        path[b].push_back({a, c});
    }

    
    priority_queue<pair<int, int> > q;
    for (auto i : engine) {
        while (!q.empty()) {
            q.pop();
        }

        for (int j = 1; j <= i; j++) {
            if (dis[i][j] != dis[0][0]) {
                q.push({0, j}); // connected node
            }
        }

        int vis[n + 1]; // visited
        for (int j = 1; j <= n; ++j) {
            vis[j] = 0;
        }

        while (!q.empty()) {
            int b = q.top().second;
            q.pop();

            if (vis[b]) continue;
            vis[b] = 1;

            for (int j = 0; j < path[b].size(); j++) {
                int node = path[b][j].first;
                int len = path[b][j].second;
                if (vis[node]) {
                    continue;
                }
                if (dis[i][b] + len < dis[i][node]) {
                    dis[i][node] = dis[i][b] + len;
                    q.push({-dis[i][node], node});
                }
            }
        }
    }

    int len[MAX_N + 1];
    for (int i = 1; i <= n; i++) {
        int num = 0;
        long long sum = 0;
        for (auto x : engine) {
            if (is_connected(i, x)) {
                len[num++] = dis[x][i];
            }
        }
        sort(len, len + num);
        for (int j = 0; j < min(num, k); j++) {
            sum += len[j];
        }
        cout << sum;
        if (i != n) cout << endl;
    }

    return 0;
}
