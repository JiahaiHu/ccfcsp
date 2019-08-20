#include <bits/stdc++.h>

using namespace std;

int s[9] = {0, 3500, 5000, 8000, 12500, 38500, 58500, 83500, INT_MAX};
double rate[9] = {0.0, 0.0, 0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};

int main() {
    int T, S;
    cin >> T;
    int t[9] = {0};
    for (int i = 1; i < 9; ++i) {
		t[i] = t[i - 1] + (s[i] - s[i - 1]) * (1 - rate[i]);
    }
    for (int i = 1; i < 9; ++i) {
		if (T <= t[i]) {
			S = (T - t[i - 1]) / (1 - rate[i]) + s[i - 1];
			cout << S;
			break;
		}
	}
	return 0;
}