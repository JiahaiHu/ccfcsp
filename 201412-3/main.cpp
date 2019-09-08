#include <bits/stdc++.h>

using namespace std;

struct Record {
    int type;   // buy:0, sell:1, cancel:2
    long long num;
    double price;
    bool cancel;
    Record(int t, long long n, double p = 0.0, bool c = false)
        : type(t), num(n), price(p), cancel(c) {}
};

vector<Record> records = {Record(-1, 0)};

bool cmp(int a, int b) {
    return records[a].price > records[b].price;
}

int main(){
    vector<int> buy, sell;
    string op;
    double price;
    int num;

    while (cin >> op) {
        if (op == "cancel") {
            scanf("%d", &num);
            records.push_back(Record(2, 0));
            records[num].cancel = true;
        } else {
            scanf("%lf%lld", &price, &num);
            records.push_back(Record(op == "buy" ? 0 : 1, num, price));
        }
    }

    long long sum_buy = 0, sum_sell = 0, ans_sum = 0;
    double ans_price = 0.0;
    for (int i = 1; i < records.size(); ++i) {
        if (records[i].type == 0 && !records[i].cancel) {
            buy.push_back(i);
        } else if (records[i].type == 1 && !records[i].cancel) {
            sell.push_back(i);
            sum_sell += records[i].num;
        }
    }

    sort(buy.begin(), buy.end(), cmp);
    sort(sell.begin(), sell.end(), cmp);

    for (int i = 0, j = 0; i < buy.size(); ++i) {
        sum_buy += records[buy[i]].num;
        while (j < sell.size() && records[sell[j]].price > records[buy[i]].price) {
            sum_sell -= records[sell[j]].num;
            ++j;
        }
        if (min(sum_buy, sum_sell) > ans_sum) {
            ans_sum = min(sum_buy, sum_sell);
            ans_price = records[buy[i]].price;
        }
    }
    printf("%.2f %lld", ans_price, ans_sum);

    return 0;
}