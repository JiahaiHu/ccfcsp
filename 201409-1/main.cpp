#include <bits/stdc++.h>

using namespace std;

vector<int> num;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        num.push_back(a);
    }
    sort(num.begin(), num.end());
    int c = 0;
    for (int i = 1; i < n; ++i) {
        if (num[i] - num[i-1] == 1) {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}