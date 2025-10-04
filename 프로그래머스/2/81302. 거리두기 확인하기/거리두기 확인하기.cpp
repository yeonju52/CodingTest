#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int vis[5][5];

bool bfs(vector<string> &place) {
    for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (place[i][j] == 'P') {
            queue<pair<pair<int, int>, int>> q;
            memset(vis, 0, sizeof(vis));
            
            q.push({{i, j}, 0});
            vis[i][j] = 1;
            
            while (!q.empty()) {
                auto [cur, w] = q.front(); q.pop();
                auto [x, y] = cur;
                for (int r = 0; r < 4; r++) {
                    int nx = x + dx[r], ny = y + dy[r];
                    int nw = w + 1;
                    if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                    if (vis[nx][ny]) continue;
                    if (place[nx][ny] == 'X') continue;
                    if (nw <= 2 && place[nx][ny] == 'P') return false;
                    if (nw < 2) {
                        vis[nx][ny] = 1;
                        q.push({{nx, ny}, nw});
                    }
                }
            }
        }
    }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto &place : places) {
        answer.push_back(bfs(place));
    }

    return answer;
}
