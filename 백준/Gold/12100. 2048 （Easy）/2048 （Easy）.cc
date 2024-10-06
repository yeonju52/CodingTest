#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];

int maxi = 0;

// void rotate(int rot){ // board 회전
//     int tmp[22][22];
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N; j++){
//             tmp[j][N - 1 - i] = board[i][j];
//         }
//     }
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N; j++){
//             board[i][j] = tmp[i][j];
//         }
//     }
// }

void rotate(int rot){ // board 회전
    // if (rot == 0) return;
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
        stack<int> num;
        int idx = 0;
        for (int j = 0; j < N; j++){
            if (board[i][j] != 0){
                if (!num.empty()){
                    if (num.top() == board[i][j]){
                        ans[i][idx++] = num.top() * 2;
                        num.pop();
                    }
                    else {
                        ans[i][idx++] = num.top();
                        num.pop();
                        num.push(board[i][j]);
                    }
                }
                else {
                    num.push(board[i][j]);
                }
            }
        }
        while(!num.empty()) {
            ans[i][idx++] = num.top(); num.pop();
        }
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