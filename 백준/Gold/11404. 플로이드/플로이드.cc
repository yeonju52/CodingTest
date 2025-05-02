#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
const int INF = 0x3f3f3f3f; // INF + INF 시, 오버플로우 방지

int N, M, board[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    // 초기화
    fill(board[1], board[N + 1], INF);
    for (int x = 1; x <= N; x++) board[x][x] = 0;
    
    while(M--) {
        int x, y, c; cin >> x >> y >> c;
        board[x][y] = min(board[x][y], c);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);

    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            if (board[x][y] == INF) cout << "0 ";
            else cout << board[x][y] << " ";
        }
        cout << "\n";
    }
}