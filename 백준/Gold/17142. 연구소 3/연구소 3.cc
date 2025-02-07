#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M, arr[52][52], dist[52][52];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> virus;
    memset(arr, 0, sizeof(arr));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virus.push_back({i, j});
        }
    }

    int cnt = min((int)virus.size(), M);
    vector<int> comb(virus.size(), 0);
    fill(comb.end() - M, comb.end(), 1);

    int ans = 50 * 50 + 1;
    do {
        queue<pair<int, int>> Q;
        memset(dist, -1, sizeof(dist));

        for (int v = 0; v < comb.size(); v++) {
            if (comb[v] == 1) {
                Q.push(virus[v]);
                dist[virus[v].X][virus[v].Y] = 0;
            }
        }

        while (!Q.empty()) {
            pair<int, int> cur = Q.front(); Q.pop();
            int x = cur.X, y = cur.Y;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (arr[nx][ny] == 1 || dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                Q.push({nx, ny});
            }
        }

        int max_time = 0;
        bool valid = true;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 0) {
                    if (dist[i][j] == -1) valid = false;
                    else max_time = max(max_time, dist[i][j]);
                }
            }
        }

        if (valid) ans = min(ans, max_time);

    } while (next_permutation(comb.begin(), comb.end()));

    cout << (ans == 50 * 50 + 1 ? -1 : ans);
    return 0;
}
