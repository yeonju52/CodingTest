#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

typedef pair<int, int> P;
const int MAX = 250;
int R, C, vis[MAX][MAX];
char board[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

P getCnt(int x, int y) {
    queue<P> q;
    q.push({x, y});
    vis[x][y] = 1;

    unordered_map<char, int> map;
    bool out = true; // 우리 밖은 취급 안 함
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        x = cur.first, y = cur.second;
        if (board[x][y] != '.') map[board[x][y]]++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                out = false;
                continue;
            }
            if (vis[nx][ny] || board[nx][ny] == '#') continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    if (!out) return {0, 0};
    if (map['o'] > map['v']) return {map['o'], 0};
    return {0, map['v']};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    
    P ans = {0, 0};
    for (int i = 1; i < R - 1; i++) {
        for (int j = 1; j < C - 1; j++) {
            if (vis[i][j]) continue;
            if (board[i][j] != '#') {
                P tmp = getCnt(i, j);
                ans.first += tmp.first, ans.second += tmp.second;
            }
        }
    }
    cout << ans.first << " " << ans.second;
}