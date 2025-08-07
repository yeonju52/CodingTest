#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

int N, L, R, board[51][51], vis[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs(int x, int y) {
	queue<P> q;
	q.push({x, y});
	vis[x][y] = 1;

	int total = 0;
	vector<P> cc;

	while(!q.empty()) {
		P cur = q.front(); q.pop();
		x = cur.first, y = cur.second;
		cc.push_back({x, y});
		total += board[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[nx][ny]) continue;
			int diff = abs(board[nx][ny] - board[x][y]);
			if (diff >= L && diff <= R) {
				vis[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}

	if (cc.size() == 1) return false;

	int nval = total / cc.size();
	for (auto &cur : cc) {
		x = cur.first, y = cur.second;
		board[x][y] = nval;
	}
	return true;
}

bool simm() {
	memset(vis, 0, sizeof(vis));
	bool pass = false;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				if(bfs(i, j)) pass = true;
			}
		}
	}
	return pass;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	int ans = 0;
	while(simm()) ans++;
	cout << ans;
}
