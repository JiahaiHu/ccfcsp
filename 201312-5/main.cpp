#include <bits/stdc++.h>
#define MAX_N 50

using namespace std;

int R, C;
int xs, ys; // starting point
int xt, yt; // terminal point
char grid[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];

bool _in(int i, int j) {
    if (i >= 0 && i < R && j >= 0 && j < C) {
        return true;
    }
    return false;
}

void dfs(int i, int j) {
    if (!_in(i, j) || vis[i][j] == 1 || grid[i][j] == '#') {
        return;
    }

    vis[i][j] = 1;

    if (grid[i][j] == '+') {
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    } else if (grid[i][j] == '-') {
        dfs(i, j - 1);
        dfs(i, j + 1);
    } else if (grid[i][j] == '|') {
        dfs(i - 1, j);
        dfs(i + 1, j);
    } else if (grid[i][j] == '.') {
        dfs(i + 1, j);
    }
}

void dfs_r(int i, int j) {
    if (grid[i][j] == '#' || vis[i][j] == 2) {
        return;
    }

    vis[i][j] = 2;

    if (_in(i - 1, j) && (grid[i - 1][j] == '+' || grid[i - 1][j] == '|' || grid[i - 1][j] == '.')) {
        dfs_r(i - 1, j);
    }
    if (_in(i + 1, j) && (grid[i + 1][j] == '+' || grid[i + 1][j] == '|')) {
        dfs_r(i + 1, j);
    }
    if (_in(i, j - 1) && (grid[i][j - 1] == '+' || grid[i][j - 1] == '-')) {
        dfs_r(i, j - 1);
    }
    if (_in(i, j + 1) && (grid[i][j + 1] == '+' || grid[i][j + 1] == '-')) {
        dfs_r(i, j + 1);
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c;
            if (grid[i][j] == 'S') {
                xs = i;
                ys = j;
                grid[i][j] = '+';
            } else if (grid[i][j] == 'T') {
                xt = i;
                yt = j;
                grid[i][j] = '+';
            }
        }
    }
    
    dfs(xs, ys);

    if (vis[xt][yt] == 1) {
        dfs_r(xt, yt);
        int num = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (vis[i][j] == 1) {
                    num++;
                }
            }
        }
        cout << num << endl;
    } else {
        puts("I'm stuck!");
    }

    return 0;
}