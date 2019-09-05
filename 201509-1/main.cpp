#include <bits/stdc++.h>

using namespace std;

int main() {
    int num = 0;
    int cur = -1;
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        if (a != cur) {
            num++;
            cur = a;
        }
    }
    cout << num << endl;
    return 0;
}