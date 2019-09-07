#include <bits/stdc++.h>
#define MAX_N 20000

using namespace std;

vector<int> children[MAX_N+1];
int max_height[MAX_N+1];
int max_length[MAX_N+1];

void dfs(int n) {
    int max1 = 0;   // first max height
    int max2 = 0;   // second max height
    for (int i : children[n]) {
        dfs(i);
        int temp = max_height[i] + 1;
        if (temp > max1) {
            max2 = max1;
            max1 = temp;
        } else if (temp > max2) {
            max2 = temp;
        }
    }
    max_height[n] = max1;
    max_length[n] = max1 + max2;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n + m; ++i) {
        int a;
        cin >> a;
        children[a].push_back(i);
    }
    dfs(1);
    cout << *max_element(max_length + 1, max_length + n + m + 1) << endl;
    return 0;
}