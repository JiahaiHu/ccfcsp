#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

struct Edge{
    int u, v, cost;
    Edge(int u, int v, int c) : u(u), v(v), cost(c) {}
    bool operator < (const Edge& e) const {
        return !(this->cost < e.cost);
    }
};

priority_queue<Edge> edges;
int father[MAX_N + 1];

int find_father(int x) {
    if (father[x] == x) {
        return x;
    }
    int f = find_father(father[x]);
    father[x] = f;
    return f;
}

int main() {
    int n, m, day;
    
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push(Edge(a, b, c));
    }

    iota(father, father + n + 1, 0);
    while (find_father(1) != find_father(n)) {
        Edge e = edges.top();
        edges.pop();
        int fu = find_father(e.u);
        int fv = find_father(e.v);
        if (fu != fv) {
            father[fu] = fv;
            day = max(day, e.cost);
        }
    }
    cout << day << endl;
    
    return 0;
}