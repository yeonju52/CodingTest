#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;
typedef pair<int, int> P;

int N, M, board[MAX][MAX], out[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void getOutside() {
    queue<P> q;
    q.push({0, 0});
    memset(out, 0, sizeof(out));
    out[0][0] = 1;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (out[nx][ny]) continue;
            if (board[nx][ny] == 0) {
                q.push({nx, ny});
                out[nx][ny] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    vector<P> ch;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(board[i][j] == 1) ch.push_back({i, j});
        }
    }

    int ans = 0;
    while(!ch.empty()) {
        vector<P> nch;
        getOutside(); // 외부 공기 2로 표시 (내부 공기 = 0과 구분)
        for (auto &cur : ch) {
            int x = cur.first, y = cur.second;
            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i]; // 맨 가장자리에는 치즈 x
                if (out[nx][ny]) cnt++;
            }
            if (cnt < 2) nch.push_back({x, y});
            else board[x][y] = 0;
        }
        ch = nch;
        ans++;
    }
    cout << ans;
}