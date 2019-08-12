#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int main() {
    int n;
    int sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v1.push_back({a, b});
    }
    for (int i = 0; i < n; ++i) {
        int c, d;
        scanf("%d %d", &c, &d);
        v2.push_back({c, d});
    }

    for (auto i : v1) {
        for (auto j : v2) {
            if (i.first <= j.second && i.second >= j.first) {
                sum += min(i.second, j.second) - max(i.first, j.first);
            }
        }
    }
    printf("%d", sum);

    return 0;
}