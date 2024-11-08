#include <bits/stdc++.h>
using namespace std;

int cube[102][102][102]; // HNM [z][x][y];
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int M, N, H;

struct coord {
    int z, x, y;
};

int bfs(){
    int dist[102][102][102];
    memcpy(dist, cube, sizeof(cube));
    queue<coord> Q;
    for (int z = 0; z < H; z++){
        for (int x = 0; x < N; x++){
            for (int y = 0; y < M; y++)
                if (cube[z][x][y] == 1) { Q.push({z, x, y}); dist[z][x][y] = 1; }// 익은 토마토 넣기
        }
    }
    int Y = 0;
    while(!Q.empty()){
        coord cur = Q.front(); Q.pop();
        for (int i = 0; i < 6; i++){
            int nz = cur.z + dz[i], nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nz][nx][ny] > 0) continue;
            if (cube[nz][nx][ny] == 0) { // 안 익었다면, 익히기
                dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
                cube[nz][nx][ny] = 1;
                Q.push({nz, nx, ny});
                Y = max(Y, dist[nz][nx][ny] - 1);
            }
        }
    }

    // 안 익은 토마토 있는지 확인하기
    for (int z = 0; z < H; z++){
        for (int x = 0; x < N; x++){
            for (int y = 0; y < M; y++)
                if (cube[z][x][y] == 0) return -1;
        }
    }

    return Y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;
    for (int z = 0; z < H; z++){
        for (int x = 0; x < N; x++)
            for (int y = 0; y < M; y++)
                cin >> cube[z][x][y];
    }
    
    cout << bfs() << "\n";
}