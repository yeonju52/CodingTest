#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 50;

int N, M, board[MAX][MAX], vis[MAX][MAX], r, c, d, ans = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int d);

int main() {
    cin >> N >> M >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    dfs(r, c, d);
    cout << ans;
}

void dfs(int x, int y, int d) {
    if (!vis[x][y]) {
        vis[x][y] = 1;
        ans++;
    }
    
    // 전진
    for (int i = 0; i < 4; i++) {
        int nd = (d + 3 - i) % 4;
        int nx = x + dx[nd], ny = y + dy[nd];
        
        if (vis[nx][ny] || board[nx][ny]) continue;
        dfs(nx, ny, nd);
        return; // 해당방향 다 갔으면 return
    }
    
    // 후진
    int bx = x - dx[d], by = y - dy[d];
    if (!board[bx][by]) dfs(x - dx[d], y - dy[d], d);
}