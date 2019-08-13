#include <bits/stdc++.h>

using namespace std;

vector<pair<regex, string>> config; // first: pattern    second: source

regex to_regex(string p) {
    p = regex_replace(p, regex("<int>"), "([0-9]+)");
    p = regex_replace(p, regex("<str>"), "([^/]+)");
    p = regex_replace(p, regex("<path>"), "(.+)");
    return regex(p);
}

int main() {
    int n, m;
    string p;   // pattern
    string s;   // source

    cin >> n >> m;
    cin.get();
    while (n--) {
        cin >> p >> s;
        config.push_back({to_regex(p), s});
    }

    smatch result;
    while (m--) {
        bool matched = false;
        cin >> p;
        for (auto c : config) {
            if (regex_match(p, result, c.first)) {
                cout << c.second;
                for (int i = 1; i < result.size(); ++i) {
                    string m = result[i];
                    if (regex_match(m, regex("[0-9]+"))) {
                        while (m[0] == '0') {
                            m.erase(0,1);
                        }
                    }
                    cout << " " << m;
                }
                cout << endl;
                matched = true;
                break;
            }
        }
        if (!matched) {
            cout << "404" << endl;
        }
    }

    return 0;
}
