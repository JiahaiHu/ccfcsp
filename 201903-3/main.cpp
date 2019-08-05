#include <bits/stdc++.h>

using namespace std;

int n, s, l, m, b;
int k_max;
string disk[1000];
int temp[8];

int to_hex(char c) {
	if (c >= 'A' && c <= 'F'){
		return c - 'A' + 10;
	} else {
		return c - '0';
	}
}

char to_char(int a) {
	if (a <= 9) {
	    return a + '0';
    } else {
	    return a - 10 + 'A';
    }
}

void _xor(int i, int k, int b) {
    string str = disk[i].substr(8*(k*s+b), 8);
    for (int j = 0; j < 8; j++) {
    	temp[j] = temp[j] xor to_hex(str[j]);
	}
}

void read_disk(int d, int k, int b) {
    if (k >= k_max) {
        cout << "-\n";
    } else if (disk[d].size() != 0) {
		cout << disk[d].substr(8*(k*s+b), 8) << "\n";
	} else if (disk[d].size() == 0 && n - l == 1) {
        for (int i = 0; i < 8; i++) {
    		temp[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (i == d) continue;
			_xor(i, k, b);
		}
		for (int i = 0; i < 8; i++) {
			printf("%c", to_char(temp[i]));
		}
        cout << "\n";
	} else {
        cout << "-\n";
	}
}

int main(void) {
	int disk_num, s_num, d_num, k;
    
    ios::sync_with_stdio(false);
	// scanf("%d %d %d", &n, &s, &l);   // score 0
    cin >> n >> s >> l; // score 100
	for (int i = 0; i < l; i++) {
        cin >> disk_num;
		cin >> disk[disk_num];
	}

    for (int i = 0; i < n; i++) {
        int len = disk[i].size();
        if (len > 0) {
            k_max = len / (8*s);
            break;
        }
    }

    cin >> m;
	for (int i = 0; i < m; i++) {
        cin >> b;
		s_num = b / s;
		k = s_num / (n - 1);
		d_num = (((n-1-k)+(s_num % (n-1))+1) % n + n) % n;
		read_disk(d_num, k, b % s);
	}
	
	return 0;
}
