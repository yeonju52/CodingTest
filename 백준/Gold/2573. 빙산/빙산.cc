#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[302][302];
bool vis[302][302];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

// void printArr(){
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < M; j++){
//             cout << vis[i][j];
//         }
//         cout << "\n";
//     }
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < M; j++){
//             cout << board[i][j];
//         }
//         cout << "\n";
//     }
// }

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (vis[nx][ny] || board[nx][ny] == 0) continue;
        dfs(nx, ny);
    }
}

bool getCluster(){
    memset(vis, false, sizeof(vis));
    // 첫번째 클러스터 찾기
    bool flag = false; // 이중 for문 탈출을 위함
    for (int x = 0; x < N; x++){
        for (int y = 0; y < M; y++){
            if (board[x][y] > 0) {
                dfs(x, y);
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    // 그 외 flood fill이 하나라도 있으면
    for (int x = 0; x < N; x++){
        for (int y = 0; y < M; y++){
            if (board[x][y] > 0 && !vis[x][y]) {
                return true;
            }
        }
    }
    return false;
}

void melt(){
    int backup[302][302];
    memcpy(backup, board, sizeof(board));
    
    for (int x = 0; x < N; x++){
        for (int y = 0; y < M; y++){
            if (board[x][y] == 0) continue;
            int cnt = 0;
            for (int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (backup[nx][ny] == 0) cnt++;
            }
            board[x][y] = max(0, board[x][y] - cnt);
        }
    }
}

bool isFinished(){
    for (int x = 0; x < N; x++){
        for (int y = 0; y < M; y++){
            if (board[x][y] != 0) return false; // 하나라도 있으면 false 반환
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    int answer = 0;
    while (true){
        melt();
        answer++;
        if(getCluster()) break;
        if(isFinished()) {
            answer = 0;
            break;
        }
    }
    cout << answer;
}