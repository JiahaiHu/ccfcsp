#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n;
    char c;

    cin >> T >> n;
    cin.get(c); // \n
    while (T--) {
        list<queue<pair<int,int>>> proc;    // first: sender, second: receiver
        string s;
        for (int i = 0; i < n; ++i) {
            proc.push_back(queue<pair<int,int>> ());
            getline(cin, s);
            for (int start = 0, end; start < s.size(); start = end + 1) {
                end = s.find(' ', start);
                if (end == string::npos) {
                    end = s.size();
                }

                int the_other = stoi(s.substr(start + 1, end - start - 1));
                if (s[start] == 'S') {
                    proc.back().push(make_pair(i, the_other));
                } else {
                    proc.back().push(make_pair(the_other, i));
                }
            }
        }

        while (!proc.empty()) {
            bool block = true;
            for (auto it = proc.begin(); it != proc.end(); ++it) {
                if ((*it).empty()) {
                    it = proc.erase(it);
                    --it;
                    continue;
                }

                pair<int,int> cmd = (*it).front();
                for (auto i = it; i != proc.end(); ++i) {
                    pair<int,int> _cmd = (*i).front();
                    if (it == i) continue;
                    if (cmd.first == _cmd.first && cmd.second == _cmd.second) {
                        (*it).pop();
                        (*i).pop();
                        block = false;
                        break;
                    }
                }
            }
            if (block) break;
        }

        puts(proc.empty() ? "0" : "1");
    }

    return 0;
}