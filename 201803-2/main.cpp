#include <bits/stdc++.h>
#define MAX_N 100
#define RIGHT true
#define LEFT false

using namespace std;

struct ball {
    int id;
    int pos;
    bool speed = RIGHT;
};

bool compare(const ball &b1, const ball &b2) {
	return b1.pos < b2.pos;
}

vector<ball> balls;
int answer[MAX_N];

int main() {
    int n, L, t;
    cin >> n >> L >> t;
    for (int i = 0; i < n; ++i) {
        ball b;
        b.id = i;
        cin >> b.pos;
        balls.push_back(b);
    }
    sort(balls.begin(), balls.end(), compare);

    // step second by second
    while (t--) {
        for (int j = 0; j < balls.size(); ++j) {
            // turn around if necessary
            if (j == 0 && balls[j].pos == 0 && balls[j].speed == LEFT) {
                balls[j].speed = !balls[j].speed;
            } 
            if (j == balls.size() - 1) {
                if (balls[j].pos == L && balls[j].speed == RIGHT) {
                    balls[j].speed = !balls[j].speed;
                }
            } else if (balls[j].pos == balls[j+1].pos && balls[j].speed == RIGHT && balls[j+1].speed == LEFT) {
                balls[j].speed = !balls[j].speed;
                balls[j+1].speed = !balls[j+1].speed;
            }

            // step
            if (balls[j].speed == RIGHT) {
                balls[j].pos++;
            } else {
                balls[j].pos--;
            }
        }
    }

    for (auto b : balls) {
        answer[b.id] = b.pos;
    }
    
    for (int i = 0; i < n; i++) {
        cout << answer[i];
        if (i != n - 1) {
            cout << " ";
        }
    }

    return 0;
}
