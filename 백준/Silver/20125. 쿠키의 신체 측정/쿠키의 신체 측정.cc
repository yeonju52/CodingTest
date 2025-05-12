#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int N, hx, hy, wx, wy; // 배열 크기, 심장 위치, 허리 위치
char board[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int bfs(int dir, int x, int y);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    // 심장 위치 찾기
    bool isHeart = false;
    for (int x = 0; x < N && !isHeart; x++) {
        for (int y = 0; y < N && !isHeart; y++) {
            if (board[x][y] == '*') {
                isHeart = true;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) isHeart = false;
                    if (board[nx][ny] == '_') isHeart = false;
                    if (!isHeart) break;
                }
                if (isHeart) hx = x, hy = y;
            }
        }
    }

    // 심장, 허리, 좌우 팔, 다리
    cout << hx + 1 << " " << hy + 1 << "\n";
    cout << bfs(0, hx, hy) - 1 << " " << bfs(1, hx, hy) - 1 << " " << bfs(2, hx, hy) - 1 
            << " " << bfs(2, wx + 1, wy - 1) << " " << bfs(2, wx + 1, wy + 1);
}

int vis[MAX][MAX];
int bfs(int dir, int x, int y) {
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        cnt++;
        if (dir == 2 && (x == hx && y == hy)) wx = cur.first, wy = cur.second; // 허리 위치 찾기
        int nx = cur.first + dx[dir], ny = cur.second + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (vis[nx][ny] || board[nx][ny] == '_') continue;
        vis[nx][ny] = 1;
        q.push({nx, ny});
    }
    return cnt;
}