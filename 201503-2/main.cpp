#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin >> n;
    unordered_map<int, int> num;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ++num[a];
    }
    vector<pair<int, int> > v;
    for (auto i : num) {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second != p2.second ? p1.second > p2.second : p1.first < p2.first;
    });
    for (auto i : v) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}