#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pll;
const int MAX = 1000;
int N, M, board[MAX][MAX], vis[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int sx, sy;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) sx = i, sy = j;
        }
    }

    queue<pll> q;
    q.push({sx, sy});
    // vis[sx][sy] = 1;

    while(!q.empty()) {
        pll cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 2) continue;
            if (vis[nx][ny] == 0 || vis[nx][ny] > vis[x][y] + 1) {
                if (board[nx][ny] == 1) q.push({nx, ny});
                vis[nx][ny] = vis[x][y] + 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j] == 0 && board[i][j] == 1) cout << "-1 ";
            else if (board[i][j] == 1) cout << vis[i][j] << " ";
            else cout << "0 ";
        }
        cout << "\n";
    }
}