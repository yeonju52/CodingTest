#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
const int INF = 0x3f3f3f3f; // INF + INF 시, 오버플로우 방지

int N, M, board[MAX][MAX], nxt[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 초기화
    fill(board[1], board[N + 1], INF);
    for (int x = 1; x <= N; x++) board[x][x] = 0;
    
    while(M--) {
        int x, y, c; cin >> x >> y >> c;
        if (board[x][y] > c) {
            board[x][y] = c;
            nxt[x][y] = y;
        }
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (board[i][j] > board[i][k] + board[k][j]) {
                    board[i][j] = board[i][k] + board[k][j];
                    nxt[i][j] = nxt[i][k];
                }

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (board[x][y] == INF) cout << "0 ";
            else cout << board[x][y] << " ";
        }
        cout << "\n";
    }

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (board[x][y] == 0 || board[x][y] == INF) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int cur = x;
            while(cur != y) {
                path.push_back(cur);
                cur = nxt[cur][y];
            }
            path.push_back(y);
            cout << path.size() << " ";
            for (auto v: path) cout << v << " ";
            cout << "\n";
        }
    }
}