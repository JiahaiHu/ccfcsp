#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    while (n--) {
        int s;
        cin >> s;
        ++m[s];
    }
    int ans = m.begin()->first;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > m[ans]) {
            ans = it->first;
        }
    }
    cout << ans << endl;
    return 0;
}