#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

using P = pair<int, int>;
const int MAX = 51;

int N, M, R, C, L, board[MAX][MAX], dst[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> dir[8] = {
	{},
	{0, 1, 2, 3},
	{0, 2},
	{1, 3},
	{0, 1},
	{1, 2},
	{2, 3},
	{3, 0}
};

void display(const int arr[MAX][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

bool isValid(int fx, int fy, int nxt) {
	fx *= -1, fy *= -1;
	for (auto &i : dir[nxt]) {
		if (dx[i] == fx && dy[i] == fy) return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> R >> C >> L;
		memset(board, 0, sizeof(board));
		memset(dst, 0, sizeof(dst));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j];
			}
		}
		
		queue<P> q;
		q.push({R, C});
		dst[R][C] = 1;
		int ans = 1;

		while(!q.empty()) {
			P cur = q.front(); q.pop();
			int x = cur.first, y = cur.second;
			int r = board[x][y];
			if (dst[x][y] >= L) break;
			for (auto i : dir[r]) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (board[nx][ny] == 0 || dst[nx][ny] > 0) continue;
				if (!isValid(dx[i], dy[i], board[nx][ny])) continue;
				q.push({nx, ny});
				dst[nx][ny] = dst[x][y] + 1;
				ans++;
			}
		}
		cout << "#" << test_case << " " << ans << "\n";
		// display(dst);
	}
	return 0;

}
