#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
const int INF = 400;

int N, M, stat, ans, board[MAX][MAX], dist[MAX][MAX];

struct pos {
    int x, y;
};

struct posD {
    int d, x, y;
    bool operator<(const posD &other) const {
        if (d != other.d) return d < other.d;
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

vector<pair<pos, pos>> men; // { start, end }
pos car;

void bfs(int x, int y);
int bfs(int sx, int sy, int ex, int ey);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> stat;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cin >> car.x >> car.y;
    car.x--, car.y--;
    for (int i = 0; i < M; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        men.push_back({{sx - 1, sy - 1}, {ex - 1, ey - 1}});
    }

    while (!men.empty()) {
        // 1. 승객 선택 (최단 거리 확인)
        posD minM = {INF + 1, MAX + 1, MAX + 1};
        auto miniter = men.end(); // 지울 men
        bfs(car.x, car.y);
        for (auto it = men.begin(); it != men.end(); it++) {
            pos cur = (*it).first;
            if (dist[cur.x][cur.y] == 0) continue;
            posD tmp = { dist[cur.x][cur.y] - 1, cur.x, cur.y };
            if (tmp < minM) { // tmp.d >= 0: 경로가 없으면 업데이트가 안 될 수도 있음
                minM = tmp;
                miniter = it;
            }
        }

        // 2. 승객 출발지로 이동, stat 변화
        if(miniter == men.end() || stat < minM.d) { ans = -1; break; } // 이동 불가 확인
        stat -= minM.d;
        
        // 3. 승객 목적지 이동, stat 변화
        pos st = (*miniter).first, ed = (*miniter).second;
        int dst = bfs(st.x, st.y, ed.x, ed.y);
        if (dst < 0 || stat < dst) { ans = -1; break; }
        stat = stat - dst + (dst * 2);
        
        // 4. 승객 제거, car 위치도 변경
        men.erase(miniter);
        car.x = ed.x, car.y = ed.y;
        ans = stat;
    }
    cout << ans;
    return 0;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int sx, int sy, int ex, int ey) {
    memset(dist, 0, sizeof(dist));
    queue<pos> q;
    dist[sx][sy] = 1;
    q.push({sx, sy});

    while(!q.empty()) {
        pos cur = q.front(); q.pop();
        int x = cur.x, y = cur.y;
        if (x == ex && y == ey) break;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] || dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return dist[ex][ey] - 1;
}

void bfs(int x, int y) {
    memset(dist, 0, sizeof(dist));
    queue<pos> q;
    dist[x][y] = 1;
    q.push({x, y});

    while(!q.empty()) {
        pos cur = q.front(); q.pop();
        x = cur.x, y = cur.y;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] || dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

}