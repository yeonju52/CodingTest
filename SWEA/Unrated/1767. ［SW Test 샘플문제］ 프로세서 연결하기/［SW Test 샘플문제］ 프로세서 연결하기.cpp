#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
const int MAX = 12;
using namespace std;

struct pos {
	int x, y;
};
int N, clen;
pos ans;
int board[MAX][MAX];

void dfs(int dep, vector<pos> &core, pos result, vector<vector<int>> &vis);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		memset(board, 0, sizeof(board));
		ans = { 0, MAX * MAX + 1 }; // 설치 개수(최대), 전선의 길이 합(최소)
		
		vector<pos> core;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (!board[i][j]) continue;
				if (i == 0 || i == N - 1 || j == 0 || j == N - 1) continue; // 가장자리에 있는 코어는 확인 필요 없음
				core.push_back({ i, j });
			}
		}
		clen = core.size();
		vector<vector<int>> vis(N, vector<int>(N, 0));
		dfs(0, core, { 0, 0 }, vis);
		if (ans.x == 0) ans.y = 0; // 한번도 업데이트 안 된 경우;
		cout << "#" << test_case << " " << ans.y << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

int install(pos &cur, int dir, vector<vector<int>> &vis, vector<pos> &installed) {
	int nx = cur.x;
	int ny = cur.y;

	while (true) {
		nx += dx[dir], ny += dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
		if (vis[nx][ny] || board[nx][ny]) return 0;
		installed.push_back({ nx, ny });
	}

	// 연결 성공 시 표시
	for (auto &p : installed) vis[p.x][p.y] = 1;
	return installed.size();
}

void dfs(int dep, vector<pos> &core, pos result, vector<vector<int>> &vis) {
	if (dep == clen) {
		if (result.x == 0) return;
		//cout << "\n" << result.x << "," << result.y;
		if (ans.x < result.x) { // 업데이트 시, 전선의 최소값 찾기
			ans = result;
		}
		else if (ans.x == result.x) {
			ans.x = result.x, ans.y = min(ans.y, result.y);
		}
		return;
	}
	for (int i = 0; i < 5; i++) {
		vector<pos> installed;
		int len = install(core[dep], i, vis, installed);
		int val = (i != 0) ? 1 : 0;
		if (!len && val) continue; // 실패의 경우

		dfs(dep + 1, core, { result.x + val, result.y + len }, vis);
		for (auto &p : installed) vis[p.x][p.y] = 0; // 원상 복구
	}
}