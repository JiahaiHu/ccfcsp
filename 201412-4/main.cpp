#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

struct Edge {
    int u, v, cost;
    Edge(int u, int v, int c) : u(u), v(v), cost(c) {}
    bool operator <(const Edge& e) const {
        return this->cost > e.cost;
    }
};

priority_queue<Edge> edges;
int parent[MAX_N+1];

int _find(int x) {
    if (parent[x] == x) {
        return x;
    }
    parent[x] = _find(parent[x]);
    return parent[x];
}

int main() {
    int n, m;
    int ans = 0;
    
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push(Edge(a, b, c));
    }

    iota(parent, parent + n + 1, 0);

    while (!edges.empty()) {
        Edge e = edges.top();
        edges.pop();
        int u_parent = _find(e.u);
        int v_parent = _find(e.v);
        if (u_parent != v_parent) {
            parent[u_parent] = v_parent;
            ans += e.cost;
        }
    }
    cout << ans << endl;

    return 0;
}