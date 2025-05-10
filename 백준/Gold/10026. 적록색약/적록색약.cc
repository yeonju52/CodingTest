#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int N, vis[MAX][MAX];
char board[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny] || board[x][y] != board[nx][ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    for (int t = 0; t < 2; t++) {
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if(!vis[i][j]) { bfs(i, j); cnt++; }
        cout << cnt << " ";
        
        if (t == 1) break;
        // 적록색약
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if(board[i][j] == 'G') { board[i][j] = 'R'; }
    }
}