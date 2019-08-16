#include <bits/stdc++.h>

using namespace std;

const int lower[5] = {0, 0, 1, 1, 0};
const int upper[5] = {59, 23, 31, 12, 6};
const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unordered_map<string, int> trans = {
    {"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, {"may", 5}, {"jun", 6},
    {"jul", 7}, {"aug", 8}, {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12},
    {"sun", 0}, {"mon", 1}, {"tue", 2}, {"wed", 3}, {"thu", 4}, {"fri", 5}, {"sat", 6}
};

int n;
long long s, t;
string cron[5];
string command;
set<int> time_range[5];
map<long long, vector<string>> ans;

int days_of_month(int y, int m){
    if ((y % 400 == 0 || y % 4 == 0 && y % 100 != 0) && m == 2) {
        return 29;
    }
    return days[m];
}

int day_of_week(int y, int m, int d) {
    int week = 4;
    for (int i = 1970; i < y; ++i){
        int temp = (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) ? 366 : 365;
        week = (week + temp) % 7;
    }
    for (int i = 1; i < m; ++i) {
        week = (week + days_of_month(y, i)) % 7;
    }
    return (week + d - 1) % 7;
}

int normalize(string s) {
    if (isdigit(s[0])) {
        return stoi(s);
    }
    for (char& c: s) {
        c = tolower(c);
    }
    return trans[s];
}

void parse_cron() {
    for (int i = 0; i < 5; ++i) {
        time_range[i].clear();
        if (cron[i] == "*") {
            for (int j = lower[i] ; j <= upper[i]; ++j) {
                time_range[i].insert(j);
            }
        } else {
            int start = 0;
            while (true) {
                int end = cron[i].find(',', start);
                string s;
                if (end == string::npos) {
                    s = cron[i].substr(start);
                } else {
                    s = cron[i].substr(start, end - start);
                }

                int p = s.find('-');
                int _lower = normalize(s.substr(0, p));
                int _upper;
                if (p == string::npos) {
                    _upper = _lower;
                } else {
                    _upper = normalize(s.substr(p + 1));
                }
                for (int j = _lower; j <= _upper; ++j) {
                    time_range[i].insert(j);
                }

                if (end == string::npos) {
                    break;
                } else {
                    start = end + 1;
                }
            }
        }
    }
}

void schedule() {
    for (int y = s / 1e8; y <= t / 1e8; ++y) {
        for (int mon : time_range[3]) {
            for (int d : time_range[2]) {
                if (d > days_of_month(y, mon)) {
                    continue;
                }
                if (find(time_range[4].begin(), time_range[4].end(),
                        day_of_week(y, mon, d)) != time_range[4].end())
                {
                    for (int h : time_range[1]) {
                        for (int min : time_range[0]) {
                            long long temp = (long long)y * 1e8 + mon * 1e6 + d * 1e4 + h * 1e2 + min;
                            if(temp >= s && temp < t) {
                                ans[temp].push_back(command);
                            }
                        }
                    }
                        
                }
                    
            }
        }
    }
}

int main() {
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> cron[j];
        }
        cin >> command;
        parse_cron();
        schedule();
    }
    for (auto a : ans) {
        for (auto cmd : a.second) {
            printf("%lld %s\n", a.first, cmd.c_str());
        }
    }
    return 0;
}