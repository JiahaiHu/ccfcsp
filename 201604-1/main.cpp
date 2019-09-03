#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;

int a[MAX_N];

int main() {
    int n;
    int num = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ++num;
        }
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            ++num;
        }
    }
    cout << num << endl;
    return 0;    
}