#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    bool case_sensitive;
    int n;

    cin >> S >> case_sensitive >> n;

    regex r;
    if (case_sensitive) {
        r = regex("[[:alpha:]]*" + S + "[[:alpha:]]*");
    } else {
        r = regex("[[:alpha:]]*" + S + "[[:alpha:]]*", regex::icase);
    }

    while (n--) {
        string s;
        cin >> s;
        if (regex_match(s, r)) {
            puts(s.c_str());
        }
    }

    return 0;
}