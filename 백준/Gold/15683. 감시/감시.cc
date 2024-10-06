#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, mini;
int board[10][10];
int vis[10][10];
vector<pair<int, int>> cctv;

void visited(int x, int y, int dir, int val){
    while(x >= 0 && x < N && y >= 0 && y < M && board[x][y] != 6){
        if(board[x][y] == 0) vis[x][y] += val; // 방문: 1, 방문제거: -1 // 중복감시 때문에
        x += dx[dir];
        y += dy[dir];
    }
}

void runCCTV(int x, int y, int dir, int val){
    if (board[x][y] == 1){
        visited(x, y, dir, val);
    }
    else if (board[x][y] == 2){
        visited(x, y, dir, val);
        visited(x, y, (dir + 2) % 4, val);
    }
    else if (board[x][y] == 3){
        visited(x, y, dir, val);
        visited(x, y, (dir + 1) % 4, val);
    }
    else if (board[x][y] == 4){
        visited(x, y, dir, val);
        visited(x, y, (dir + 1) % 4, val);
        visited(x, y, (dir + 2) % 4, val);
    }
    else if (board[x][y] == 5){
        visited(x, y, dir, val);
        visited(x, y, (dir + 1) % 4, val);
        visited(x, y, (dir + 2) % 4, val);
        visited(x, y, (dir + 3) % 4, val);
    }
}

void dfs(int dep){
    if(dep == cctv.size()){
        int cnt = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (!vis[i][j] && board[i][j] == 0) cnt++;
            }
        }
        mini = min(mini, cnt);
        return;
    }
    for (int dir = 0; dir < 4; dir++){
        runCCTV(cctv[dep].first, cctv[dep].second, dir, 1);
        dfs(dep + 1);
        runCCTV(cctv[dep].first, cctv[dep].second, dir, -1);
    }
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
            if (board[i][j] > 0 && board[i][j] < 6){
                cctv.push_back({i, j});
            }
        }
    }
    mini = N * M; // 최대값으로 초기화
    dfs(0);
    cout << mini;
}