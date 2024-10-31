#define NMAX 100001
#include <bits/stdc++.h>
using namespace std;

// 인접 리스트
vector<int> board[NMAX];
int cnt = 0, N, M, R;
int vis[NMAX];

void dfs(int s){
    vis[s] = ++cnt;
    for (int e : board[s]){
        if (vis[e] > 0) continue;
        dfs(e);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(vis, 0, sizeof(vis));
    cin >> N >> M >> R;
    for (int i = 0; i < M; i++){
        int u, v; cin >> u >> v;
        board[u].push_back(v);
        board[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) sort(board[i].begin(), board[i].end());
    dfs(R);
    for (int i = 1; i <= N; i++) cout << vis[i] << "\n";
}