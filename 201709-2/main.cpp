#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;

struct Task {
    bool borrow;  // borrow: 1, return: 0
    int time;
    int key;
    bool operator < (const Task& t) const {
        if (time == t.time) {
            if (borrow == t.borrow) {
                return !(key < t.key);
            } else {
                return !(borrow < t.borrow);   // return first
            }
        } else {
            return !(time < t.time);
        }
    }
};

int key[MAX_N + 1];
priority_queue<Task> task;

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i <= N; ++i) {
        key[i] = i;
    }
    for (int i = 0; i < K; ++i) {
        int w, s, c;
        cin >> w >> s >> c;
        Task t;
        t.key = w;
        t.borrow = true;
        t.time = s;
        task.push(t);
        t.borrow = false;
        t.time = s + c;
        task.push(t);
    }
    while (!task.empty()) {
        Task t = task.top();
        task.pop();
        if (t.borrow) {
            for (int i = 1; i <= N; ++i) {
                if (key[i] == t.key) {
                    key[i] = 0;
                }
            }
        } else {    // return
            for (int i = 1; i <= N; ++i) {
                if (key[i] == 0) {
                    key[i] = t.key;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << key[i];
        if (i != N) {
            cout << " ";
        }
    }
    return 0;
}