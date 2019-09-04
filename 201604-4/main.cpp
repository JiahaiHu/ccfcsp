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
pair<int, int> unsafe[MAX_N + 1][MAX_N + 1];

bool _in(int r, int c) {
    return r > 0 && r <= n && c > 0 && c <= m;
}

bool _safe(int r, int c, int t) {
    return t < unsafe[r][c].first || t > unsafe[r][c].second;
}

int main() {
    cin >> n >> m >> t;
    while (t--) {
        int r, c, a, b;
        cin >> r >> c >> a >> b;
        unsafe[r][c] = {a, b};
    }

    queue<Step> step;
    step.push(Step(1, 1, 0));
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
            if (_in(r, c) && _safe(r, c, t)) {
                step.push(Step(r, c, t));
            }
        }
    }
    
    return 0;
}