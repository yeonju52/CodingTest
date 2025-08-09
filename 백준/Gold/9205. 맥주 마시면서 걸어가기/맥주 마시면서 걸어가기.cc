#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

int T, N, sx, sy, tx, ty, vis[101];
vector<P> arr;

bool bfs() {
	queue<P> q;
	q.push({sx, sy});

	while(!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		if (x == tx && y == ty) return true;
		for (int i = 0; i <= N; i++) {
			if(vis[i]) continue;
			auto [nx, ny] = arr[i];
			if ((abs(nx - x) + abs(ny - y)) > 1000) continue;
			q.push({nx, ny});
			vis[i] = 1;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--) {
		arr.clear();
		memset(vis, 0, sizeof(vis));
		cin >> N >> sx >> sy;
		for (int i = 0; i < N; i++) {
			int x, y; cin >> x >> y;
			arr.push_back({x, y});
		}
		cin >> tx >> ty;
		arr.push_back({tx, ty});
		cout << (bfs() ? "happy" : "sad") << "\n";
	}
}
