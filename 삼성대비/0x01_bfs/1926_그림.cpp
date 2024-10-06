#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool board[502][502];
bool vis[502][502];
// RLDU
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

int bfs(int fir, int sec, int sum){
    queue<pair<int, int>> Q;
    vis[fir][sec] = 1;
    Q.push({fir, sec});
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        sum++;
        for (int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    
    int cnt = 0, maxi = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 0 || vis[i][j] == 1) continue;
            int sumi = bfs(i, j, 0);
            if (sumi > maxi) maxi = sumi;
            cnt++;
        }
    }
    
    cout << cnt << '\n' << maxi;
    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++){
    //         cout << board[i][j];
    //     }
    //     cout << '\n';
    // }
}