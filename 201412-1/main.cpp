#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;

int num[MAX_N+1];

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        num[k]++;
        cout << num[k] << " ";
    }
    return 0;
}