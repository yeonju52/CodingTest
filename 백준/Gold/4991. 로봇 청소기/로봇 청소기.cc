#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
const int INF = 0x3f3f3f3f;
char board[MAX][MAX];
int N, M, dist[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(pair<int, int> st, pair<int, int> ed);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> M >> N;
        if (N == 0 && M == 0) break;
        pair<int, int> st;
        memset(board, 0, sizeof(board));
        memset(dist, 0, sizeof(dist));

        vector<pair<int, int>> pos;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> board[i][j];
                if (board[i][j] == 'o') st = {i, j};
                else if (board[i][j] == '*') pos.push_back({i, j});
            }
        }

        // sort(pos.begin(), pos.end());
        pos.push_back(st);
        int K = pos.size();
        vector<vector<int>> dirt(K, vector<int>(K, 0));
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (i == j) continue;
                dirt[i][j] = bfs(pos[i], pos[j]);
            }
        }
        pos.pop_back();

        vector<int> comb;
        for (int i = 0; i < K - 1; i++) comb.push_back(i);
        int ans = INF;
        do {
            int res = 0, cur = K - 1;
            for (auto &nxt : comb) {
                int cnt = dirt[cur][nxt];
                if (cnt == -1) { res = -1; break; }
                res += cnt;
                if (res > ans) continue;
                cur = nxt;
            }
            if (res < 0) continue;
            ans = min(ans, res);
        } while(next_permutation(comb.begin(), comb.end()));
        
        if (ans == INF) cout << "-1\n";
        else cout << ans << "\n";
    }
}

int bfs(pair<int, int> st, pair<int, int> ed) {
    
    queue<pair<int, int>> q;
    memset(dist, 0, sizeof(dist));
    q.push(st);
    dist[st.first][st.second] = 1;

    while(!q.empty()) {
        st = q.front(); q.pop();
        int x = st.first, y = st.second;
        if (x == ed.first && y == ed.second) return dist[x][y] - 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 'x') continue;
            if (dist[nx][ny] == 0 || dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}