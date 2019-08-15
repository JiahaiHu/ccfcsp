#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    queue<int> a;

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        a.push(i);
    }
    int num = 0;
    while (n > 1) {
        int t = a.front();
        a.pop();
        ++num;
        if (num % k == 0 || num % 10 == k) {
            --n;
        } else {
            a.push(t);
        }
    }
    cout << a.front() << endl;

    return 0;
}