#include <iostream>
#include <queue>
using namespace std;

const int MAX = 50;
int N, M;
int board[MAX][MAX];

int bfs(queue<pair<int, int>> &q);

int main() {
  // memset(board, 0, sizeof(board));
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  queue<pair<int, int>> q;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      if (board[i][j]) {
        q.push({i, j});
      }
    }
  }
  cout << bfs(q);
  return 0;
}

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int bfs(queue<pair<int, int>> &q) {
  // memset(vis, 0, sizeof(vis))
  int maxDist = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front(); q.pop();
    int x = cur.first, y = cur.second;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if (board[nx][ny]) continue;
      board[nx][ny] = board[x][y] + 1;
      q.push({nx, ny});
      maxDist = max(board[nx][ny], maxDist);
    }
  }
  return maxDist - 1;
}