#include <bits/stdc++.h>

using namespace std;

// (privilege name, max level)
unordered_map<string, int> privilege;   // never uesd
// (role name or user name, (privilege name, level))
unordered_map<string, unordered_map<string, int> > role, user;

// return (privilege name, level)
pair<string, int> parse_privilege(string& s) {
    int i = s.find(':');
    int level = (i != string::npos) ? stoi(s.substr(i + 1)) : -1;
    return make_pair(s.substr(0, i), level);
}

int main() {
    int p, r, u, q;
    string str;

    cin >> p;
    while (p--) {
        cin >> str;
        privilege.insert(parse_privilege(str));
    }

    cin >> r;
    while (r--) {
        int s;
        cin >> str >> s;
        while (s--) {
            string _s;
            cin >> _s;
            pair<string, int> a = parse_privilege(_s);
            if (role[str].find(a.first) != role[str].end()) {
                role[str][a.first] = max(a.second, role[str][a.first]);
            } else {
                role[str][a.first] = a.second;
            }
        }
    }

    cin >> u;
    while (u--) {
        int t;
        cin >> str >> t;
        while (t--) {
            string _s;
            cin >> _s;  // role name
            for (auto i : role[_s]) {
                if (user[str].find(i.first) != user[str].end()) {
                    user[str][i.first] = max(i.second, user[str][i.first]);
                } else {
                    user[str][i.first] = i.second;
                }
            }
        }
    }

    cin >> q;
    while (q--) {
        string _s;  // privilege name
        cin >> str >> _s;
        pair<string, int> p = parse_privilege(_s);
        if (user.find(str) != user.end() && user[str].find(p.first) != user[str].end()
            && p.second <= user[str][p.first])
        {
            if (p.second == -1 && user[str][p.first] != -1) {
                cout << user[str][p.first] << endl;
            } else {
                puts("true");
            }
        } else {
            puts("false");
        }
    }

    return 0;
}