#include <cstdio>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days_of_month(int y, int m) {
    if ((y % 400 == 0 || y % 4 == 0 && y % 100 != 0) && m == 2) {
        return 29;
    }
    return days[m];
}

int day_of_week(int y, int m, int d) {
    int day = 2;
    int days = 0;
    for (int i = 1850; i < y; ++i) {
        days += (i % 400 == 0 || i % 4 == 0 && i % 100 != 0) ? 366 : 365;
    }
    for (int i = 1; i < m; ++i) {
        days += days_of_month(y, i);
    }
    day = (day + days) % 7;
    return (day + d - 1) % 7;
}

int main() {
    int a, b, c, y1, y2;
    scanf("%d %d %d %d %d", &a, &b, &c, &y1, &y2);
    c %= 7;
    for (int i = y1; i <= y2; ++i) {
        int first_day_of_month = day_of_week(i, a, 1);
        int day = 1 + (c + 7 - first_day_of_month) % 7 + 7 * (b - 1);
        if (day <= days_of_month(i, a)) {
            printf("%04d/%02d/%02d\n", i, a, day);
        }
        else {
            puts("none");
        }
    }
    return 0;
}