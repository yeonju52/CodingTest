#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
int ans[22][22];

int maxi = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int orX, orY;

void dup(int x, int y, int rot, int temp){
    if (x < 0 || x >= N || y < 0 || y >= N) return ;
    if (board[x][y] == 0) dup(x + dx[rot], y + dy[rot], rot, temp);
    if (board[x][y] == temp) ans[x][y] = temp;
    else return ;
    return ;
}

void dfs(int dep){
    if (dep == 5){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                maxi = max(maxi, board[i][j]);
            }
        }
    }
    for (int rot = 0; rot < 4; rot++){
        // 순회
        dfs(dep + 1);
        // 원상복귀
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // for (int i = 0; i < N; i++) fill(board[i], board[i] + N, 0);
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    int maxidx = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            maxidx = max(maxidx, board[i][j]);
        }
    }
    
    cout << maxidx;
    // dfs(0);
}