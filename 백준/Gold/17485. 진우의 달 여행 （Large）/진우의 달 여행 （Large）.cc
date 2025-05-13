#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;
const int INF = 987654321; // 1000 * 1000 * 100
int N, M;

struct pos {
    int w, x, y, r;
    bool operator<(const pos &other) const {
        if (w != other.w) return w > other.w;
        if (x != other.x) return x > other.x;
        if (y != other.y) return y > other.y;
        return r > other.r;
    }
};

int adj[MAX][MAX], vis[MAX][MAX][3];

int dx[3] = {1, 1, 1};
int dy[3] = {-1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < M; j++) {
            cin >> adj[i][j];
        }
    }
    fill(&vis[0][0][0], &vis[0][0][0] + MAX * MAX * 3, INF);

    priority_queue<pos> pq;
    for (int j = 0; j < M; j++) {
        for (int  r = 0; r < 3; r++) {
            vis[0][j][r] = adj[0][j];
            pq.push({vis[0][j][r], 0, j, r});
        }
    }

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y, r = cur.r; // w = cur.w;
        for(int i = 0; i < 3; i++) {
            if (r == i) continue;
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny][i] > vis[x][y][r] + adj[nx][ny]) {
                vis[nx][ny][i] = vis[x][y][r] + adj[nx][ny];
                pq.push({vis[nx][ny][i], nx, ny, i});
            }
        }
    }
    int ans = INF;
    for (int y = 0; y < M; y++) {
        ans = min(*min_element(vis[N - 1][y], vis[N - 1][y] + 3), ans);
    }
    cout << ans;
}