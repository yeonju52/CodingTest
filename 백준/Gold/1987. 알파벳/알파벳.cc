#include <bits/stdc++.h>
using namespace std;

int N, M, dst[21][21], alpha[26];
char board[21][21];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans = 0;

void dfs(int x, int y, int dep) {
	alpha[board[x][y] - 'A'] = 1;
	dst[x][y] = dep;
	ans = max(ans, dep);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (dst[nx][ny] > 0 && dst[nx][ny] < dep) continue;
		if (alpha[board[nx][ny] - 'A']) continue;
		dfs(nx, ny, dep + 1);
		dst[nx][ny] = 0;
		alpha[board[nx][ny] - 'A'] = 0;
	}
	return ;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0, 0, 1);
	cout << ans;
}
