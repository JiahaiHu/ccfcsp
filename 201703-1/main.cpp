#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;

int cake[MAX_N];

int main() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cake[i];
        sum += cake[i];
        if (sum >= k) {
            sum = 0;
            num++;
        } else if (i == n - 1) {
            num++;
        }
    }
    cout << num << endl;
    return 0;
}