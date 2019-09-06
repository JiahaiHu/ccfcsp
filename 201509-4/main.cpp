#include <bits/stdc++.h>
#define MAX_N 10000

using namespace std;

vector<int> graph[MAX_N+1];
int index[MAX_N+1], lowLink[MAX_N+1];
stack<int> s;
bool onStack[MAX_N+1];
int _index = 0, ans;

void DFS(int v) {
    // Set the depth index for v to the smallest unused index
    index[v] = lowLink[v] = ++_index;
    s.push(v);
    onStack[v] = true;
    for (int i : graph[v]){
        if (index[i] == 0) {
            // Successor i has not yet been visited; recurse on it
            DFS(i);
            lowLink[v] = min(lowLink[v], lowLink[i]);
        } else if (onStack[i]) {
            // Successor i is in stack S and hence in the current SCC
            // If i is not on stack, then (v, i) is a cross-edge in the DFS tree and must be ignored
            lowLink[v] = min(lowLink[v], index[i]);
        }
    }
    // If v is a root node, pop the stack and generate an SCC
    if (lowLink[v] == index[v]) {
        int t, num = 0;
        do {
            t = s.top();
            s.pop();
            ++num;
            onStack[t] = false;
        } while (t != v);
        ans += (num - 1) * num / 2;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (index[i] == 0) {
            DFS(i);
        }
    }
    cout << ans << endl;
    return 0;
}