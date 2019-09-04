#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    int sum = 0;
    cin >> n;
    for (auto c : n) {
        sum += c - '0';
    }
    cout << sum << endl;
    return 0;
}