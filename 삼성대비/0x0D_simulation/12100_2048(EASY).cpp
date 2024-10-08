// 틀린 이유
// stack에서 2 4 4 8 4 4 -> 2 8 8 8 이런식으로 되어야하는데
// 잘못 구성해서
// 8(합) 8(합) 2 8 이런식으로 구현됐을 듯
#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];

int maxi = 0;

void rotate(int rot){ // board 회전
    int tmp[22][22];
    for (int i = 0; i < xN; i++){
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
                // 스택이 빈다면, top, pop 할 수 없음
                else {
                    num.push(board[i][j]);
                }
            }
        }
        // 맨 마지막 원소가 남아 있다면
        if (!num.empty()){
            ans[i][idx] = num.top(); num.pop();
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