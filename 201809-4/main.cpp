#include <bits/stdc++.h>
#define MAX_N 300

using namespace std;

int t[MAX_N + 1];   // today
int y[MAX_N + 1];   // yesterday
int n;
bool solved[MAX_N + 1][MAX_N + 1][MAX_N + 1];

void dfs(int i) {
    int a = y[i - 1];
    int b = y[i];

    if (solved[i][a][b]) {  // already solved but not the answer
        return;
    }
    solved[i][a][b] = true;

    if (i == n) {
        if ((a + b) / 2 == t[n]) {
            for (int j = 1; j <= n; ++j) {
                printf("%d", y[j]);
                if (j != n) {
                    printf(" ");
                }
            }
            exit(0);
        }
        return;
    }

    for (int j = 0; j < 3; ++j) {
        y[i + 1] = 3 * t[i] + j - a - b;
        if (y[i + 1] > 0) {
            dfs(i + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", t + i);
    }

    for (int i = 1; i <= 2 * t[1]; ++i) {
        y[1] = i;
        y[2] = 2 * t[1] - i;
        if (y[2] >0) {
            dfs(2);
        }
        y[2] = 2 * t[1] + 1 - i;
        dfs(2);
    }


    return 0;
}