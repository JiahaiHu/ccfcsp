#include <bits/stdc++.h>

using namespace std;

struct IP {
    string ip = ""; // 32 bit binary ip
    int len = -1;    // prefix length
};

int pow_2[] = {1,2,4,8,16,32,64,128};
string to_binary(string& decimal) {
    string binary;
    int num = stoi(decimal);

    for (int i = 7; i >= 0; --i) {
        if (num >= pow_2[i]) {
            num -= pow_2[i];
            binary += '1';
        } else {
            binary += '0';
        }
    }

    return binary;
}

// normalize
IP normalize(string& s) {
    IP ip;
    string num;

    for (int i = 0; i <= s.size(); ++i) {
        if (i == s.size() || s[i] == '.') {
            ip.ip += to_binary(num);
            num.clear();
        } else if (s[i] == '/') {
            ip.ip += to_binary(num);
            num.clear();
            ip.len = stoi(s.substr(i + 1));
            break;
        } else {    // number
            num += s[i];
        }
    }

    // complete prefix length
    if (ip.len == -1) {
        ip.len = ip.ip.size();
    }

    // complete zero
    while (ip.ip.size() < 32) {
        ip.ip += '0';
    }

    return ip;
}

bool compare(IP& a, IP& b) {
    if (a.ip != b.ip) {
        return a.ip < b.ip;
    }
    return a.len < b.len;
}

bool include(IP& parent, IP& child) {
    if (parent.len > child.len) {
        return false;
    }
    for (int i = 0; i < parent.len; ++i) {
        if (parent.ip[i] != child.ip[i]) {
            return false;
        }
    }
    return true;
}

void merge_child_ip(list<IP>& ip_list) {
    auto i = ip_list.begin();
    auto j = ip_list.begin();

    ++j;
    while (j != ip_list.end()) {
        if (include(*i, *j)) {
            j = ip_list.erase(j);
        } else {
            ++i;
            ++j;
        }
    }
}

bool is_sibling(IP& a, IP& b) {
    if (a.len != b.len) {
        return false;
    }

    for (int i = 0; i < a.len - 1; ++i) {
        if (a.ip[i] != b.ip[i]) {
            return false;
        }
    }

    return true;
}

void merge_sibling_ip(list<IP>& ip_list) {
    auto i = ip_list.begin();
    auto j = ip_list.begin();

    ++j;
    while (j != ip_list.end()) {
        if (is_sibling(*i, *j)) {
            j = ip_list.erase(j);
            --(*i).len;
            if (i != ip_list.begin()) {
                --i;
                --j;
            }
        } else {
            ++i;
            ++j;
        }
    }
}

int main() {
    int n;
    list<IP> ip_list;

    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        ip_list.push_back(normalize(s));
    }

    ip_list.sort(compare);
    merge_child_ip(ip_list);
    merge_sibling_ip(ip_list);

    for (auto& ip : ip_list){
        for (int seg = 0; seg < 4; ++seg) {
            int num = 0;
            for (int bit = 0; bit < 8; ++bit) {
                num = num * 2 + (ip.ip[bit + seg * 8] - '0');
            }
            printf("%d%c", num, seg < 3 ? '.' : '/');
        }
        printf("%d\n", ip.len);
    }

    return 0;
}