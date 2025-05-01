#include <bits/stdc++.h>
using namespace std;

const int MAX = 8;
int N, M, board[MAX][MAX], vis[MAX][MAX];
vector<pair<int, int>> wall, virus;
vector<int> brute;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs();
void display(const int arr[MAX][MAX]);

int main() {
    // 0은 빈 칸, 1은 벽, 2는 바이러스
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) wall.push_back({i, j});
            else if (board[i][j] == 2) virus.push_back({i, j});
        }
    }
    int len = wall.size();
    brute.resize(len, 0);
    fill(brute.end() - 3, brute.end(), 1);
    int ans = 0;
    do {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < len; i++) {
            if (brute[i]) vis[wall[i].first][wall[i].second] = 1;
        }
        ans = max(bfs(), ans);
    } while (next_permutation(brute.begin(), brute.end()));
    cout << ans;
}

int bfs() {
    queue<pair<int, int>> q;
    for (auto &v : virus) {
        q.push(v);
        vis[v.first][v.second] = 2;
    }

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny] > 0 || board[nx][ny] > 0) continue;
            vis[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
    // display(vis);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0 && vis[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void display(const int arr[MAX][MAX]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}