#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    auto p = equal_range(a.begin(), a.end(), a[a.size() / 2]);
    if (p.first - a.begin() == a.end() - p.second) {
        cout << a[a.size() / 2] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}