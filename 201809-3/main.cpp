#include <bits/stdc++.h>

using namespace std;

struct Element {
    string label;
    string id;  // include '#'
    int level;
    int parent = -1;
};

Element line[100];

void tolowercase(string& s) {
    for (int i = 0; i < s.length(); ++i) {
        s[i] = tolower(s[i]);
    }
}

bool selected(int i, string sel) {
    if (sel[0] == '#' && line[i].id == sel) return true;
    if (sel[0] != '#' && line[i].label == sel) return true;
    return false;
}

int select_parent(int i, string sel) {
    int p = line[i].parent;
    while (p != -1) {
        if (selected(p, sel)) {
            return p;
        }
        p = line[p].parent;
    }
    return -1;
}

int main() {
    int n, m;
    int parent[100];

    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; ++i) {
        string s;
        int dot;
        int id_index;

        getline(cin, s);
        dot = s.rfind('.') + 1;
        id_index = s.find('#', dot);

        line[i].level = dot / 2;
        parent[line[i].level] = i;
        if (line[i].level > 0) {
            line[i].parent = parent[line[i].level - 1];
        }

        if (id_index == -1) {
            line[i].id = "";
            line[i].label = s.substr(dot);
        } else {
            line[i].id = s.substr(id_index);
            line[i].label = s.substr(dot, id_index - dot - 1);
        }
        tolowercase(line[i].label);
    }

    while (m--) {
        string s, sel;
        vector<string> selectors;
        vector<int> answer;

        getline(cin, s);
        stringstream ss(s);
        while (ss >> sel) {
            if (sel[0] != '#') {    // label selector
                tolowercase(sel);
            }
            selectors.push_back(sel);
        }

        for (int i = 0; i < n; ++i) {
            int e = i;
            bool is_selected = false;
            for (int j = selectors.size() - 1; j >= 0; --j) {
                sel = selectors[j];
                if (j == selectors.size() - 1) {
                    if (!selected(e, sel)) {
                        break;
                    }
                    if (j == 0) {
                        is_selected = true;
                    }
                } else {
                    int parent = select_parent(e, sel);
                    if (parent == -1) {
                        break;
                    }
                    e = parent;
                    if (j == 0) {
                        is_selected = true;
                    }
                }
            }
            if (is_selected) {
                answer.push_back(i);
            }
        }
        printf("%d ", answer.size());
        for (auto i : answer) {
            printf("%d ", i + 1);
        }
        puts("");
    }

    return 0;
}