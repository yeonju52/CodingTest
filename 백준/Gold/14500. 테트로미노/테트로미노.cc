#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 502;
const int SHAPE = 7;
int N, M;
int board[MAX][MAX];
int backup[MAX][MAX];

int dx[SHAPE][4] = {
    {0, 0, 0, 0}, // ㅡ
    {0, 0, -1, -1}, // ㅁ
    {0, -1, -2, -2}, // ㄴ
    {0, -1, -1, -2}, // ㄹ
    {0, 0, -1, 0}, // ㅜ
    {0, -1, -2, -2}, // ㄴ (좌우반전)
    {0, -1, -1, -2} // ㄹ (좌우반전)
};
    
int dy[SHAPE][4] = {
    {0, 1, 2, 3}, // ㅡ
    {0, 1, 0, 1}, // ㅁ
    {0, 0, 0, 1}, // ㄴ
    {0, 0, 1, 1}, // ㄹ
    {0, 1, 1, 2}, // ㅜ
    {0, 0, 0, -1}, // ㄴ (좌우반전)
    {0, 0, -1, -1} // ㄹ (좌우반전)
};

void rotate();
int putTet(int k);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    memset(board, 0, sizeof(board));
    memset(backup, 0, sizeof(backup));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < SHAPE; k++) {
            ans = max(ans, putTet(k));
        }
        rotate();
    }
    cout << ans;
}

int putTet(int k) {
    int maxScr = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            bool flag = true;
            int scr = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[k][i], ny = y + dy[k][i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    flag = false;
                    break;
                }
                scr += board[nx][ny];
            }
            if (flag) maxScr = max(scr, maxScr);
        }
    }
    return maxScr;
}

void rotate() { // 시계방향
    memcpy(backup, board, sizeof(backup));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[j][N - 1 - i] = backup[i][j];
        }
    }
    swap(N, M);
}