#include <bits/stdc++.h>
#define MAX_N 1000

using namespace std;

struct Point{
    int x, y, len;
    Point(int x, int y, int len = 0) : x(x), y(y), len(len) {}
};

int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int graph[MAX_N+1][MAX_N+1];
bool vis[MAX_N+1][MAX_N+1];
long long ans = 0;

int main() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    
    queue<Point> q;
    int x, y, c;
    while (m--) {
        cin >> x >> y;
        q.push(Point(x, y));
        vis[x][y] = true;
    }
    while (k--) {
        cin >> x >> y >> c;
        graph[x][y] += c;
    }
    while (d--) {
        cin >> x >> y;
        graph[x][y] = -1;
    }

    while(!q.empty()){
        Point p = q.front();
        q.pop();

        if (graph[p.x][p.y] > 0) {
            ans += (long long)p.len * graph[p.x][p.y];
        }

        for (int i = 0; i < 4; ++i) {
            int x = p.x + direction[i][0];
            int y = p.y + direction[i][1];
            if (x > 0 && x <= n && y > 0 && y <= n && graph[x][y] >= 0 && !vis[x][y]) {
                q.push(Point(x, y, p.len + 1));
                vis[x][y] = true;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}