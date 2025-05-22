#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef pair<int, int> pii;

struct pos{
    int s, x, y;
};

const int MAX = 20;
int N, board[MAX][MAX], vis[MAX][MAX];
pos shark;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) shark = pos{2, i, j}, board[i][j] = 0;
            else if (board[i][j] > 0) cnt++;
        }
    }

    int ans = 0, eat = 0, res;
    while(cnt--) {
        res = bfs();
        if (res == 0) break;
        ans += res, eat++;
        if (eat == shark.s) shark.s++, eat = 0;
    }
    cout << ans;
}

bool cmp(int x, int y) { // 우선순위
    if (x == shark.x) return y < shark.y;
    return x < shark.x;
}

int bfs() {
    memset(vis, 0, sizeof(vis));
    queue<pii> q;
    int x = shark.x, y = shark.y;
    q.push({x, y});
    vis[x][y] = 1;

    int find = 1;
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        x = cur.X, y = cur.Y;
        if (board[x][y] > 0 && board[x][y] < shark.s) {
            if (find == 1) find = vis[x][y], shark.x = x, shark.y = y;
            if (find == vis[x][y]) {
                if(cmp(x, y)) shark.x = x, shark.y = y;
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny] > 0) continue;
            if (board[nx][ny] > shark.s) continue;
            if (find == 1 || find == vis[x][y] + 1) {
                q.push({nx, ny});
                vis[nx][ny] = vis[x][y] + 1;
            }
        }
    }
    if (find > 1) board[shark.x][shark.y] = 0;
    return find - 1;
}