#include <bits/stdc++.h>

using namespace std;

vector<pair<regex, string>> trans = {
    {regex("^\\* +(.*)"), "<li>$1</li>"},
    {regex("_([^_]+)_"), "<em>$1</em>"},
    {regex("\\[([^\\]]+)\\]\\(([^\\)]+)\\)"), "<a href=\"$2\">$1</a>"}
};

vector<vector<string>> markdown;

void to_html(vector<string>& b, bool p) {
    for (int i = 0; i < b.size(); ++i) {
        for (auto& j : trans) {
            b[i] = regex_replace(b[i], j.first, j.second);
        }
        if (p && i == b.size() - 1) {   // last line of a paragraph
            cout << b[i];   // nowrap, for the "</p>" following
        } else {
            puts(b[i].c_str());
        }
    }
}

int main() {
    // header regex
    for (int i = 1; i <= 6; ++i) {
        trans.push_back({
            regex("^" + string(i, '#') + " +(.*)"),
            "<h" + to_string(i) + ">$1</h" + to_string(i) + ">"
        });
    }

    string s;
    markdown.push_back({});
    while (getline(cin, s)) {
        if (s == "") {
            markdown.push_back({});
        } else {
            markdown.back().push_back(s);
        }
    }

    for (auto& b : markdown) {   // parse block
        if (b.empty()) {    // trim empty line
            continue;
        }
        if (b[0][0] == '*') {   // list
            puts("<ul>");
            to_html(b, false);
            puts("</ul>");
        } else if (b[0][0] == '#') {    // header
            to_html(b, false);
        } else {    // paragraph
            cout << "<p>";
            to_html(b, true);
            cout << "</p>" << endl;
        }
    }
}