#include<bits/stdc++.h>

using namespace std;

int main() {
    int r, y, g;
    int n, k, t;
    long long cost = 0;

    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);

    int cycle = r + g + y;
    int light[3] = {r, g, y};   // convenient for light switch

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &k, &t);
        if (k == 0) {
            cost += t;
            continue;
        }
        
        // map k to index of array 'light'
        if (k == 1) {
            k = 0;
        } else if (k == 3) {
            k = 1;
        }

        // calculate the light and countdown at the time XiaoMing arrive there
        t = (light[k] - t + cost) % cycle;
        while (t >= light[k]) {
            t -= light[k];
            k = (k + 1) % 3;
        }

        t = light[k] - t;
        if (k == 0) {   // red
            cost += t;
        } else if (k == 2) {    // yellow
            cost += t + r;
        }
    }

    printf("%lld", cost);

    return 0;
}