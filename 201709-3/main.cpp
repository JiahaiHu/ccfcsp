#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> kv;
vector<string> keys;

void parse_json(string json) {
    bool done = false;
    int start = 1;  // index of first '"'
    while (!done) {
        string key = "";
        string value;
        int i, j;

        i= json.find(':', start);  // index of first ':'
        string _key = json.substr(start + 1, (i - 1) - (start + 1));
        keys.push_back(_key);

        if (json[i + 1] == '"') {   // value is a string
            j = json.find(',', i);
            if (j == string::npos) {    // the last key value
                j = json.size() - 1;
                done = true;
            }
            value = json.substr(i + 2, (j - 1) - (i + 2));
            
        } else {    // value is an object
            int num = 1;
            for (j = i + 2; j < json.size(); ++j) {
                if (json[j] == '{') {
                    num++;
                } else if (json[j] == '}') {
                    num--;
                }
                if (num == 0) {
                    break;  // found matched brace
                }
            }
            parse_json(json.substr(i + 1, (j + 1) - (i + 1)));
            value = "{}";
            if (json[j + 1] != ',') {
                done = true;
            } else {
                j++;
            }
        }

        for (int k = 0; k < keys.size(); ++k) {
            key += keys[k];
            if (k != keys.size() -1 ) {
                key += '.';
            }
        }
        // cout << key << ':' << value << endl;
        kv[key] = value;

        keys.pop_back();
        start = j + 1;
    }
}

void normalize(string& json) {
    json = regex_replace(json, regex(" "), "");   // trim space
    json = regex_replace(json, regex("\\\\\""), "\"");    // \" -> "   .
    json = regex_replace(json, regex("\\\\\\\\"), "\\");  // \\ -> \   .
}

int main() {
    int n, m;
    string json = "";

    cin >> n >> m;
    cin.get();
    while (n--) {
        string l;
        getline(cin, l);
        json += l;
    }
    normalize(json);
    parse_json(json);

    string key;
    while (m--) {
        cin >> key;
        if (kv.find(key) == kv.end()) {
            puts("NOTEXIST");
        } else if (kv[key] == "{}") {
            puts("OBJECT");
        } else {
            printf("STRING %s\n", kv[key].c_str());
        }
    }

    return 0;
}