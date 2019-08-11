#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;

int today[MAX_N + 1];
int tomorrow[MAX_N + 1];

int main() {
    int n;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", today + i);
    }

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            tomorrow[i] = (today[i] + today[i+1]) / 2;
        } else if (i == n) {
            tomorrow[i] = (today[i-1] + today[i]) / 2;
        } else {
            tomorrow[i] = (today[i-1] + today[i] + today[i+1]) / 3;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d", tomorrow[i]);
        if (i != n) {
            printf(" ");
        }
    }

    return 0;
}