#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[1002][1002];
int dist[1002][1002];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> Q;
int x, y;

void bfs(){
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        x = cur.first; y = cur.second;
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] != 0) continue;
            if (dist[nx][ny] != -1 && dist[nx][ny] <= dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1; // min 갱신
            Q.push({nx, ny});    
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) fill(dist[i], dist[i] + M, -1);
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (board[i][j] == 1) {
                Q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    bfs();

    int maxi = -1;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            // cout << dist[i][j];
            if (board[i][j] == -1) continue;
            if (dist[i][j] == -1) {
                cout << -1 << '\n';
                return 0;
            }
            // if (maxi < dist[i][j]) maxi = dist[i][j];
            maxi = max(maxi, dist[i][j]);
        }
        // cout << endl;
    }
    cout << maxi << '\n';
    return 0;
}