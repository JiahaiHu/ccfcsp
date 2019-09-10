#include <bits/stdc++.h>

using namespace std;

unordered_map<char, bool> option;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i+1] == ':') {
            option[s[i]] = true;
            ++i;
        } else {
            option[s[i]] = false;
        }
    }

    int N;
    cin >> N;
    cin.get();
    for (int i = 1; i <= N; ++i) {
        getline(cin, s);
        stringstream ss(s);
        map<char, string> args;
        ss >> s;    // option name
        while (ss >> s) {
            if (s.size() == 2 && s[0] == '-') {
                if (option.find(s[1]) == option.end()) {
                    break;
                }
                if (option[s[1]]) {
                    string arg;
                    ss >> arg;
                    if (ss.fail()) {
                        break;
                    }
                    args[s[1]] = arg;
                } else {
                    args[s[1]] = "";
                }
            } else {
                break;
            }
        }
        cout << "Case " << i << ":";
        for (auto& arg : args) {
            cout << " -" << arg.first;
            if (arg.second != "") {
                cout << " " << arg.second;
            }
        }
        cout << endl;
    }

    return 0;
}