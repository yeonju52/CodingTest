#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX = 10;

struct pos {
	int x, y, cnt;
	bool operator==(const pos &other) const {
		return x == other.x && y == other.y;
	}
	bool operator!=(const pos &other) const {
		return !(x == other.x && y == other.y);
	}
};

int N, M, ans;
int board[MAX][MAX];
pos hole;

void dfs(int dep, pos rpos, pos bpos);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(board, 0, sizeof(board));
	pos rpos, bpos;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			if (c == '#') board[i][j] = 1;
			else if (c == 'R') rpos.x = i, rpos.y = j;
			else if (c == 'B') bpos.x = i, bpos.y = j;
			else if (c == 'O') hole.x = i, hole.y = j;
		}
	}
	ans = 11;
	rpos.cnt = 0, bpos.cnt = 0; // 초기화 필요 없지만?
	dfs(1, rpos, bpos);
	if (ans == 11) cout << "-1\n";
	else cout << ans << "\n";
}

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

pos move(pos cur, int dir) {
	while (true) {
		cur.x += dx[dir], cur.y += dy[dir], cur.cnt++; // 업데이트
		if (cur == hole) { // 홀이면
			return cur;
		}
		if (board[cur.x][cur.y]) { // 벽이라면
			return { cur.x - dx[dir], cur.y - dy[dir], cur.cnt - 1 };
		}
	}
}

void dfs(int dep, pos rpos, pos bpos) {
	if (dep > 10) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		pos nxtr = move(rpos, i);
		pos nxtb = move(bpos, i);
		if (nxtb == hole) continue;
		if (nxtr.cnt == 0 && nxtb.cnt == 0) continue;
		if (nxtr == hole) { // 홀이라면
			ans = min(dep, ans);
			return;
		}
		if (nxtr == nxtb) { // 둘의 좌표가 같다면
			if (nxtr.cnt < nxtb.cnt) {
				nxtb.x -= dx[i], nxtb.y -= dy[i];
			}
			else if (nxtr.cnt > nxtb.cnt) {
				nxtr.x -= dx[i], nxtr.y -= dy[i];
			}
		}
		nxtr.cnt = 0, nxtb.cnt = 0;
		dfs(dep + 1, nxtr, nxtb);
	}
}