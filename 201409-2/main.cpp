#include <bits/stdc++.h>
#define MAX_N 100

using namespace std;

bool matrix[MAX_N][MAX_N];
int num = 0;

void draw_rect(int x1, int y1, int x2, int y2) {
    for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y) {
            if (matrix[x][y] == false) {
                matrix[x][y] = true;
                ++num;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        draw_rect(x1, y1, x2 - 1, y2 - 1);
    }
    cout << num << endl;
    return 0;
}