#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

struct City {
    int u;
    long long s, v, f;
};

long long worth[MAX_N + 1];
int vis[MAX_N + 1];
City c[MAX_N + 1];

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        memset(worth, 0, sizeof(worth));
	    memset(vis, 0, sizeof(vis));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> c[i].u >> c[i].s >> c[i].v >> c[i].f;
        }
        for (int i = n; i > 0; --i) {
            long long d = c[i].s;
            int u = c[i].u;
            while (u != 0) {
                long long w = c[u].v - (c[u].f - d) * (c[u].f - d);   // u->i
                if (w + worth[i] > worth[u]) {
                    worth[u] = w + worth[i];
                }
                d += c[u].s;
                u = c[u].u;
            }
        }
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += worth[i];
        }
        cout << sum << endl;
    }
    return 0;
}