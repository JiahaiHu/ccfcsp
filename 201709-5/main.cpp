#include <bits/stdc++.h>
#define MAX_N 100000

using namespace std;

int num[MAX_N + 1];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> num[i];
    }
    while (M--) {
        int opt;
        cin >> opt;
        int l, r, v;
        if (opt == 1) {
            cin >> l >> r >> v;
            for (int i = l; i <= r; ++i) {
                if (num[i] % v == 0) {
                    num[i] /= v;
                }
            }
        } else {
            cin >> l >> r;
            int sum = 0;
            for (int i = l; i <= r; ++i) {
                sum += num[i];
            }
            cout << sum << endl;
        }
    }
    return 0;
}