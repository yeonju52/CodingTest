#include <bits/stdc++.h>
using namespace std;

char board[1002][1002];
int fire[1002][1002];
int dist[1002][1002];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    queue<pair<int, int>> fQ;
    queue<pair<int, int>> jQ;
    // for (int i = 0; i < R; i++) fill(fire[i], fire[i] + C, -1);
    // for (int i = 0; i < R; i++) fill(dist[i], dist[i] + C, -1);

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> board[i][j];
            if (board[i][j] == 'J') { 
                jQ.push({i, j});
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = -1;
            }
            if (board[i][j] == 'F') { 
                fQ.push({i, j});
                fire[i][j] = 0;
            }
            else { 
                fire[i][j] = -1; 
            }
            
        }
    }

    // fire
    while(!fQ.empty()){
        pair<int, int> cur = fQ.front(); fQ.pop();
        int x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            fire[nx][ny] = fire[x][y] + 1;
            fQ.push({nx, ny});
        }
    }

    // 지훈이
    while(!jQ.empty()){
        pair<int, int> cur = jQ.front(); jQ.pop();
        int x = cur.first, y = cur.second;
        if (x == 0 || x == R - 1 || y == 0 || y == C - 1) { // 탈출 조건
                cout << dist[x][y] + 1 << '\n';
                return 0;
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (fire[nx][ny] >= 0 && fire[nx][ny] <= dist[x][y] + 1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            jQ.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE\n";
    // for (int i = 0; i < R; i++){
    //     for (int j = 0; j < C; j++){
    //         cout << dist[i][j];
    //     }
    //     cout << '\n';
    // }
    return 0;
}