#include <bits/stdc++.h>

using namespace std;

int bonus[16] = {0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 6};

int main() {
    int N;
    int sum = 0;
    cin >> N;
    N /= 10;
    while (N >= 15) {
        N -= 15;
        sum += 15 + bonus[15];
    }
    sum += N + bonus[N];
    cout << sum << endl;
    return 0;
}