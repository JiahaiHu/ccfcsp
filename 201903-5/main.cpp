#include <bits/stdc++.h>
#define MAX_N 10000
#define INF 0x3f3f3f3f  // possible longest path: 10^4(max m) * 10^3(max w)

using namespace std;

int dis[MAX_N + 1][MAX_N + 1];  // distance

void update(int a, int b, int c) {
    // cout << c << ' ' << dis[a][b] << endl;
    if (c < dis[a][b]) {
        dis[a][b] = c;
        dis[b][a] = c;
    }
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
    for (int i = 1; i <= n; ++i) {
        dis[i][i] = 0;
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        update(a, b, c);
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dis[i][k] != INF && dis[k][j] != INF &&
                    dis[i][k] + dis[k][j] < dis[i][j])
                {
                    // cout << i << ' ' << k << ' ' << j << endl;
                    // cout << dis[i][j] << ' ' << dis[i][k] << ' ' << dis[k][j] << endl;
                    dis[i][j] = dis[i][k] + dis[k][j];
                    dis[j][i] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int len[MAX_N + 1];
    for (int i = 1; i <= n; ++i){
        int num = 0;
        long long sum = 0;
        for (auto x : engine){
            if (dis[i][x] != INF){
                // cout << i << ' ' << x << ' ' << dis[i][x] << endl;
                len[num++] = dis[i][x];
            }
        }
        sort(len, len + num);
        for (int j = 0; j < min(num, k); ++j){
            sum += len[j];
        }
        cout << sum;
        if (i != n) cout << endl;
    }

    return 0;
}