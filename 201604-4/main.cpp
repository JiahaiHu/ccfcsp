#include <bits/stdc++.h>
#define MAX_N 100

using namespace std;

struct Step {
    int row, col, t;
    Step(int r, int c, int t) : row(r), col(c), t(t) {};
};

pair<int, int> direction[4] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

int n, m, t;
bool vis[MAX_N + 1][MAX_N + 1][301];

bool _in(int r, int c) {
    return r > 0 && r <= n && c > 0 && c <= m;
}

int main() {
    cin >> n >> m >> t;
    while (t--) {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        for (int i = a; i <= b; ++i) {
            vis[r][c][i] = true;
        }
    }

    queue<Step> step;
    step.push(Step(1, 1, 0));
    vis[1][1][0] = true;
    while (!step.empty()) {
        Step s = step.front();
        step.pop();

        if (s.row == n && s.col == m) {
            cout << s.t << endl;
            break;
        }

        int t = s.t + 1;
        for (int i = 0; i < 4; ++i) {
            int r = s.row + direction[i].first;
            int c = s.col + direction[i].second;
            if (_in(r, c) && !vis[r][c][t]) {
                step.push(Step(r, c, t));
                vis[r][c][t] = true;
            }
        }
    }
    
    return 0;
}