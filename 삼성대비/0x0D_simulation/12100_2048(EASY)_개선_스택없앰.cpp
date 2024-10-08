// 틀린 이유
// stack이 필요 없었다..
#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
int maxi = 0;

void rotate(int rot){ // board 회전
    int tmp[22][22];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (rot == 0) tmp[i][j] = board[i][j];
            else if (rot == 1) tmp[j][N - 1 - i] = board[i][j];
            else if (rot == 2) tmp[N - 1 - i][N - 1 - j] = board[i][j];
            else if (rot == 3) tmp[N - 1 - j][i] = board[i][j];
        }
    }
    memcpy(board, tmp, sizeof(board));
}

void play(){
    int ans[22][22];
    for (int i = 0; i < N; i++) fill(ans[i], ans[i] + N, 0);
    
    for (int i = 0; i < N; i++){
        int num = 0;
        int idx = 0;
        for (int j = 0; j < N; j++){
            if (board[i][j] == 0) continue;
            if (num == 0) num = board[i][j];
            else if (num == board[i][j]) {
                ans[i][idx++] = num * 2;
                num = 0;
            }
            else {
                ans[i][idx++] = num;
                num = board[i][j];
            }
        }
        if (num != 0) ans[i][idx] = num;
    }
    // board update
    memcpy(board, ans, sizeof(ans));
}

void dfs(int dep){
    if (dep == 5){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                maxi = max(maxi, board[i][j]);
                // cout << board[i][j] << " ";
            }
            // cout << endl;
        }
        return;
    }
    for (int rot = 0; rot < 4; rot++){
        int tmp[22][22];
        memcpy(tmp, board, sizeof(tmp));
        // 순회
        rotate(rot);
        play();
        dfs(dep + 1);
        // 복구
        memcpy(board, tmp, sizeof(board));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        fill(board[i], board[i] + N, 0);
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << maxi;
}