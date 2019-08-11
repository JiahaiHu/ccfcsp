#include <bits/stdc++.h>
#define MAX_N 50000
using namespace std;

struct Edge {
    int u, v, cost;
    Edge(int u, int v, int t): u(u), v(v), cost(t) {}
    bool operator < (const Edge& e) const {
        return this->cost > e.cost;
    }
};

priority_queue<Edge> edges;
int root[MAX_N + 1];   // disjoint-set

int find_root(int x) {  // with path compression
    int r = root[x];
    if (r != x) {
        root[x] = find_root(r);
    }
    return root[x];
}

int main() {
    int n, m, r;
    int max = 0;

    scanf("%d %d %d", &n, &m, &r);
    iota(root, root + n + 1, 0);    // init set

    while (m--) {
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        edges.push(Edge(u, v, t));
    }

    while (!edges.empty()) {
        Edge e = edges.top();   // edge with min cost
        edges.pop();
        int root_u = find_root(e.u);
        int root_v = find_root(e.v);
        if (root_u != root_v) { // not in the same set
            root[root_u] = root_v;  // union
            max = e.cost;
        }
    }
    printf("%d", max);

    return 0;
}