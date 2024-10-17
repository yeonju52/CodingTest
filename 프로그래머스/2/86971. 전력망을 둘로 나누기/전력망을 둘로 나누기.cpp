#define MAX 102
#define cur first
#define next second
#include <bits/stdc++.h>
using namespace std;

int N;
int board[MAX][MAX];
queue<pair<int, int>> Q;
int vis[MAX];

void print(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j];
        cout << "\n";
    }
}

int bfs(int i_cur, int i_next){
    int cnt = 0;
    Q.push({i_cur, i_next});
    vis[i_cur] = 1;
    
    while(!Q.empty()){
        pair<int, int> wire = Q.front(); Q.pop();
        for (int idx = 0; idx < N; idx++){
            if (vis[idx] || !board[wire.next][idx]) continue;
            if (!board[wire.next][idx]) continue;
            Q.push({wire.next, idx});
            vis[wire.next] = 1;
            cnt++;
        }
    }
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    N = wires.size() + 1; // 송전탑의 개수 = N + 1
    for (auto& wire : wires){
        board[wire[0] - 1][wire[1] - 1] = 1;
        board[wire[1] - 1][wire[0] - 1] = 1;
    }
    int minCnt = MAX;
    for (auto& wire : wires){
        memset(vis, 0, sizeof(vis));
        int cnt = bfs(wire[0] - 1, wire[1] - 1) + 1;
        minCnt = min(abs((N - cnt) - cnt), minCnt);
    }
    answer = minCnt;
    return answer;
}