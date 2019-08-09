#include<bits/stdc++.h>

using namespace std;

int main() {
    int r, y, g;
    int n, k, t;
    int cost = 0;

    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &k, &t);
        if (k == 0 || k == 1) {
            cost += t;
        } else if (k == 2) {
            cost += t + r;
        }
    }
    printf("%d", cost);

    return 0;
}