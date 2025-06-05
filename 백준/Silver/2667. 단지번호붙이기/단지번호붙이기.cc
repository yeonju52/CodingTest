#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MAX = 25;

int N, board[MAX][MAX];

vector<int> ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            board[i][j] = c - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                int cnt = 0;
                queue<pii> q;
                q.push({i, j});
                board[i][j] = 0;
                while(!q.empty()) {
                    pii cur = q.front(); q.pop();
                    int x = cur.first, y = cur.second;
                    cnt++;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i], ny = y + dy[i];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (board[nx][ny]) {
                            q.push({nx, ny});
                            board[nx][ny] = 0;
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto &c : ans) cout << c << "\n";
}