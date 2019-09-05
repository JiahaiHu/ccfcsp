#include <bits/stdc++.h>
#define MAX_N 100

using namespace std;

pair<int, int> direction[4] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

int n, m, q;
char canvas[MAX_N][MAX_N];
bool _visit[MAX_N][MAX_N];

bool _in(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void _fill(int x, int y, char c) {
    canvas[x][y] = c;
    _visit[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int _x = x + direction[i].first;
        int _y = y + direction[i].second;
        if (_in(_x, _y) && !_visit[_x][_y]) {
            char _old = canvas[_x][_y];
            if (_old == '-' || _old == '|' || _old == '+') {
                continue;
            }
            _fill(_x, _y, c);
        }
    }
}

void display() {
    for (int j = n - 1; j >= 0; --j) {
        for (int i = 0 ; i < m; ++i) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin >> m >> n >> q;

    memset(canvas, '.', sizeof(canvas));

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {  // fill
            int x, y;
            char c;
            cin >> x >> y >> c;
            memset(_visit, 0, sizeof(_visit));
            _fill(x, y, c);
        } else {    // draw line
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2) {
                int _min = min(y1, y2);
                int _max = max(y1, y2);
                for (int y = _min; y <= _max; ++y) {
                    if (canvas[x1][y] == '-') {
                        canvas[x1][y] = '+';
                    } else if (canvas[x1][y] != '+') {
                        canvas[x1][y] = '|';
                    }
                }
            } else {
                int _min = min(x1, x2);
                int _max = max(x1, x2);
                for (int x = _min; x <= _max; ++x) {
                    if (canvas[x][y1] == '|') {
                        canvas[x][y1] = '+';
                    } else if (canvas[x][y1] != '+') {
                        canvas[x][y1] = '-';
                    }
                }
            }
        }
    }

    display();

    return 0;
}