#include <bits/stdc++.h>

using namespace std;

struct Window{
	int id;
	int x1, y1, x2, y2;
};

int main() {
    int N, M;
    cin >> N >> M;
    list<Window> windows;
	for (int i = 1; i <= N; ++i) {
		Window w;
		cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
		w.id = i;
		windows.push_front(w);
	}
    while (M--) {
		int x, y;
		cin >> x >> y;
		auto i = windows.begin();
		while (i != windows.end() && !(x >= i->x1 && x <= i->x2 && y >= i->y1 && y <= i->y2)) {
			++i;
        }
		if (i == windows.end()) {
			puts("IGNORED");
        } else {
			cout << i->id << endl;
			windows.erase(i);
			windows.push_front(*i);
		}
	}
	return 0;
}