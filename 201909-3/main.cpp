#include <bits/stdc++.h>
#define MAXM 1920

using namespace std;

struct Pixel {
	int r, g, b;
};

Pixel line[MAXM] = {0};

int charToNum(char c) {
	int a;
	if (c >= '0' && c <= '9') {
		a = c - '0';
	} else {
		a = c - 'a' + 10;
	}
	return a;
}

int sToHex(char c1, char c2) {
	int a = charToNum(c1);
	int b = charToNum(c2);
	return a * 16 + b;
}

char numToChar(long long a) {
	if (a < 10) {
		return a + '0';
	} else {
		return a - 10 + 'A';
	}
}

void numToS(long long a) {
	char c1 = numToChar(a / 100);
	char c2 = numToChar(a / 10 % 10);
	char c3 = numToChar(a % 10);
	if (c1 != '0') {
		cout << "\\x3" << c1;
	}
	if (c1 != '0' || c2 != '0') {
		cout << "\\x3" << c2;
	}
	cout << "\\x3" << c3;
}

long long r = 0;
long long g = 0;
long long b = 0;
			
int main() {
	int m, p;	// width
	int n, q;	// height
	cin >> m >> n;
	cin >> p >> q;
	int k = n / q;
	while (k--) {	// k组
		memset(line, 0, sizeof(line));
		// 先累加q行
		for (int i = 0; i < q; ++i) {	// q行 
			for (int j = 0; j < m; ++j) {	// m列 
				string s;
				cin >> s;
				int r = 0, g = 0, b = 0;
				if (s.size() == 2) {	// #a
					r = g = b = sToHex(s[1], s[1]);
				} else if (s.size() == 4) {	// #abc
					r = sToHex(s[1], s[1]);
					g = sToHex(s[2], s[2]);
					b = sToHex(s[3], s[3]);
				} else {	// #abcdef
					r = sToHex(s[1], s[2]);
					g = sToHex(s[3], s[4]);
					b = sToHex(s[5], s[6]);
				}
				line[j].r += r;
				line[j].g += g;
				line[j].b += b;
			}
		}
		
		// 求q行的平均值，以p为一组 
		for (int i = 0; i < m/p; ++i) {	// 组数 
			long long sum_r = 0;
			long long sum_g = 0;
			long long sum_b = 0;
			for (int j = i*p; j < (i+1)*p; ++j) {
				sum_r += (long long)line[j].r;
				sum_g += (long long)line[j].g;
				sum_b += (long long)line[j].b;
			}
			// 平均值 
			sum_r /= (long long) p * q;
			sum_g /= (long long) p * q;
			sum_b /= (long long) p * q;
			// 改变背景色
			if (sum_r == r && sum_g == g && sum_b == b) {	// 颜色与上一次相同
				// do nothing
			} else if (sum_r == 0 && sum_g == 0 && sum_b == 0) {	// 与默认值相同 
				cout << "\\x1B\\x5B\\x30\\x6D";
			} else {
				cout << "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";
				numToS(sum_r);
				cout << "\\x3B";
				numToS(sum_g);
				cout << "\\x3B";
				numToS(sum_b);
				cout << "\\x6D";
			}
			// 输出空格 
			cout << "\\x20";
			r = sum_r;
			g = sum_g;
			b = sum_b;
		}
		// 如果不是默认颜色，恢复默认
		if (r != 0 || g != 0 || b != 0) {
			cout << "\\x1B\\x5B\\x30\\x6D";
			r = g = b = 0;
		}
		// 换行 
		cout << "\\x0A";
	}
	
	return 0;
}
