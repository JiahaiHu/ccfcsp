#include <bits/stdc++.h>
#define MAX_N 500
#define INF 0x3f3f3f3f
using namespace std;

int path[MAX_N + 1][MAX_N + 1];  // positive: big, negative: small
long long len[MAX_N + 1];    // 0: big, other: continuous length
long long dis[MAX_N + 1];
bool vis[MAX_N + 1] = {false};

int main() {
    int n, m;
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    memset(path, 0x3f, sizeof(path));
    for (int i = 0; i < m; ++i) {
        int t, a, b, c;
        cin >> t >> a >> b >> c;
        if (t == 0) {   // big
            path[a][b] = c;
            path[b][a] = c;
        } else {    // small
            path[a][b] = -c;
            path[b][a] = -c;
        }
    }

    dis[1] = 0;
    len[1] = 0;
    for (int i = 1; i <= n; ++i) {
        int u;
        int _min = INF;
        for (int j = 1; j <= n; ++j) {
            if (vis[j] == false && dis[j] < _min) {
                u = j;
                _min = dis[j];
            }
        }
        vis[u] = true;
        for (int v = 1; v <= n; ++v) {
            if (vis[v] == false && path[u][v] != INF) {
                long long delta;
                if (path[u][v] > 0) {
                    len[v] = 0;
                    delta = path[u][v];
                } else {
                    if (len[u] == 0) {
                        len[v] = -path[u][v];
                        delta = len[v] * len[v];
                    } else {
                        len[v] = len[u] - path[u][v];
                        delta = len[v] * len[v] - len[u] * len[u];
                    }
                }

                if(dis[u] + delta < dis[v]) {
                    dis[v] = dis[u] + delta;
                }
            }
        }
    }

    cout << dis[n] << endl;

    return 0;
}