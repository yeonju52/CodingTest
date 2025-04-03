// 40분 소요
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
int board[52][52];
vector<pair<int, int>> chk;
int vis[15] = {0, };
vector<pair<int, int>> house;
int dist = 250002; // 정답

int cal(){
    int hx, hy;
    int sum = 0;
    for (auto cur : house){
        int mini = 102;
        hx = cur.X, hy = cur.Y;
        for (int i = 0; i < chk.size(); i++){
            if (vis[i]){
                mini = min(mini, abs(hx - chk[i].X) + abs(hy- chk[i].Y));
            }
        }
        sum += mini;

    }
    return sum;
}

void dfs(int dep, int idx){
    if (dep == M) {
        dist = min(dist, cal());
        // for (int i = 0; i < chk.size(); i++){
        //     cout << vis[i];
        // }
        // cout << endl;
        return;
    }
    for (int i = idx; i < chk.size(); i++){
        if(!vis[i]) {
            vis[i] = 1;
            dfs(dep + 1, i + 1);
            vis[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> board[i][j];
            if (board[i][j] == 2) chk.push_back({i, j});
            else if (board[i][j] == 1) house.push_back({i, j});
        }
    }
    dfs(0, 0);
    cout << dist;
}