#include <bits/stdc++.h>

using namespace std;

int board[3][3];

int check() {
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    if (board[1][1] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[1][1];
    }
    if (board[1][1] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[1][1];
    }
    return 0;
}

int blank() {
    int num = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                num++;
            }
        }
    }
    return num;
}

int dfs(int id) {
    int _max = -99, _min = 99;
    if (blank() == 0) {
        return 0;   // draw
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = id;
                if (check() == id) {
                    int num = blank();
                    board[i][j] = 0;    // undo
                    if (id == 1) {
                        return max(_max, num + 1);  // win
                    } else {
                        return min(_min, -(num + 1));   // lose
                    }
                }
                // not terminate
                int ret = dfs(3 - id);
                if (id == 1) {
                    _max = max(_max, ret);
                } else {
                    _min = min(_min, ret);
                }
                board[i][j] = 0;    // undo
            }
        }
    }
    if (id == 1) {
        return _max;
    } else {
        return _min;
    }
}

// Adversarial search
int main() {
    int T;

    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> board[i][j];
            }
        }
        int ret = check();
        if (ret == 1) {
            int num = blank();
            cout << num + 1 << endl;
            continue;
        } else if (ret == 2) {
            int num = blank();
            cout << -(num + 1) << endl;
            continue;
        }
        cout << dfs(1) << endl;
    }

    return 0;
}