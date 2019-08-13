#include <bits/stdc++.h>

using namespace std;

int main() {
    int combo = 0;
    int point = 0;
    
    while (true) {
        int d;
        scanf("%d", &d);
        if (d == 1) {
            combo = 0;
            point++;
        } else if (d == 2) {
            combo++;
            point = point + combo * 2;
        } else {    // 0
            break;
        }
    }
    printf("%d", point);

    return 0;
}