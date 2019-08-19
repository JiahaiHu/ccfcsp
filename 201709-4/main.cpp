#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;

bool root[MAX_N + 1];
bool vis[MAX_N + 1];
vector<int> child[MAX_N + 1];
vector<int> path;
int num[MAX_N + 1] = {0};
int _new = 0;

void dfs(int n) {
    path.push_back(n);
    if (!vis[n]) {
        _new++;
    }
    if (child[n].size() == 0) { // end of path
        for (int i : path) {
            if (vis[i]) {
                num[i] += _new;
            } else {
                num[i] += path.size();
            }
            vis[i] = true;
        }
        _new = 0;
    } else {
        for (int i : child[n]) {
            dfs(i);
        }
    }
    path.pop_back();
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        root[i] = true;
        vis[i] = false;
    }
    while (M--) {
        int a, b;
        cin >> a >> b;
        child[a].push_back(b);
        root[b] = false;
    }
    for (int i = 1; i <= N; ++i) {
        if (root[i]) {
            dfs(i);
        }
    }
    int sum = 0;
    for (int i = 1; i <= N; ++i) {
        if (num[i] == N) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}