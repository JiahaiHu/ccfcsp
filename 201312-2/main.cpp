#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string number;
    number = s.substr(2, 3) + s.substr(6, 5);
    int ans = s[0] - '0';
    for (int i = 0; i < number.size(); ++i) {
        ans = (ans + (number[i] - '0') * (2 + i)) % 11;
    }
    char c;
    if (ans == 10) {
        c = 'X';
    } else {
        c = ans + '0';
    }
    if (c == s[12]) {
        puts("Right");
    } else {
        cout << s.substr(0, 12) << c << endl;
    }
    return 0;
}