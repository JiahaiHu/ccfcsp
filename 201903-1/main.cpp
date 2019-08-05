#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a, min, max, mid_double;
    vector<int> v;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    min = v.front();
    max = v.back();
    if (n % 2 == 0) {
        mid_double = v[n/2] + v[n/2-1];
    } else {
        mid_double = v[(n-1)/2] * 2;
    }

    printf("%d ", max);
    if (mid_double % 2 == 0) {
        printf("%d", mid_double/2);
    } else {
        printf("%.1f", mid_double*1.0/2);
    }
    printf(" %d", min);

    return 0;
}
