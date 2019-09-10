#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);

    int num = 0;
    for (int i = 0; a[i] < 0; ++i) {
        if (binary_search(a, a + N, -a[i])) {
            num++;
        }
    }
    cout << num << endl;
    
    return 0;
}