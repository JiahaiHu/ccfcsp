#include <bits/stdc++.h>

using namespace std;

vector<string> html;
unordered_map<string, string> VAR;

int main() {
    int m, n;
    cin >> m >> n;
    cin.get();
    while (m--) {
        string s;
        getline(cin, s);
        html.push_back(s);
    }
    while (n--) {
        string s;
        getline(cin, s);
        int i = s.find(' ');
        string name = s.substr(0, i);
        string value = s.substr(i + 2, s.size() - i - 3);
        VAR[name] = value;
    }
    for (string& s: html) {
        for (auto& m: VAR) {
            s = regex_replace(s, regex("\\{\\{ " + m.first + " \\}\\}"), m.second);
        }
        s = regex_replace(s, regex("\\{\\{ [^\\}]+ \\}\\}"), "");
        puts(s.c_str());
    }
    return 0;
}