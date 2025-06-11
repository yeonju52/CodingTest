#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100;
typedef pair<int, int> P;

int N, M, board[MAX][MAX], backup[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int getOutside() {
    memcpy(backup, board, sizeof(backup)); // 외부 공기 5로 표시 (내부 공기 = 0과 구분)
    int cnt = 0;
    queue<P> q;

    q.push({0, 0});
    backup[0][0] = 5;
    
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (backup[nx][ny] == 5) continue;
            else if (backup[nx][ny] >= 1) {
                if (++backup[nx][ny] >= 3) {
                    board[nx][ny] = 0;
                    cnt++;
                }
            }
            else if (backup[nx][ny] == 0) {
                q.push({nx, ny});
                backup[nx][ny] = 5;
            }
        }
    }
    return cnt;
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

    int ans = 0;
    while(getOutside() > 0) {
        ans++;
    }
    cout << ans;
}