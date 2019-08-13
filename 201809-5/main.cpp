#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

const int Q = 998244353;
unsigned long long a[MAX_N];
unsigned long long k[MAX_N + 1];

int main() {
    int m;
    unsigned long long l, r;

    cin >> m >> l >> r;
    for (int i = 1; i <= m; ++i) {
        cin >> k[i];
    }

    a[0] = 1;
    for (int i = 1; i <= r; ++i) {
        for (int j = i - 1; j >= i - min(m, i); --j) {
            a[i % MAX_N] += k[i - j] * a[j % MAX_N] % Q;
        }
        a[i % MAX_N] %= Q;
        if (i >= l) cout << a[i % MAX_N] << endl;
    }

    return 0;
}