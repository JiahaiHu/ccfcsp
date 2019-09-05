#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;

vector<int> graph[MAX_N + 1];
bool _visit[MAX_N + 1][MAX_N + 1];
vector<int> path;

bool odd(vector<int>& v) {
    return v.size() % 2 == 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int u = s.top();
        int i;
        for (i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            if (!_visit[u][v]) {
                s.push(v);
                _visit[u][v] = _visit[v][u] = true;
                break;
            }
        }
        if (i == graph[u].size()) {
            path.push_back(u);
            s.pop();
        }
    }
    int k = count_if(graph + 1, graph + n + 1, odd);
    if (path.size() == m + 1 && (k == 0 || k == 2 && odd(graph[1]))) {
        for (auto i = path.rbegin(); i != path.rend(); ++i) {
            printf("%d ", *i);
        }
    } else {
        printf("-1");
    }
    return 0;
}