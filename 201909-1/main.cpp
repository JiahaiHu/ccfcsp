#include <bits/stdc++.h>
#define MAXN 1000

using namespace std;

int a[MAXN];
int b[MAXN];

int main() {
	int N, M;
	int left = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		left += a[i];
		
		int sum = 0;
		for (int j = 0; j < M; ++j) {
			int d;
			cin >> d;
			sum = sum - d; 
		}
		b[i] = sum;
		left -= sum;
	}
	
	int max_b = 0;
	int max_i = 0;
	for (int i = 0; i < N; ++i) {
		a[i] = a[i] - b[i];
		if (b[i] > max_b) {
			max_b = b[i];
			max_i = i + 1;
		}
	}
	
	cout << left << " " << max_i << " " << max_b;
	 
	return 0;
}
