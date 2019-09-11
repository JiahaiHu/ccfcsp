#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int ans = 0;
    for (int left = 0; left < n; ++left) {
        int minh = h[left];
        for (int right = left; right < n; ++right) {
            minh = min(h[right], minh);
            ans = max(ans, (right - left + 1) * minh);
        }
    }
    cout << ans << endl;
    return 0;
}