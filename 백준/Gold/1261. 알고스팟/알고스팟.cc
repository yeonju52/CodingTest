#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
const int INF = 10001;
int N, M;
int board[MAX][MAX];
int dist[MAX][MAX];

struct pos {
    int w, x, y;
    bool operator>(const pos &other) const {
        return w > other.w;
    }
};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(board, 0, sizeof(board));

    cin >> M >> N; // 문제 입력 조건 잘 읽자
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c; cin >> c;
            board[i][j] = c - '0';
        }
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = INF;
        }
    }

    priority_queue<pos, vector<pos>, greater<pos>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while(!pq.empty()) {
        pos cur = pq.top(); pq.pop();
        int x = cur.x, y = cur.y, w = cur.w;
        if (x == N - 1 && y == M - 1) {
            cout << w;
            break;
        }
        if (dist[x][y] < w) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            int nw = w + board[nx][ny];
            if (dist[nx][ny] > nw) {
                dist[nx][ny] = nw;
                pq.push({nw, nx, ny});
            }
        }
    }
    return 0;
}