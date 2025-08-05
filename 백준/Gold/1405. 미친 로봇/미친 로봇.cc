#include <bits/stdc++.h>
using namespace std;

int N, vis[30][30];
double p[4], ans;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int dep, double pi) {
	vis[x][y] = 1;
	if (dep == N) {
		ans += pi;
		vis[x][y] = 0; // 재귀 호출 후 복원
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (p[i] == 0) continue;
		int nx = x + dx[i], ny = y + dy[i];
		if (!vis[nx][ny]) {
			dfs(nx, ny, dep + 1, pi * p[i]);
		}
	}
	vis[x][y] = 0;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> p[i];
		p[i] /= 100;
	}

	dfs(15, 15, 0, 1);
	cout << fixed << setprecision(10) << ans << '\n';
}
