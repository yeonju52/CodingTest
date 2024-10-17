#define MAX 102
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int board[MAX][MAX]; // 1 ~ 50
int draw[MAX][MAX];
int dist[MAX][MAX];
int N;
queue<pair<int , int>> Q;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int iX, iY;

pair<int, int> coord[MAX];

void print(const int (&arr)[MAX][MAX]){
    for (int y = N; y > 0; y--){
        for (int x = 1; x <= N; x++){
            cout << arr[x][y] << " ";
        }
        cout << "\n";
    }
    for (int y = 1; y <= N; y++){
        cout << "==";
    }
    cout << "\n";
}

bool isOut(int x, int y){
    return x < 1 || x > N || y < 1 || y > N;
}

bool isLine(int x, int y, vector<vector<int>> &rect){
    for (int i = 0; i < 8; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (isOut(nx, ny) || board[nx][ny] == 0) return 1;
    }
    return 0;
}

void bfs(int x, int y, vector<vector<int>> &rect){
    Q.push({x, y});
    draw[x][y] = 1;
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (isOut(nx, ny)) continue;
            if (!draw[nx][ny] && board[nx][ny] == 1 && isLine(nx, ny, rect)) {
                Q.push({nx, ny});
                draw[nx][ny] = 1;
            }
        }
    }
}

void getDist(int x, int y){
    Q.push({x, y});
    dist[x][y] = 1;
    
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        x = cur.first, y = cur.second;
        if (iX == x && iY == y){
            return ;
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (isOut(nx, ny)) continue;
            if (draw[nx][ny] && (dist[nx][ny] == 0 || dist[nx][ny] > dist[x][y] + 1)){
                dist[nx][ny] = dist[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 핵심 키: 좌표 축 * 2 배로 늘려야함. ㄷ에서 문제 생김
    int answer = 0;
    iX = itemX * 2, iY = itemY * 2;
    
    for (auto &arec : rectangle){
       N = max(N, *max_element(arec.begin(), arec.end()));
       for (int x = arec[0] * 2; x <= arec[2] * 2; x++)
           for (int y = arec[1] * 2; y <= arec[3] * 2; y++)
               board[x][y] = 1;
    }
    N *= 2;
    
    // 테두리 그리기
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (!draw[i][j] && board[i][j] == 1 && isLine(i, j, rectangle)) bfs(i, j, rectangle);
        }
    }
    // 가장 짧은 거리
    getDist(characterX * 2, characterY * 2);
    answer = dist[iX][iY] / 2;
    
    // print(board);
    // print(draw);
    // print(dist);
    return answer;
}