#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N, M, board[10][10];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void put(int x, int y, int c) {
	board[x][y] = c;

	for (int i = 0; i < 8; i++) {
		vector<pair<int, int>> np;
		int nx = x + dx[i], ny = y + dy[i];
		while(nx >= 0 && nx <= N + 1 && ny >= 0 && ny <= N + 1) {
			if (board[nx][ny] == c) break;
			if (board[nx][ny] == 0) {
				np = vector<pair<int, int>>{};
				break;
			}
			np.push_back({nx, ny});
			nx += dx[i], ny += dy[i];
		}
		for (auto &p : np) board[p.first][p.second] = c;
	}
	
	return ;
}

void display(const int arr[10][10]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(board, 0, sizeof(board));
		cin >> N >> M;

		// 보드 초기화
		int hN = N / 2;
		board[hN][hN] = 2, board[hN + 1][hN + 1] = 2;
		board[hN][hN + 1] = 1, board[hN + 1][hN] = 1;

		// 보드 게임 시작
		while(M--) {
			int x, y, c;
			cin >> x >> y >> c;
			put(x, y, c);
			// display(board);
		}

		// 게임 종료, 개수 카운트
		int B = 0, W = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] == 1) B++;
				else if (board[i][j] == 2) W++;
			}
		}

		cout << "#" << test_case << " " << B << " " << W << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
