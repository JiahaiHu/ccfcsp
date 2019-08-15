#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> a;

    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; ++i) {
        a[i] = abs(a[i] - a[i + 1]);
    }
    a.pop_back();
    sort(a.begin(), a.end());
    printf("%d", a[0]);

    return 0;
}