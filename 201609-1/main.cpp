#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;

int a[MAX_N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int max = 0;
    for (int i = 1; i < n; ++i) {
        int d = abs(a[i] - a[i - 1]);
        if (d > max) {
            max = d;
        }
    }
    cout << max << endl;
    return 0;
}