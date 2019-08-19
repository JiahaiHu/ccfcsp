#include <bits/stdc++.h>
#define lowbit(i) (i&(-i))
#define MAX_N 100000

using namespace std;

int num[MAX_N + 1];
long long tree[MAX_N + 1] = {0};
int N, M;

void update(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i)) {
        tree[i] += v;
    }
}

long long get_sum(int x) {
    long long sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> num[i];
        update(i, num[i]);
    }
    while (M--) {
        int opt;
        cin >> opt;
        int l, r, v;
        if (opt == 1) {
            cin >> l >> r >> v;
            for (int i = l; i <= r; ++i) {
                if (num[i] % v == 0) {
                    int temp = num[i];
                    num[i] /= v;
                    update(i, num[i] - temp);
                }
            }
        } else {
            cin >> l >> r;
            cout << get_sum(r) - get_sum(l - 1) << endl;
        }
    }
    return 0;
}