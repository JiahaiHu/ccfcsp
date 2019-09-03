#include <bits/stdc++.h>

using namespace std;

int main() {
    int P;
    cin >> P;
    string pwd;
    cin >> pwd;
    cin.get();
    while (P--) {
        string s, temp;
        getline(cin, s);
        if (s == "") {
            cout << pwd << endl;
            continue;
        }
        if (s[0] != '/') {
            temp = pwd + '/' + s;
        } else {
            temp = s;
        }
        temp = regex_replace(temp, regex("//+"), "/");
        if (temp[temp.size() - 1] != '/') {
            temp += '/';
        }
        int start = 0;
        bool done = false;
        while (!done) {
            int end = temp.find('/', start + 1);
            if (end == temp.size() - 1) {
                done = true;
            }
            string sub = temp.substr(start + 1, end - start - 1);
            if (sub == ".") {
                temp.erase(start, end - start);
            } else if (sub == "..") {
                int pre = temp.substr(0, start).rfind('/');
                if (pre == string::npos) {
                    pre = 0;
                }
                temp.erase(pre, end - pre);
                start = pre;
            } else {
                start = end;
            }
        }
        if (temp.size() != 1) {
            temp.pop_back();    // remove last '/'
        }
        cout << temp << endl;
    }
    return 0;
}