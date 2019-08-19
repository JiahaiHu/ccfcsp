#include <bits/stdc++.h>

using namespace std;

vector<int> student;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        student.push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        int p, q;
        cin >> p >> q;
        auto x = find(student.begin(), student.end(), p);
        x = student.erase(x);
        student.insert(x + q, p);
    }
    for (int i = 0; i < student.size(); ++i) {
        cout << student[i];
        if (i != student.size() - 1) {
            cout << " ";
        }
    }
    return 0;
}