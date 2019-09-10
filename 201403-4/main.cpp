#include <bits/stdc++.h>

using namespace std;

struct Router {
    long long x, y;
    bool fixed;
    int cost = 0;
    int num_add = 0;
    Router(long long x, long long y, bool fixed)
        : x(x), y(y), fixed(fixed) {}
};

vector<Router> routers;
bool vis[200];

bool reachable(int i, int j, int r) {
    return (routers[i].x - routers[j].x) * (routers[i].x - routers[j].x) +
        (routers[i].y - routers[j].y) * (routers[i].y - routers[j].y) <= (long long)r * r;
}

int main() {
    int n, m, k, r;
    cin >> n >> m >> k >> r;
    long long x, y;
    while (n--) {
        cin >> x >> y;
        routers.push_back(Router(x, y, true));
    }
    while (m--) {
        cin >> x >> y;
        routers.push_back(Router(x, y, false));
    }
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (i == 1) {
            break;
        }
        for (int j = 0; j < routers.size(); ++j) {
            if (!vis[j] && reachable(i, j, r)) {
                if (!routers[j].fixed && routers[j].num_add + 1 > k) {
                    continue;
                }
                routers[j].cost = routers[i].cost + 1;
                routers[j].num_add = routers[i].num_add + (routers[j].fixed ? 0 : 1);
                vis[j] = true;
                q.push(j);
            }
        }
    }
    cout << routers[1].cost - 1 << endl;
    return 0;
}