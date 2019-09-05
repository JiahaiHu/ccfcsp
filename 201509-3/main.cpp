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
        smatch result;
        auto i = s.cbegin();
        while (regex_search(i, s.cend(), result, regex("\\{\\{ ([^\\}]+) \\}\\}"))) {
            while (i != result[0].first) {
                cout << *i;
                ++i;
            }
            auto v = VAR.find(result[1]);
            if (v != VAR.end()) {
                cout << v->second;
            }
            i = result[0].second;
        }
        while (i != s.cend()) {
            cout << *i;
            ++i;
        }
        cout << endl;
    }
    return 0;
}