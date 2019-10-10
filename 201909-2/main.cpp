#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;
bool dropped[MAXN] = {0};
int num[MAXN] = {0};

int main() {
	int T = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int m;
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int a;
			cin >> a;
			if (a > 0) {
				if (a < num[i]) {
					dropped[i] = true;
				}
				num[i] = a;
			} else {
				num[i] += a;
			}
		}
		T += num[i];
	}
	
	int D = 0;
	for (int i = 0; i < N; ++i) {
		if (dropped[i]) {
			D++;
		}
	}
	
	int E = 0;
	for (int i = 1; i < N - 1; ++i) {
		if (dropped[i-1] && dropped[i] && dropped[i+1]) {
			E++;
		}
	}
	if (dropped[N-2] && dropped[N-1] && dropped[0]) {
		E++;
	}
	if (dropped[N-1] && dropped[0] && dropped[1]) {
		E++;
	}
	
	cout << T << " " << D << " " << E;
	
	return 0;
}
